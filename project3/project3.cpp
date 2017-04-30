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

// Can we use namespace gloabl as function?..! 
// We need to include enumeration..!!!
// https://msdn.microsoft.com/en-us/library/5cb46ksf.aspx

class transaction {

protected:
	long trxid, salerepid, amount;
	int transaction_type, pos;
public:

	transaction(long _trxid = 0, long _salerepid = 0, long _amount = 0, int _transaction_type = 0) {
		trxid = _trxid; salerepid = _salerepid;
		amount = _amount; transaction_type = _transaction_type;
	}
	void read_write();

	//Do we need getter and setter ?

	//How we can pass the data members to each part in the line?

};
void transaction::read_write()
{
	ifstream file("transaction.txt", ios_base::in);
	ofstream outputFile("territory_output.txt");
	typedef vector<string> lines;
	string line;
	vector<lines> array;
	while (getline(file, line)) {
		lines in;
		while ((pos = line.find(',')) > 0) {
			string field = line.substr(0, pos);
			line = line.substr(pos + 1);
			in.push_back(field);
		}
		in.push_back(line);
		array.push_back(in);
	}
	for (unsigned int i = 0; i < array.size(); i++) {
		vector <string> transactions = array.at(i);
		outputFile << transactions.at(0) << " " << transactions.at(1) << " " << transactions.at(2) << " "
			<< transactions.at(3) << endl;

		cout << transactions.at(0) << " " << transactions.at(1) << " " << transactions.at(2) << " "
			<< transactions.at(3) << endl;

	}
}
int main(int argc, char *argv[])
{
	cout << argv << endl;
	cout << argv[0] << endl;
	//cout << argv[1] << endl;
	//cout << argv[2] << endl;
	transaction t;
	t.read_write();
	return 0;
}
