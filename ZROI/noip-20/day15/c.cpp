#include <bits/stdc++.h>
using namespace std;
template<typename T>
void rd(T &a) {
  cin >> a;
}
template<typename A, typename... B>
void rd(A &a, B& ...b) {
  cin >> a;
  rd(b...);
}
template<typename A>
void print(const A& a) {
  cout << a;
}
template<typename A, typename... B>
void print(const A& a, const B& ...b) {
  cout << a;
  print(b...);
}
template<typename A>
void println(const A& a) {
  cout << a << '\n';
}
template<typename A, typename... B>
void println(const A& a, const B& ...b) {
  cout << a << ' ';
  println(b...);
}
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int, int> pii;
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define FOR(i, j, k) for (int i = (j); i < (k); ++i)
#define ROF(i, j, k) for (int i = ((k) - 1); i >= j; --i)
template<typename T>
inline void chkmin(T &a, const T b) {
  a = min(a, b);
}
template<typename T>
inline void chkmax(T &a, const T b) {
  a = max(a, b);
}

const int N = 1e6+5;
int d[N];
i64 f[N][3] = {{1, 1, 2}};
const int p = 1e9+7;
int n;

inline void solve() {
  rd(n);
  i64 ans = 1;
  for (int i = 1, u, v; i < n; ++i) {
    rd(u, v);
    ++d[u], ++d[v];
    ans = ans * 500000004 % p;
  }
  FOR(i, 1, n) {
    f[i][0] = (f[i-1][1] + f[i-2][2] * (i - 1) * 2) % p;
    f[i][1] = (f[i][0] + f[i-1][1] * i * 2) % p;
    f[i][2] = (f[i][0] + f[i][1] + f[i-1][2] * i * 2) % p;
  }
  FOR(i, 1, n + 1) ans = ans * f[d[i]][0] % p;
  println(ans);
}

int main() {
#ifndef MISAKA
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif
  solve();
  return 0;
}
/* Checklist:
 * - data type
 * - overflow
 * - typo/logic
 * - special cases
 * - cleanup (multi-test)
 * - bounds
 * - memory usage
 * - file IO
 */

