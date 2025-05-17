#include <iostream>

struct Student {
	int grade;
	char fn[11];
	char name[50];
	double averageGradeOfGroup;
};

void initializeStudent(Student* group, int index, double &gradesSum) {

	std::cout << "What is the student's grade?" << std::endl;
	std::cin >> group[index].grade;
	gradesSum += group[index].grade;
	std::cout << "What is the student's fn? (MAX 10 chars)" << std::endl;
	std::cin >> group[index].fn;
	std::cout << "What is the student's name?" << std::endl;
	std::cin >> group[index].name;
	return;
}

const Student* createGroup(int& groupSize) {
	std::cout << "What size will the group be?" << std::endl;
	std::cin >> groupSize;
	double gradesSum = 0;
	Student* group = new Student[groupSize];
	//initialize all students in group
	for (int i = 0; i < groupSize; i++) {
		initializeStudent(group, i, gradesSum);
	}
	//after we know their grades, we traverse again to change each student's averageGradeOfGroup
	double averageGradeOfGroup = gradesSum / groupSize;
	for (int i = 0; i < groupSize; i++) {
		group[i].averageGradeOfGroup = averageGradeOfGroup;
	}
	return group;
}

void printStudent(Student student, const int &number) {
	std::cout << "Student's " <<number<< " grade: " << student.grade << std::endl;
	std::cout << "Student's " <<number<< " fn: " << student.fn << std::endl;
	std::cout << "Student's " << number << " name: " << student.name << std::endl;
	return;
}

void printGroup(const Student* studentsGroup, int groupSize) {
	for (int i = 0; i < groupSize;i++) {
		printStudent(studentsGroup[i], i+1);
	}
	std::cout << "Average grade in group: " << studentsGroup[0].averageGradeOfGroup << std::endl;
	return;
}

int howManyWillGetScholarship(const Student* group, int size, double minGrade) {
	int studentsCount = 0;
	for (int i = 0; i < size; i++) {
		if (group[i].grade >= minGrade) studentsCount++;
	}
	return studentsCount;
}



int main()
{
	int groupSize;
	const Student* studentsGroup;
	studentsGroup = createGroup(groupSize);
	printGroup(studentsGroup, groupSize);
}