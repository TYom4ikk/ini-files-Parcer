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
					if (Line[0] == ';' || Line[0] == '#') //Проверка на строку с комментариями
					{
						continue;
					}
					else {
						if (Line[0] == '[') { //Проверка на Секцию
							std::string section = Line.substr(1, Line.find(']') - 1);
							parcer.AddSection(section);
							//std::cout << "Section: " << section << std::endl; //Вывод (на всякий случай)
						}
						else {
							if (!Line.empty()) // Проверка на пустоту строки
							{
								if (Line[0] == ' ') // Даже если не пуста, то вдруг там пробелы
								{
									continue;
								}
								else {
									std::string Key = Line.substr(0, Line.find('=')); // Всё что до = это ключ
									std::string str = Line.substr(Line.find('=') + 1); //Всё что после = это значение
									std::string Value; // Конечное значение
									for (size_t i = 0; i != str.size(); i++)
									{
										if (str[i] == ';' || str[i] == '#') {// Так как после Key= Вполне может
										// быть комментарий (Не раньше, потому что существует key= (без значения))

											break; // Заходим сюда, только если есть комментарий, а значит,
											// остальное в строке нам не важно - это тоже комментарий
										}
										else {
											Value += str[i]; //Выборочная, посимвольная перезапись в конечный value
										}
									}
									parcer.AddKeyValue(Key, Value);

									//std::cout << "Key: " << Key << std::endl; //Вывод (на всякий случай)
									//std::cout << "Value: " << Value << std::endl; //Вывод (на всякий случай)
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
