#ifndef __ManagerController_H__
#define __ManagerController_H__

#include <iostream>
#include "Manager.h"

using EmployeeDB::Model::Manager;

namespace EmployeeDB::Controller {
	
	class ManagerController {
	public:
		static bool insertManager(Manager& obj);
		static bool selectManager(const std::string& attributeName = "", const std::string& attributeValue = "");
		static bool deleteManagerByID(int ID);
		static bool updateManager(Manager& obj);
		static bool checkManagerExistence(const std::string& managerID);
	protected:
		static std::string getUpdateQueryCondition(Manager& obj);
	};
}

#endif