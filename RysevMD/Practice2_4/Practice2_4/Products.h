#ifndef _Prod
#define _Prod

using namespace std;

struct TProduct {
	long code;
	string name;
	double cost;
	double disc;
	TProduct(long _code, string _name, double _cost, double _disc);
	TProduct();
};

class TProductBase {
private:
	int count = 25;
	
};
#endif

