#include <iostream>

struct date_and_time {
	int year;
	int month;
	int day;
	int hour;
	int minute;
};

int Get_Total(date_and_time dt) {
	int total;

	total = (dt.year * 525600) + (dt.month * 43800) + (dt.day * 1440) + (dt.hour * 60) + dt.minute;

	return total;
}

int Time_Difference(date_and_time a, date_and_time b) {
	int diff;

	diff = Get_Total(a) - Get_Total(b);
	
	return diff;
}

int main() {
	date_and_time a = {
		2022,
		2,
		24,
		17,
		42
	};

	date_and_time b = {
		2010,
		6,
		12,
		13,
		25
	};


	std::cout << "\nThis program takes two dates and times and finds the difference in minutes\n\n";
		
	std::cout << "Time Difference: " << Time_Difference(a, b) << "\n\n";

	return 0;
}
