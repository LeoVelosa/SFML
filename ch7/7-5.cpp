#include <iostream>

bool primeCheck(int number) {
        bool prime = true;
        for(int i=2;i<number-1;i++) {
                if((number % i) == 0) {
                        prime = false;
			break;
                }
        }
        return prime;
}

int main() {
	int number;
	std::cout << "\nThis program takes a number and tells you if its a prime number or not" << "\nEnter a number: ";

	std::cin >> number;

	if(primeCheck(number)){
		std::cout << number << " is prime\n";
	}
	else {
		std::cout << number << " is not prime\n";
	}

	return 0;
}
