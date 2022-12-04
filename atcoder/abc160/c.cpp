#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main() {
	int k, n;
	cin>>k>>n;
	int a[n], max=0;
	for(int i=0; i < n; i++){
		cin >> a[i];
	}
	for(int i=0; i < n; i++){
		int diff = 0;
		if(i == n-1){
			diff = k - a[n-1] + a[0];	
		} else {
			diff = (abs(a[i+1] - a[i]))%k;
		}
		if(diff > max)max=diff; 
	}

	cout<<k-max<<endl;
}
