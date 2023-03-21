#pragma once
#include <iostream>

class IParser
{
public:
	virtual void FindSectionByKey(const std::string& Key) = 0;
	virtual void DoesTitleExist(const std::string& Section) = 0;
	virtual void DoesKeyExist(const std::string& Key) = 0;
	virtual void DoesValueExist(const std::string& Value) = 0;
	virtual void FindValueByKeyInSection(const std::string& Section, const std::string& Key) = 0;
	virtual void ChangeValue(const std::string& Section, const std::string& Key, const std::string& Value) = 0;
	virtual void MakeNewFile() = 0;
	virtual void AddSection(const std::string& Section) = 0;
	virtual void AddKeyValue(const std::string& Key, const std::string& Value) = 0;
	virtual ~IParser() {};
};

