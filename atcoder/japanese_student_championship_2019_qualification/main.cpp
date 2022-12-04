#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	long long int k;
	cin >> n >> k;
	int a[n];
	int initCount = 0;
	int count = 0;
	long long int ans = 0;

	//num of numbers that an element of the sequence is > than other values
	//following it within the first iteration
	for (int i = 0; i < n; i++){
		cin >> a[i];
		for(int j = 0; j < i; j++){
			//cout << "i, j: " << i << ", " << j << endl;
			if(a[j] > a[i]){
				initCount++;
			}
		}
	}

	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i] > a[j]){
				count++;
			}
		}
	}
	count = count % ((int)pow(10, 9)+7);
	//cout << "initCount: " << initCount << endl;
	//cout << "count: " << count << endl;
	//cout << "initCount * k: " << (initCount*k)%((long long int)pow(10, 9) + 7) << endl;
	//cout << "count * (k-1)k/2: " << count * (((k-1)*k/2)%((long long int)pow(10, 9) + 7)) << endl;

	ans += (initCount*k)%((long long int)pow(10, 9) + 7) + count * (((k-1)*k/2)%((long long int)pow(10, 9) + 7));

	ans = ans % ((long long int)pow(10, 9) + 7);
	cout << ans << "\n"; 
}
