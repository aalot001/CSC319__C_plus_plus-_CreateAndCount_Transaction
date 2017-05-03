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
//  territory.txt salerep.txt transactions.txt territory_output.txt

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

	Transaction(string _trxid, string _salerepid, string _transactiontype, string _amount):
		trxid(piece_casts::to_int(_trxid)),
		salerepid(piece_casts::to_int(_salerepid)),
		transactiontype(piece_casts::to_int(_transactiontype)),
		amount(piece_casts::to_long(_amount)) { }
};


struct Salerep {
	int salerepid;
	int territoryid;
	long amount;

	Salerep(string _salerepid, string _territoryid, string _amount) :
		salerepid(piece_casts::to_int(_salerepid)),
		territoryid(piece_casts::to_int(_territoryid)),
		amount(piece_casts::to_long(_amount)) { }
};

bool compare_salereps(const Salerep &a, const Salerep &b) {
	return a.amount > b.amount;
}

int main(int argc, char *argv[])
{
	string data;
	ifstream territory_input(argv[1]);
	vector<Territory> territories;
	while (territory_input >> data) {
		vector<string> p;
		territories.push_back(Territory(p[0], p[1]));
	}

	ifstream salerep_input(argv[2]);
	vector<Salerep> salereps;
	while (salerep_input >> data) {
		vector<string> p;
		salereps.push_back(Salerep(p[0], p[1], p[2]));
	}

	ifstream transaction_input(argv[2]);
	while (transaction_input >> data) {
		vector<string> p;
		Transaction t = Transaction(p[0], p[1], p[2], p[3]);

		long long tP, sP, sgn;

		if (t.transactiontype <= 2) {
			tP = 100;
			sP = 110;
			sgn = 1;
		}
		if (t.transactiontype == 3) {
			tP = 100;
			sP = 100;
			sgn = -1;
		}
		if (t.transactiontype == 4) {
			tP = 100;
			sP = 125;
			sgn = 0;
		}
		if (t.transactiontype == 5) {
			tP = 100;
			sP = 0;
			sgn = -1;
		}
		if (t.transactiontype == 6) {
			tP = 100;
			sP = 110;
			sgn = -1;
		}
		if (t.transactiontype == 7) {
			tP = 0;
			sP = 75;
			sgn = +1;
		}

		for (int i = 0; i < (int)territories.size(); i++) {
			if (territories[i].territoryid == t.trxid) {
				territories[i].amount += sgn * (tP * t.amount / 100);
			}
		}
		for (int i = 0; i < (int)salereps.size(); i++) {
			if (salereps[i].salerepid == t.salerepid) {
				salereps[i].amount += sgn * (sP * t.amount / 100);
			}
		}
	}
	return 0;
}