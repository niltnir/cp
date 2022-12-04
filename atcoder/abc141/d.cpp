#include <bits/stdc++.h>
using namespace std;
int getExp(int k);

int main() {
  int n, m;
  long long int ans = 0;
  cin >> n >> m;
  long long int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n, greater<>());

  // b[n] gets v_2 of all the prices
  int b[n];
  // O(n log a_i)
  for (int i = 0; i < n; i++) {
    b[i] = getExp(a[i]);
  }
  // example: int b[] = {8, 5, 5, 4, 2, 1};
  // convert to rotated ferrers O(n log a_i)
  int maxV = b[0]; // by specification, at most 30
  int fer[maxV];
  fill(fer, fer + maxV, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < b[i]; j++) {
      fer[j]++;
    }
  }
  // rotated ferrers:
  // {1, 1, 1, 3, 4, 4, 5, 6}
  // {{0}, {0}, {0}, {0, 1, 2}, {0, 1, 2, 3}, etc.}
  // while sum < k, run thru elements and add to tmp
  // we create an array divNum to store the number of times we divide each price
  // O(m)
  // k = 7, divNum = {5, 1, 1}
  int divNum[n];
  int tmp = 0, sum = 0;
  fill(divNum, divNum + n, 0);
  sort(fer, fer + maxV);
  // go thru fer O(log a_i)
  for (int i = 0; i < maxV; i++) {
    sum += fer[i];
    if (sum + fer[i + 1] >= m) {
      vector<pair<int, int>> c;
      // O(log a_i)
      for (int j = 0; j < fer[i]; j++) {
        c.push_back(make_pair(a[j] / pow(2, divNum[j]), j));
      }
      sort(c.begin(), c.end(), greater<>());
      for (int j = 0; j < c.size(); j++) {
        divNum[c[j].second]++;
        tmp++;
        if (tmp >= m)
          break;
      }
    } else {
      // go thru each element of fer O(log a_i)
      for (int j = 0; j < fer[i]; j++) {
        divNum[j]++;
        tmp++;
        if (tmp >= m)
          break;
      }
    }
    if (tmp >= m)
      break;
  }
  // finally, we divide each price by 2 an appropriate number of times
  // O(n)
  for (int i = 0; i < n; i++) {
    a[i] = a[i] / pow(2, divNum[i]);
  }

  ans += accumulate(a, a + n, ans);
  cout << ans << "\n";
}

int getExp(int k) {
  int ans = 0;
  while (k > 1) {
    k = k / 2;
    ans++;
  }
  return ans + 1;
}
