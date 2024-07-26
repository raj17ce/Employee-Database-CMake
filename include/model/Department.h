#ifndef __Department_H__
#define __Department_H__

#include <string>

namespace EmployeeDB::Model {
	class Department {
	public:
        Department() : 
            m_DepartmentName{ "" },
            m_DepartmentID{ 0 },
            m_BaseSalary{ 0.0 },
            m_Allowance{ 0.0 },
            m_Deduction{ 0.0 } {
        }

        Department(bool isUpdateObj) :
            m_DepartmentName{ "#" },
            m_DepartmentID{ -1 },
            m_BaseSalary{ -1.0 },
            m_Allowance{ -1.0 },
            m_Deduction{ -1.0 } {
        }

        void setDepartmentName(const std::string& name) {
            m_DepartmentName = name;
        }
        void setDepartmentID(int departmentID) {
            m_DepartmentID = departmentID;
        }
        void setBaseSalary(double baseSalary) {
            m_BaseSalary = baseSalary;
        }
        void setAllowance(double allowance) {
            m_Allowance = allowance;
        }
        void setDeduction(double deduction) {
            m_Deduction = deduction;
        }

        const std::string& getDepartmentName() const {
            return m_DepartmentName;
        }
        int getDepartmentID() const {
            return m_DepartmentID;
        }
        double getBaseSalary() const {
            return m_BaseSalary;
        }
        double getAllowance() const {
            return m_Allowance;
        }
        double getDeduction() const {
            return m_Deduction;
        }
	private:
        std::string m_DepartmentName;
		int m_DepartmentID;
		double m_BaseSalary;
        double m_Allowance;
        double m_Deduction;
	};
}

#endif