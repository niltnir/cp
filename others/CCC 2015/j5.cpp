#include <bits/stdc++.h>

using namespace std;

int part(int numPie, int k);

int main(){
	int numPie;
	int k;
	cin >> numPie >> k;
	int ans = part(numPie, k);
	cout << ans << "\n";
}

//partitions assume no boxes are empty
int part(int numPie, int k){
	if(numPie >= k && k > 1){
		return (part(numPie-1, k-1) + part(numPie - k, k));
	} else if (numPie < k) {
		return 0;
	} else {
		return 1;
	}
	//part(n, k) = part(n-1, k-1) + part(n-k, k)
	//the partition of n can be split into 2 disjoint sets:
	//1. there exists a box that has exactly 1 ball
	// --> this can be done in part(n-1, k-1) ways
	//2. all boxes have at least 2 balls 
	// --> this can be done in part(n-k, k) ways
}

