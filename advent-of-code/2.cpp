#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;
	
int to_int(const string& s) {
	stringstream ss;
	ss << s;
	int res;
	ss >> res;
	ss.clear();
	return res;
}
int main(){
	int t; cin >> t;

	int v = 0;
	int l;
	int b[3];
	int acc;
	int xpos;
	for (int i=0; i < t; i++) {
		string p; cin >> p;

		l = p.length();
		acc = 0;
		xpos = -1;
		for (int j=0; j < l; j++) {
			if (p[j] == 'x') {
				b[acc] = to_int(p.substr(xpos+1,j-(xpos+1)));
				acc++;
				xpos = j;
			}
			if (acc == 2) {
				b[2] = to_int(p.substr(xpos+1,l-(xpos+1)));
			}
		}

		// Part 1:

		// int ha[3] = {b[0]*b[1], b[0]*b[2], b[1]*b[2]};
  //    	int min = ha[0];       // finding min val in array
  //    	for(int k = 1; k<3; k++) {
  //         	if(ha[k] < min) {
  //               min = ha[k];
  //    			}
  //    	}
  //    	int sum = 0;		// finding sum of all in array
  //    	for(int m=0; m<3; m++) {
  //    		sum+= ha[m];
  //    	}
		// v = v + 2*sum + min;

		// Part 2:

		int hp[3] = {b[0]+b[1], b[0]+b[2], b[1]+b[2]};
     	int minp = hp[0];       // finding min val in array
     	for(int k = 1; k<3; k++) {
          	if(hp[k] < minp) {
                minp = hp[k];
     			}
     	}
     	int vol = 1;		// finding product of array
     	for(int m=0; m<3; m++) {
     		vol = vol*b[m];
     	}
		v = v + vol + 2*minp;
	}
	cout << v << endl;
	return 0;
}