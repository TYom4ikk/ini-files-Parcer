#pragma once
#include "IParser.h"
#include <string>
#include <fstream>
#include <map>
#include <conio.h>
#include <Windows.h>

class Parcer :public IParser {
public:
	// 1. В каком заголовке лежит ключ X?
	void FindSectionByKey(const std::string& Key)override;

	// 2. Существует ли заголовок X (секция)?
	void DoesTitleExist(const std::string& Section)override;

	// 3. Существует ли ключ X в файле?
	void DoesKeyExist(const std::string& Key)override;

	// 4. Существует ли значение X в файле ?
	void DoesValueExist(const std::string& Value)override;

	// 5. Какое значение у ключа X в секции Y?
	void FindValueByKeyInSection(const std::string& Section, const std::string& Key)override;


	// 6. Обратиться к секции X и присвоить ключу Y значение Z(если ключа или секции не существует - создать)
	void ChangeValue(const std::string& Section, const std::string& Key, const std::string& Value)override;

	// 7. Вывести отредактированный(или оставленный как есть).ini файл в новый файл с пользовательским названием.
	void MakeNewFile()override;

	void AddSection(const std::string& Section)override;
	void AddKeyValue(const std::string& Key, const std::string& Value)override;

private:
	std::map <std::string, std::map<std::string, std::string> > _sections;
	//	<Section	< key    value > >
	std::string _LastSection;
};
