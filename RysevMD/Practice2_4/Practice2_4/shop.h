#ifndef _S
#define _S
#include <iostream>
#include "TReciept.h"

int InArr(TContainer <Pair>& arr, string& product);
void ElementSelection(TContainer <Pair>& arr, TProductBase& base);
void RecieptEditing(TReciept& reciept);
void instruction();
void ReadPath(std::string& path);
void RecPrint(TReciept& rec);

#endif
