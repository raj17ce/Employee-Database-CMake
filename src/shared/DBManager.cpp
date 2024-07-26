#include "DBManager.h"

#include <cstring>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
#include "Config.h"
#include "EmployeeController.h"
#include "LogManager.h"
#include "Salary.h"

using EmployeeDB::DBManager;
using EmployeeDB::Model::Salary;
using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::LogManager;

DBManager& DBManager::instance() {
	static DBManager dbManager;
	return dbManager;
}

int DBManager::openConnection() {
	m_ResultCode = sqlite3_open(EmployeeDB::Config::DBFilePath.string().c_str(), &m_DB);

	if (m_ResultCode == SQLITE_OK) {
		LogManager::instance().getLogger().debug("Successfully opened DB Connection");
	}
	else {
		LogManager::instance().getLogger().error("Error opening DB connection");
		std::cerr << "\x1B[31m" << "Error opening DB connection" << "\033[0m" << '\n';
	}
	return m_ResultCode;
}

int DBManager::closeConnection() {
	m_ResultCode = sqlite3_close(m_DB);

	if (m_ResultCode == SQLITE_OK) {
		LogManager::instance().getLogger().debug("Successfully closed DB Connection");
	}
	else {
		LogManager::instance().getLogger().error("Error closing DB connection");
		std::cerr << "\x1B[31m" << "Error closing DB connection" << "\033[0m" << '\n';
	}
	return m_ResultCode;
}

int DBManager::executeQuery(const char* queryString) {
	LogManager::instance().getLogger().debug("started executing query : ", queryString);

	m_ResultCode = sqlite3_exec(m_DB, queryString, 0, 0, &m_ErrorMessage);

	if (m_ResultCode == SQLITE_OK) {
		LogManager::instance().getLogger().debug("Successfully executed query : ", queryString);
	}
	else {
		LogManager::instance().getLogger().error("Error executing query : ", queryString, " : ", m_ErrorMessage);
		throw std::runtime_error{ m_ErrorMessage };
	}
	return m_ResultCode;
}

int DBManager::executeCustomQuery(const char* queryString, int (*callback)(void*, int, char**, char**), void* arg) {
	LogManager::instance().getLogger().debug("started executing query : ", queryString);

	m_ResultCode = sqlite3_exec(m_DB, queryString, callback, arg, &m_ErrorMessage);

	if (m_ResultCode == SQLITE_OK) {
		LogManager::instance().getLogger().debug("Successfully executed query : ", queryString);
	}
	else {
		LogManager::instance().getLogger().error("Error executing query : ", queryString, " : ", m_ErrorMessage);
		throw std::runtime_error{ m_ErrorMessage };
	}
	return m_ResultCode;
}

int DBManager::selectCallback(void* arg, int argc, char** argv, char** azColName) {
	int* rowCount = static_cast<int*>(arg);
	(*rowCount)++;
	std::cout << "|--------------------|----------------------------------------|\n";
	int i;
	for (i = 0; i < argc; i++) {
		std::cout << "|" << std::setw(20) << std::left << azColName[i] << "|" << std::setw(40) << std::left << (argv[i] ? argv[i] : "NULL") << "|\n";
	}
	std::cout << "|--------------------|----------------------------------------|\n";
	std::cout << std::endl;
	return 0;
}

int DBManager::executeSelectQuery(const char* queryString) {
	auto rowCount{ 0 };
	LogManager::instance().getLogger().debug("started executing query : ", queryString);

	m_ResultCode = sqlite3_exec(m_DB, queryString, selectCallback, &rowCount, &m_ErrorMessage);

	if (m_ResultCode == SQLITE_OK) {
		LogManager::instance().getLogger().debug("Successfully executed query : ", queryString);
	}
	else {
		LogManager::instance().getLogger().error("Error executing query : ", queryString, " : ", m_ErrorMessage);
		throw std::runtime_error{ m_ErrorMessage };
	}
	return rowCount;
}

int DBManager::selectSalaryCallback(void* arg, int argc, char** argv, char** azColName) {
	int* rowCount = static_cast<int*>(arg);
	(*rowCount)++;

	Salary obj;

	std::cout << "|--------------------|----------------------------------------|\n";
	int i;
	for (i = 0; i < argc; i++) {
		if (!strcmp(azColName[i], "employeeID")) {
			obj.setEmployeeID(std::stoi(argv[i]));
		}
		std::cout << "|" << std::setw(20) << std::left << azColName[i] << "|" << std::setw(40) << std::left << (argv[i] ? argv[i] : "NULL") << "|\n";
	}
	EmployeeController::getSalaryDetails(obj);
	double totalSalary = obj.computeSalary();
	std::cout << "|" << std::setw(20) << std::left << "Total Salary" << "|" << std::setw(40) << std::left << std::fixed << std::setprecision(2) << totalSalary << "|\n";
	std::cout << "|--------------------|----------------------------------------|\n";
	std::cout << std::endl;
	return 0;
}

int DBManager::executeSelectSalaryQuery(const char* queryString) {
	auto rowCount{ 0 };
	LogManager::instance().getLogger().debug("started executing query : ", queryString);

	m_ResultCode = sqlite3_exec(m_DB, queryString, selectSalaryCallback, &rowCount, &m_ErrorMessage);

	if (m_ResultCode == SQLITE_OK) {
		LogManager::instance().getLogger().debug("Successfully executed query : ", queryString);
	}
	else {
		LogManager::instance().getLogger().error("Error executing query : ", queryString, " : ", m_ErrorMessage);
		throw std::runtime_error{ m_ErrorMessage };
	}
	return rowCount;
}

int DBManager::rowCountCallback(void* arg, int argc, char** argv, char** azColName) {
	int* rowCount = static_cast<int*>(arg);
	(*rowCount)++;
	return 0;
}

int DBManager::executeRowCountQuery(const char* queryString) {
	auto rowCount{ 0 };
	LogManager::instance().getLogger().debug("started executing query : ", queryString);

	m_ResultCode = sqlite3_exec(m_DB, queryString, rowCountCallback, &rowCount, &m_ErrorMessage);

	if (m_ResultCode == SQLITE_OK) {
		LogManager::instance().getLogger().debug("Successfully executed query : ", queryString);
	}
	else {
		LogManager::instance().getLogger().error("Error executing query : ", queryString, " : ", m_ErrorMessage);
		throw std::runtime_error{ m_ErrorMessage };
	}
	return rowCount;
}

void DBManager::executeConfigQuery() {
	std::string queryString = "PRAGMA foreign_keys = ON;";

	try {
		instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << "\x1B[31m" << e.what() << "\033[0m" << '\n';
	}
}

void DBManager::executeTruncateQuery(const char* tableName) {
	std::string queryString = std::string{ "DELETE FROM " } + tableName + ";";

	try {
		instance().executeQuery(queryString.c_str());
	}
	catch (const std::exception& e) {
		std::cerr << "\x1B[31m" << e.what() << "\033[0m" << '\n';
	}
}