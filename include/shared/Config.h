#ifndef __Config_H__
#define __Config_H__

#include <filesystem>

#ifndef PROJECT_BASE_DIR
	#define PROJECT_BASE_DIR "../.."
#endif

namespace EmployeeDB::Config {
	static std::filesystem::path ProjectBasePath{PROJECT_BASE_DIR};
	static std::filesystem::path DBFilePath{ProjectBasePath / "data/Employee.db"};
	static std::filesystem::path LogFilePath{ProjectBasePath / "data/EmployeeDB.log"};
	static std::filesystem::path CSVFilePath{ProjectBasePath / "data/csv/"};
}

#endif