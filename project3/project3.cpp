// project3.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>

using std::cout;
using std::endl;

std::vector<std::string> parse(std::string data) {

	std::vector<std::string> res;

	data += ",";
	std::string current_piece = "";

	for (int i = 0; i < (int)data.size(); i++) {
		if (data[i] == ',') {
			res.push_back(current_piece);
			current_piece.clear();
			continue;
		}
		current_piece += data[i];
	}
	return res;
}

enum TerritoryType { NORMAL, PREMIUM };

namespace piece_casts {

	int to_int(std::string s) {
		int res = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			res = 10 * res + s[i] - '0';
		}
		return res;
	}
	long to_long(std::string s) {
		long res = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			res = 10 * res + s[i] - '0';
		}
		return res;
	}
	TerritoryType to_ttype(std::string s) {
		return s[0] == 'N' ? NORMAL : PREMIUM;
	}
}
struct Territory {
	int territoryid;
	long amount;
	TerritoryType type;

	Territory(std::string _territoryid, std::string _type) :
		territoryid(piece_casts::to_int(_territoryid)),
		type(piece_casts::to_ttype(_type)),
		amount(0) {}
};

struct Transaction {
	int trxid;
	int salerepid;
	int transactiontype;
	long amount;

	Transaction(std::string _trxid, std::string _salerepid, std::string _transactiontype, std::string _amount):
		trxid(piece_casts::to_int(_trxid)),
		salerepid(piece_casts::to_int(_salerepid)),
		transactiontype(piece_casts::to_int(_transactiontype)),
		amount(piece_casts::to_long(_amount)) { }
};


struct Salerep {
	int salerepid;
	int territoryid;
	long amount;

	Salerep(std::string _salerepid, std::string _territoryid, std::string _amount) :
		salerepid(piece_casts::to_int(_salerepid)),
		territoryid(piece_casts::to_int(_territoryid)),
		amount(piece_casts::to_long(_amount)) { }
};

bool compare_territories(const Territory & a, const Territory & b)
{
	return a.amount > b.amount;
}

bool compare_salereps(const Salerep &a, const Salerep &b) {
	return a.amount > b.amount;
}

std::string make_formatted(long x, int len) {
	std::string s = "";

	while (x > 0) {
		s = (char)('0' + x % 10) + s;
		x /= 10;
	}
	while ((int)s.size() < len) {
		s = "0" + s;
	}
	return s;
}
int main(int argc, char *argv[])
{
	std::string data;
	std::ifstream territory_input(argv[1]);
	std::vector<Territory> territories;
	while (territory_input >> data) {
		std::vector<std::string> p = parse(data);
		territories.push_back(Territory(p[0], p[1]));
	}

	std::ifstream salerep_input(argv[2]);
	std::vector<Salerep> salereps;
	while (salerep_input >> data) {
		std::vector<std::string> p = parse(data);
		salereps.push_back(Salerep(p[0], p[1], p[2]));
	}

	std::ifstream transaction_input(argv[3]);
	while (transaction_input >> data) {
		std::vector<std::string> p;
		Transaction t = Transaction(p[0], p[1], p[2], p[3]);

		long tP, sP, sgn;

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

		for ( unsigned int i = 0; i < (int)territories.size(); i++) {
			if (territories[i].territoryid == t.trxid) {
				territories[i].amount += sgn * (tP * t.amount / 100);
			}
		}
		for ( unsigned int i = 0; i < (int)salereps.size(); i++) {
			if (salereps[i].salerepid == t.salerepid) {
				salereps[i].amount += sgn * (sP * t.amount / 100);
			}
		}
	 }

	// output territories in territory_output
	std::ofstream territory_output(argv[4]);
	std::sort(territories.begin(), territories.end(), compare_territories);
	for (unsigned int i = 0; i < (int)territories.size(); i++) {
		territory_output << make_formatted(territories[i].territoryid, 4) << "," <<
			make_formatted(territories[i].amount, 7) << "\n";
	}
	// output salereps in stdout
	std::sort(salereps.begin(), salereps.end(), compare_salereps);
	for (unsigned int i = 0; i < (int)salereps.size(); i++) {
		std::cout << make_formatted(salereps[i].salerepid, 4) << "," <<
			make_formatted(salereps[i].amount, 7) << "\n";
	}
	return 0;
}