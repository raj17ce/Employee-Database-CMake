#include <exception>
#include "DBManager.h"
#include "HRController.h"
#include "EmployeeController.h"
#include "DepartmentController.h"

using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Controller::HRController;
using EmployeeDB::Controller::DepartmentController;
using EmployeeDB::DBManager;

bool HRController::insertHR(HR& obj) {
	auto departmentID = DepartmentController::getDepartmentIDbyName("HR");

	if (departmentID == -1) {
		std::cerr << "\x1B[31m" << "HR department not found. Please insert a department named HR." << "\033[0m\n";
		return false;
	}

	obj.setDepartmentID(departmentID);

	auto employeeResult = EmployeeController::insertEmployee(obj);

	if (!employeeResult) {
		std::cerr << "\x1B[31m" << "HR could not be inserted." << "\033[0m\n";
		return false;
	}

	auto employeeID = EmployeeController::getEmployeeIDbyEmail(obj.getEmail());

	std::string queryString = "INSERT INTO HR (employeeID, hrSpecialization) VALUES (" +
		std::to_string(employeeID) + ", " +
		"\"" + obj.getHRSpecialization() + "\");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "\x1B[32m" << "Successfully inserted an HR." << "\033[0m\n";
	}
	catch (const std::exception& e) {
		std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
		std::cerr << "\x1B[31m" << "HR could not be inserted." << "\033[0m\n";
		return false;
	}
	return true;
}

bool HRController::selectHR(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM Employee NATURAL JOIN HR " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\" COLLATE NOCASE" : "") + ";";

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

bool HRController::deleteHRByID(int ID) {
	auto deleteResult = EmployeeController::deleteEmployeeByID(ID);

	if (deleteResult) {
		std::cout << "\x1B[32m" << "Successfully deleted an HR." << "\033[0m\n";
	}
	else {
		std::cerr << "\x1B[31m" << "HR could not be deleted." << "\033[0m\n";
	}
	return deleteResult;
}

std::string HRController::getUpdateQueryCondition(HR& obj) {
	std::string updateQueryCondition{ "" };

	if (obj.getHRSpecialization() != "#") {
		updateQueryCondition = "hrSpecialization = \"" + obj.getHRSpecialization() + "\"";
	}

	return updateQueryCondition;
}

bool HRController::updateHR(HR& obj) {

	auto employeeResult = EmployeeController::updateEmployee(obj);

	if (!employeeResult) {
		std::cerr << "\x1B[31m" << "HR could not be updated." << "\033[0m\n";
		return false;
	}

	auto updateQueryCondition = getUpdateQueryCondition(obj);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE HR SET " + updateQueryCondition + " WHERE employeeID = " + std::to_string(obj.getEmployeeID()) + ";";

		try {
			DBManager::instance().executeQuery(queryString.c_str());
			std::cout << "\x1B[32m" << "Successfully updated an HR." << "\033[0m\n";
		}
		catch (const std::exception& e) {
			std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
			std::cerr << "\x1B[31m" << "HR could not be updated." << "\033[0m\n";
			return false;
		}
	}
	else {
		std::cout << "\x1B[32m" << "Successfully updated an HR." << "\033[0m\n";
	}
	return true;
}