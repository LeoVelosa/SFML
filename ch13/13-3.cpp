#include <iostream>

class queue {
	private:
		int data[100];
		int first;
		int last;

	public:
		queue();
		void put(int item);
		int get(void);

};

int main() {

	queue q;
	q.put(7);
	q.put(3);
	q.put(12);

	std::cout << '\n' << q.get() << '\n';
	std::cout << q.get() << '\n';

	return 0;
}

queue::queue() {
	first = 0;
	last = 0;
}

void queue::put(int item) {
	data[last] = item;
	last++;
}

int queue::get(void) {
	int f = first;
	first++;
	return data[f];
}
