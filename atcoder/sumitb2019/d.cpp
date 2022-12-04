#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main() {
  int n;
  string s;
  stringstream ss;
  cin >> n >> s;

  set<int> nums;
  int tmpDig1 = -1;
  int tmpDig2 = -1;
  int tmpDig3 = -1;
  string reduced1 = s;
  for (int i = 0; i < reduced1.length(); i++) {
    ss << reduced1[i];
    ss >> tmpDig1;
    reduced1.erase(
        remove(reduced1.begin() + i + 1, reduced1.end(), reduced1[i]),
        reduced1.end());
    ss.str("");
    ss.clear();
    string chopped1 = s.substr(i);
    string reduced2 = chopped1;
    for (int j = chopped1.find(reduced1[i]) + 1; j < reduced2.length(); j++) {
      ss << reduced2[j];
      ss >> tmpDig2;
      reduced2.erase(
          remove(reduced2.begin() + j + 1, reduced2.end(), reduced2[j]),
          reduced2.end());
      ss.str("");
      ss.clear();
      string chopped2 = chopped1.substr(j);
      string reduced3 = chopped2;
      for (int k = chopped2.find(reduced2[j]) + 1; k < reduced3.length(); k++) {
        ss << reduced3[k];
        ss >> tmpDig3;
        reduced3.erase(
            remove(reduced3.begin() + k + 1, reduced3.end(), reduced3[k]),
            reduced3.end());
        nums.insert(100 * tmpDig1 + 10 * tmpDig2 + tmpDig3);
        ss.str("");
        ss.clear();
      }
    }
  }

  cout << nums.size() << "\n";
}
