#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  int count = 0;
  int a = 0;
  int ba = 0;
  int b = 0;
  for (int i = 0; i < n; i++) {
    if (s[i][0] == 'B') {
      b++;
    }
    if (s[i][s[i].length() - 1] == 'A') {
      a++;
    }
    if (s[i][0] == 'B' && s[i][s[i].length() - 1] == 'A') {
      ba++;
    }
    for (int j = 0; j < s[i].length(); j++) {
      if (j != 0 && s[i][j - 1] == 'A' && s[i][j] == 'B') {
        count++;
      }
    }
  }

  if (ba - a == 0 && ba - b == 0 && ba > 0) {
    cout << count + ba - 1;
  } else {
    cout << count + min(a, b);
  }
}

/* xxxxxxA */
/* xxxxxxA */
/* xxxxxxA */
/* xxxxxxA */
/* BxxxxxA */
/* BxxxxxA */
/* BxxxxxA */
/* Bxxxxxx */
/* Bxxxxxx */
//
// a = 4, ba = 3, b = 2
//
// ans += min(a, b) //2
// ans += min(ba, abs(a - b)) //2 + 2 = 4 //what is left is either a few ba or a
// or b
// --> if ba left over, connect to self
// --> if a left over, just left over
// --> if b left over, just left over
// therefore, ans = min(a, b) + min(ba, abs(a - b))
//
//
//
// xxxxxxA
// BxxxxxA
// BxxxxxA
// BxxxxxA
// Bxxxxxx
//
//
