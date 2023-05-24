#ifndef _TRP
#define _TRP
#include "Products.h"
#include "TContainer.h"

using namespace std;

class TRecieptLine {
private:
	int count;
	double sum;
	TProduct product;
public:
	TRecieptLine();
	TRecieptLine(const Pair& _product);
	friend ostream& operator << (ostream& out, const TRecieptLine& line);
	TRecieptLine& operator = (const TRecieptLine& line);
	bool operator == (const TRecieptLine& line);
};

#endif
