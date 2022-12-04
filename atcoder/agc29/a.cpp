#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main(){
	string s;
	cin >> s;

	long long int numWhite = 0;
	long long int  ans = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'W'){
			ans += (i-numWhite);
			numWhite++;
		}
	}

	cout << ans << endl;
}
