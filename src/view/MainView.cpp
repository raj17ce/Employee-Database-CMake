#include <iostream>
#include <string>
#include "View.h"

using EmployeeDB::View::MainView, EmployeeDB::View::DepartmentView, EmployeeDB::View::ManagerView, EmployeeDB::View::ExportView, EmployeeDB::View::TableView;
using EmployeeDB::View::EngineerView, EmployeeDB::View::FinanceView, EmployeeDB::View::HRView, EmployeeDB::View::QAView;

void MainView::mainMenuView() {
	auto isInvalidInput{ false };

	while (true) {
		printMainMenu();

		if (isInvalidInput) {
			std::cerr << "\x1B[33m" << "Wrong Input, Please enter an input in the range: [0-6]" << "\x1B[0m\n";
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
			
			if (userInput >= 0 && userInput <= 6) {
				mainMenuSelection(userInput);
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}
}

void MainView::printMainMenu() {
	system("cls");
	std::cout << "------------------------------------------"<< "\x1B[36m" <<"Welcome to Employee Database"<< "\x1B[0m" <<"-------------------------------------------------\n";
	std::cout << "0. Exit\n";
	std::cout << "1. Table Operations\n";
	std::cout << "2. Insert Data\n";
	std::cout << "3. Update Data\n";
	std::cout << "4. Delete Data\n";
	std::cout << "5. View Data\n";
	std::cout << "6. Export Data(csv)\n";
	std::cout << "\x1B[33m" << "Please select an operation to perform: " << "\x1B[0m\n";
}

void MainView::mainMenuSelection(short int userInput) {
	switch (userInput) {
		case 0:
			std::exit(0);
		case 1:
			tableMenuView();
			break;
		case 2:
			insertMenuView();
			break;
		case 3:
			updateMenuView();
			break;
		case 4:
			deleteMenuView();
			break;
		case 5:
			viewMenuView();
			break;
		case 6:
			exportMenuView();
			break;
	}
};

void MainView::tableMenuView() {
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\x1B[36m" << "Table Menu" << "\x1B[0m" << "-------------------------------------------------\n";
		std::cout << "0. Exit\n";
		std::cout << "1. Create Table\n";
		std::cout << "2. Delete Table\n";
		std::cout << "3. Main Menu\n";
		std::cout << "\x1B[33m" << "Please select an operation to perform: " << "\x1B[0m\n";

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
			if (userInput >= 0 && userInput <= 2) {
				tableMenuSelection(userInput);
			}
			else if (userInput == 3) {
				return;
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}
}

void MainView::tableMenuSelection(short int userInput) {
	auto continueOperation{ true };
	switch (userInput) {
	case 0:
		std::exit(0);
	case 1:
		while (continueOperation) {
			continueOperation = TableView::createTable();
		}
		break;
	case 2:
		while (continueOperation) {
			continueOperation = TableView::deleteTable();
		}
		break;
	}
}

void MainView::printTableMenu() {
	std::cout << "0. Exit\n";
	std::cout << "1. Department\n";
	std::cout << "2. Engineer\n";
	std::cout << "3. Finance\n";
	std::cout << "4. HR\n";
	std::cout << "5. QA\n";
	std::cout << "6. Manager\n";
	std::cout << "7. Main Menu\n";
}

void MainView::insertMenuView() {
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\x1B[36m" << "Insert Menu" << "\x1B[0m" << "-------------------------------------------------\n";
		printTableMenu();
		std::cout << "\x1B[33m" << "Please select an entity to insert: " << "\x1B[0m\n";

		if (isInvalidInput) {
			std::cerr << "\x1B[33m" << "Wrong Input, Please enter an input in the range: [0-7]" << "\x1B[0m\n";
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
			if (userInput >= 0 && userInput <= 6) {
				insertMenuSelection(userInput);
			}
			else if (userInput == 7) {
				return;
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}
}

void MainView::insertMenuSelection(short int userInput) {
	auto continueInsertion{ true };
	switch (userInput) {
		case 0:
			std::exit(0);
		case 1:
			while (continueInsertion) {
				continueInsertion = DepartmentView::insertDepartment();
			}
			break;
		case 2:
			while (continueInsertion) {
				continueInsertion = EngineerView::insertEngineer();
			}
			break;
		case 3:
			while (continueInsertion) {
				continueInsertion = FinanceView::insertFinance();
			}
			break;
		case 4:
			while (continueInsertion) {
				continueInsertion = HRView::insertHR();
			}
			break;
		case 5:
			while (continueInsertion) {
				continueInsertion = QAView::insertQA();
			}
			break;
		case 6:
			while (continueInsertion) {
				continueInsertion = ManagerView::insertManager();
			}
			break;
	}
}

void MainView::updateMenuView() {
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\x1B[36m" << "Update Menu" << "\x1B[0m" << "-------------------------------------------------\n";
		printTableMenu();
		std::cout << "\x1B[33m" << "Please select an entity to update: " << "\x1B[0m\n";

		if (isInvalidInput) {
			std::cerr << "\x1B[33m" << "Wrong Input, Please enter an input in the range: [0-7]" << "\x1B[0m\n";
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
			if (userInput >= 0 && userInput <= 6) {
				updateMenuSelection(userInput);
			}
			else if (userInput == 7) {
				return;
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}
}

void MainView::updateMenuSelection(short int userInput) {
	auto continueUpdation{ true };
	switch (userInput) {
	case 0:
		std::exit(0);
	case 1:
		while (continueUpdation) {
			continueUpdation = DepartmentView::updateDepartment();
		}
		break;
	case 2:
		while (continueUpdation) {
			continueUpdation = EngineerView::updateEngineer();
		}
		break;
	case 3:
		while (continueUpdation) {
			continueUpdation = FinanceView::updateFinance();
		}
		break;
	case 4:
		while (continueUpdation) {
			continueUpdation = HRView::updateHR();
		}
		break;
	case 5:
		while (continueUpdation) {
			continueUpdation = QAView::updateQA();
		}
		break;
	case 6:
		while (continueUpdation) {
			continueUpdation = ManagerView::updateManager();
		}
		break;
	}
}

void MainView::deleteMenuView() {
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\x1B[36m" << "Delete Menu" << "\x1B[0m" << "-------------------------------------------------\n";
		printTableMenu();
		std::cout << "\x1B[33m" << "Please select an entity to delete:" << "\x1B[0m\n";

		if (isInvalidInput) {
			std::cerr << "\x1B[33m" << "Wrong Input, Please enter an input in the range: [0-7]" << "\x1B[0m\n";
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
			if (userInput >= 0 && userInput <= 6) {
				deleteMenuSelection(userInput);
			}
			else if (userInput == 7) {
				return;
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}
}

void MainView::deleteMenuSelection(short int userInput) {
	auto continueDeletion{ true };
	switch (userInput) {
	case 0:
		std::exit(0);
	case 1:
		while (continueDeletion) {
			continueDeletion = DepartmentView::deleteDepartment();
		}
		break;
	case 2:
		while (continueDeletion) {
			continueDeletion = EngineerView::deleteEngineer();
		}
		break;
	case 3:
		while (continueDeletion) {
			continueDeletion = FinanceView::deleteFinance();
		}
		break;
	case 4:
		while (continueDeletion) {
			continueDeletion = HRView::deleteHR();
		}
		break;
	case 5:
		while (continueDeletion) {
			continueDeletion = QAView::deleteQA();
		}
		break;
	case 6:
		while (continueDeletion) {
			continueDeletion = ManagerView::deleteManager();
		}
		break;
	}
}

void MainView::viewMenuView() {
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\x1B[36m" << "View Menu" << "\x1B[0m" << "-------------------------------------------------\n";
		printTableMenu();
		std::cout << "\x1B[33m" << "Please select an entity to view:" << "\x1B[0m\n";

		if (isInvalidInput) {
			std::cerr << "\x1B[33m" << "Wrong Input, Please enter an input in the range: [0-7]" << "\x1B[0m\n";
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
			if (userInput >= 0 && userInput <= 6) {
				viewMenuSelection(userInput);
			}
			else if (userInput == 7) {
				return;
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}
}

void MainView::viewMenuSelection(short int userInput) {
	auto continueViewing{ true };
	switch (userInput) {
	case 0:
		std::exit(0);
	case 1:
		while (continueViewing) {
			continueViewing = DepartmentView::viewDepartment();
		}
		break;
	case 2:
		while (continueViewing) {
			continueViewing = EngineerView::viewEngineer();
		}
		break;
	case 3:
		while (continueViewing) {
			continueViewing = FinanceView::viewFinance();
		}
		break;
	case 4:
		while (continueViewing) {
			continueViewing = HRView::viewHR();
		}
		break;
	case 5:
		while (continueViewing) {
			continueViewing = QAView::viewQA();
		}
		break;
	case 6:
		while (continueViewing) {
			continueViewing = ManagerView::viewManager();
		}
		break;
	}
}

void MainView::printExportTableMenu() {
	std::cout << "0. Exit\n";
	std::cout << "1. Department\n";
	std::cout << "2. Engineer\n";
	std::cout << "3. Finance\n";
	std::cout << "4. HR\n";
	std::cout << "5. QA\n";
	std::cout << "6. Manager\n";
	std::cout << "7. Backup Database(Export All)\n";
	std::cout << "8. Main Menu\n";
}

void MainView::exportMenuView() {
	auto isInvalidInput{ false };

	while (true) {
		system("cls");
		std::cout << "------------------------------------------" << "\x1B[36m" << "Export Menu" << "\x1B[0m" << "-------------------------------------------------\n";
		printExportTableMenu();
		std::cout << "\x1B[33m" << "Please select an entity to export:" << "\x1B[0m\n";

		if (isInvalidInput) {
			std::cerr << "\x1B[33m" << "Wrong Input, Please enter an input in the range: [0-8]" << "\x1B[0m\n";
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
			if (userInput >= 0 && userInput <= 7) {
				if (!exportMenuSelection(userInput)) {
					return;
				};
			}
			else if (userInput == 8) {
				return;
			}
			else {
				isInvalidInput = true;
			}
		}
		catch (...) {
			isInvalidInput = true;
		}
	}
}

bool MainView::exportMenuSelection(short int userInput) {
	auto continueExporting{ true };
	switch (userInput) {
	case 0:
		std::exit(0);
	case 1:
		continueExporting = ExportView::exportToCSV("Department");
		break;
	case 2:
		continueExporting = ExportView::exportToCSV("Engineer");
		break;
	case 3:
		continueExporting = ExportView::exportToCSV("Finance");
		break;
	case 4:
		continueExporting = ExportView::exportToCSV("HR");
		break;
	case 5:
		continueExporting = ExportView::exportToCSV("QA");
		break;
	case 6:
		continueExporting = ExportView::exportToCSV("Manager");
		break;
	case 7:
		continueExporting = ExportView::exportAll();
		break;
	}

	return continueExporting;
}