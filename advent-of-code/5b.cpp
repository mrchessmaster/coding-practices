#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;
	
int main(){
	int n = 0;
	string s;
	bool twicepair;
	bool twiceletter;
	string pair;
	for (int i=0; i<1000; i++){
		cin >> s;
		twicepair = false;
		twiceletter = false;
		for (int j=0; j<16; j++){
			if (j < 13) {
				pair = s.substr(j,2);
				for (int k=j+2; k<15; k++){
					if (pair == s.substr(k,2)){
						twicepair = true;
						break;
					}
				}	
			}
			if (j < 14) {
				if (s[j]==s[j+2]){
					twiceletter = true;
				}
			}
		}
		if (twiceletter&&twicepair){
			n++;
		}
	}
	cout << n << endl;
	return 0;
}