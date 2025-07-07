#include <iostream>

#include <DS/List.h>

int main(void) {
	DS::List<int> list{ 0, 1, 2, 3, 4 };

	for (int i = 5; i <= 100; i++) {
		list.pushCopy(i);
	}

	for (const auto& element : list) {
		std::cout << element; std::cout << ' ';
	}

	std::cout << '\n';

	auto last = list.pop();

	std::cout << *last << '\n';
}