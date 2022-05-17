#include <iostream>

const int X_SIZE = 40;
const int Y_SIZE = 40;

char graphics[X_SIZE / 8][Y_SIZE];

void inline clear_bit(const int x, const int y, const int bit) {
	graphics[x][y] = ~(~graphics[x][y] & bit);
}

void inline test_bit(const int x, const int y, const int bit) {
	if((graphics[x][y] & bit) != 0) {
		std::cout << "true";
	}
}

void inline set_bit(const int x, const int y) {
	graphics[(x)/8][y] |= (0x80 >> ((x)%8));
}

int main() {
	int loc;
	void print_graphics(void);

	for(loc = 0; loc<X_SIZE; ++loc) {
		set_bit(loc, loc);
	}
	
	print_graphics();

	test_bit(0, 0, 0);
	clear_bit(0, 0, 0);
	test_bit(0, 0, 0);
	return 0;
}

void print_graphics(void) {
	int x;
	int y;
	int bit;

	for(y=0;y<Y_SIZE;++y) {
		for(x=0;x<X_SIZE / 8; ++x) {
			for(bit = 0x80; bit > 0; bit = (bit >> 1)) {
				if((graphics[x][y] & bit) != 0) {
					std::cout << 'X';
				}
				else {
					std::cout << '.';
				}
			}
			std::cout << '\n';
		}
	}
}
