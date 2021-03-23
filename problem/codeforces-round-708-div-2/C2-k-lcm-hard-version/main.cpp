// Original Author: misaka18931
// Date: 03-17-21
// tag:
// 

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define LF << '\n'
#define SPC << ' '
#define CLRBUF cout << endl;

void solve() {
  int n, k, n0;
  cin >> n >> k;
  for (int i = 0; i < k - 3; ++i) {
    cout << "1 ";
  }
  n -= k - 3;
  n0 = n;
  int base = 0;
  while (~n & 1) {
    n >>= 1;
    ++base;
  };
  if (n == 1)
    printf("%d %d %d\n", n0 / 2, n0 / 4, n0 / 4);
  else {
    n /= 2;
    printf("%d %d %d\n", n << base, n << base, 1 << base);
  }
}

int main() {
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
