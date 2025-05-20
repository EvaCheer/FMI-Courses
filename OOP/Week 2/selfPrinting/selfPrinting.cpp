#include <iostream>
#include <fstream>

int main()
{
	char file_name[] = "selfPrinting.cpp";
	std::ifstream file(file_name);
	if (!file.is_open()) {
		std::cout << "Error when opening!" << std::endl;
		return -1;
	}

	char buffer[1024];
	while (!file.eof()) {
		file.getline(buffer, 1024);
		std::cout << buffer << std::endl;
	}
	return 0;
}

