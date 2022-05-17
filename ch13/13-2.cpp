#include <iostream>

class checkbook {
        private:
                int checks[100];
                int count = 0;

        public:
                void add_item(int amount);
                int total(void);
};

int main() {

	checkbook cb;
	cb.add_item(203);
	cb.add_item(806);
	cb.add_item(3345);

	std::cout << "\n\nThe total of your checkbook is: " << cb.total() << '\n'; 

	return 0;
}

void checkbook::add_item(int amount) {
	checks[count] = amount;
	count++;
}

int checkbook::total(void) {
	int total = 0;
	if(count == 0)
		std::cout << "There are no checks to add up";
	for(int i=0;i<count;i++) {
		total += checks[i];
	}
	return total;
}
