#include <iostream>
#include "TContainer.h"
#include "Products.h"

using namespace std;

int main() {
	TContainer <TProduct> prod(1);
	TProduct p(12321, "тест", 50, 0);
	prod.insert(p, 0);
	return 0;
}