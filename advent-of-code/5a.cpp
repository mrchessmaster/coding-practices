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
	int v;
	bool vowel;
	bool twice;
	bool nobad;
	for (int i=0; i<1000; i++){
		cin >> s;
		v = 0;
		vowel = false;
		twice = false;
		nobad = true;
		for (int j=0; j<16; j++){
			if ((s[j]=='a')||(s[j]=='e')||(s[j]=='i')||(s[j]=='o')||(s[j]=='u')){
				v++;
			}
			if (v >= 3) {
				vowel = true;
			}
			if ((j<15)&&(s[j]==s[j+1])) {
				twice = true;
			}
			if ((j<15)&&(((s[j]=='a')&&(s[j+1]=='b'))||((s[j]=='c')&&(s[j+1]=='d'))||((s[j]=='p')&&(s[j+1]=='q'))||((s[j]=='x')&&(s[j+1]=='y')))) {
				nobad = false;
			}
		}
		if (vowel&&twice&&nobad){
			n++;
		}
	}
	cout << n << endl;
	return 0;
}