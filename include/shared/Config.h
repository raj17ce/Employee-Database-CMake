#ifndef __Config_H__
#define __Config_H__

#include <filesystem>

namespace EmployeeDB::Config {
	static std::filesystem::path DBFilePath = "../../data/Employee.db";
	static std::filesystem::path LogFilePath = "../../data/EmployeeDB.log";
	static std::filesystem::path CSVFilePath = "../../data/csv/";
}

#endif