#include <fstream>

int b() {
	std::ifstream fin;
	fin.open("C://1.txt", std::ios_base::in);

	char prev_space = 0;
	std::string str;
	char c;
	while (fin.get(c))
		if (c == ' ')
			prev_space = 1;

		else {
			if (prev_space) {
				str += ' ';
				prev_space = 0;
			}

			str += c;
		}

	fin.close();

	std::ofstream fout;
	fout.open("C://1.txt", std::ios_base::out);

	fout << str;

	fout.close();

	return 0;
}