#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long int a[n];
  int counter = 0;
  long long int min = pow(10, 9);
  long long int ans = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0) {
      counter++;
      a[i] = -a[i];
    }
    if (a[i] < min) {
      min = a[i];
    }
    ans += a[i];
  }

  if (counter % 2 == 0) {
    cout << ans << "\n";
  } else {
    cout << ans - 2 * min << "\n";
  }
}
