#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int n;
  long long int ans = 0;
  cin >> n;
  if (n % 2 != 0) {
    cout << "0"
         << "\n";
    return 0;
  } else {
    int k = 1;
    while (n / (2 * (long long int)pow(5, k)) >= 1) {
      ans += n / (2 * (long long int)pow(5, k));
      k++;
    }
  }

  cout << ans << "\n";
}

// ****Cover all nums of the form 2*5^k
// f(0) = 1, f(1) = 1, f(n) = nf(n - 2)
// f(2) = 2, f(3) = 3, f(4) = 4f(2) = 8, f(5) = 5f(3) = 15
// okay, so basically f computes the odd or even "factorial"
// ex. f(12) = 12 x 10 x 8 x 6 x 4 x 2 --> 1 trailing zero
// number of trailing zeroes in f(N)
// 100 -> 100, 90, 80, 70, 60, 50, 40, 30, 20, 10 --> 12
// 50, 150, 250, 350, 450, 500, 750, 1250, 1500, ...
// 10 = 2*5^1
// 100 = 4*5^2
// 50 = 2*5^2
// 250 = 2*5^3
