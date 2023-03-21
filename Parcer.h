#pragma once
#include "IParser.h"
#include <string>
#include <fstream>
#include <map>
#include <conio.h>
#include <Windows.h>

class Parcer :public IParser {
public:
	// 1. � ����� ��������� ����� ���� X?
	void FindSectionByKey(const std::string& Key)override;

	// 2. ���������� �� ��������� X (������)?
	void DoesTitleExist(const std::string& Section)override;

	// 3. ���������� �� ���� X � �����?
	void DoesKeyExist(const std::string& Key)override;

	// 4. ���������� �� �������� X � ����� ?
	void DoesValueExist(const std::string& Value)override;

	// 5. ����� �������� � ����� X � ������ Y?
	void FindValueByKeyInSection(const std::string& Section, const std::string& Key)override;


	// 6. ���������� � ������ X � ��������� ����� Y �������� Z(���� ����� ��� ������ �� ���������� - �������)
	void ChangeValue(const std::string& Section, const std::string& Key, const std::string& Value)override;

	// 7. ������� �����������������(��� ����������� ��� ����).ini ���� � ����� ���� � ���������������� ���������.
	void MakeNewFile()override;

	void AddSection(const std::string& Section)override;
	void AddKeyValue(const std::string& Key, const std::string& Value)override;

private:
	std::map <std::string, std::map<std::string, std::string> > _sections;
	//	<Section	< key    value > >
	std::string _LastSection;
};
