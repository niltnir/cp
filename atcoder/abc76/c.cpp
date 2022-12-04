#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int sl = s.length();
  int tl = t.length();
  bool found = false;
  if (tl > sl) {
    cout << "UNRESTORABLE"
         << "\n";
    return 0;
  }
  for (int i = sl - tl; i >= 0; i--) {
    for (int j = 0; j < tl; j++) {
      if (s[i + j] != '?' && s[i + j] != t[j]) {
        break;
      }
      if (j == tl - 1) {
        found = true;
        s.replace(i, tl, t);
        break;
      }
    }
    if (found) {
      break;
    }
  }

  if (found) {
    for (int i = 0; i < sl; i++) {
      if (s[i] == '?') {
        s[i] = 'a';
      }
    }
    cout << s << "\n";
  } else {
    cout << "UNRESTORABLE"
         << "\n";
  }
}
