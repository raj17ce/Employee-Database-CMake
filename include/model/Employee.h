#ifndef __Employee_H__
#define __Employee_H__

#include <string>
#include <algorithm>
#include <optional>
#include "Salary.h"

namespace EmployeeDB::Model {

	enum class Gender {
		Male,
		Female,
		Other,
        Default
	};

    class Name {
    public:
        Name() : m_FirstName{""}, m_MiddleName{std::nullopt}, m_LastName{""} {}
        Name(bool isUpdateObj) : m_FirstName{ "#" }, m_MiddleName{ std::nullopt }, m_LastName{ "#" } {}

        void setFirstName(const std::string& firstName) {
            m_FirstName = firstName;
        }
        void setMiddleName(const std::optional<std::string>& middleName) {
            m_MiddleName = middleName;
        }
        void setLastName(const std::string& lastName) {
            m_LastName = lastName;
        }

        const std::string& getFirstName() const {
            return m_FirstName;
        }
        const std::optional<std::string>& getMiddleName() const {
            return m_MiddleName;
        }
        const std::string& getLastName() const {
            return m_LastName;
        }
    private:
        std::string m_FirstName;
        std::optional<std::string> m_MiddleName;
        std::string m_LastName;
    };

	class Employee {
	public:
        Employee() :
            name{},
            m_Email{""},
            m_Address{""},
            m_DateOfBirth{""},
            m_DateOfJoining{""},
            m_PerformanceMetric{ std::nullopt },
            m_Bonus{ std::nullopt },
            m_MobileNumber{ 0 },
            m_Gender{ Gender::Default },
            m_EmployeeID{ 0 },
            m_DepartmentID{ 0 },
            m_MentorID{ std::nullopt } {
        }

        Employee(bool isUpdateObj) :
            name{true},
            m_Email{ "#" },
            m_Address{ "#" },
            m_DateOfBirth{ std::nullopt },
            m_DateOfJoining{ "#" },
            m_PerformanceMetric{ std::nullopt },
            m_Bonus{ std::nullopt },
            m_MobileNumber{ -1 },
            m_Gender{ Gender::Default },
            m_EmployeeID{ -1 },
            m_DepartmentID{ -1 },
            m_MentorID{ std::nullopt } {
        }

        void setFirstName(const std::string& firstName) {
            name.setFirstName(firstName);
        }
        void setMiddleName(const std::optional<std::string>& middleName) {
            name.setMiddleName(middleName);
        }
        void setLastName(const std::string& lastName) {
            name.setLastName(lastName);
        }
        void setEmail(const std::string& email) {
            m_Email = email;
        }
        void setAddress(const std::string& address) {
            m_Address = address;
        }
        void setDateOfBirth(const std::string& dateOfBirth) {
            m_DateOfBirth = dateOfBirth;
        }
        void setDateOfJoining(const std::string& dateOfJoining) {
            m_DateOfJoining = dateOfJoining;
        }
        void setPerformanceMetric(const std::optional<double>& performanceMetric) {
            m_PerformanceMetric = performanceMetric;
        }
        void setBonus(const std::optional<double>& bonus) {
            m_Bonus = bonus;
        }
        void setMobileNumber(long long mobileNumber) {
            m_MobileNumber = mobileNumber;
        }
        void setGender(Gender gender) {
            m_Gender = gender;
        }
        void setEmployeeID(int employeeID) {
            m_EmployeeID = employeeID;
        }
        void setDepartmentID(int departmentID) {
            m_DepartmentID = departmentID;
        }
        void setMentorID(const std::optional<int>& mentorID) {
            m_MentorID = mentorID;
        }

        const std::string& getFirstName() const {
            return name.getFirstName();
        }
        const std::optional<std::string>& getMiddleName() const {
            return name.getMiddleName();
        }
        const std::string& getLastName() const {
            return name.getLastName();
        }
        const std::string& getEmail() const {
            return m_Email;
        }
        const std::string& getAddress() const {
            return m_Address;
        }
        const std::optional<std::string>& getDateOfBirth() const {
            return m_DateOfBirth;
        }
        const std::string& getDateOfJoining() const {
            return m_DateOfJoining;
        }
        std::optional<double> getPerformanceMetric() const {
            return m_PerformanceMetric;
        }
        std::optional<double> getBonus() const {
            return m_Bonus;
        }
        long long getMobileNumber() const {
            return m_MobileNumber;
        }
        Gender getGender() const {
            return m_Gender;
        }
        int getEmployeeID() const {
            return m_EmployeeID;
        }
        int getDepartmentID() const {
            return m_DepartmentID;
        }
        std::optional<int> getMentorID() const {
            return m_MentorID;
        }

	    private:
        Name name;
        std::string m_Email;
        std::string m_Address;
        std::optional<std::string> m_DateOfBirth;
        std::string  m_DateOfJoining;
		std::optional<double> m_PerformanceMetric;
        std::optional<double> m_Bonus;
		long long m_MobileNumber;
		Gender m_Gender;
		int m_EmployeeID;
		int m_DepartmentID;
		std::optional<int> m_MentorID;
	};

    inline std::string getGenderString(Gender g) {
        std::string tempStr{ "" };
        switch (g) {
        case Gender::Male:
            tempStr = "Male";
            break;
        case Gender::Female:
            tempStr = "Female";
            break;
        case Gender::Other:
            tempStr = "Other";
            break;
        }
        return tempStr;
    }

    inline Gender getGenderFromString(std::string& genderString) {
        Gender gender{ Gender::Default };

        std::transform(genderString.begin(), genderString.end(), genderString.begin(), ::tolower);
        if (genderString == "male") {
            gender = Gender::Male;
        }
        else if (genderString == "female") {
            gender = Gender::Female;
        }
        else if (genderString == "other") {
            gender = Gender::Other;
        }
        return gender;
    }
}

#endif