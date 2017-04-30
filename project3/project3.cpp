// project3.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <ostream>
#include <vector>

using namespace std;

using std::cout;
using std::endl;
using std::ostream;
using std::ifstream;

//enum TerritoryType { NORMAL, PREMIUM }; // We need it: 

struct Territory {
	int territoryid = 2;
	long amount;
	void read();

	Territory() {
		territoryid = 0;
		amount = 0000;
		if (territoryid == 0) {
			cout << "I am zero: Territory struct: " << endl;
		}
	}
};

void Territory::read()
{
	cout << "Territory's Read function calls: " << endl;
	string data;
	ifstream territory("territory.txt");
	ofstream output("out00.txt");
	if (!territory.is_open()) {
		cerr << "cannot open the file: territory.txt" << endl;
	}
	else {
		cout << "Need to go over the file: Ready to read: " << endl;
	}
}

struct Transaction {
	int trxid = 5;
	int salerepid;
	int transactiontype;
	long amount;
	void read();

	Transaction() {
		trxid = 0;
		if (trxid == 0) {
			cout << "I am zero: Transaction struct: " << endl;
		}
	}
};


void Transaction::read()
{
	cout << "Transaction's read function calls: " << endl;
	string data;
	ifstream transaction;
	transaction.open("transaction.txt");
	ofstream output("out01.txt");

	if (!transaction.is_open()) {
		cerr << "cannot open the file: transaction.txt" << endl;
	}
	else {
		cout << "Need to go over the file: Ready to read: " << endl;
	}
}
struct Salerep {
	int saleepid;
	int territoryid;
	long amount;
};

int main(int argc, char *argv[])
{
	cout << argv << endl;
	cout << argv[0] << endl;
	//cout << argv[1] << endl;
	//cout << argv[2] << endl;
	Territory test;
	test.read();
	Transaction test01;
	test01.read();

	return 0;
}


