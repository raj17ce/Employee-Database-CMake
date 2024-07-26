#ifndef __HR_H__
#define __HR_H__

#include "Employee.h"

namespace EmployeeDB::Model {
	class HR : public Employee {
	public:
		HR() : m_HRSpecialization{ "" } {}
		HR(bool isUpdateObj) : Employee{ isUpdateObj }, m_HRSpecialization{ "#" } {}

		void setHRSpecialization(const std::string& specialization) {
			m_HRSpecialization = specialization;
		}

		const std::string& getHRSpecialization() const {
			return m_HRSpecialization;
		}

	private:
		std::string m_HRSpecialization;
	};
}

#endif