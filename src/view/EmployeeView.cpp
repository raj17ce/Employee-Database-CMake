#include <iostream>
#include "EmployeeView.h"
#include "EmployeeController.h"
#include "Validate.h"
#include "Utility.h"

using EmployeeDB::View::EmployeeView, EmployeeDB::View::Utility;
using EmployeeDB::Controller::EmployeeController;
using EmployeeDB::Validate;

void EmployeeView::printEmployeeFields() {
	std::cout << "1. firstName* : " << '\n';
	std::cout << "2. middleName : " << '\n';
	std::cout << "3. lastName* : " << '\n';
	std::cout << "4. dateOfBirth : " << '\n';
	std::cout << "5. mobileNo* : " << '\n';
	std::cout << "6. email* :" << '\n';
	std::cout << "7. address* :" << '\n';
	std::cout << "8. gender* :" << '\n';
	std::cout << "9. dateOfJoining* :" << '\n';
	std::cout << "10. mentorID :" << '\n';
	std::cout << "11. performanceMetric :" << '\n';
	std::cout << "12. bonus :" << '\n';
}

void EmployeeView::printViewEmployeeFields() {
	std::cout << "1. employeeID* : " << '\n';
	std::cout << "2. firstName* : " << '\n';
	std::cout << "3. middleName* : " << '\n';
	std::cout << "4. lastName* : " << '\n';
	std::cout << "5. dateOfBirth* : " << '\n';
	std::cout << "6. mobileNo* : " << '\n';
	std::cout << "7. email* :" << '\n';
	std::cout << "8. address* :" << '\n';
	std::cout << "9. gender* :" << '\n';
	std::cout << "10. dateOfJoining* :" << '\n';
	std::cout << "11. mentorID* :" << '\n';
	std::cout << "12. performanceMetric* :" << '\n';
	std::cout << "13. bonus* :" << '\n';
}

void EmployeeView::getInsertEmployeeInput(Employee& obj) {
	
	{
		auto firstName = Utility::getUserInputString("firstName").value();
		obj.setFirstName(firstName);
	}

	{
		auto middleName = Utility::getUserInputString("middleName", 0, false);
		if (middleName.has_value()) {
			obj.setMiddleName(middleName.value());
		}
	}

	{
		auto lastName = Utility::getUserInputString("lastName").value();
		obj.setLastName(lastName);
	}

	{
		auto dateOfBirth = Utility::getUserInputDate("dateOfBirth", Validate::validateDate, false);
		if (dateOfBirth.has_value()) {
			obj.setDateOfBirth(dateOfBirth.value());
		}
	}

	{
		auto mobileNo = Utility::getUserInputLL("mobileNo", Validate::validateMobile).value();
		obj.setMobileNumber(mobileNo);
	}

	{
		auto email = Utility::getUserInputString("email", Validate::validateEmail).value();
		obj.setEmail(email);
	}

	{
		auto address = Utility::getUserInputString("address").value();
		obj.setAddress(address);
	}

	{
		auto gender = Utility::getUserInputGender("gender", Validate::validateGender).value();
		obj.setGender(EmployeeDB::Model::getGenderFromString(gender));
	}
	
	{
		auto dateOfJoining = Utility::getUserInputDate("dateOfJoining", Validate::validateDate).value();
		obj.setDateOfJoining(dateOfJoining);
	}

	{
		auto mentorID = Utility::getUserInputInt("mentorID", 0, false);
		if (mentorID.has_value()) {
			obj.setMentorID(mentorID.value());
		}
	}

	{
		auto performanceMetric = Utility::getUserInputDouble("performanceMetric", false);
		if (performanceMetric.has_value()) {
			obj.setPerformanceMetric(performanceMetric.value());
		}
	}

	{
		auto bonus = Utility::getUserInputDouble("bonus", false);
		if (bonus.has_value()) {
			obj.setBonus(bonus.value());
		}
	}
};

