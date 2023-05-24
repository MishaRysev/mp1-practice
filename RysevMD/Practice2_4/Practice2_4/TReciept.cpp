#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include "TRecieptLine.h"
#include "TContainer.h"
#include "TReciept.h"


using namespace std;

TReciept::TReciept(TContainer <Pair>& arr) {
	index = 0;
	sum = 0;
	count = arr.GetSize();
	ltm = nullptr;
	time_t now = time(0);
	TRecieptLine *tmp;
	for (int i = 0; i < count; i++) {
		sum += arr[i].product.cost * (1 - arr[i].product.disc) * arr[i].count;
		tmp = new TRecieptLine(arr[i]);
		lines.insert(*tmp, i);
		index += 1;
	}
}

void TReciept::AddLine(const Pair& pair) {
	TRecieptLine tmp(pair);
	lines.insert(pair, index);
	index += 1;
}
void TReciept::DelLine(int index){
	for (int i = index; i < count; i++) {
		lines[i] = lines[i + 1];
	}
	count -= 1;
}

ostream& operator << (ostream& out, const TReciept& reciept) {
	for (int i = 0; i < reciept.count; i++) {
		out << reciept.lines[i] << endl;
	}
	cout << "Total cost: " << reciept.sum;
	return out;
}