#include <iostream>

float convert(float filesize) {
        float bytes = filesize * 1048576;
	float seconds = bytes * 960;
	float minutes = seconds / 60;
	float hours = minutes / 60;
	float days = hours / 24;
        return days;
}

int main() {
	int filesize;

	std::cout << "This program tells you how long your file will take to send." << "\nEnter your filesize here in MB: ";

	std::cin >> filesize;

	std::cout << convert(filesize) << " days\n";

	return 0;
}

