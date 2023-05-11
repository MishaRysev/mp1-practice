#include <iostream>
#include <fstream>
#include "TContainer.h"
#include "Products.h"

using namespace std;

ostream& operator << (ostream& out, const TProduct element) {
	out << element.code << " " << element.name << " " << element.cost << " " << element.cost * (1 - element.disc);
	return out;
}
ostream& operator << (ostream& out, const Pair element) {
	out << element.product << " " << element.count;
}
istream& operator >> (istream& in, Pair element) {
	double tmp;
	in >> element.product.code >> element.product.name >> element.product.cost >> tmp;
	element.product.disc = tmp / 100;
	return in;
}

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
	in.open(path);
	if (in.is_open()) {
		in >> count;
		for (int i = 0; i < count; i++) {
			in >> tmp.product >> tmp.count;
			pairs.insert(tmp, i);
		}
		in.close();
	}
}
