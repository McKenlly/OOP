#include <iostream>
#include "./TList/TList.h"

using namespace std;

int main() {
	Figure *ptr;
	TList<Figure> *a = new TList<Figure>;
	//TList<int> z;
	for (int i = 0; i < 2; i++) {
		ptr = new Square(i);
		a->PushBack(*ptr);
		//z.PushBack(i);
		//delete ptr;
	}
	for (auto i:*a) {
		std::cout << i.GetValue().Area() << std::endl;
	}
	TList<Figure> *p = new TList<Figure>(*a);
	for (auto i:*p) {
		std::cout << i.GetValue().Area() << std::endl;
	}
	std::cout << "Destroy a\n";
	delete a;
	//std::cout << "Print pointer List\n";
	//for (auto i:*p) {
	//	std::cout << i.GetValue().Area() << std::endl;
	//}
	//delete p;
//	TList<int> a;
//	for (int i = 0; i < 1; i++) {
//		int p = i;
//		a.PushBack(i);
//	}
	//TList<int> z(a);
//	for (auto i:z) {
//		std::cout << i.GetValue() << std::endl;
//	}
//	for (auto i:a) {
//		std::cout << i.GetValue() << std::endl;
//	}
	/*TList<int> *Vec = new TList<int>[2];
	for (int i = 10; i < 12; i++) {
		Vec[i-10].PushBack(i);
	}
	for (int i = 0; i < 2; i++) {
		std::cout << "TLIST: " << i << std::endl;
		for (auto g:Vec[i]) {
			std::cout << typeid(g.GetValue()).name() << std::endl;
		}
	}
	delete [] Vec;*/
	//Figure *ptr = new Square(10);
	//std::cout << typeid(ptr).name() << std::endl;

	return 0;
}