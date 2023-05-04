#include <iostream>
#include "TContainer.h"

using namespace std;

int main() {
	Tcontainer <int> arr(10);

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		arr.size += 1;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	arr.insert(10, 1);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	arr.pozrem();
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	arr.pozrem(-1);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	arr.remove(0);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	arr.insert(10, 4);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	arr.pozins(11, 1);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}