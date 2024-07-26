#ifndef __Engineer_H__
#define __Engineer_H__

#include "Employee.h"

namespace EmployeeDB::Model {

	class Engineer : public Employee {
	public:
		Engineer() : m_Technology{ "" } {}
		Engineer(bool isUpdateObj) : Employee{isUpdateObj}, m_Technology{"#"} {}

		void setTechnology(const std::string& technology) {
			m_Technology = technology;
		}

		const std::string& getTechnology() const {
			return m_Technology;
		}
	private:
		std::string m_Technology;
	};
}

#endif