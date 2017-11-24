#include <iostream>
#include "./TList/TList.h"

using namespace std;

int main() {
	Figure *ptr;
	TList<Figure> *a = new TList<Figure>;
	//TList<int> z;
	for (int i = 0; i < 10; i++) {
		ptr = new Square(rand()%10);
		a->PushBack(ptr);
		//z.PushBack(i);
		//delete ptr;
	}
	//for (auto i:*a) {
	//	std::cout << i-> << std::endl;
	//}
	//TList<Figure> *p = new TList<Figure>(*a);
	for (auto i:*a) {
		std::cout << i->Area() << std::endl;
	}
	a->Sort();
	for (auto i:*a) {
		std::cout << i->Area() << std::endl;
	}
	delete a;
	return 0;
}