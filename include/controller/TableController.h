#ifndef __TableController_H__
#define __TableController_H__

#include <string>
#include <array>
#include <vector>
#include "Table.h"

using EmployeeDB::Model::Table;

namespace EmployeeDB::Controller {

	class TableController {
	public:
		static bool createTable(Table& obj);
		static bool deleteTable(const std::string& tableName);
	protected:
		static std::string getCreateTableQuery(Table& obj);
	};
}

#endif