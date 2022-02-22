#include <iostream>

void printCheckerBoard(int x, int y) {
	for(int i=0;i<y;i++) {
		for(int i=0;i<x;i++) {
                	std::cout << "+-----";
        	}
        	std::cout << "+\n";
        	for(int i=0;i<3;i++) {
			for(int j=0;j<x;j++) {
                        	std::cout << "|     ";
                	}
			std::cout << "|\n";
		}
	}
	for(int i=0;i<x;i++) {
                std::cout << "+-----";
        }
        std::cout << "+\n";
}

int main() {
	int width;
	int height;

	std::cout << "\nThis program prints out a checkerboard with the given width and height.\n\nEnter the desired width: ";

	std::cin >> width;

	std::cout << "\nEnter the desired height: ";

	std::cin >> height;

	printCheckerBoard(width, height);
	return 0;
}
