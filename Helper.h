#pragma once
#include <iostream>
#include <vector>
#include <bitset>

namespace Helper {
	int GetValidatedInt(const char* strMessage, int nMinimumRange = INT_MIN, int nMaximumRange = INT_MAX) {
		int response = NULL;
		bool invalid = true;
		std::cout << strMessage;
		while (invalid) {
			std::cin >> response;
			if (std::cin.fail()) {
				std::cin.clear(); // clears any errors in the input buffer
				std::cin.ignore(INT_MAX, '\n'); //flushes the buffer
				std::cout << "Please enter a valid number." << std::endl;
			}
			else if (response < nMinimumRange || response > nMaximumRange) {
				std::cin.clear(); // clears any errors in the input buffer
				std::cin.ignore(INT_MAX, '\n'); //flushes the buffer
				std::cout << "Please enter a valid number." << std::endl;
			}
			else {
				invalid = false;
			}
		}
		std::cin.ignore(INT_MAX, '\n');
		return response;
	}

	int PrintMenu(std::vector<std::string> options) {
		for (int i = 0; i < options.size(); i++) {
			std::cout << options[i] << std::endl;
		}
		return GetValidatedInt("Choice? ", 1, (int)options.size());
	}

	/// <summary>
	/// Prints an integer in 1. Binary, 2. Hexadecimal, 3. Octal
	/// </summary>
	/// <param name="num"></param>
	/// <param name="option"></param>
	void IntPrintOptions(int num, int option) {
		switch (option)
		{
		case 1:
			std::cout << "Binary = " << std::bitset<8>(num) << std::endl;
			/*for (int i = 32 - 1; i >= 0; i--)
			{
				if (((i + 1) % 4) == 0)
					std::cout << " ";
				if (num & (1 << i))
					std::cout << 1;
				else
					std::cout << 0;
			}
			std::cout << std::endl;*/
			break;
		case 2:
			std::cout << "Hexidecimal = " << std::hex << num << std::endl;
			break;
		case 3:
			std::cout << "Octal = " << std::oct << num << std::endl;
			break;
		default:
			break;
		}
	}
}
