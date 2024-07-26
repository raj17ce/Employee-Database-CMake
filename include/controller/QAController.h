#ifndef __QAController_H__
#define __QAController_H__

#include <iostream>
#include "QA.h"

using EmployeeDB::Model::QA;

namespace EmployeeDB::Controller {

	class QAController {
	public:
		static bool insertQA(QA& obj);
		static bool selectQA(const std::string& attributeName = "", const std::string& attributeValue = "");
		static bool deleteQAByID(int ID);
		static bool updateQA(QA& obj);
	protected:
		static std::string getUpdateQueryCondition(QA& obj);
	};
}

#endif