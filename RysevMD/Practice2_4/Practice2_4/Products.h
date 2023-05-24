#ifndef _Prod
#define _Prod
#include "TContainer.h"

using namespace std;

struct TProduct {
	long code;
	string name;
	double cost;
	double disc;

	TProduct();
	TProduct(long _code, string _name, double _cost, double _disc);

	friend istream& operator >> (istream& in, TProduct& product);
	friend ostream& operator << (ostream& out, const TProduct element);
	TProduct& operator = (const TProduct& element);
	bool operator == (const TProduct & element);
};

struct Pair {
	TProduct product;
	int count;

	Pair();
	friend ostream& operator << (ostream& out, const Pair element);
	friend istream& operator >> (istream& in, Pair& element);
	Pair& operator = (const Pair& pair);
	bool operator == (const Pair& pair);
};

class TProductBase {
private:
	int count = 0;
	TContainer <Pair> pairs;
public:
	TProductBase(string& path);
	Pair& operator [] (int i) const { return pairs[i]; }

	int GetCount(int i) const { return pairs[i].count; }
	void SetCount(int _count, int i) { pairs[i].count = _count; }

	long int FindIndex(string name) const;
	long int FindIndex(long int code) const;
};
#endif

