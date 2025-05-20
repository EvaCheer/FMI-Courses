#include <iostream>
#include <fstream>

void copyFile(const char* fromFileName, const char* toFileName) {

	std::ifstream file1(fromFileName);
	if (!file1.is_open()) {
		std::cout << "Could not open file 1";
		return;
	}
	std::ofstream file2(toFileName);
	if (!file2.is_open()) {
		std::cout << "Could not open file 2";
		return;
	}

	while (!file1.eof()) {
		char buffer[1024];
		file1.getline(buffer, 1024);
		file2 << buffer;
	}

	file1.close();
	file2.close();
	return;
}

void printFile(const char* file_name) {

	std::ifstream file(file_name);
	if (!file.is_open()) {
		std::cout << "Could not open file to read";
		return;
	}

	while (!file.eof()) {
		char buffer[1024];
		file.getline(buffer, 1024);
		std::cout << buffer;
	}
	return;
}

int main()
{
	copyFile("text1.txt", "text2.txt");
	printFile("text2.txt");

}
