#include <bits/stdc++.h>
using namespace std;

// cleaner solution is to define a function f(n) that counts the number of
// multiples of x between 0 and n. then, the desired value becomes f(b) -
// f(a-1), where f(-1) = 0 when a = 0.
int main() {
  long long int a, b, x;
  cin >> a >> b >> x;
  long long int ans = 0;
  long long int l = b - (b % x);
  long long int s = a + x - (a % x);
  // int l = b - (b % x) biggest multiple of x <= b
  // int s = a + x - (a % x) smallest multiple of x > a
  // ans = (l - s)/x + 1;

  if (a == b && a % x == 0) {
    ans = 2;
    /* cout << "1 was triggered!" << endl; */
  } else if (a == b && a % x != 0) {
    ans = 0;
    /* cout << "2 was triggered!" << endl; */
  } else if (a != b && b - a < x) {
    if ((a <= x && x <= b) || (a % x == 0 || b % x == 0)) {
      ans = 1;
    } else if (x > b) {
      ans = 0;
    } else {
      if (b % x - a % x < 0) {
        ans = 1;
      } else {
        ans = 0;
      }
    }
    /* cout << "3 was triggered!" << endl; */
  } else if (a != b && b - a >= x && a % x == 0) {
    ans = (l - a) / x + 1;
    /* cout << "4 was triggered!" << endl; */
  } else {
    ans = (l - s) / x + 1;
    /* cout << "5 was triggered!" << endl; */
  }

  cout << ans << "\n";
}

// a = 47, b = 60, x = 6
// s = 48, l = 60
// (l - s)/x = 12/6 = 2
// 1 + 2 = 3
