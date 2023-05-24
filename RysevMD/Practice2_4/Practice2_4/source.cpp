#include <iostream>
#include <string>
#include <iomanip>
#include "shop.h"
#include "TContainer.h"
#include "Products.h"


using namespace std;

int InArr(TContainer <Pair>& arr, string& product) {
	for (int i = 0; i < arr.GetSize(); i++) {
		if (arr[i].product.name == product) return i;
	}
	return -1;
}
void repack(TContainer <Pair>& arr, int ind) {
	for (int i = ind; i < arr.GetSize(); i++) {
		arr[i] = arr[i + 1];
	}
	arr.SetSize(arr.GetSize() - 1);
}

void ElementSelection(TContainer <Pair>& arr, TProductBase& base) {
	string KeyWord, product, miss;
	Pair tmp;
	int count, ind, n;
	do {
		cout << ">>> ";
		cin >> KeyWord;
		if (KeyWord == "add") {
			cin >> product >> count;
			ind = InArr(arr, product);
			if (count > base.GetCount(ind)) cout << "This quantity is not available. " << base.GetCount(ind) << " left" << endl;
			else if (ind != -1) {
				arr[ind].count += count;
				base.SetCount(base.GetCount(ind) - count, ind);
			}
			else {
				n = base.FindIndex(product);
				if (n == -1) cout << "Product not found" << endl;
				else {
					ind = arr.GetSize();
					tmp.product = base[n].product;
					tmp.count = count;
					arr.insert(tmp, ind);
					base.SetCount(base.GetCount(ind) - count, ind);
				}
			}
		}
		else if (KeyWord == "sub") {
			cin >> product >> count;
			ind = InArr(arr, product);
			if (ind == -1) cout << "Product not found" << endl;
			else {
				if (count > arr[ind].count || count <= 0) cout << "Count Error. You have " << arr[ind].count << endl;
				else arr[ind].count -= count;
				if (arr[ind].count == 0) repack(arr, ind);
				base.SetCount(base.GetCount(ind) + count, ind);
			}
		}
		else if (KeyWord != "stop") {
			cout << "Key word not found" << endl;
			getline(cin, miss);
		}
	} while (KeyWord != "stop");
}
void RecieptEditing(TReciept& reciept) {
	string KeyWord, product;
	do {

	} while (KeyWord != "stop");
}
void ReadPath(string& path) {
	cout << "Enter the path" << endl << ">>> ";
	cin >> path;
}

void instruction() {
	cout << setw(80) << setfill('*') << "\n";
	cout << "*  " << setw(70) << right << "Use add <product> <count> to add a product or increase its quantity        *" << endl;
	cout << "*" << setw(78) << setfill(' ') << "*" << endl;
	cout << "*  " << setw(76) << right << "Use sub <product> <count> to to remove the product or reduce its quantity  *" << endl;
	cout << "*" << setw(78) << setfill(' ') << "*" << endl;
	cout << "*  " << setw(45) << right << "Use stop to stop editing the product basket or check                       *" << endl;
	cout << setw(80) << setfill('*') << " " << setfill(' ') << "\n";
}
