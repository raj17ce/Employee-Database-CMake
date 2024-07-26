#ifndef __ExportController_H__
#define __ExportController_H__

#include <iostream>
#include <filesystem>

namespace EmployeeDB::Controller {

	class ExportController {
	public:
		static bool exportToCSV(const std::string& entity, std::filesystem::path filename);
		static bool exportAll();
	protected:
		static int exportCallback(void* arg, int argc, char** argv, char** azColName);
		static void removeCommas(std::string& str);
	};
}

#endif