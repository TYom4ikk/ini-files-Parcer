#include "Parcer.h"
#include "All Func.h"

int main(int argc, char** argv) {

	std::cout << "\n\n===================START===================\n\n";
	try {
		if (argc > 1 && argc <= 2)
		{
			std::string path = (argv[1]);

			Parcer parcer;
			std::ifstream IniFile;
			IniFile.open(path);
			if (!IniFile.is_open())
			{
				std::cerr << "An error occurred when opening the file: " << path << std::endl;
			}
			else {
				std::cout << "File \'" << path << "\' was opened!" << std::endl;

				std::string Line;
				while (!IniFile.eof()) {
					getline(IniFile, Line);
					if (Line[0] == ';' || Line[0] == '#') //�������� �� ������ � �������������
					{
						continue;
					}
					else {
						if (Line[0] == '[') { //�������� �� ������
							std::string section = Line.substr(1, Line.find(']') - 1);
							parcer.AddSection(section);
							//std::cout << "Section: " << section << std::endl; //����� (�� ������ ������)
						}
						else {
							if (!Line.empty()) // �������� �� ������� ������
							{
								if (Line[0] == ' ') // ���� ���� �� �����, �� ����� ��� �������
								{
									continue;
								}
								else {
									std::string Key = Line.substr(0, Line.find('=')); // �� ��� �� = ��� ����
									std::string str = Line.substr(Line.find('=') + 1); //�� ��� ����� = ��� ��������
									std::string Value; // �������� ��������
									for (size_t i = 0; i != str.size(); i++)
									{
										if (str[i] == ';' || str[i] == '#') {// ��� ��� ����� Key= ������ �����
										// ���� ����������� (�� ������, ������ ��� ���������� key= (��� ��������))

											break; // ������� ����, ������ ���� ���� �����������, � ������,
											// ��������� � ������ ��� �� ����� - ��� ���� �����������
										}
										else {
											Value += str[i]; //����������, ������������ ���������� � �������� value
										}
									}
									parcer.AddKeyValue(Key, Value);

									//std::cout << "Key: " << Key << std::endl; //����� (�� ������ ������)
									//std::cout << "Value: " << Value << std::endl; //����� (�� ������ ������)
								}
							}
						}
					}
				}

			}
			UserInteraction(parcer);
			IniFile.close();
		}
		else if (argc > 2)
		{
			std::cout << "Too much argument was entered!" << std::endl;
		}
		else {
			std::cout << "Only one argument was entered!" << std::endl;
		}
		std::cout << "\n\n====================END====================\n\n";
	}
	catch (const std::ofstream::failure & ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
