#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; i++)	{
		cin>>a[i];
	}

	int ans=0;
	int tmp=1;
	for (int i = 0; i < n; i++)	{
		if (a[tmp-1]==2)	{
			ans++;
			cout<<ans<<endl;
			return 0;
			break;
		} else {
			tmp = a[tmp-1];
			ans++;
		}
	}

	cout<<-1<<endl;
}
