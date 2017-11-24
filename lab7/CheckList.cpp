#include <iostream>
#include "./TList/TList.h"

using namespace std;

int main() {
	//Figure *ptr;
	//TList<Figure> a;
	//TList<int> z;
	/*for (int i = 0; i < 10; i++) {
		ptr = new Square(i);
		a.PushBack(*ptr);
		//z.PushBack(i);
	}
    for (auto i:a) {
		cout << i.GetValue().Area() << "\t";
	}*/
	TList<int> a;
	for (int i = 0; i < 10; i++) {
		int *p = new int(i);
		a.PushBack(*p);
	}
	for (auto i:a) {
		cout << i.GetValue() << "\t";
	}
	return 0;
}