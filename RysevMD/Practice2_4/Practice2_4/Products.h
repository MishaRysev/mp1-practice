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

struct Pair {
	TProduct product;
	int count;
};

class TProductBase {
private:
	int count;
	TContainer <Pair> pairs;
public:
	TProductBase(string& path);
	~TProductBase();

	long int FindCode(string name) const;
	string FindName(long int code) const;

	friend ostream& operator << (ostream& out, const TProduct element);
	friend ostream& operator << (ostream& out, const Pair element);
	friend istream& operator >> (istream& out, TProduct element);
};
#endif

