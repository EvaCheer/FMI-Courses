#include <iostream>

enum errorCode {
	OK,
	pointerIsNull,
	invalidCharInStr,

};

struct convertedString {
	errorCode error = errorCode::OK;
	unsigned int result;
};

bool isItAnInt(const char &ch) {
	return ch >= '0' && ch <= '9';
}

int convertCharToInt(const char& ch) {
	return ch - '0';
}

convertedString convertStringToInt(const char* str) {
	convertedString res;
	if (str == nullptr) {
		res.error = errorCode::pointerIsNull;
		return res;
	}
	int i = 0;
	unsigned num = 0;
	while (str[i] != '\0') {
		if (!isItAnInt(str[i])) {
			res.error = errorCode::invalidCharInStr;
			return res;
		}
		num *= 10;
		num += convertCharToInt(str[i]);
		i++;
	}
	res.result = num;
	return res;
}

int main()
{
	const char* str = "11456";

	convertedString res = convertStringToInt(str);
	if (res.error == 0) {
		std::cout << "Our converted number is: " << res.result;
	}
	else {
		std::cout << "Error!";
	}

	return 0;
}
