#include <iostream>
#include "Utility.h"

using EmployeeDB::View::Utility;

bool Utility::proceedFurther(const std::string& operation) {
	auto isInvalidInput{ false };

	while (true) {
		if (!isInvalidInput) {
			std::cout << "\x1B[33m" << "Do you want to proceed with "+ operation +"? [y/n] : " << "\x1B[0m";
		}

		std::string inputLine;
		std::getline(std::cin, inputLine);
		removeEmptySpaces(inputLine);

		if (inputLine.size() == 1 && (inputLine[0] == 'y' || inputLine[0] == 'Y')) {
			return true;
		}
		else if (inputLine.size() == 1 && (inputLine[0] == 'n' || inputLine[0] == 'N')) {
			return false;
		}
		else {
			std::cerr << "\x1B[33m" << "Wrong Input, Please enter character [y/n] : " << "\x1B[0m";
			isInvalidInput = true;
		}
	}

	return false;
}

bool Utility::repeatOperation(const std::string& operation, const std::string& Entity) {
	auto isInvalidInput = false;

	while (true) {
		if (!isInvalidInput) {
			std::cout << "\x1B[33m" << "Do you want to "+ operation + " another " + Entity +"? [y / n] : " << "\x1B[0m";
		}
		
		std::string inputLine;
		std::getline(std::cin, inputLine);
		removeEmptySpaces(inputLine);

		if (inputLine.size() == 1 && (inputLine[0] == 'y' || inputLine[0] == 'Y')) {
			return true;
		}
		else if (inputLine.size() == 1 && (inputLine[0] == 'n' || inputLine[0] == 'N')) {
			return false;
		}
		else {
			std::cerr << "\x1B[33m" << "Wrong Input, Please enter character [y/n] : " << "\x1B[0m";
			isInvalidInput = true;
		}
	}

	return false;
}

void Utility::removeEmptySpaces(std::string& str, const std::string& chars) {
	if (str.size() == 0) {
		return;
	}
	else {
		str.erase(str.find_last_not_of(chars) + 1);
		str.erase(0, str.find_first_not_of(chars));

		std::string tempStr;
		auto preSpace{ false };
		auto i{ 0 };
		while (i < str.size()) {
			if (str.at(i) != ' ') {
				if (preSpace) {
					tempStr += ' ';
				}
				tempStr += str.at(i);
				preSpace = false;
			}
			else {
				preSpace = true;
			}
			++i;
		}
		str = std::move(tempStr);
	}
}

std::optional<int> Utility::getUserInputInt(const std::string& inputText, std::function<bool(const std::string&)> validator, bool isMandatory) {
	auto isInvalidInput{ false };

	std::string userInput;
	std::optional<int> result{std::nullopt};
	do {
		isInvalidInput = false;
		std::cout << inputText << (isMandatory ? "*" : "") << " : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0 && isMandatory) {
			std::cout << "\x1B[33m" << inputText <<" is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else if (userInput.size() == 0 && !isMandatory) {
			break;
		}
		else {
			try {
				if (validator) {
					if (validator(userInput)) {
						result = stoi(userInput);
						break;
					}
					else {
						throw "Wrong Input\n";
					}
				}
				else {
					result = stoi(userInput);
					if (result < 0) {
						throw "Negative Number\n";
					}
					break;
				}
			}
			catch (...) {
				isInvalidInput = true;
				std::cout << "\x1B[33m" << "Wrong input...Please enter positive integer number!!" << "\x1B[0m\n";
			}
		}
	} while (isMandatory || isInvalidInput);

	return result;
}

std::optional<int> Utility::getUserInputInt(const std::string& inputText, std::function<bool(const std::string&, const std::string&)> validator, const std::string& entity) {

	std::string userInput;
	std::optional<int> result{ std::nullopt };

	do {
		std::cout << inputText << "* : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0) {
			std::cout << "\x1B[33m" << inputText << " is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else {
			try {
				if (validator(userInput, entity)) {
					result = stoi(userInput);
					break;
				}
				else {
					throw "Wrong Input\n";
				}
			}
			catch (...) {
				std::cout << "\x1B[33m" << "Wrong input...Please enter positive integer number!!" << "\x1B[0m\n";
			}
		}
	} while (true);

	return result;
}

