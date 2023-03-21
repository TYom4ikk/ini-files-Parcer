#include "Parcer.h"

void Func_1(Parcer& parcer) {
	system("CLS");
	std::string UserChoice;
	std::cout << "Enter Key Name:";
	std::cin >> UserChoice;
	parcer.FindSectionByKey(UserChoice);
}

void Func_2(Parcer& parcer) {
	system("CLS");
	std::string UserChoice;
	std::cout << "Enter Section Name:";
	std::cin >> UserChoice;
	parcer.DoesTitleExist(UserChoice);
}

void Func_3(Parcer& parcer) {
	system("CLS");
	std::string UserChoice;
	std::cout << "Enter Key Name:";
	std::cin >> UserChoice;
	parcer.DoesKeyExist(UserChoice);
}

void Func_4(Parcer& parcer) {
	system("CLS");
	std::string UserChoice;
	std::cout << "Enter Value Name:";
	std::cin >> UserChoice;
	parcer.DoesValueExist(UserChoice);
}

void Func_5(Parcer& parcer) {
	system("CLS");
	std::string Section, Key;
	std::cout << "Enter Section: ";
	std::cin >> Section;
	std::cout << "Enter Key: ";
	std::cin >> Key;
	parcer.FindValueByKeyInSection(Section, Key);
}

void Func_6(Parcer& parcer) {
	system("CLS");
	std::string Section, Key, Value;
	std::cout << "Enter Section: ";
	std::cin >> Section;
	std::cout << "Enter Key: ";
	std::cin >> Key;
	std::cout << "Enter Value to change: ";
	std::cin >> Value;
	parcer.ChangeValue(Section, Key, Value);
}

void Func_7(Parcer& parcer) {
	system("CLS");
	parcer.MakeNewFile();
}