#include <iostream>
#include <string>

struct airline_reservation {
	int flight_number;
	std::string origin_airport_code;
	std::string dest_airport_code;
	int departure_time;
	int arrival_time;
};
const int reservations_size = 7;

airline_reservation reservations[reservations_size] = {
	{36, "JFK", "NYZ", 1200, 1700},
	{23, "LGA", "MIA", 900, 1400},
	{27, "LGA", "LAX", 300, 800},
	{32, "JFK", "MIA", 1700, 2300},
	{14, "MIA", "LGA", 1600, 2000},
	{16, "JFK", "MIA", 1300, 1800},
	{44, "MIA", "JFK", 1400, 1900}
};
void list_airlines(std::string a1) {
	int i;
	std::cout << '\n' << a1 << ":";
	for(i=0;i<reservations_size;i++) {
		if(reservations[i].origin_airport_code == a1) {
			std::cout << "\nFlight #" << reservations[i].flight_number;
		}
	}
	std::cout << '\n';
}

int main() {
	std::string airport1;
	std::string airport2;


	std::cout << "This program lists all the planes that are leaving from two specified airports\nEnter the first airports code: ";

	std::cin >> airport1;

	list_airlines(airport1);

	std::cout << "\nNow enter the second airports code: ";

	std::cin >> airport2;

	list_airlines(airport2);

	return 0;
}
