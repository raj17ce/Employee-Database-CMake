#ifndef __DepartmentController_H__
#define __DepartmentController_H__

#include <iostream>
#include "Department.h"

using EmployeeDB::Model::Department;

namespace EmployeeDB::Controller {

	class DepartmentController {
	public:
		static bool insertDepartment(const Department& obj);
		static int getDepartmentIDbyName(const std::string& departmentName);
		static bool checkDepartmentExistence(const std::string& departmentID);
		static bool selectDepartment(const std::string& attributeName = "", const std::string& attributeValue = "");
		static bool deleteDepartmentByID(int ID);
		static bool updateDepartment(Department& obj);
	protected:
		static std::string getUpdateQueryCondition(Department& obj);
	};
}

#endif