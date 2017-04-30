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


struct Territory {
	int territoryid;
	long amount;
};

struct Transaction {
	int trxid;
	int salerepid;
	int transactiontype;
	long amount;
};

struct Salerep {
	int saleepid;
	int territoryid;
	long amount;
};

int main(int argc, char *argv[])
{
	cout << argv << endl;
	cout << argv[0] << endl;
	cout << argv[1] << endl;
	cout << argv[2] << endl;
	
	return 0;
}
