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

enum TerritoryType { NORMAL, PREMIUM }; 

struct Territory {
	int territoryid;
	long amount;
	TerritoryType type;

	Territory(string _territoryid = 0, string _type = "");

		TerritoryType to_ttype(string _type);
		bool compare_territories(const Territory &a, const Territory &b);
};

// Not sure ... 
Territory::Territory(string _territoryid, string _type)
{
	ifstream territory_input("territory.txt");
	string s;
	vector<Territory> line;
	if (!territory_input.is_open()) {
		cerr << "Cannot open: territory.txt" << endl;
	}
	while (territory_input >> s) {
		vector<string> p;
		line.push_back(Territory(p[0], p[1]));
	}
	/*int res = 0;
	for (unsigned int i = 0; i < line.size(); i++) {
		res = 10 * res + s[i] - '0';
		break;
		cout << res << endl;
	}*/
}

TerritoryType Territory::to_ttype(string _type)
{
	cout << _type << endl;
	return _type[0] == 'N' ? NORMAL : PREMIUM;
}

bool Territory::compare_territories(const Territory & a, const Territory & b)
{
	return a.amount > b.amount;
}

struct Transaction {
	int trxid;
	int salerepid;
	int transactiontype;
	long amount;
	

	Transaction() {}
};


struct Salerep {
	int saleepid;
	int territoryid;
	long amount;

	Salerep() {}
};

int main(int argc, char *argv[])
{
	cout << argc << endl;
	cout <<"Argv[0]: "<< argv[0] << endl;
	cout <<"Argv[1]: "<< argv[1] << endl;
	cout <<"Argv[2]: "<< argv[2] << endl;
	cout << "Argv[3]: " << argv[3] << endl;
	cout << "Argv[4]: " << argv[4] << endl;

	return 0;
}
