#include <iostream>
#include <fstream>

// Древен свитък с важни записки е намерен, но мастилото е избледняло и някои думи са
// изгубени. За щастие, текстът е записан в scroll.txt, но ти трябва да го възстановиш,
// като прочетеш и отпечаташ съдържанието му. Измежду думите са скрити и цифри.
// Тези цифри образуват тайна парола, която трябва да бъде записана в бинарен файл,
// за да не може да се прочете с просто око

void printFile(const char* file_name) {

	std::ifstream file(file_name);
	if (!file.is_open()) {
		std::cout << "Error while opening the file!";
		return;
	}

	while (!file.eof()) {
		char buffer[1024];
		file.getline(buffer, 1024);
		std::cout << buffer;
	}
	return;
}

void printBinaryFile(const char* file_name) {

	std::ifstream file(file_name, std::ios::binary);
	if (!file.is_open()) {
		std::cout << "Error while opening the file!";
		return;
	}

	char ch;
	while (file.read(&ch, 1)) {
		std::cout << ch;
	}
	return;
}

bool isDigit(const char& ch) {
	return ch >= '0' && ch <= '9';
}

void getNumbers(const char* fromFile, const char* toFile) {
	
	std::ifstream file1(fromFile);
	if (!file1.is_open()) {
		std::cout << "Error while opening!";
		return;
	}

	std::ofstream file2(toFile, std::ios::app, std::ios::binary);
	if (!file2.is_open()) {
		std::cout << "Error while opening!";
		return;
	}

	char buffer[1024];

	while (file1.getline(buffer, 1024)) {
		for (int i = 0; buffer[i] != '\0'; i++) {
			if (isDigit(buffer[i])) {
				file2.write(&buffer[i], 1); // write as binary
			}
		}
	}

	file1.close();
	file2.close();
	return;
}



int main()
{
	const char* file_name = "scroll.txt";
	printFile(file_name);
	getNumbers(file_name, "binary_file.dat");
	std::cout << std::endl;
	std::cout << "This is the password: ";
	printBinaryFile("binary_file.dat");

}