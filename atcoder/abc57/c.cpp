#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int n;
  cin >> n;
  vector<long long int> factors;

  for (int i = 1; i < sqrt(n) + 1; i++) {
    if (n % i == 0) {
      factors.push_back(i);
    } else {
      continue;
    }
  }

  int fac1 = factors.back();
  int fac2 = n / factors.back();
  string a = to_string(fac1);
  string b = to_string(fac2);

  cout << max(a.length(), b.length()) << "\n";
}
