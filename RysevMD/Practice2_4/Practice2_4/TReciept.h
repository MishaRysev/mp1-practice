#ifndef _TRC
#define _TRC
#include "TRecieptLine.h"

class TReciept {
private:
	tm* ltm;
	long int index;
	long int count;
	double sum;
	TContainer <TRecieptLine> lines;
public:
	TReciept(TContainer <Pair>& arr);

	void AddLine(const Pair& pair);
	void DelLine(int index);

	friend std::ostream& operator << (ostream& out, const TReciept& reciept);
};

#endif
