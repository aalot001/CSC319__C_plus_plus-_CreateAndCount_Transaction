// project3.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <ostream>
#include <vector>
#include <algorithm>

// https://msdn.microsoft.com/en-us/library/5cb46ksf.aspx

// Not sure which one of the following arugemnts are right to pass: 
// <territory.txt>,<salerep.txt>,<transactions.txt>,<territory_output.txt> 
// (territory.txt, salerep.txt, transactions.txt, territory_output.txt)

//using namespace std; 

using std::cout;
using std::endl;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::string;


enum TerritoryType { NORMAL, PREMIUM };


namespace piece_casts {

	int to_int(string s) {
		int res = 0;
		for (unsigned int i = 0; i < s.size(); i++) {
			res = 10 * res + s[i] - '0';
		}
		return res;
	}
	long to_long(string s) {
		long res = 0;
		for (unsigned int i = 0; i < s.size(); i++) {
			res = 10 * res + s[i] - '0';
		}
		return res;
	}
	TerritoryType to_ttype(string s) {
		return s[0] == 'N' ? NORMAL : PREMIUM;
	}
}
struct Territory {
	int territoryid;
	long amount;
	TerritoryType type;

	Territory(string _territoryid, string _type) :
		territoryid(piece_casts::to_int(_territoryid)),
		type(piece_casts::to_ttype(_type)),
		amount(0) {}
};

bool compare_territories(const Territory & a, const Territory & b)
{
	return a.amount > b.amount;
}

struct Transaction {
	int trxid;
	int salerepid;
	int transactiontype;
	long amount;

	Transaction(string _trxid, string _salerepid, string _transactiontype, string _amount) :
		trxid(piece_casts::to_int(_trxid)),
		salerepid(piece_casts::to_int(_salerepid)),
		transactiontype(piece_casts::to_int(_transactiontype)),
		amount(0) {}

};


struct Salerep {
	int saleepid;
	int territoryid;
	long amount;

	Salerep(string _saleepid, string _territoryid, string _amount) :
		saleepid(piece_casts::to_int(_saleepid)),
		territoryid(piece_casts::to_int(_territoryid)),
		amount(0) {}

};

int main(int argc, char *argv[])
{
	cout << argc << endl;
	//cout << "Argv[0]: " << argv[0] << endl;
	cout <<"Argv[1]: "<< argv[1] << endl;
	cout <<"Argv[2]: "<< argv[2] << endl;
	cout << "Argv[3]: " << argv[3] << endl;
	cout << "Argv[4]: " << argv[4] << endl;
	string data;
	ifstream territory_input(argv[1]);
	vector<Territory> territories;
	while (territory_input >> data) {
		vector<string> p;
		territories.push_back(Territory(p[0], p[1]));
	  }
	return 0;
}
