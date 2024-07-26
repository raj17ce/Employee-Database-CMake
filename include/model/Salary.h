#ifndef __Salary_H__
#define __Salary_H__

namespace EmployeeDB::Model {

	class Salary {
	public:
        Salary() :
            m_EmployeeID{0},
            m_DepartmentID{0},
            m_PerformanceMetric{0.0},
            m_Bonus{0.0},
            m_BaseSalary{0.0},
            m_Allowance{0.0},
            m_Deduction{0.0} {}

        void setEmployeeID(int employeeID) {
            m_EmployeeID = employeeID;
        }
        void setDepartmentID(int departmentID) {
            m_DepartmentID = departmentID;
        }
        void setPerformanceMetric(double performanceMetric) {
            m_PerformanceMetric = performanceMetric;
        }
        void setBonus(double bonus) {
            m_Bonus = bonus;
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

        int getEmployeeID() const {
            return m_EmployeeID;
        }
        int getDepartmentID() const {
            return m_DepartmentID;
        }
        double getPerformanceMetric() const {
            return m_PerformanceMetric;
        }
        double getBonus() const {
            return m_Bonus;
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

        inline double computeSalary();
	private:
		int m_EmployeeID;
		int m_DepartmentID;
		double m_PerformanceMetric;
		double m_Bonus;
		double m_BaseSalary;
		double m_Allowance;
		double m_Deduction;
	};

    inline double Salary::computeSalary() {
        auto totalSalary{ 0.0 };

        totalSalary += m_BaseSalary;
        totalSalary += m_Allowance;
        totalSalary -= m_Deduction;
        totalSalary += m_Bonus;
        totalSalary += (m_BaseSalary * (m_PerformanceMetric / 100));

        return totalSalary;
    }
}

#endif