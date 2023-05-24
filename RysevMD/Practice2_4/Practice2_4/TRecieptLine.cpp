#include <iostream>
#include <iomanip>
#include <fstream>
#include "TRecieptLine.h"
#include "TContainer.h"


using namespace std;

ostream& operator << (ostream& out, const TRecieptLine& line) {
	out << line.product << left << setw(7) << line.count << left << setw(7) << line.sum;
	return out;
}
TRecieptLine& TRecieptLine::operator = (const TRecieptLine& line) {
	count = line.count;
	sum = line.sum;
	product = line.product;
	return *this;
}
bool TRecieptLine::operator == (const TRecieptLine& line) {
	if (count == line.count && sum == line.sum && product == line.product) return true;
	return false;
}

TRecieptLine::TRecieptLine() {
	count = 0;
	sum = 0;
}
TRecieptLine::TRecieptLine(const Pair& _pair) {
	count = _pair.count;
	sum = _pair.product.cost * (1 - _pair.product.disc) * count;
	product = _pair.product;
}