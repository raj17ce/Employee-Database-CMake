#ifndef __DepartmentView_H__
#define __DepartmentView_H__

#include "DepartmentController.h"

namespace EmployeeDB::View {

	class DepartmentView {
	public:
		static bool insertDepartment();
		static bool updateDepartment();
		static bool deleteDepartment();
		static bool viewDepartment();
	private:
		static void printDepartmentFields();
		static void printViewDepartmentFields();
		static void getInsertDepartmentInput(Department& obj);
		static void getUpdateDepartmentInput(Department& obj, int fieldNumber);
		static void getViewDepartmentInput(Department& obj, int fieldNumber);
		static bool getDepartmentIDInput(Department& obj, const std::string& operation);
		static bool viewDepartmentConditional();
	};
}

#endif