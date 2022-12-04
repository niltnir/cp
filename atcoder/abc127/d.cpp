#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  priority_queue<long long int, vector<long long int>, greater<long long int>>
      cards;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cards.push(a);
  }
  vector<pair<long long int, int>> edit;
  for (int i = 0; i < m; i++) {
    int b, c;
    cin >> b >> c;
    edit.push_back(make_pair(c, b));
  }
  // O(m log m)
  sort(edit.begin(), edit.end(), greater<>());

  // worst case for loop is m = 10^5
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < edit[i].second; j++) {
      if (edit[i].first > cards.top()) {
        cards.pop();
        cards.push(edit[i].first);
      } else {
        break;
      }
    }
  }

  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += cards.top();
    cards.pop();
  }

  cout << ans << "\n";
}
