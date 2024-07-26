#ifndef __HRController_H__
#define __HRController_H__

#include <iostream>
#include "HR.h"

using EmployeeDB::Model::HR;

namespace EmployeeDB::Controller {

	class HRController {
	public:
		static bool insertHR(HR& obj);
		static bool selectHR(const std::string& attributeName = "", const std::string& attributeValue = "");
		static bool deleteHRByID(int ID);
		static bool updateHR(HR& obj);
	protected:
		static std::string getUpdateQueryCondition(HR& obj);
	};
}

#endif