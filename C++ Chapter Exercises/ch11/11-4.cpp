#include <iostream>

int count_bits(const int number) {
	int bits_set = 0;
	int bit;
	for(bit = 0x80; bit > 0; bit = (bit >> 1)) {
		if((number & bit) != 0){
			bits_set += 1;
		}
	}
	return bits_set;
}	

int main() {
	int number;
	
	std::cout << "\nThis program counts the number of bits set in a number" << "\n\nEnter a number: ";

	std::cin >> number;

	std::cout << "\nBits set in " << number << ": " << count_bits(number) << '\n';

	return 0;
}
