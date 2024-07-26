#include "EmployeeView.h"
#include "HRView.h"
#include "Utility.h"
#include "HRController.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::HRView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::HRController;

bool HRView::insertHR() {
	HR obj;

	Utility::clearScreen();
	std::cout << "------------------------------------------" << "\x1B[36m" << "Insert HR" << "\x1B[0m" << "-------------------------------------------------\n";
	std::cout << "\x1B[36m" << "Fields with * are required fields" << "\x1B[0m\n";
	EmployeeView::printEmployeeFields();
	std::cout << "13. hrSpecialization* : " << '\n';

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	EmployeeView::getInsertEmployeeInput(obj);

	{
		auto hrSpecialization = Utility::getUserInputString("hrSpecialization").value();
		obj.setHRSpecialization(hrSpecialization);
	}

	HRController::insertHR(obj);

	return Utility::repeatOperation("insert", "HR");
}

bool HRView::updateHR() {
	HR obj{ true };
	auto isInvalidInput{ false };

	EmployeeView::getEmployeeIDInput(obj, "Update", "HR");

	Utility::clearScreen();
	std::cout << "------------------------------------------" << "\x1B[36m" << "Update HR" << "\x1B[0m" << "-------------------------------------------------\n";
	HRController::selectHR("Employee.employeeID", std::to_string(obj.getEmployeeID()));
	if (!Utility::proceedFurther("Update")) {
		return false;
	}

	while (true) {
		Utility::clearScreen();
		std::cout << "------------------------------------------" << "\x1B[36m" << "Update HR" << "\x1B[0m" << "-------------------------------------------------\n";
		std::cout << "\x1B[36m" << "Fields with * are required fields" << "\x1B[0m\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printEmployeeFields();
		std::cout << "13. hrSpecialization* : " << '\n';
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
					auto hrSpecialization = Utility::getUserInputString("hrSpecialization").value();
					obj.setHRSpecialization(hrSpecialization);
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

	HRController::updateHR(obj);

	return Utility::repeatOperation("update", "HR");
}

bool HRView::deleteHR() {
	HR obj{ true };
	auto isInvalidInput{ false };

	EmployeeView::getEmployeeIDInput(obj, "Delete", "HR");

	Utility::clearScreen();
	std::cout << "------------------------------------------" << "\x1B[36m" << "Delete HR" << "\x1B[0m" << "-------------------------------------------------\n";
	HRController::selectHR("Employee.employeeID", std::to_string(obj.getEmployeeID()));
	if (!Utility::proceedFurther("Delete")) {
		return false;
	}

	HRController::deleteHRByID(obj.getEmployeeID());

	return Utility::repeatOperation("delete", "HR");
}

bool HRView::viewHRConditional() {
	HR obj;
	auto isInvalidInput{ false };

	while (true) {
		Utility::clearScreen();
		std::cout << "------------------------------------------" << "\x1B[36m" << "View HR" << "\x1B[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printViewEmployeeFields();
		std::cout << "14. hrSpecialization* : " << '\n';
		std::cout << "15. Go Back" << '\n';
		std::cout << "\x1B[33m" << "Select the field by which you want to view the HR, or select 0/15 for operations:" << "\x1B[0m\n";

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
				HRController::selectHR("employeeID", std::to_string(obj.getEmployeeID()));
				break;
			}
			else if (userInput == 2) {
				EmployeeView::getViewEmployeeInput(obj, 2);
				HRController::selectHR("firstName", obj.getFirstName());
				break;
			}
			else if (userInput == 3) {
				EmployeeView::getViewEmployeeInput(obj, 3);
				HRController::selectHR("middleName", obj.getMiddleName().value());
				break;
			}
			else if (userInput == 4) {
				EmployeeView::getViewEmployeeInput(obj, 4);
				HRController::selectHR("lastName", obj.getLastName());
				break;
			}
			else if (userInput == 5) {
				EmployeeView::getViewEmployeeInput(obj, 5);
				HRController::selectHR("dateOfBirth", obj.getDateOfBirth().value());
				break;
			}
			else if (userInput == 6) {
				EmployeeView::getViewEmployeeInput(obj, 6);
				HRController::selectHR("mobileNo", std::to_string(obj.getMobileNumber()));
				break;
			}
			else if (userInput == 7) {
				EmployeeView::getViewEmployeeInput(obj, 7);
				HRController::selectHR("email", obj.getEmail());
				break;
			}
			else if (userInput == 8) {
				EmployeeView::getViewEmployeeInput(obj, 8);
				HRController::selectHR("address", obj.getAddress());
				break;
			}
			else if (userInput == 9) {
				EmployeeView::getViewEmployeeInput(obj, 9);
				HRController::selectHR("gender", EmployeeDB::Model::getGenderString(obj.getGender()));
				break;
			}
			else if (userInput == 10) {
				EmployeeView::getViewEmployeeInput(obj, 10);
				HRController::selectHR("dateOfJoining", obj.getDateOfJoining());
				break;
			}
			else if (userInput == 11) {
				EmployeeView::getViewEmployeeInput(obj, 11);
				HRController::selectHR("mentorID", std::to_string(obj.getMentorID().value()));
				break;
			}
			else if (userInput == 12) {
				EmployeeView::getViewEmployeeInput(obj, 12);
				HRController::selectHR("performanceMetric", std::to_string(obj.getPerformanceMetric().value()));
				break;
			}
			else if (userInput == 13) {
				EmployeeView::getViewEmployeeInput(obj, 13);
				HRController::selectHR("bonus", std::to_string(obj.getBonus().value()));
				break;
			}
			else if (userInput == 14) {
				{
					auto hrSpecialization = Utility::getUserInputString("hrSpecialization").value();
					obj.setHRSpecialization(hrSpecialization);
				}
				HRController::selectHR("hrSpecialization", obj.getHRSpecialization());
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

bool HRView::viewHR() {
	auto isInvalidInput{ false };

	while (true) {
		Utility::clearScreen();
		std::cout << "------------------------------------------" << "\x1B[36m" << "View HR" << "\x1B[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		std::cout << "1. View HR based on a field" << '\n';
		std::cout << "2. View all HR" << '\n';
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
				if (!viewHRConditional()) {
					return true;
				}
				break;
			}
			else if (userInput == 2) {
				HRController::selectHR();
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

	return Utility::repeatOperation("view", "HR");
}