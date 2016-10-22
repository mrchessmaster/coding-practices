#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <map>

using namespace std;
	


vector<int> strtoi(string q);

char encrypt(char, int);

int main() {

	//ofstream fout("1a.out");
	//ifstream fin("1a.in");

	string l; string msg; string skey;
	getline(cin, l);
	for (int i=0; i<l.size(); i++) {
		if (l[i] == '|') {
			skey = l.substr(i+1);
			msg = l.substr(0,l.size()-skey.size()-1);
		}
	}

	vector<int> key = strtoi(skey);


	int p = 0;
	for (int i=0; i<msg.size(); i++) {
		cout << encrypt(msg[i],key[p]);
		if (p == 4) {
			p = 0;
		} else {
			p++;
		}
	}
	cout << endl;
	return 0;
}

char encrypt(char c, int w) {
	//(h % 26)

}

vector<int> strtoi(string q) {
	map<char, int> mapkey;
mapkey['A'] = 0;
mapkey['B'] = 1;
mapkey['C'] = 2;
mapkey['D'] = 3;
mapkey['E'] = 4;
mapkey['F'] = 5;
mapkey['G'] = 6;
mapkey['H'] = 7;
mapkey['I'] = 8;
mapkey['J'] = 9;
mapkey['K'] = 10;
mapkey['L'] = 11;
mapkey['M'] = 12;
mapkey['N'] = 13;
mapkey['O'] = 14;
mapkey['P'] = 15;
mapkey['Q'] = 16;
mapkey['R'] = 17;
mapkey['S'] = 18;
mapkey['T'] = 19;
mapkey['U'] = 20;
mapkey['V'] = 21;
mapkey['W'] = 22;
mapkey['X'] = 23;
mapkey['Y'] = 24;
mapkey['Z'] = 25;
	vector<int> keytemp;
	for (int j=0; j<q.size(); j++) {
		keytemp.push_back(mapkey[q[j]]);
	}


	return keytemp;
}






