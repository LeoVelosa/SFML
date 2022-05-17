#include <iostream>

class pig {
	private:
		static int pig_count;
	
	public:
		pig() {
			++pig_count;
		}
		static int get_count(void) {
        		return pig_count;
		}
};

class horse {
	private:
		static int horse_count;

	public:
		horse() {
			++horse_count;
		}
		static int get_count(void) {
        		return horse_count;
		}
};

class dog {
	private:
		static int dog_count;

	public:
		dog() {
			++dog_count;
		}
		static int get_count(void) {
        		return dog_count;
		}
};

int main() {

	int get_total_count(void);

	//pig p1 = new pig();
	//pig p2 = new pig();
	//horse h1 = new horse();
	//horse h2 = new horse();
	//horse h3 = new horse();
	//dog d1 = new dog();

	int total = pig::get_count() + horse::get_count() + dog::get_count();
	std::cout << '\n' << "total 1:" << total;

	//std::cout << '\n' << get_total_count();

	return 0;
}

int get_total_count(void) {
        //int total = pig::get_count() + horse::get_count() + dog::get_count();
        //return total;
}
