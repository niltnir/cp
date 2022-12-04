#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	
	long long int ans = 0;
	if(s[0] == '>' && s[s.length()-1] == '>'){
		s = '<' + s + '<';
		ans = -1;
	} else if(s[0] == '<' && s[s.length() - 1] == '>'){
		s = s + '<';
		ans = -1;
	} else if(s[0] == '>' && s[s.length() - 1] == '<'){
		s = '<' + s;
	}

	vector<long long int> up;
	vector<long long int> down;

	long long int upStreak = 0;
	long long int downStreak = 0;
	char prevSym = s[0];
	for(int i=0; i<s.length(); i++){
		if(s[i]== '>'){
			downStreak++;
			if(prevSym == '<'){
				up.push_back(upStreak);
				upStreak = 0;
			}
		} else {
			upStreak++;
			if(prevSym == '>'){
				down.push_back(downStreak);
				downStreak = 0;
			}
		}

		if(i == s.length() - 1){
			up.push_back(upStreak);
			down.push_back(downStreak);
		}
		prevSym = s[i];

	}
	for(int i = 0; i < up.size(); i++){
//		cout << "up streak: " << up.at(i) << endl;
//		cout << "down streak: " << down.at(i) << endl;
		long long int g;
		long long int l;
		if(up.at(i) > down.at(i)){
			g = up.at(i);
			l = down.at(i);
		} else {
			g = down.at(i);
			l = up.at(i);
		}
		ans += ((long long int)g*(g+1)/2)+((long long int)(l-1)*(l)/2);
	}
	cout << ans << endl;
	
}
