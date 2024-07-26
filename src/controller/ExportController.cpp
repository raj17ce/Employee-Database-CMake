#include "ExportController.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include "Config.h"
#include "DBManager.h"

using EmployeeDB::Controller::ExportController;
using EmployeeDB::DBManager;

void ExportController::removeCommas(std::string& str) {
    str.erase(std::remove_if(str.begin(), str.end(), [](char c) { return c == ','; }), str.end());
}

int ExportController::exportCallback(void* arg, int argc, char** argv, char** azColName) {
	auto& [titlesWritten, outStream] = *(static_cast<std::tuple<bool, std::ofstream>*>(arg));

    if (!titlesWritten) {
        for (int i = 0; i < argc; i++) {
            outStream << azColName[i];
            if (i < argc - 1) {
                outStream << ",";
            }
        }
        outStream << std::endl;
        titlesWritten = true;
    }

    for (int i = 0; i < argc; i++) {
        std::string value = (argv[i]? argv[i]:"NULL");
        removeCommas(value);
        outStream << value;
        if (i < argc - 1) {
            outStream << ",";
        }
    }
    outStream << std::endl;
    return 0;
}

bool ExportController::exportToCSV(const std::string& entity, std::filesystem::path filename) {
    std::string queryString = "SELECT * FROM " + entity + ";";

    filename += ".csv";
    std::filesystem::path filepath = EmployeeDB::Config::CSVFilePath / filename;

    std::ofstream outStream{filepath.string().c_str()};
    if (!outStream) {
        std::cerr << "\x1B[31m" << entity << " Could not be exported to " << filename << "\033[0m\n";
        return false;
    }

    std::tuple<bool, std::ofstream> tuple(false, std::move(outStream));

    try {
        DBManager::instance().executeCustomQuery(queryString.c_str(), exportCallback, &tuple);
        std::cout << "\x1B[32m" << "Successfully exported " << entity << " to " << "\033[0m";
        std::cout << "\x1B[36m" << filepath << "\033[0m\n";
    }
    catch (const std::exception& e) {
        std::cerr << "\x1B[31m" << e.what() << "\033[0m\n";
        std::cerr << "\x1B[31m" << entity << " Could not be exported to " << filename << "\033[0m\n";
        return false;
    }
    return true;
}

bool ExportController::exportAll() {
    auto resultVariable{ true };
    auto count{ 0 };

    resultVariable = exportToCSV("Department", "DepartmentBackup");
    if (resultVariable) {
        count++;
    }

    resultVariable = exportToCSV("Employee", "EmployeeBackup");
    if (resultVariable) {
        count++;
    }

    resultVariable = exportToCSV("Engineer", "EngineerBackup");
    if (resultVariable) {
        count++;
    }

    resultVariable = exportToCSV("Finance", "FinanceBackup");
    if (resultVariable) {
        count++;
    }

    resultVariable = exportToCSV("HR", "HRBackup");
    if (resultVariable) {
        count++;
    }

    resultVariable = exportToCSV("QA", "QABackup");
    if (resultVariable) {
        count++;
    }

    resultVariable = exportToCSV("Manager", "ManagerBackup");
    if (resultVariable) {
        count++;
    }

    std::cout << (count == 7 ? "\x1B[32m" : "\x1B[31m") << count << "\033[0m";
    std::cout << "\x1B[32m" << "/" << "\033[0m";
    std::cout << "\x1B[32m" << "7 " << "\033[0m";
    std::cout << "\x1B[32m" << "Files Exported." << "\033[0m\n";
    std::cout << "\x1B[33m" << "You can find all the exported csv files at : "<< "\033[0m";
    std::cout << "\x1B[36m" << EmployeeDB::Config::CSVFilePath << "\033[0m\n";

    return count;
}