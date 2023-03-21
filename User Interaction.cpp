#include "Parcer.h"
#include "IParser.h"
#include "All Func.h"

void UserInteraction(Parcer& parcer) {
start:
	system("CLS");
	std::cout << "\t\t\tINI PARCER" << std::endl
		<< "Select an action:\n"
		<< "1. Find out which Section contains the key\n"
		<< "2. Find out if the Section exists\n"
		<< "3. Find out if the Key exists in the file\n"
		<< "4. Find out if the Value exists in the file\n"
		<< "5. Find out what is the value of the X key in section Y\n"
		<< "6. Set to Key Y Value Z in X Section\n"
		<< "7. Create a New File\n"
		<< "0. Close the Program\n:";
	char choice;
	std::cin >> choice;
	switch (choice)
	{
	case '1':
		Func_1(parcer);
		Sleep(6000);
		goto start; // Наконец-то нашлось применение для goto!
	case '2':
		Func_2(parcer);
		Sleep(6000);
		goto start;
	case '3':
		Func_3(parcer);
		Sleep(6000);
		goto start;
	case '4':
		Func_4(parcer);
		Sleep(6000);
		goto start;
	case '5':
		Func_5(parcer);
		Sleep(6000);
		goto start;
	case '6':
		Func_6(parcer);
		Sleep(6000);
		goto start;
	case '7':
		Func_7(parcer);
		Sleep(6000);
		goto start;
	case '0':
		break;
	default:
		std::cout << "Wrong chosen Action!";
		Sleep(6000);
		goto start;
	}
}