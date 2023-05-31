#include <iostream>
#include <iomanip>
#include "shop.h"
#include "TContainer.h"
#include "TReciept.h"

using namespace std;

int main() {

	system("chcp 1251");

	string path;
	ReadPath(path);
	TProductBase base(path);
	TContainer <Pair> arr;

	instruction();
	ElementSelection(arr, base);
	TReciept reciept(arr);

	RecPrint(reciept);

	return 0;
}