/**********************************************************************
 * This file is the c++ solution to a particular CP problem written by
 * misaka18931 and was hosted on GitHub Repository below:
 * URL: https://github.com/misaka18931/competitive-programming
 *
 * Original Author: misaka18931
 * Date:
 * Algorithm:
 * Difficulty:
 *
 *********************************************************************/

#include <algorithm>
#include <cctype>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/********************************** buffer IO *********************************/
namespace IO {
char in[1 << 24];  // sizeof in varied in problem
char const *o;
void init_in() {
  o = in;
  in[fread(in, 1, sizeof(in) - 4, stdin)] = 0;  // set 0 at the end of buffer.
}
int rd() {
  unsigned u = 0, s = 0;
  while (*o && *o <= 32) ++o;  // skip whitespaces...
  if (*o == '-')
    s = ~s, ++o;
  else if (*o == '+')
    ++o;  // skip sign
  while (*o >= '0' && *o <= '9')
    u = (u << 3) + (u << 1) + (*o++ - '0');  // u * 10 = u * 8 + u * 2 :)
  return static_cast<int>((u ^ s) + !!s);
}
char *rdstr(char *s) {
  while (*o && *o <= 32) ++o;
  while (*o > 32) *s++ = *o++;
  *s = '\0';
  return s;
}
}  // namespace IO

/********************************* utility ************************************/
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef pair<int, int> pii;
#define pb(x) push_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
#define FOR(x, y, z) for (int x = y; x < z; ++x)  // always [y, z)
#define ROF(x, y, z) for (int x = z - 1; x >= y; --x)
template <typename T>
void chkmax(T &a, const T &b) {
  a = max(a, b);
}
template <typename T>
void chkmin(T &a, const T &b) {
  a = min(a, b);
}
pii operator+(const pii &a, const pii &b) {
  return mkp(a.fi + b.fi, a.se + b.se);
}

/*********************************** solution *********************************/
using IO::rd;
// #define MULTI
const int N = 66;
int p, m;
i64 inv[N], fac[N], ifac[N];
int j[N];
int n;
int ans;
inline void prework() {
  inv[1] = fac[1] = fac[0] = ifac[0] = ifac[1] = 1;
  for (int i = 2; i <= n; ++i) {
    fac[i] = fac[i - 1] * i % p;
    inv[i] = (p - p / i * inv[p % i] % p) % p;
    ifac[i] = ifac[i - 1] * inv[i] % p;
  }
}
i64 q_pow(i64 x, int y) {
  i64 ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % p;
    x = x * x % p;
    y >>= 1;
  }
  return ret;
}
void getans() {
  int f = 1;
  for (int i = 1; i <= n; ++i) {
    if (j[i])f = 1ll * f * ifac[j[i]] % p * q_pow(q_pow(i, j[i]), p - 2) % p;
  }
  int g = 0;
  for (int i = 1; i <= n; ++i) {
    g += i / 2 * j[i];
  }
  for (int i = 1; i <= n; ++i) {
      if (!j[i]) continue;
    for (int k = 1; k < i; ++k) {
      if (j[k]) g += __gcd(i, k) * j[i] * j[k];
    }
    g += i * (j[i] * (j[i] - 1) / 2);
  }
  g = q_pow(m, g);
  ans = (ans + 1ll * f * g) % p;
}

void dfs(int i, int n) {
  if (n == 0) {
    getans();
  } else if (n >= i) {
    for (int k = 0; k <= n; k += i) {
      j[i] = k / i;
      dfs(i + 1, n - k);
    }
  }
  j[i] = 0;
}

void solve() {
  n = rd(), m = rd(), p = rd();
  prework();
  dfs(1, n);
  cout << ans << '\n';
}

int main() {
  IO::init_in();
#ifdef MULTI
  int T = IO::rd();
  while (T--) solve();
#else
  solve();
#endif
  return 0;
}
/*
 * checklist:
 * - IO buffer size
 * - potential out-of-bound Errors
 * - inappropriate variable type
 * - potential Arithmetic Error
 * - potential Arithmetic Overflow
 * - typo / logical flaws
 * - clean-up on multiple test cases
 * - sufficient stress tests / random data tests
*/
