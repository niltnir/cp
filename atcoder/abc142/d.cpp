#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b);
set<long long int> factorize(long long int a);

int main() {
  long long int a, b;
  cin >> a >> b;
  long long int g = gcd(a, b);

  /* cout << g << endl; */
  set<long long int> factors = factorize(g);
  int ans = factors.size();
  /* copy(factors.begin(), factors.end(), ostream_iterator<int>(cout, " ")); */
  /* cout << endl; */
  cout << ans + 1 << "\n";
}

long long int gcd(long long int a, long long int b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

// failed test case: common factor has an absurdly large prime factor
//
set<long long int> factorize(long long int a) {
  set<long long int> primeFactors;
  for (int i = 2; i < a + 1; i++) {
    if (a % i == 0) {
      if (a / i == 1) {
        // a is prime
        primeFactors.insert(a);
        return primeFactors;
        break;
      }
      /* cout << "a/i: " << a / i << endl; */
      /* cout << "i: " << i << endl; */
      set<long long int> first = factorize(a / i);
      set<long long int> second = factorize(i);
      primeFactors.insert(first.begin(), first.end());
      primeFactors.insert(second.begin(), second.end());
      break;
    } else if (i >= sqrt(a)) {
      // a is prime
      primeFactors.insert(a);
      return primeFactors;
      break;
    }
  }
  /* cout << "prime factors: "; */
  /* for (auto const &i : primeFactors) { */
  /*   cout << i << " "; */
  /* } */
  /* cout << endl; */
  return primeFactors;
}

// euclidean algorithm:
// a = bq + r
// gcd(a, b) = gcd(b, r)
