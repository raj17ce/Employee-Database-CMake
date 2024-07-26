#include <iostream>
#include "ManagerView.h"
#include "EmployeeView.h"
#include "Utility.h"
#include "ManagerController.h"
#include "Validate.h"

using EmployeeDB::View::ManagerView, EmployeeDB::View::EmployeeView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::ManagerController;
using EmployeeDB::Validate;

void ManagerView::printManagerFields() {
	std::cout << "1. managerID* (employeeID) : " << '\n';
	std::cout << "2. teamSize* : " << '\n';
	std::cout << "3. yearsOfExperience* : " << '\n';
	std::cout << "4. projectTitle : " << '\n';
	std::cout << "5. role : " << '\n';
}

void ManagerView::getInsertManagerInput(Manager& obj) {

	{
		auto managerID = Utility::getUserInputInt("managerID", Validate::validateEmployeeID, "*").value();
		obj.setManagerID(managerID);
	}

	{
		auto teamSize = Utility::getUserInputInt("teamSize").value();
		obj.setTeamSize(teamSize);
	}

	{
		auto yearsOfExperience = Utility::getUserInputDouble("yearsOfExperience").value();
		obj.setYearsOfExperience(yearsOfExperience);
	}

	{
		auto projectTitle = Utility::getUserInputString("projectTitle", 0, false);
		if (projectTitle.has_value()) {
			obj.setProjectTitle(projectTitle.value());
		}
	}

	{
		auto role = Utility::getUserInputString("role", 0, false);
		if (role.has_value()) {
			obj.setRole(role.value());
		}
	}
};

bool ManagerView::insertManager() {
	Manager obj;

	system("cls");
	std::cout << "------------------------------------------" << "\x1B[36m" << "Insert Manager" << "\x1B[0m" << "-------------------------------------------------\n";
	std::cout << "\x1B[36m" << "Fields with * are required fields" << "\x1B[0m\n";
	printManagerFields();

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	getInsertManagerInput(obj);
	ManagerController::insertManager(obj);

	return Utility::repeatOperation("insert", "Manager");
}

void ManagerView::printUpdateManagerFields() {
	std::cout << "13. teamSize* : " << '\n';
	std::cout << "14. yearsOfExperience* : " << '\n';
	std::cout << "15. projectTitle : " << '\n';
	std::cout << "16. role : " << '\n';
}

void ManagerView::printViewManagerFields() {
	std::cout << "14. teamSize* : " << '\n';
	std::cout << "15. yearsOfExperience* : " << '\n';
	std::cout << "16. projectTitle* : " << '\n';
	std::cout << "17. role* : " << '\n';
}

void ManagerView::getUpdateManagerInput(Manager& obj, int fieldNumber) {

	switch (fieldNumber) {
	case 13:
	{
		auto teamSize = Utility::getUserInputInt("teamSize").value();
		obj.setTeamSize(teamSize);
	}
	break;
	case 14:
	{
		auto yearsOfExperience = Utility::getUserInputDouble("yearsOfExperience").value();
		obj.setYearsOfExperience(yearsOfExperience);
	}
	break;
	case 15:
	{
		auto projectTitle = Utility::getUserInputString("projectTitle", 0, false);
		if (projectTitle.has_value()) {
			obj.setProjectTitle(projectTitle.value());
		}
	}
	break;
	case 16:
	{
		auto role = Utility::getUserInputString("role", 0, false);
		if (role.has_value()) {
			obj.setRole(role.value());
		}
	}
	break;
	}
}

void ManagerView::getViewManagerInput(Manager& obj, int fieldNumber) {

	switch (fieldNumber) {
	case 14:
	{
		auto teamSize = Utility::getUserInputInt("teamSize").value();
		obj.setTeamSize(teamSize);
	}
	break;
	case 15:
	{
		auto yearsOfExperience = Utility::getUserInputDouble("yearsOfExperience").value();
		obj.setYearsOfExperience(yearsOfExperience);
	}
	break;
	case 16:
	{
		auto projectTitle = Utility::getUserInputString("projectTitle").value();
		obj.setProjectTitle(projectTitle);
	}
	break;
	case 17:
	{
		auto role = Utility::getUserInputString("role").value();
		obj.setRole(role);
	}
	break;
	}
}

