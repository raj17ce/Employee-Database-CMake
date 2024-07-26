#ifndef __EmployeeController_H__
#define __EmployeeController_H__

#include <iostream>
#include "Employee.h"
#include "Salary.h"

using EmployeeDB::Model::Employee, EmployeeDB::Model::Salary;

namespace EmployeeDB::Controller {

	class EmployeeController {
	public:
		static bool insertEmployee(const Employee& obj);
		static int getEmployeeIDbyEmail(const std::string& email);
		static int getDepartmentIDbyEmployeeID(int ID);
		static bool checkEmployeeExistence(const std::string& employeeID, const std::string& departmentName);
		static bool deleteEmployeeByID(int ID);
		static bool updateEmployee(Employee& obj);
		static bool getSalaryDetails(Salary& obj);
	protected:
		static std::string getUpdateQueryCondition(Employee& obj);
	};
}

#endif