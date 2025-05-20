#include <iostream>
#include <fstream>

int newLinesCount(char file_name[]) {

	std::ifstream file(file_name);
	if (!file.is_open()) {
		std::cout << "Error while opening!" << std::endl;
		return -1;
	}
	int count = 0;
	char current;

	while (file.get(current)) {
		if (current == '\n') count++;
	}

	return count;
}


int main()
{
	char file_name[] = "file.txt";

	std::cout << newLinesCount(file_name);
}