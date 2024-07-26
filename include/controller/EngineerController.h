#ifndef __EngineerController_H__
#define __EngineerController_H__

#include <iostream>
#include "Engineer.h"

using EmployeeDB::Model::Engineer;

namespace EmployeeDB::Controller {

	class EngineerController {
	public:
		static bool insertEngineer(Engineer& obj);
		static bool selectEngineer(const std::string& attributeName="", const std::string& attributeValue="");
		static bool deleteEngineerByID(int ID);
		static bool updateEngineer(Engineer& obj);
	protected:
		static std::string getUpdateQueryCondition(Engineer& obj);
	};
}

#endif