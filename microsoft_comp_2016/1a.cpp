#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <sstream>

using namespace std;

bool findb(char it, string curr);

int main() {

	//ofstream fout("1a.out");
	//ifstream fin("1a.in");

	ifstream file("Common-characters_InputForSubmission_2.txt");

	string ms;
	getline(file,ms);
	int m = stoi(ms);
	for (int k=0; k<m; k++) {
		string s;
		getline(file,s);
		istringstream iss(s);
		vector<string> s_arr;
		

		while (iss) {
			string sub;
			iss >> sub;
			s_arr.push_back(sub);
		}
		s_arr.pop_back();

		//cout << s_arr.at(0);

		//cout << s_arr.size();

		vector<char> common;

		string first_str = s_arr.at(0);
		for (int c = 0; c < first_str.size(); c++) {
			//cout << first_str.size();
			bool found = true;
			//cout << s_arr.size();


			for (int i=1; i<s_arr.size(); i++) {
				if(!findb(first_str[c], s_arr.at(i))) {
					found = false;
					break;
				}
			}
			if (found) {
				bool contain = false;
				for (int p =0; p<common.size(); p++) {
					if (common[p] == first_str[c]) {
						contain = true;
						break;
					}
				}
				if (!contain) {
					common.push_back(first_str[c]);
				}
			}
		}
		//common.pop_back();
		//int commonsize = common.size();
		unique(begin(common),end(common));

		sort(begin(common), end(common));

		//cout << common.size() << endl;

		if (common.size() == 0) {
			cout << endl;
		}


		for (int o=0; o<common.size(); o++) {
			cout << common[o];
			if (o == common.size()-1) {
				cout << endl;
			}
		}
	}

	//ofstream fout("1a.txt");
	return 0;
}

bool findb(char it, string curr) {
	for (int d = 0; d < curr.size(); d++) {
		if (it == curr[d]) {
			return true;
		}
	}
	return false;
}
