#ifndef __EmployeeView_H__
#define __EmployeeView_H__

#include "EmployeeController.h"

namespace EmployeeDB::View {

	class EmployeeView {
	public:
		static void printEmployeeFields();
		static void printViewEmployeeFields();
		static void getInsertEmployeeInput(Employee& obj);
		static void getUpdateEmployeeInput(Employee& obj, int fieldNumber);
		static void getViewEmployeeInput(Employee& obj, int fieldNumber);
		static void getEmployeeIDInput(Employee& obj, const std::string& operation, const std::string& entity);
	};
}

#endif