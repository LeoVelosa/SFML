#include <iostream>
#include <string>

std::string letterEvaluator(char letter) {
	std::string res = "consonant";	

	if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
		res = "vowel";
	}
	return res;
}

int main() {
	char letter;

	std::cout << "\nThis program reads a character and tells you if it is a vowel or not.\n\nEnter a letter: ";

	std::cin >> letter;

	std::cout << letter << " is a " << letterEvaluator(letter) << "\n";

	return 0;
}
