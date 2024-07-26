#ifndef __FinanceController_H__
#define __FinanceController_H__

#include <iostream>
#include "Finance.h"

using EmployeeDB::Model::Finance;

namespace EmployeeDB::Controller {

	class FinanceController {
	public:
		static bool insertFinance(Finance& obj);
		static bool selectFinance(const std::string& attributeName = "", const std::string& attributeValue = "");
		static bool deleteFinanceByID(int ID);
		static bool updateFinance(Finance& obj);
	protected:
		static std::string getUpdateQueryCondition(Finance& obj);
	};
}

#endif