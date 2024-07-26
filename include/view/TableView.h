#ifndef __TableView_H__
#define __TableView_H__

#include "TableController.h"

namespace EmployeeDB::View {

	class TableView {
	public:
		static bool createTable();
		static bool deleteTable();
	private:
		static void getAttributesInput(Table& obj);
		static void getForeignKeysInput(Table& obj);
	};
}

#endif