std::optional<long long> Utility::getUserInputLL(const std::string& inputText, std::function<bool(const std::string&)> validator, bool isMandatory) {
	auto isInvalidInput{ false };

	std::string userInput;
	std::optional<long long> result{ std::nullopt };
	do {
		isInvalidInput = false;
		std::cout << inputText << (isMandatory ? "*" : "") << " (Starting from [6-9]) : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0 && isMandatory) {
			std::cout << "\x1B[33m" << inputText << " is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else if (userInput.size() == 0 && !isMandatory) {
			break;
		}
		else {
			try {
				if (validator) {
					if (validator(userInput)) {
						result = stoll(userInput);
						break;
					}
					else {
						throw "Wrong Input\n";
					}
				}
				else {
					result = stoll(userInput);
					if (result < 0) {
						throw "Negative Number\n";
					}
					break;
				}				
			}
			catch (...) {
				isInvalidInput = true;
				std::cout << "\x1B[33m" << "Wrong input...Please enter positive integer number!!" << "\x1B[0m\n";
			}
		}
	} while (isMandatory || isInvalidInput);

	return result;
}

std::optional<double> Utility::getUserInputDouble(const std::string& inputText, bool isMandatory) {
	auto isInvalidInput{ false };

	std::string userInput;
	std::optional<double> result{std::nullopt};
	do {
		isInvalidInput = false;
		std::cout << inputText << (isMandatory ? "*" : "") << " : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0 && isMandatory) {
			std::cout << "\x1B[33m" << inputText << " is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else if (userInput.size() == 0 && !isMandatory) {
			break;
		}
		else {
			try {
				result = stod(userInput);
				if (result < 0.0) {
					throw "Negative Number\n";
				}
				break;
			}
			catch (...) {
				isInvalidInput = true;
				std::cout << "\x1B[33m" << "Wrong input...Please enter positive integer number!!" << "\x1B[0m\n";
			}
		}
	} while (isMandatory || isInvalidInput);

	return result;
}

std::optional<std::string> Utility::getUserInputString(const std::string& inputText, std::function<bool(const std::string&)> validator, bool isMandatory) {
	auto isInvalidInput{ false };

	std::string userInput;
	std::optional<std::string> result{ std::nullopt };
	do {
		isInvalidInput = false;
		std::cout << inputText << (isMandatory ? "*" : "") << " : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0 && isMandatory) {
			std::cout << "\x1B[33m" << inputText << " is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else if (userInput.size() == 0 && !isMandatory) {
			break;
		}
		else {
			if (validator) {
				if (validator(userInput)) {
					result = userInput;
					break;
				}
				else {
					isInvalidInput = true;
					std::cerr << "\x1B[33m" << "Wrong " << inputText << "... Please enter again!!" << "\x1B[0m\n";
				}
			}
			else {
				result = userInput;
				break;
			}
		}
	} while (isMandatory || isInvalidInput);

	return result;
}

std::optional<std::string> Utility::getUserInputGender(const std::string& inputText, std::function<bool(std::string&)> validator, bool isMandatory) {
	auto isInvalidInput{ false };
	
	std::string userInput;
	std::optional<std::string> result{ std::nullopt };
	do {
		isInvalidInput = false;
		std::cout << inputText << (isMandatory ? "*" : "") << " : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0 && isMandatory) {
			std::cout << "\x1B[33m" << inputText << " is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else if (userInput.size() == 0 && !isMandatory) {
			break;
		}
		else {
			if (validator) {
				if (validator(userInput)) {
					result = userInput;
					break;
				}
				else {
					isInvalidInput = true;
					std::cerr << "\x1B[33m" << "Wrong " << inputText << "... Please enter again!!" << "\x1B[0m\n";
				}
			}
			else {
				result = userInput;
				break;
			}
		}
	} while (isMandatory || isInvalidInput);

	return result;
}

std::optional<std::string> Utility::getUserInputDate(const std::string& inputText, std::function<bool(const std::string&)> validator, bool isMandatory) {
	auto isInvalidInput{ false };

	std::string userInput;
	std::optional<std::string> result{ std::nullopt };
	do {
		isInvalidInput = false;
		std::cout << inputText << (isMandatory ? "*" : "") << " [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : ";
		std::getline(std::cin, userInput);
		Utility::removeEmptySpaces(userInput);

		if (userInput.size() == 0 && isMandatory) {
			std::cout << "\x1B[33m" << inputText << " is mandatory...Please enter again!!" << "\x1B[0m\n";
		}
		else if (userInput.size() == 0 && !isMandatory) {
			break;
		}
		else {
			if (validator(userInput)) {
				result = userInput;
				break;
			}
			else {
				isInvalidInput = true;
				std::cerr << "\x1B[33m" << "Please Enter the date in format [dd-mm-yyyy or dd/mm/yyyy or dd.mm.yyyy] : " << "\x1B[0m\n";
			}
		}
	}
	while (isMandatory || isInvalidInput);

	return result;
}