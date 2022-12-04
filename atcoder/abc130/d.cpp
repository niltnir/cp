#include <bits/stdc++.h>
using namespace std;

// only thing left to do is radically simplify the code...
int main() {
  int n;
  long long int k;
  cin >> n >> k;

  int a[n];
  int subS[n];
  vector<pair<int, int>> ind;
  int tmp = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tmp += a[i];
    if (tmp >= k) {
      // store index?
      ind.push_back({i, tmp});
      // cout << "ind: " << i << "," << tmp << endl;
      tmp = a[i];
    }
  }

  tmp = 0;
  for (int i = 0; i < ind.size(); i++) {
    /* cout << "ind " << i << ": " << ind[i].first << ", " << ind[i].second */
    /*      << endl; */
    if (i == ind.size() - 1 && i != 0) {
      for (int j = 0; j < ind[i].first - ind[i - 1].first + 1; j++) {
        if (j != 0) {
          tmp += a[j + ind[i - 1].first];
        }
        subS[j + ind[i - 1].first] = ind[i].second - tmp;
        /* cout << "subS[" << j + ind[i - 1].first */
        /*      << "]: " << subS[j + ind[i - 1].first] << endl; */
      }
    } else if (i == 0) {
      for (int j = 0; j < ind[i].first; j++) {
        if (j != 0) {
          tmp += a[j - 1];
        }
        /* cout << "tmp: " << tmp << endl; */
        subS[j] = ind[i].second - a[ind[i].first] - tmp;
        /* cout << "subS[" << j << "]: " << subS[j] << endl; */
      }
    } else {
      for (int j = 0; j < ind[i].first - ind[i - 1].first; j++) {
        if (j != 0) {
          tmp += a[j + ind[i - 1].first];
        }
        subS[j + ind[i - 1].first] = ind[i].second - a[ind[i].first] - tmp;
        /* cout << "subS[" << j + ind[i - 1].first */
        /* << "]: " << subS[j + ind[i - 1].first] << endl; */
      }
    }
    tmp = 0;
  }

  long long int ans = 0;
  long long int sum = 0;
  // we can write a linear? time algorithm (w/ approx 2n comparisons)
  for (int i = 0; i < ind.size(); i++) {
    int expr;
    if (i == ind.size() - 1 && i != 0) {
      for (int j = ind[i].first; j < n; j++) {
        if (expr >= k) {
          // every subsequence after will be >= k
          ans += n - ind[i].first;
          /* cout << "adding1: " << n - ind[i].first << endl; */
        } else {
          // search until sum of subsequence >= k
          int count = 0;
          while (expr < k) {
            count++;
            expr += a[ind[i].first + count];
            if (ind[i].first + count == n - 1) {
              break;
            }
          }
          ans += n - (ind[i].first + count);
          /* cout << "adding1: " << n - (ind[i].first + count) << endl; */
        }
        /* cout << "ans: " << ans << endl; */
      }
    } else if (i == 0) {
      for (int j = 0; j < ind[i].first; j++) {
        expr = subS[j] + a[ind[i].first];
        if (expr >= k) {
          // every subsequence after will be >= k
          ans += n - ind[i].first;
          /* cout << "expr >= k" << endl; */
          /* cout << "adding2: " << n - ind[i].first << endl; */
        } else {
          // search until sum of subsequence >= k
          /* cout << "expr < k" << endl; */
          int count = 0;
          while (expr < k) {
            count++;
            expr += a[ind[i].first + count];
            if (ind[i].first + count == n - 1) {
              break;
            }
          }
          ans += n - (ind[i].first + count);
          /* cout << "adding2: " << n - (ind[i].first + count) << endl; */
        }
        /* cout << "ans: " << ans << endl; */
      }
    } else {
      for (int j = 0; j < ind[i].first - ind[i - 1].first; j++) {
        expr = subS[j + ind[i - 1].first] + a[ind[i].first];
        if (expr >= k) {
          // every subsequence after will be >= k
          ans += n - ind[i].first;
          /* cout << "adding3: " << n - ind[i].first << endl; */
        } else {
          // search until sum of subsequence >= k
          int count = 0;
          while (expr < k) {
            count++;
            expr += a[ind[i].first + count];
            if (ind[i].first + count == n - 1) {
              break;
            }
          }
          ans += n - (ind[i].first + count);
          /* cout << "adding3: " << n - (ind[i].first + count) << endl; */
        }
      }
    }
  }

  cout << ans << "\n";
}
