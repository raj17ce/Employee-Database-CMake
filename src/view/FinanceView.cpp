#include "EmployeeView.h"
#include "FinanceView.h"
#include "Utility.h"
#include "FinanceController.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::FinanceView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::FinanceController;

bool FinanceView::insertFinance() {
	Finance obj;

	system("cls");
	std::cout << "------------------------------------------" << "\x1B[36m" << "Insert Finance" << "\x1B[0m" << "-------------------------------------------------\n";
	std::cout << "\x1B[36m" << "Fields with * are required fields" << "\x1B[0m\n";
	EmployeeView::printEmployeeFields();
	std::cout << "13. accountingTool* : " << '\n';

	if (!Utility::proceedFurther("insertion")) {
		return false;
	}

	EmployeeView::getInsertEmployeeInput(obj);

	{
		auto accountingTool = Utility::getUserInputString("accountingTool").value();
		obj.setAccountingTool(accountingTool);
	}

	FinanceController::insertFinance(obj);

	return Utility::repeatOperation("insert", "Finance");
}

bool FinanceView::updateFinance() {
	Finance obj{ true };
	auto isInvalidInput{ false };

	EmployeeView::getEmployeeIDInput(obj, "Update", "Finance");

	system("cls");
	std::cout << "------------------------------------------" << "\x1B[36m" << "Update Finance" << "\x1B[0m" << "-------------------------------------------------\n";
	FinanceController::selectFinance("Employee.employeeID", std::to_string(obj.getEmployeeID()));
	if (!Utility::proceedFurther("Update")) {
		return false;
	}

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\x1B[36m" << "Update Finance" << "\x1B[0m" << "-------------------------------------------------\n";
		std::cout << "\x1B[36m" << "Fields with * are required fields" << "\x1B[0m\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printEmployeeFields();
		std::cout << "13. accountingTool* : " << '\n';
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
					auto accountingTool = Utility::getUserInputString("accountingTool").value();
					obj.setAccountingTool(accountingTool);
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

	FinanceController::updateFinance(obj);

	return Utility::repeatOperation("update", "Finance");
}

bool FinanceView::deleteFinance() {
	Finance obj{ true };
	auto isInvalidInput{ false };

	EmployeeView::getEmployeeIDInput(obj, "Delete", "Finance");

	system("cls");
	std::cout << "------------------------------------------" << "\x1B[36m" << "Delete Finance" << "\x1B[0m" << "-------------------------------------------------\n";
	FinanceController::selectFinance("Employee.employeeID", std::to_string(obj.getEmployeeID()));
	if (!Utility::proceedFurther("Delete")) {
		return false;
	}

	FinanceController::deleteFinanceByID(obj.getEmployeeID());

	return Utility::repeatOperation("delete", "Finance");
}

bool FinanceView::viewFinanceConditional() {
	Finance obj;
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\x1B[36m" << "View Finance" << "\x1B[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		EmployeeView::printViewEmployeeFields();
		std::cout << "14. accountingTool* : " << '\n';
		std::cout << "15. Go Back" << '\n';
		std::cout << "\x1B[33m" << "Select the field by which you want to view the Finance, or select 0/15 for operations: " << "\x1B[0m\n";

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
				FinanceController::selectFinance("employeeID", std::to_string(obj.getEmployeeID()));
				break;
			}
			else if (userInput == 2) {
				EmployeeView::getViewEmployeeInput(obj, 2);
				FinanceController::selectFinance("firstName", obj.getFirstName());
				break;
			}
			else if (userInput == 3) {
				EmployeeView::getViewEmployeeInput(obj, 3);
				FinanceController::selectFinance("middleName", obj.getMiddleName().value());
				break;
			}
			else if (userInput == 4) {
				EmployeeView::getViewEmployeeInput(obj, 4);
				FinanceController::selectFinance("lastName", obj.getLastName());
				break;
			}
			else if (userInput == 5) {
				EmployeeView::getViewEmployeeInput(obj, 5);
				FinanceController::selectFinance("dateOfBirth", obj.getDateOfBirth().value());
				break;
			}
			else if (userInput == 6) {
				EmployeeView::getViewEmployeeInput(obj, 6);
				FinanceController::selectFinance("mobileNo", std::to_string(obj.getMobileNumber()));
				break;
			}
			else if (userInput == 7) {
				EmployeeView::getViewEmployeeInput(obj, 7);
				FinanceController::selectFinance("email", obj.getEmail());
				break;
			}
			else if (userInput == 8) {
				EmployeeView::getViewEmployeeInput(obj, 8);
				FinanceController::selectFinance("address", obj.getAddress());
				break;
			}
			else if (userInput == 9) {
				EmployeeView::getViewEmployeeInput(obj, 9);
				FinanceController::selectFinance("gender", EmployeeDB::Model::getGenderString(obj.getGender()));
				break;
			}
			else if (userInput == 10) {
				EmployeeView::getViewEmployeeInput(obj, 10);
				FinanceController::selectFinance("dateOfJoining", obj.getDateOfJoining());
				break;
			}
			else if (userInput == 11) {
				EmployeeView::getViewEmployeeInput(obj, 11);
				FinanceController::selectFinance("mentorID", std::to_string(obj.getMentorID().value()));
				break;
			}
			else if (userInput == 12) {
				EmployeeView::getViewEmployeeInput(obj, 12);
				FinanceController::selectFinance("performanceMetric", std::to_string(obj.getPerformanceMetric().value()));
				break;
			}
			else if (userInput == 13) {
				EmployeeView::getViewEmployeeInput(obj, 13);
				FinanceController::selectFinance("bonus", std::to_string(obj.getBonus().value()));
				break;
			}
			else if (userInput == 14) {
				{
					auto accountingTool = Utility::getUserInputString("accountingTool").value();
					obj.setAccountingTool(accountingTool);
				}
				FinanceController::selectFinance("accountingTool", obj.getAccountingTool());
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

bool FinanceView::viewFinance() {
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\x1B[36m" << "View Finance" << "\x1B[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit" << '\n';
		std::cout << "1. View Finance based on a field" << '\n';
		std::cout << "2. View all Finance" << '\n';
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
				if (!viewFinanceConditional()) {
					return true;
				}
				break;
			}
			else if (userInput == 2) {
				FinanceController::selectFinance();
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

	return Utility::repeatOperation("view", "Finance");
}