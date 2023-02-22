#include <fstream>
#include <string>

int b()
{
	std::ifstream fin;
	fin.open("C://1.txt", std::ios_base::in);

	char c;
	std::string str;
	while (fin.get(c))
		if (c == ' ')
		{
			str += ' ';
			while (c == ' ')
				fin >> c;
			str += c;
		}
		else
			str += c;

	fin.close();

	std::ofstream fout;
	fout.open("C://1.txt", std::ios_base::trunc);
	fout << str;

	fout.close();

	return 0;
}