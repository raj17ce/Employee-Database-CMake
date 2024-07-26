#include "EmployeeView.h"
#include "EngineerView.h"
#include "Utility.h"
#include "EngineerController.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::EngineerView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::EngineerController;

bool EngineerView::insertEngineer() {
	Engineer obj;

	Utility::clearScreen();
	std::cout << "------------------------------------------" << "\x1B[36m" << "Insert Engineer" << "\x1B[0m" << "-------------------------------------------------\n";
	std::cout << "\x1B[36m" << "Fields with * are required fields" << "\x1B[0m\n";
	EmployeeView::printEmployeeFields();
	std::cout << "13. technology* : " << '\n';

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	EmployeeView::getInsertEmployeeInput(obj);

	{
		auto technology = Utility::getUserInputString("technology").value();
		obj.setTechnology(technology);
	}

	EngineerController::insertEngineer(obj);

	return Utility::repeatOperation("insert", "Engineer");
}

bool EngineerView::updateEngineer() {
	Engineer obj{ true };
	auto isInvalidInput{ false };

	EmployeeView::getEmployeeIDInput(obj, "Update", "Engineer");

	Utility::clearScreen();
	std::cout << "------------------------------------------" << "\x1B[36m" << "Update Engineer" << "\x1B[0m" << "-------------------------------------------------\n";
	EngineerController::selectEngineer("Employee.employeeID", std::to_string(obj.getEmployeeID()));
	if (!Utility::proceedFurther("Update")) {
		return false;
	}

	while (true) {
		Utility::clearScreen();
		std::cout << "------------------------------------------" << "\x1B[36m" << "Update Engineer" << "\x1B[0m" << "-------------------------------------------------\n";
		std::cout << "\x1B[36m" << "Fields with * are required fields" << "\x1B[0m\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printEmployeeFields();
		std::cout << "13. technology* : " << '\n';
		std::cout << "14. Go Back" << '\n';
		std::cout << "\x1B[33m" << "Select the field you want to update, or select 0/14 for operations: " << "\x1B[0m\n";

		if (isInvalidInput) {
			std::cerr << "\x1B[33m" << "Wrong Input, Please enter an input in the range: [0-14]" << "\x1B[0m\n";
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
			else if (userInput == 13) {
				{
					auto technology = Utility::getUserInputString("technology").value();
					obj.setTechnology(technology);
				}
				if (Utility::repeatOperation("update", "field")) {
					continue;
				}
				else {
					break;
				}
			}
			else if (userInput == 14) {
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

	EngineerController::updateEngineer(obj);

	return Utility::repeatOperation("update", "Engineer");
}

bool EngineerView::deleteEngineer() {
	Engineer obj{ true };
	auto isInvalidInput{ false };

	EmployeeView::getEmployeeIDInput(obj, "Delete", "Engineer");

	Utility::clearScreen();
	std::cout << "------------------------------------------" << "\x1B[36m" << "Delete Engineer" << "\x1B[0m" << "-------------------------------------------------\n";
	EngineerController::selectEngineer("Employee.employeeID", std::to_string(obj.getEmployeeID()));
	if (!Utility::proceedFurther("Delete")) {
		return false;
	}

	EngineerController::deleteEngineerByID(obj.getEmployeeID());

	return Utility::repeatOperation("delete", "Engineer");
}

bool EngineerView::viewEngineerConditional() {
	Engineer obj;
	auto isInvalidInput{ false };

	while (true) {
		Utility::clearScreen();
		std::cout << "------------------------------------------" << "\x1B[36m" << "View Engineer" << "\x1B[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printViewEmployeeFields();
		std::cout << "14. technology* : " << '\n';
		std::cout << "15. Go Back" << '\n';
		std::cout << "\x1B[33m" << "Select the field by which you want to view the Engineer, or select 0/15 for operations: " << "\x1B[0m\n";

		if (isInvalidInput) {
			std::cerr << "\x1B[33m" << "Wrong Input, Please enter an input in the range: [0-15]" << "\x1B[0m\n";
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
				EngineerController::selectEngineer("employeeID", std::to_string(obj.getEmployeeID()));
				break;
			}
			else if (userInput == 2) {
				EmployeeView::getViewEmployeeInput(obj, 2);
				EngineerController::selectEngineer("firstName", obj.getFirstName());
				break;
			}
			else if (userInput == 3) {
				EmployeeView::getViewEmployeeInput(obj, 3);
				EngineerController::selectEngineer("middleName", obj.getMiddleName().value());
				break;
			}
			else if (userInput == 4) {
				EmployeeView::getViewEmployeeInput(obj, 4);
				EngineerController::selectEngineer("lastName", obj.getLastName());
				break;
			}
			else if (userInput == 5) {
				EmployeeView::getViewEmployeeInput(obj, 5);
				EngineerController::selectEngineer("dateOfBirth", obj.getDateOfBirth().value());
				break;
			}
			else if (userInput == 6) {
				EmployeeView::getViewEmployeeInput(obj, 6);
				EngineerController::selectEngineer("mobileNo", std::to_string(obj.getMobileNumber()));
				break;
			}
			else if (userInput == 7) {
				EmployeeView::getViewEmployeeInput(obj, 7);
				EngineerController::selectEngineer("email", obj.getEmail());
				break;
			}
			else if (userInput == 8) {
				EmployeeView::getViewEmployeeInput(obj, 8);
				EngineerController::selectEngineer("address", obj.getAddress());
				break;
			}
			else if (userInput == 9) {
				EmployeeView::getViewEmployeeInput(obj, 9);
				EngineerController::selectEngineer("gender", EmployeeDB::Model::getGenderString(obj.getGender()));
				break;
			}
			else if (userInput == 10) {
				EmployeeView::getViewEmployeeInput(obj, 10);
				EngineerController::selectEngineer("dateOfJoining", obj.getDateOfJoining());
				break;
			}
			else if (userInput == 11) {
				EmployeeView::getViewEmployeeInput(obj, 11);
				EngineerController::selectEngineer("mentorID", std::to_string(obj.getMentorID().value()));
				break;
			}
			else if (userInput == 12) {
				EmployeeView::getViewEmployeeInput(obj, 12);
				EngineerController::selectEngineer("performanceMetric", std::to_string(obj.getPerformanceMetric().value()));
				break;
			}
			else if (userInput == 13) {
				EmployeeView::getViewEmployeeInput(obj, 13);
				EngineerController::selectEngineer("bonus", std::to_string(obj.getBonus().value()));
				break;
			}
			else if (userInput == 14) {
				{
					auto technology = Utility::getUserInputString("technology").value();
					obj.setTechnology(technology);
				}
				EngineerController::selectEngineer("technology", obj.getTechnology());
				break;
			}
			else if (userInput == 15) {
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

bool EngineerView::viewEngineer() {
	auto isInvalidInput{ false };

	while (true) {
		Utility::clearScreen();
		std::cout << "------------------------------------------" << "\x1B[36m" << "View Engineer" << "\x1B[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		std::cout << "1. View Engineer based on a field" << '\n';
		std::cout << "2. View all Engineer" << '\n';
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
				if (!viewEngineerConditional()) {
					return true;
				}
				break;
			}
			else if (userInput == 2) {
				EngineerController::selectEngineer();
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

	return Utility::repeatOperation("view", "Engineer");
}