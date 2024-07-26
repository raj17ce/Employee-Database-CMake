#ifndef __ManagerView_H__
#define __ManagerView_H__

#include "ManagerController.h"

namespace EmployeeDB::View {

	class ManagerView {
	public:
		static bool insertManager();
		static bool updateManager();
		static bool deleteManager();
		static bool viewManager();
	private:
		static void printManagerFields();
		static void getInsertManagerInput(Manager& obj);
		static void printUpdateManagerFields();
		static void printViewManagerFields();
		static void getUpdateManagerInput(Manager& obj, int fieldNumber);
		static void getViewManagerInput(Manager& obj, int fieldNumber);
		static bool viewManagerConditional();
		static bool getManagerIDInput(Manager& obj, const std::string& operation);
	};
}

#endif