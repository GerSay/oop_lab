#include <fstream>
#include <vector>

typedef std::vector<std::vector<double>> Matrix;

std::ostream& operator<<(std::ostream& os, const std::vector<Matrix>& M)
{
	for (const auto& k : M)
		for (const auto& i : k) 
			for (const auto& j : i)
				os << j << ' ';

	return os;
}

Matrix transposeMatrix(const Matrix& m)
{
	Matrix result(m.size(), std::vector<double>(m[0].size()));
	for (uint32_t i = 0; i < m.size(); i++)
		for (uint32_t j = 0; j < m[0].size(); j++)
			result[j][i] = m[i][j];

	return result;
}

int a()
{
	std::ifstream fin;
	fin.open("C://1.txt", std::ios_base::in);

	std::vector<Matrix> matrixs;
	while (!fin.eof())
	{
		uint32_t size;
		fin >> size;

		Matrix matrix(size, std::vector<double>(size));

		for (uint32_t i = 0; i < size; i++)
			for (uint32_t j = 0; j < size; j++)
				fin >> matrix[i][j];

		matrixs.push_back(transposeMatrix(matrix));
	}

	fin.close();

	std::ofstream fout;
	fout.open("C://1.txt", std::ios_base::trunc);
	fout << matrixs;

	fout.close();

	return 0;
}