#include <iostream>
#include <fstream>

// Археолог е открил няколко съкровища и записва техните координати в бинарен файл
// treasure.dat. Създайте структура Treasure, която да има име (до 20 символа),
// координата Х и координата У. Запишете няколко структури в бинарния файл и после ги
// прочетете.

struct Treasure {
	char name[20];
	int X;
	int Y;
};

void writeObjectInBinary(const char* file_name, const Treasure& treasure) {

	std::ofstream file(file_name, std::ios::app, std::ios::binary);
	if (!file.is_open()) {
		std::cout << "Error while opening the file!";
		return;
	}

	file.write(treasure.name, sizeof(treasure.name));
	file.write(reinterpret_cast<const char*>(&treasure.X), sizeof(treasure.X));
	file.write(reinterpret_cast<const char*>(&treasure.Y), sizeof(treasure.Y));
	file.close();
	return;
}

void writeStructArrayInFile(const char* file_name, const Treasure treasure[], const int& arraySize) {
	std::ofstream file(file_name, std::ios::binary);
	if (!file.is_open()) {
		std::cout << "Error while opening!";
		return;
	}

	for (int i = 0; i < arraySize; i++) {
		file.write(treasure[i].name, sizeof(treasure[i].name));
		file.write(reinterpret_cast<const char*>(&treasure[i].X), sizeof(treasure[i].X));
		file.write(reinterpret_cast<const char*>(&treasure[i].Y), sizeof(treasure[i].Y));
	}
	file.close();
	return;
}

void readStructsFromFile(const char* file_name) {
	std::ifstream file(file_name, std::ios::binary);
	if (!file.is_open()) {
		std::cout << "Error while opening file!";
		return;
	}
	Treasure current;
	while (file.read(reinterpret_cast<char*>(&current), sizeof(Treasure))) {
		std::cout << "Name: " << current.name << "; Coordinates: ("<< current.X << ", " << current.Y << ")." << std::endl;
	}
	file.close();
	return;
}

int main()
{
	Treasure treasureArray[] = {
		{"Zlato",43,21},
		{"Srebro",3,23},
		{"Mastilo za printer",0,0}
	};

	writeStructArrayInFile("treasures.dat", treasureArray, 3);
	readStructsFromFile("treasures.dat");

	return 0;
}
