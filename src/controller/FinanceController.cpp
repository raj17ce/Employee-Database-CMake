#include <exception>
#include "DBManager.h"
#include "FinanceController.h"
#include "EmployeeController.h"
#include "DepartmentController.h"

using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Controller::FinanceController;
using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool FinanceController::insertFinance(Finance& obj) {
	auto departmentID = DepartmentController::getDepartmentIDbyName("Finance");

	if (departmentID == -1) {
		std::cerr << "\x1B[31m" << "Finance department not found. Please insert a department named Finance." << "\033[0m\n";
		return false;
	}

	obj.setDepartmentID(departmentID);

	auto employeeResult = EmployeeController::insertEmployee(obj);

	if (!employeeResult) {
		std::cerr << "\x1B[31m" << "Finance could not be inserted." << "\033[0m\n";
		return false;
	}

	auto employeeID = EmployeeController::getEmployeeIDbyEmail(obj.getEmail());

	std::string queryString = "INSERT INTO Finance (employeeID, accountingTool) VALUES (" +
		std::to_string(employeeID) + ", " +
		"\"" + obj.getAccountingTool() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "\x1B[32m" << "Successfully inserted a Finance." << "\033[0m\n";
	}
	catch (const std::exception& e) {
		std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
		std::cerr << "\x1B[31m" << "Finance could not be inserted." << "\033[0m\n";
		return false;
	}
	return true;
}

bool FinanceController::selectFinance(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Employee NATURAL JOIN Finance " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\" COLLATE NOCASE" : "") + ";";

	try {
		auto rowCount = DBManager::instance().executeSelectSalaryQuery(queryString.c_str());
		std::cout << "\x1B[32m" << rowCount << std::string{ " record" } + (rowCount > 1 ? "s" : "") + " found" << "\033[0m\n";
	}
	catch (const std::exception& e) {
		std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
		return false;
	}
	return true;
};

bool FinanceController::deleteFinanceByID(int ID) {
	auto deleteResult = EmployeeController::deleteEmployeeByID(ID);

	if (deleteResult) {
		std::cout << "\x1B[32m" << "Successfully deleted a Finance." << "\033[0m\n";
	}
	else {
		std::cerr << "\x1B[31m" << "Finance could not be deleted." << "\033[0m\n";
	}
	return deleteResult;
}

std::string FinanceController::getUpdateQueryCondition(Finance& obj) {
	std::string updateQueryCondition{ "" };

	if (obj.getAccountingTool() != "#") {
		updateQueryCondition = "accountingTool = \"" + obj.getAccountingTool() + "\""; 
	}

	return updateQueryCondition;
}

bool FinanceController::updateFinance(Finance& obj) {

	auto employeeResult = EmployeeController::updateEmployee(obj);

	if (!employeeResult) {
		std::cerr << "\x1B[31m" << "Finance could not be updated." << "\033[0m\n";
		return false;
	}

	auto updateQueryCondition = getUpdateQueryCondition(obj);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE Finance SET " + updateQueryCondition + " WHERE employeeID = " + std::to_string(obj.getEmployeeID()) + ";";

		try {
			DBManager::instance().executeQuery(queryString.c_str());
			std::cout << "\x1B[32m" << "Successfully updated a Finance." << "\033[0m\n";
		}
		catch (const std::exception& e) {
			std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
			std::cerr << "\x1B[31m" << "Finance could not be updated." << "\033[0m\n";
			return false;
		}
	}
	else {
		std::cout << "\x1B[32m" << "Successfully updated a Finance." << "\033[0m\n";
	}
	return true;
}