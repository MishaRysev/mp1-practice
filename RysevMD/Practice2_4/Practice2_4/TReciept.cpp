#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>
#include "TRecieptLine.h"
#include "TContainer.h"
#include "TReciept.h"

using namespace std;

TReciept::TReciept(TContainer <Pair>& arr) {
	index = 0;
	sum = 0;
	count = arr.GetSize();
	ltm = nullptr;
	time_t now = time(0);
	TRecieptLine *tmp;
	for (int i = 0; i < count; i++) {
		sum += arr[i].product.cost * (1 - arr[i].product.disc) * arr[i].count;
		tmp = new TRecieptLine(arr[i]);
		lines.insert(*tmp, i);
		index += 1;
	}
}

void TReciept::AddLine(const Pair& pair) {
	TRecieptLine tmp(pair);
	lines.insert(pair, index);
	index += 1;
}
void TReciept::DelLine(int index){
	for (int i = index; i < count; i++) {
		lines[i] = lines[i + 1];
	}
	count -= 1;
}

ostream& operator << (ostream& out, const tm* ltm) {
	time_t now = time(0);
	ltm = localtime(&now);
	string day = to_string(ltm->tm_mday);
	string month = to_string(ltm->tm_mon + 1);
	string year = to_string(ltm->tm_year + 1900);
	string min = to_string(ltm->tm_min);
	string hour = to_string(ltm->tm_hour);
	string sec = to_string(ltm->tm_sec);
	out << "|" << setw(8) << setfill(' ') << right << "" << setw(3) << setfill('0') << right << day + "." << setw(3) << 
		right << month + "." << setw(4) << year << setw(23) << setfill(' ') << " |" << endl;
	out << "|" << setw(8) << right << "" << setw(3) << setfill('0') << right << hour + ":" << setw(3) << right << min + ":" << 
		setw(2) << right << sec << setfill(' ') << setw(25) << " |" << endl;
	return out;
}
ostream& operator << (ostream& out, const TReciept& reciept) {
	int n = to_string(reciept.sum).length();
	out << " " << setw(41) << setfill('_') << " " << setfill(' ') << "\n";
	out << "|" << setw(40) << setfill(' ') << " " << "|" << endl;
	for (int i = 0; i < reciept.count; i++) {
		out << "|   " << reciept.lines[i] << "|" << endl;
	}
	out << "|" << setw(40) << setfill('_') << "" << setfill(' ') << "|" << endl;
	out << "|" << setw(40) << setfill(' ') << " " << "|" << endl;
	out << "|" << setw(20) << right << "Total cost: " << setw(n) << left << reciept.sum << setw(21 - n) << right << "|" << endl;
	out << reciept.ltm;
	out << "|" << setw(40) << setfill('_') << "" << setfill(' ') << "|" << endl;
	return out;
}