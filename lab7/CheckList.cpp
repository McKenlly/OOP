#include <iostream>
#include "./TList/TList.h"
using namespace std;

int main() {
	TList<int> a;
    int k;
    while (std::cin >>k) a.PushBack(k);

    for (auto i:a) {
		cout << i.GetValue() << "\t";
	}
	return 0;
}