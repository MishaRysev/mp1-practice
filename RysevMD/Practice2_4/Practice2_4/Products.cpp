#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "TContainer.h"
#include "Products.h"
#include "shop.h"

using namespace std;

ostream& operator << (ostream& out, const TProduct element) {
	out << left << setw(7) << element.name << left << setw(7) << element.cost << left << setw(9) << element.cost * (1 - element.disc);
	return out;
}
ostream& operator << (ostream& out, const Pair element) {
	out << element.product << " " <<  element.count;
	return out;
}

istream& operator >> (istream& in, Pair& element) {
	in >> element.product >> element.count;
	element.product.disc /= 100;
	return in;
}
istream& operator >> (istream& in, TProduct& product) {
	in >> product.code >> product.name >> product.cost >> product.disc;
	return in;
}

TProduct& TProduct::operator = (const TProduct& element) {
	code = element.code;
	name = element.name;
	cost = element.cost;
	disc = element.disc;
	return *this;
}
bool TProduct::operator == (const TProduct& element) {
	if (code != element.code) return false;
	return true;
}

Pair& Pair::operator = (const Pair& pair) {
	count = pair.count;
	product = pair.product;
	return *this;
}
bool Pair::operator == (const Pair& pair) {
	if (count == pair.count && product == pair.product) return true;
	return false;
}

Pair::Pair() { count = 0; }
TProduct::TProduct() {
	code = 0;
	name = "";
	cost = 0.0;
	disc = 0.0;
}
TProduct::TProduct(long _code, string _name, double _cost, double _disc) {
	code = _code;
	name = _name;
	cost = _cost;
	disc = _disc / 100;
}

TProductBase::TProductBase(string& path) {
	ifstream in;
	Pair tmp;
	char flag = 1;
	string miss;
	in.open(path);
	do {
		if (in.is_open()) {
			in >> count;
			for (int i = 0; i < count; i++) {
				in >> tmp;
				pairs.insert(tmp, i);
			}
			in.close();
			flag = 0;
		}
		else { 
			cout << "File not found" << endl;
			getline(in, miss);
			ReadPath(path);
			in.open(path);
		}
	} while (flag == 1);
}
long int TProductBase::FindIndex(string name) const{
	for (int i = 0; i < count; i++) {
		if (name == pairs[i].product.name) return i;
	}
	return -1;
}
long int TProductBase::FindIndex(long int code) const {
	for (int i = 0; i < count; i++) {
		if (code == pairs[i].product.code) return i;
	}
	return -1;
}