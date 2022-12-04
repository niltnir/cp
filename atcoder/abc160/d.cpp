#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  int dist[n - 1];
  fill(dist, dist + n, 0);

  for (int s = 1; s < n; s++) {
    for (int t = s + 1; t < n + 1; t++) {
      if (s <= x) {
        if ((t >= x && t <= x + (y - x) / 2) || t < x) {
          // don't use x -> y
          dist[t - s]++;
        } else {
          // use x -> y
          dist[abs(s - x) + 1 + abs(t - y)]++;
        }
      } else if (s > x && s <= x + (y - x) / 2) {
        if (t - s > s - x + 1 + abs(y - t)) {
          // use x -> y
          dist[abs(s - x) + 1 + abs(t - y)]++;
        } else {
          // don't use x -> y
          dist[t - s]++;
        }
      } else {
        // don't use x -> y
        dist[t - s]++;
      }
    }
  }
  for (int i = 1; i < n; i++) {
    cout << dist[i] << "\n";
  }
}

// x+t = y-(t-1)
// t < y + 1
// x x x * y y (y-x)/2 + x = (6 - 1)/2 + 1 = 5/2 = 2 + 1 = 3
// 13  x x x x y y y (y-x)/2 + x = (20 - 14)/2 + 14 = 6/2 + 14 = 17
// 15  x x x x x y y y y (y-x)/2 + x = (24 - 16)/2 + 16 = 8/2 + 16 = 20
// 10  x x x x x * y y y y (y-x)/2 + x = (20 - 11)/2 + 11 = 9/2 + 11 = 15