bool ManagerView::getManagerIDInput(Manager& obj, const std::string& operation) {

	system("cls");
	std::cout << "------------------------------------------" << "\x1B[36m" << operation <<" Manager" << "\x1B[0m" << "-------------------------------------------------\n";
	std::cout << "\x1B[33m" << "To "+ operation +" a Manager, please enter managerID." << "\x1B[0m\n";

	{
		auto managerID = Utility::getUserInputInt("managerID", Validate::validateManagerID).value();
		obj.setManagerID(managerID);
		obj.setEmployeeID(managerID);
	}

	system("cls");
	std::cout << "------------------------------------------" << "\x1B[36m" << operation << " Manager" << "\x1B[0m" << "-------------------------------------------------\n";
	ManagerController::selectManager("employeeID", std::to_string(obj.getEmployeeID()));

	if (operation == "Delete") {
		std::cout << "\x1B[31m" << "Note : Deleting manager will not affect the corresponding Employee entry." << "\x1B[0m\n";
	}
	return Utility::proceedFurther(operation);
}

bool ManagerView::updateManager() {
	Manager obj{ true };
	auto isInvalidInput{ false };

	if (!getManagerIDInput(obj, "Update")) {
		return false;
	}

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\x1B[36m" << "Update Manager" << "\x1B[0m" << "-------------------------------------------------\n";
		std::cout << "\x1B[36m" << "Fields with * are required fields" << "\x1B[0m\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printEmployeeFields();
		printUpdateManagerFields();
		std::cout << "17. Go Back" << '\n';
		std::cout << "\x1B[33m" << "Select the field you want to update, or select 0/17 for operations: " << "\x1B[0m\n";

		if (isInvalidInput) {
			std::cerr << "\x1B[33m" << "Wrong Input, Please enter an input in the range: [0-17]" << "\x1B[0m\n";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);
		Utility::removeEmptySpaces(inputLine);

		if (inputLine.length() == 0) {
			isInvalidInput = true;
			continue;
		}
		try {
			userInput = stoi(inputLine);
			if (userInput == 0) {
				std::exit(0);
			}
			else if (userInput >= 1 && userInput <= 12) {
				EmployeeView::getUpdateEmployeeInput(obj, userInput);
				if (Utility::repeatOperation("update", "field")) {
					continue;
				}
				else {
					break;
				}
			}
			else if (userInput >= 13 && userInput <= 16) {
				getUpdateManagerInput(obj, userInput);
				if (Utility::repeatOperation("update", "field")) {
					continue;
				}
				else {
					break;
				}
			}
			else if (userInput == 17) {
				return false;
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}

	ManagerController::updateManager(obj);

	return Utility::repeatOperation("update", "Manager");
}

bool ManagerView::deleteManager() {
	Manager obj{ true };
	auto isInvalidInput{ false };

	if (!getManagerIDInput(obj, "Delete")) {
		return false;
	}

	ManagerController::deleteManagerByID(obj.getManagerID());

	return Utility::repeatOperation("delete", "Manager");
}

bool ManagerView::viewManagerConditional() {
	Manager obj;
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\x1B[36m" << "View Manager" << "\x1B[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printViewEmployeeFields();
		printViewManagerFields();
		std::cout << "18. Go Back" << '\n';
		std::cout << "\x1B[33m" << "Select the field by which you want to view the Manager, or select 0/18 for operations: " << "\x1B[0m\n";

		if (isInvalidInput) {
			std::cerr << "\x1B[33m" << "Wrong Input, Please enter an input in the range: [0-18]" << "\x1B[0m\n";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);
		Utility::removeEmptySpaces(inputLine);

		if (inputLine.length() == 0) {
			isInvalidInput = true;
			continue;
		}
		try {
			userInput = stoi(inputLine);
			if (userInput == 0) {
				std::exit(0);
			}
			else if (userInput == 1) {
				EmployeeView::getViewEmployeeInput(obj, 1);
				ManagerController::selectManager("employeeID", std::to_string(obj.getEmployeeID()));
				break;
			}
			else if (userInput == 2) {
				EmployeeView::getViewEmployeeInput(obj, 2);
				ManagerController::selectManager("firstName", obj.getFirstName());
				break;
			}
			else if (userInput == 3) {
				EmployeeView::getViewEmployeeInput(obj, 3);
				ManagerController::selectManager("middleName", obj.getMiddleName().value());
				break;
			}
			else if (userInput == 4) {
				EmployeeView::getViewEmployeeInput(obj, 4);
				ManagerController::selectManager("lastName", obj.getLastName());
				break;
			}
			else if (userInput == 5) {
				EmployeeView::getViewEmployeeInput(obj, 5);
				ManagerController::selectManager("dateOfBirth", obj.getDateOfBirth().value());
				break;
			}
			else if (userInput == 6) {
				EmployeeView::getViewEmployeeInput(obj, 6);
				ManagerController::selectManager("mobileNo", std::to_string(obj.getMobileNumber()));
				break;
			}
			else if (userInput == 7) {
				EmployeeView::getViewEmployeeInput(obj, 7);
				ManagerController::selectManager("email", obj.getEmail());
				break;
			}
			else if (userInput == 8) {
				EmployeeView::getViewEmployeeInput(obj, 8);
				ManagerController::selectManager("address", obj.getAddress());
				break;
			}
			else if (userInput == 9) {
				EmployeeView::getViewEmployeeInput(obj, 9);
				ManagerController::selectManager("gender", EmployeeDB::Model::getGenderString(obj.getGender()));
				break;
			}
			else if (userInput == 10) {
				EmployeeView::getViewEmployeeInput(obj, 10);
				ManagerController::selectManager("dateOfJoining", obj.getDateOfJoining());
				break;
			}
			else if (userInput == 11) {
				EmployeeView::getViewEmployeeInput(obj, 11);
				ManagerController::selectManager("mentorID", std::to_string(obj.getMentorID().value()));
				break;
			}
			else if (userInput == 12) {
				EmployeeView::getViewEmployeeInput(obj, 12);
				ManagerController::selectManager("performanceMetric", std::to_string(obj.getPerformanceMetric().value()));
				break;
			}
			else if (userInput == 13) {
				EmployeeView::getViewEmployeeInput(obj, 13);
				ManagerController::selectManager("bonus", std::to_string(obj.getBonus().value()));
				break;
			}
			else if (userInput == 14) {
				getViewManagerInput(obj, 14);
				ManagerController::selectManager("teamSize", std::to_string(obj.getTeamSize()));
				break;
			}
			else if (userInput == 15) {
				getViewManagerInput(obj, 15);
				ManagerController::selectManager("yearsOfExperience", std::to_string(obj.getYearsOfExperience()));
				break;
			}
			else if (userInput == 16) {
				getViewManagerInput(obj, 16);
				ManagerController::selectManager("projectTitle", obj.getProjectTitle().value());
				break;
			}
			else if (userInput == 17) {
				getViewManagerInput(obj, 17);
				ManagerController::selectManager("role", obj.getRole().value());
				break;
			}
			else if (userInput == 18) {
				return false;
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}
	return true;
}

bool ManagerView::viewManager() {
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\x1B[36m" << "View Manager" << "\x1B[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		std::cout << "1. View Manager based on a field" << '\n';
		std::cout << "2. View all Manager" << '\n';
		std::cout << "3. Go Back" << '\n';
		std::cout << "\x1B[33m" << "Select the operation [0-3]: " << "\x1B[0m\n";

		if (isInvalidInput) {
			std::cerr << "\x1B[33m" << "Wrong Input, Please enter an input in the range: [0-3]" << "\x1B[0m\n";
			isInvalidInput = false;
		}

		int userInput;
		std::string inputLine;
		std::getline(std::cin, inputLine);
		Utility::removeEmptySpaces(inputLine);

		if (inputLine.length() == 0) {
			isInvalidInput = true;
			continue;
		}
		try {
			userInput = stoi(inputLine);
			if (userInput == 0) {
				std::exit(0);
			}
			else if (userInput == 1) {
				if (!viewManagerConditional()) {
					return true;
				}
				break;
			}
			else if (userInput == 2) {
				ManagerController::selectManager();
				break;
			}
			else if (userInput == 3) {
				return false;
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}

	return Utility::repeatOperation("view", "Manager");
}