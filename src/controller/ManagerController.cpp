#include <exception>
#include "ManagerController.h"
#include "EmployeeController.h"
#include "DBManager.h"

using EmployeeDB::Controller::ManagerController, EmployeeDB::Controller::EmployeeController;

bool ManagerController::insertManager(Manager& obj) {

	auto departmentID = EmployeeController::getDepartmentIDbyEmployeeID(obj.getManagerID());

	if (departmentID == -1) {
		std::cerr << "\x1B[31m" << "Department was not found for provided managerID." << "\033[0m\n";
		return false;
	}

	obj.setDepartmentID(departmentID);

	std::string queryString = "INSERT INTO Manager (managerID, departmentID, teamSize, yearsOfExperience, projectTitle, role) VALUES (" +
		std::to_string(obj.getManagerID()) + ", " +
		std::to_string(obj.getDepartmentID()) + ", " +
		std::to_string(obj.getTeamSize()) + ", " +
		std::to_string(obj.getYearsOfExperience()) + ", " +
		(obj.getProjectTitle().has_value() ? "\"" + obj.getProjectTitle().value() + "\"" : "NULL") + "," +
		(obj.getRole().has_value() ? "\"" + obj.getRole().value() + "\"" : "NULL") + ");";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "\x1B[32m" << "Successfully inserted a Manager." << "\033[0m\n";
	}
	catch (std::exception& e) {
		std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
		std::cerr << "\x1B[31m" << "Manager could not be inserted." << "\033[0m\n";
		return false;
	}
	return true;
}

bool ManagerController::selectManager(const std::string& attributeName, const std::string& attributeValue) {
	std::string queryString = "SELECT * FROM ManagerView " + ((attributeName.size() != 0) ? "WHERE " + attributeName + " = \"" + attributeValue + "\" COLLATE NOCASE" : "") + ";";

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

bool ManagerController::deleteManagerByID(int ID) {
	std::string queryString = "DELETE FROM Manager WHERE managerID = " + std::to_string(ID) + ";";

	try {
		DBManager::instance().executeQuery(queryString.c_str());
		std::cout << "\x1B[32m" << "Successfully deleted a Manager." << "\033[0m\n";
	}
	catch (const std::exception& e) {
		std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
		std::cerr << "\x1B[31m" << "Manager could not be deleted." << "\033[0m\n";
		return false;
	}
	return true;
};

std::string ManagerController::getUpdateQueryCondition(Manager& obj) {
	std::string updateQueryCondition{ "" };

	if (obj.getTeamSize() != -1) {
		updateQueryCondition += "teamSize = " + std::to_string(obj.getTeamSize());
	}
	if (obj.getYearsOfExperience() != -1) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "yearsOfExperience = " + std::to_string(obj.getYearsOfExperience());
	}
	if (obj.getProjectTitle().has_value()) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "projectTitle = \"" + obj.getProjectTitle().value() + "\"";
	}
	if (obj.getRole().has_value()) {
		if (updateQueryCondition.size() != 0) {
			updateQueryCondition += ", ";
		}
		updateQueryCondition += "role = \"" + obj.getRole().value() + "\"";
	}

	return updateQueryCondition;
}

bool ManagerController::updateManager(Manager& obj) {
	auto employeeResult = EmployeeController::updateEmployee(obj);

	if (!employeeResult) {
		std::cerr << "\x1B[31m" << "Manager could not be updated." << "\033[0m\n";
		return false;
	}

	auto updateQueryCondition = getUpdateQueryCondition(obj);

	if (updateQueryCondition.size() != 0) {
		std::string queryString = "UPDATE Manager SET " + updateQueryCondition + " WHERE managerID = " + std::to_string(obj.getManagerID()) + ";";
		try {
			DBManager::instance().executeQuery(queryString.c_str());
			std::cout << "\x1B[32m" << "Successfully updated a Manager." << "\033[0m\n";
		}
		catch (const std::exception& e) {
			std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
			std::cerr << "\x1B[31m" << "Manager could not be updated." << "\033[0m\n";
			return false;
		}
	}
	else {
		std::cout << "\x1B[32m" << "Successfully updated a Manager." << "\033[0m\n";
	}
	return true;
}

bool ManagerController::checkManagerExistence(const std::string& managerID) {
	std::string queryString = "SELECT managerID FROM Manager WHERE managerID = " + managerID + ";";

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
