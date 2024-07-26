#ifndef __Finance_H__
#define __Finance_H__

#include "Employee.h"

namespace EmployeeDB::Model {
	class Finance : public Employee {
	public:
		Finance() : m_AccountingTool{ "" } {}
		Finance(bool isUpdateObj) : Employee{ isUpdateObj }, m_AccountingTool{ "#" } {}

		void setAccountingTool(const std::string& accountingTool) {
			m_AccountingTool = accountingTool;
		}

		const std::string& getAccountingTool() const {
			return m_AccountingTool;
		}

	private:
		std::string m_AccountingTool;
	};
}

#endif