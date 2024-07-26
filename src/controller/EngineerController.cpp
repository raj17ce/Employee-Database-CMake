#include <exception>
#include "DBManager.h"
#include "EngineerController.h"
#include "EmployeeController.h"
#include "DepartmentController.h"

using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Controller::EngineerController;
using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool EngineerController::insertEngineer(Engineer& obj) {
	auto departmentID = DepartmentController::getDepartmentIDbyName("Engineer");

	if (departmentID == -1) {
		std::cerr << "\x1B[31m" << "Engineer department not found. Please insert a department named Engineer." << "\033[0m\n";
		return false;
	}

	obj.setDepartmentID(departmentID);

	auto employeeResult = EmployeeController::insertEmployee(obj);

	if (!employeeResult) {
		std::cerr << "\x1B[31m" << "Engineer could not be inserted." << "\033[0m\n";
		return false;
	}

	auto employeeID = EmployeeController::getEmployeeIDbyEmail(obj.getEmail());

	std::string queryString = "INSERT INTO Engineer (employeeID, technology) VALUES (" +
		std::to_string(employeeID) + ", " +
		"\"" + obj.getTechnology() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "\x1B[32m" << "Successfully inserted an Engineer." << "\033[0m\n";
	}
	catch (const std::exception& e) {
		std::cerr << "\x1B[31m" << e.what() << '\n';
		std::cerr << "\x1B[31m" << "Engineer could not be inserted." << "\033[0m\n";
		return false;
	}
	return true;
}

bool EngineerController::selectEngineer(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Employee NATURAL JOIN Engineer " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\" COLLATE NOCASE" : "") + ";";

	try {
		auto rowCount = DBManager::instance().executeSelectSalaryQuery(queryString.c_str());
		std::cout << "\x1B[32m" << rowCount << std::string{ " record" } + (rowCount > 1 ? "s" : "") + " found" << "\033[0m\n";
	}
	catch (const std::exception& e) {
		std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
		return false;
	}
	return true;
}

bool EngineerController::deleteEngineerByID(int ID) {
	auto deleteResult = EmployeeController::deleteEmployeeByID(ID);
	
	if (deleteResult) {
		std::cout << "\x1B[32m" << "Successfully deleted an Engineer." << "\033[0m\n";
	}
	else {
		std::cerr << "\x1B[31m" << "Engineer could not be deleted." << "\033[0m\n";
	}
	return deleteResult;
}

std::string EngineerController::getUpdateQueryCondition(Engineer& obj) {
	std::string updateQueryCondition{ "" };

	if (obj.getTechnology() != "#") {
		updateQueryCondition = "technology = \"" + obj.getTechnology() + "\"";
	}

	return updateQueryCondition;
}

bool EngineerController::updateEngineer(Engineer& obj) {
	
	auto employeeResult = EmployeeController::updateEmployee(obj);

	if (!employeeResult) {
		std::cerr << "\x1B[31m" << "Engineer could not be updated." << "\033[0m\n";
		return false;
	}

	auto updateQueryCondition = getUpdateQueryCondition(obj);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE Engineer SET " + updateQueryCondition + " WHERE employeeID = " + std::to_string(obj.getEmployeeID()) + ";";

		try {
			DBManager::instance().executeQuery(queryString.c_str());
			std::cout << "\x1B[32m" << "Successfully updated an Engineer." << "\033[0m\n";
		}
		catch (const std::exception& e) {
			std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
			std::cerr << "\x1B[31m" << "Engineer could not be updated." << "\033[0m\n";
			return false;
		}
	}
	else {
		std::cout << "\x1B[32m" << "Successfully updated an Engineer." << "\033[0m\n";
	}
	return true;
}