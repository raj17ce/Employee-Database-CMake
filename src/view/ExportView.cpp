#include <iostream>
#include <string>
#include "filesystem"
#include "ExportView.h"
#include "Utility.h"
#include "ExportController.h"

using EmployeeDB::View::ExportView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::ExportController;

bool ExportView::exportToCSV(const std::string& entity) {
	Utility::clearScreen();
	std::cout << "------------------------------------------" << "\x1B[36m" << "Export "<< entity << "\x1B[0m" << "-------------------------------------------------\n";
	std::cout << "\x1B[33m" << "Enter filename for exporting " << entity << "Table(do not add .csv extension)\n" << "\x1B[0m\n";
	
	auto userInput = Utility::getUserInputString("filename").value();

	std::filesystem::path filename{userInput};

	ExportController::exportToCSV(entity, filename);

	return Utility::repeatOperation("Export", "Table");
}

bool ExportView::exportAll() {
	Utility::clearScreen();
	std::cout << "------------------------------------------" << "\x1B[36m" << "Backup Database (Export All) " << "\x1B[0m" << "-------------------------------------------------\n";
	std::cout << "\x1B[32m" << "Exporting All Tables...\n" << "\x1B[0m\n";

	ExportController::exportAll();

	return Utility::repeatOperation("Export", "Table");
}