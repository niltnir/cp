#include <bits/stdc++.h>
using namespace std;

int searchWhite(int curR, int curC, vector<vector<int>> wData);

int main() {
  int h, w, ans = 0;
  cin >> h >> w;
  string s[h];
  vector<vector<int>> wData;

  for (int r = 0; r < h; r++) {
    cin >> s[r];
    for (int c = 0; c < w; c++) {
      if (s[r][c] == '.') {
        wData.insert(wData.end(), {r, c});
      }
    }
  }
  int curR = 1;
  int curC = 1;
  while (curR != h + 1 && curC != w + 1) {
    // cout << "curR: " << curR << endl;
    // cout << "curC: " << curC << endl;
    if (s[curR - 1][curC - 1] == '#') {
      ans++;
    }
    // go right
    if (curR == h) {
      curC++;
      continue;
    }
    // go down
    if (curC == w) {
      curR++;
      continue;
    }
    // go right
    if (searchWhite(curR, curC + 1, wData) >=
        searchWhite(curR + 1, curC, wData)) {
      curC++;
    } else
    // go down
    {
      curR++;
    }
  }
  cout << ans << "\n";
}
int searchWhite(int curR, int curC, vector<vector<int>> wData) {
  // cout << "curR:" << curR << endl;
  // cout << "curC:" << curC << endl;
  int returnVal = 0;
  for (int i = 0; i < wData.size(); i++) {
    // cout << "wData point: " << wData[i][0] << ", " << wData[i][1] << endl;
    if (wData[i][0] >= curR - 1 && wData[i][1] >= curC - 1) {
      returnVal++;
    }
  }
  // cout << "retVal: " << returnVal << endl;
  return returnVal;
}
