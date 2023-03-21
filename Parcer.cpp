#include "Parcer.h"

// 1. � ����� ��������� ����� ���� X?
void Parcer::FindSectionByKey(const std::string& Key) { // ��� ��� ����� ������ ������ ����� ����� ���������� ��������, �� 
	// �� � ������ ����� ��� ������, � ������� ���� ����� ����
	bool WasMessage = false; // ��� �� ����� � ���, ��� ���� ����������? (���������� ��� ������ � �������)
	for (std::map<std::string, std::map<std::string, std::string>>::iterator it = _sections.begin(); it != _sections.end(); it++)
	{
		if (it->second.contains(Key)) // �������� �� ������������� Key ��� ������ ������ contains
		{
			std::cout << "Key: " << Key << " located in Section: " << it->first << std::endl;
			WasMessage = true;
		}
	}
	if (WasMessage == false)
	{
		std::cout << "Key: " << Key << " does not exist!" << std::endl;
		return;
	}
}

// 2. ���������� �� ��������� X (������)?
void Parcer::DoesTitleExist(const std::string& Section) {
	for (std::map<std::string, std::map<std::string, std::string>>::iterator it = _sections.begin(); it != _sections.end(); it++)
	{
		if (it->first == Section)
		{
			std::cout << "Section: " << Section << " exists!" << std::endl;
			return; // ����� �� ������
		}
	}
	std::cout << "Section: " << Section << " does not exist!" << std::endl;
}

// 3. ���������� �� ���� X � �����?
void Parcer::DoesKeyExist(const std::string& Key) {
	for (std::map<std::string, std::map<std::string, std::string>>::iterator it = _sections.begin(); it != _sections.end(); it++)
	{
		if ((it->second.find(Key)) == it->second.end())
		{
			continue;
		}
		else {
			std::cout << "Key: " << Key << " exists in File!" << std::endl;
			return;
		}
	}
	std::cout << "Key: " << Key << " does not exists in File!" << std::endl;
}

// 4. ���������� �� �������� X � ����� ?
void Parcer::DoesValueExist(const std::string& Value) {
	for (std::map<std::string, std::map<std::string, std::string>>::iterator it = _sections.begin(); it != _sections.end(); it++)
	{
		for (auto& item : it->second)
		{
			if (item.second == Value)
			{
				std::cout << "Value: " << Value << " exists in File!" << std::endl;
				return;
			}
		}
	}
	std::cout << "Value: " << Value << " does not exists in File!" << std::endl;
}

// 5. ����� �������� � ����� X � ������ Y?
void Parcer::FindValueByKeyInSection(const std::string& Section, const std::string& Key) {
	for (std::map<std::string, std::map<std::string, std::string>>::iterator it = _sections.begin(); it != _sections.end(); it++)
	{
		if (it->first == Section)
		{
			for (auto& item : it->second)
			{
				if (item.first == Key)
				{
					if (item.second == "")
					{
						//The key a in section b has no value!
						std::cout << "The Key: " << Key << " in Section: " << it->first << " no value!" << std::endl;
						return;
					}
					else {
						std::cout << "The Value of Key: " << Key << " in Section: " << it->first << " is: " << item.second << std::endl;
						return;
					}
				}
			}
			std::cout << "Key: " << Key << " in Section: " << it->first << " does not exist!" << std::endl;
			return;
		}
	}
	std::cout << "Section: " << Section << " does not exist!" << std::endl;
}


// 6. ���������� � ������ X � ��������� ����� Y �������� Z(���� ����� ��� ������ �� ���������� - �������)
void Parcer::ChangeValue(const std::string& Section, const std::string& Key, const std::string& Value) {
	for (std::map<std::string, std::map<std::string, std::string>>::iterator it = _sections.begin(); it != _sections.end(); it++)
	{
		if (it->first == Section)
		{
			for (auto& item : it->second)
			{
				if (item.first == Key)
				{
					item.second = Value;
					std::cout << "The Value of Key: " << Key << " in Section: " << it->first << " changed to: " << item.second << std::endl;
					return;
				}
			}
			std::cout << "Key: " << Key << " in Section: " << it->first << " does not exist!" << std::endl << "Creating Key..." << std::endl;
			it->second.insert({ Key, Value });
			return;
		}
	}
	std::cout << "Section: " << Section << " does not exist!" << std::endl << "Creating Section..." << std::endl;
	_sections.insert({ Section,{} });
	_sections[Section].insert({ Key, Value });
}

// 7. ������� �����������������(��� ����������� ��� ����).ini ���� � ����� ���� � ���������������� ���������.
void Parcer::MakeNewFile() {
	std::ofstream NewFile;
	NewFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	std::string NewFilePath;
	std::cout << "Enter name of File (File.ini)";
	try {
		std::cin >> NewFilePath;
		NewFile.open(NewFilePath);

		if (NewFile.is_open())
		{
			for (std::map<std::string, std::map<std::string, std::string>>::iterator it = _sections.begin(); it != _sections.end(); it++)
			{
				NewFile << '[' << it->first;
				NewFile << ']';
				NewFile << '\n';
				for (auto& item : it->second)
				{
					NewFile << item.first;
					NewFile << '=';
					NewFile << item.second;
					NewFile << '\n';
				}
			}
		}
		else {
			std::cerr << "File Opening Error!" << std::endl;
		}
		NewFile.close();
	}
	catch (const std::ofstream::failure& ex) {
		std::cout << ex.what() << std::endl;
	}
}

void Parcer::AddSection(const std::string& Section) {
	_sections.insert({ Section,{} });
	_LastSection = Section;
}

void Parcer::AddKeyValue(const std::string& Key, const std::string& Value) {
	_sections[_LastSection].insert({ Key, Value });
}