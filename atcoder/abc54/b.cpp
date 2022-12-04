#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  string a[n], b[m];
  bool match[m][m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  if (n == m && n == 1) {
    n = 2;
  }

  int trueCounter = 0;
  for (int i = 0; i < n - m; i++) {
    for (int j = 0; j < n - m; j++) {
      for (int r = 0; r < m; r++) {
        for (int c = 0; c < m; c++) {
          if (a[i + r][j + c] == b[r][c]) {
            match[r][c] = true;
            trueCounter++;
          } else {
            match[r][c] = false;
            trueCounter = 0;
          }
          if (trueCounter == m * m) {
            cout << "Yes"
                 << "\n";
            return 0;
          }
        }
      }
      trueCounter = 0;
      fill(&match[0][0], &match[0][0] + sizeof(match), false);
    }
  }
  cout << "No"
       << "\n";
}
