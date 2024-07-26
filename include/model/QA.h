#ifndef __QA_H__
#define __QA_H__

#include "Employee.h"

namespace EmployeeDB::Model {
	class QA : public Employee {
	public:
		QA() : m_TestingTool{ "" } {}
		QA(bool isUpdateObj) : Employee{ isUpdateObj }, m_TestingTool{ "#" } {}

		void setTestingTool(const std::string& testingTool) {
			m_TestingTool = testingTool;
		}

		const std::string& getTestingTool() const {
			return m_TestingTool;
		}

	private:
		std::string m_TestingTool;
	};
}

#endif