void EmployeeView::getUpdateEmployeeInput(Employee& obj, int fieldNumber) {

	switch (fieldNumber) {
	case 1:
	{
		auto firstName = Utility::getUserInputString("firstName").value();
		obj.setFirstName(firstName);
	}
	break;
	case 2:
	{
		auto middleName = Utility::getUserInputString("middleName", 0, false);
		if (middleName.has_value()) {
			obj.setMiddleName(middleName.value());
		}
	}
	break;
	case 3:
	{
		auto lastName = Utility::getUserInputString("lastName").value();
		obj.setLastName(lastName);
	}
	break;
	case 4:
	{
		auto dateOfBirth = Utility::getUserInputDate("dateOfBirth", Validate::validateDate, false);
		if (dateOfBirth.has_value()) {
			obj.setDateOfBirth(dateOfBirth.value());
		}
	}
	break;
	case 5:
	{
		auto mobileNo = Utility::getUserInputLL("mobileNo", Validate::validateMobile).value();
		obj.setMobileNumber(mobileNo);
	}
	break;
	case 6:
	{
		auto email = Utility::getUserInputString("email", Validate::validateEmail).value();
		obj.setEmail(email);
	}
	break;
	case 7:
	{
		auto address = Utility::getUserInputString("address").value();
		obj.setAddress(address);
	}
	break;
	case 8:
	{
		auto gender = Utility::getUserInputGender("gender", Validate::validateGender).value();
		obj.setGender(EmployeeDB::Model::getGenderFromString(gender));
	}
	break;
	case 9:
	{
		auto dateOfJoining = Utility::getUserInputDate("dateOfJoining", Validate::validateDate).value();
		obj.setDateOfJoining(dateOfJoining);
	}
	break;
	case 10:
	{
		std::optional<int> mentorID = Utility::getUserInputInt("mentorID", 0, false);
		if (mentorID.has_value()) {
			obj.setMentorID(mentorID.value());
		}
	}
	break;
	case 11:
	{
		auto performanceMetric = Utility::getUserInputDouble("performanceMetric", false);
		if (performanceMetric.has_value()) {
			obj.setPerformanceMetric(performanceMetric.value());
		}
	}
	break;
	case 12:
	{
		auto bonus = Utility::getUserInputDouble("bonus", false);
		if (bonus.has_value()) {
			obj.setBonus(bonus.value());
		}
		break;
	}
	}
};

void EmployeeView::getViewEmployeeInput(Employee& obj, int fieldNumber) {

	switch (fieldNumber) {
	case 1:
	{
		auto employeeID = Utility::getUserInputInt("employeeID").value();
		obj.setEmployeeID(employeeID);
	}
	break;
	case 2:
	{
		auto firstName = Utility::getUserInputString("firstName").value();
		obj.setFirstName(firstName);
	}
	break;
	case 3:
	{
		auto middleName = Utility::getUserInputString("middleName").value();
		obj.setMiddleName(middleName);
	}
	break;
	case 4:
	{
		auto lastName = Utility::getUserInputString("lastName").value();
		obj.setLastName(lastName);
	}
	break;
	case 5:
	{
		auto dateOfBirth = Utility::getUserInputDate("dateOfBirth", Validate::validateDate).value();
		obj.setDateOfBirth(dateOfBirth);
	}
	break;
	case 6:
	{
		auto mobileNo = Utility::getUserInputLL("mobileNo", Validate::validateMobile).value();
		obj.setMobileNumber(mobileNo);
	}
	break;
	case 7:
	{
		auto email = Utility::getUserInputString("email", Validate::validateEmail).value();
		obj.setEmail(email);
	}
	break;
	case 8:
	{
		auto address = Utility::getUserInputString("address").value();
		obj.setAddress(address);
	}
	break;
	case 9:
	{
		auto gender = Utility::getUserInputGender("gender", Validate::validateGender).value();
		obj.setGender(EmployeeDB::Model::getGenderFromString(gender));
	}
	break;
	case 10:
	{
		auto dateOfJoining = Utility::getUserInputDate("dateOfJoining", Validate::validateDate).value();
		obj.setDateOfJoining(dateOfJoining);
	}
	break;
	case 11:
	{
		auto mentorID = Utility::getUserInputInt("mentorID").value();
		obj.setMentorID(mentorID);
		break;
	}
	case 12:
	{
		auto performanceMetric = Utility::getUserInputDouble("performanceMetric").value();
		obj.setPerformanceMetric(performanceMetric);
	}
	break;
	case 13:
	{
		auto bonus = Utility::getUserInputDouble("bonus").value();
		obj.setBonus(bonus);
	}
	break;
	}
};

void EmployeeView::getEmployeeIDInput(Employee& obj, const std::string& operation, const std::string& entity) {

	Utility::clearScreen();
	std::cout << "------------------------------------------" << "\x1B[36m" << operation << " " + entity << "\x1B[0m" << "-------------------------------------------------\n";
	std::cout << "\x1B[33m" << "To " + operation + " " + entity + ", please enter employeeID." << "\x1B[0m\n";

	auto employeeID = Utility::getUserInputInt("employeeID",Validate::validateEmployeeID,entity).value();
	obj.setEmployeeID(employeeID);
}