#include <iostream>
#include "TContainer.h"
#include "Products.h"

using namespace std;

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
	disc = _disc;
}

