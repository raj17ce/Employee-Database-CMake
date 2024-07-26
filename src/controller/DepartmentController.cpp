#include <exception>
#include <iomanip>
#include "DepartmentController.h"
#include "DBManager.h"

using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool DepartmentController::insertDepartment(const Department& obj) {
	std::string queryString = "INSERT INTO Department (departmentName, baseSalary, allowance, deduction) "
		+ std::string{ "VALUES (" } +
		"\"" + obj.getDepartmentName() + "\"" + ", " +
		std::to_string(obj.getBaseSalary()) + ", " +
		std::to_string(obj.getAllowance()) + ", " +
		std::to_string(obj.getDeduction()) + ");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "\x1B[32m" << "Successfully inserted a Department." << "\033[0m\n";
	}
	catch (const std::exception& e) {
		std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
		std::cerr << "\x1B[31m" << "Department could not be inserted." << "\033[0m\n";
		return false;
	}
	return true;
}

int DepartmentController::getDepartmentIDbyName(const std::string& departmentName) {
	std::string queryString = "SELECT departmentID FROM Department WHERE departmentName = \"" + departmentName + "\" COLLATE NOCASE;";
	auto departmentID{ -1 };

	auto getDepartmentIDCallback = [](void* data, int argc, char** argv, char** azColName) -> int {
		int* eId = static_cast<int*>(data);
		if (!strcmp(azColName[0], "departmentID")) {
			*eId = std::stoi(argv[0]);
		}
		return 0;
		};

	try {
		DBManager::instance().executeCustomQuery(queryString.c_str(), getDepartmentIDCallback, &departmentID);
	}
	catch (const std::exception& e) {
		std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
		return -1;
	}

	return departmentID;
}

bool DepartmentController::checkDepartmentExistence(const std::string& departmentID) {
	std::string queryString = "SELECT departmentID FROM Department WHERE departmentID = " + departmentID + ";";

	auto callbackCount{ 0 };

	try {
		callbackCount = DBManager::instance().executeRowCountQuery(queryString.c_str());
	}
	catch (std::exception& e) {
		std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
	}

	if (callbackCount == 0) {
		return false;
	}

	return true;
}

bool DepartmentController::selectDepartment(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Department " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\" COLLATE NOCASE":"") + ";";

	try {
		auto rowCount = DBManager::instance().executeSelectQuery(queryString.c_str());
		std::cout << "\x1B[32m" << rowCount << std::string{ " record" } + (rowCount > 1 ? "s" : "") + " found" << "\033[0m\n";
	}
	catch (const std::exception& e) {
		std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
		return false;
	}
	return true;
};

bool DepartmentController::deleteDepartmentByID(int ID) {
	std::string queryString = "DELETE FROM Department WHERE departmentID = " + std::to_string(ID) + ";";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "\x1B[32m" << "Successfully deleted a Department." << "\033[0m\n";
	}
	catch (const std::exception& e) {
		std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
		std::cerr << "\x1B[31m" << "Department could not be deleted." << "\033[0m]\n";
		return false;
	}
	return true;
}

std::string DepartmentController::getUpdateQueryCondition(Department& obj) {
	std::string updateQueryCondition{ "" };

	if (obj.getDepartmentName() != "#") {
		updateQueryCondition += "departmentName = \"" + obj.getDepartmentName() + "\"";
	}
	if (obj.getBaseSalary() != -1.0) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "baseSalary = " + std::to_string(obj.getBaseSalary());
	}
	if (obj.getAllowance() != -1.0) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "allowance = " + std::to_string(obj.getAllowance());
	}
	if (obj.getDeduction() != -1.0) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "deduction = " + std::to_string(obj.getDeduction());
	}

	return updateQueryCondition;
}

bool DepartmentController::updateDepartment(Department& obj) {

	std::string updateQueryCondition = getUpdateQueryCondition(obj);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE Department SET " + updateQueryCondition + " WHERE departmentID = " + std::to_string(obj.getDepartmentID()) + ";";
		try {
			DBManager::instance().executeQuery(queryString.c_str());
			std::cout << "\x1B[32m" << "Successfully updated a Department." << "\033[0m\n";
		}
		catch (const std::exception& e) {
			std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
			std::cerr << "\x1B[31m"<< "Department could not be updated." << "\033[0m\n";
			return false;
		}
	}
	return true;
}