#include <bits/stdc++.h>
using namespace std;

//this is a O(nlogn) algorithm
int main(){
 string s;
 cin >> s;
 int ans[s.length()];
 fill(ans, ans + s.length(), 0);
 //go through each child and place him in the right index
 //if child is on R, find the first instance of L on the right
 //if index of child mod 2 is the same as the first L, arr[indexL]++
 //otherwise, arr[indexL - 1]++
 //same with if child is on L but find first instance of R on the left
 vector<int> rArr;
 vector<int> lArr;
 
 for(int i = 0; i < s.length(); i++){
	 if(s[i] == 'R'){
		rArr.push_back(s.length() - 1 - i);
	 } else {
		lArr.push_back(i);
	 }
 }
 sort(rArr.begin(), rArr.end());
   
 for(int i = 0; i < s.length(); i++){
	 auto l = upper_bound(lArr.begin(), lArr.end(), i);
	 //cout << "index of L: "<< *l << endl;
	 auto r = upper_bound(rArr.begin(), rArr.end(), s.length() - 1 - i);
	 //cout << "index of R: " << *r << endl;
 	if(s[i] == 'R' && abs(i - *l)%2 == 0){
		 ans[*l]++;
	 } else if (s[i] == 'R' && abs(i - *l)%2 == 1){
		 ans[*l - 1]++;
	 } else if (s[i] == 'L' && (abs((int)s.length() - 1 - i - *r))%2 == 0){
		 ans[s.length() - 1 - *r]++; 
	 } else {
		 ans[s.length() - *r]++;
	 }
 }
 
 for (int i = 0; i < s.length(); i++){
	cout << ans[i] << " ";
 }
 
 cout << "\n";
}

//following is a O(n^2) algorithm
void inefficient(){
	string s;
	cin >> s;
	int ans[s.length()];
	fill(ans, ans + s.length(), 1);

	int iterNum;
	if(s.length()%2 == 0){
		iterNum = s.length();
	} else {
		iterNum = s.length() + 1;
	}

	int tmp[s.length()];
	copy(ans, ans + s.length(), tmp);

	for (int j = 0; j < iterNum; j++){
	
//	for (int i = 0; i < s.length(); i++){
//		cout << ans[i] << " ";
//	}
//	cout << endl;
	for (int i = 0; i < s.length(); i++){
		if (ans[i] == 0) continue;
		if(i == 0){
			ans[0]-=tmp[i];
			ans[1]+=tmp[i];
		} else if (i == s.length()-1){
			ans[s.length() - 1]-=tmp[i];
			ans[s.length() - 2]+=tmp[i];
		} else {
			if(s[i] == 'L'){
				ans[i - 1]+=tmp[i];
				ans[i]-=tmp[i];
			} else {
				ans[i + 1]+=tmp[i];
				ans[i]-=tmp[i];
			}
		}
	}
	copy(ans, ans + s.length(), tmp);
	}
	
	for (int i = 0; i < s.length(); i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
}
