/** @file
 * @ingroup DP math
@loj{3706}

 */
#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void O(const T &x) { cout << x << '\n'; }
template <typename T, typename... W> inline void O(const T &x, const W &...b) {
  cout << x << ' ';
  O(b...);
}
template <typename T> inline void rd(T &x) { cin >> x; }
template <typename T, typename... W> inline void rd(T &x, W &...b) {
  cin >> x;
  rd(b...);
}
#ifndef MISAKA
#define err(...)
#else
#define err(...) fprintf(stderr, __VA_ARGS__)
#endif
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef long double dbl;
typedef pair<int, int> pii;
typedef uniform_int_distribution<int> r32;
typedef uniform_int_distribution<i64> r64;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define shuf(L, R) shuffle((L), (R), rng)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define FOR(i, j, k) for (int i = (j); i <= (k); ++i)
#define ROF(i, j, k) for (int i = (k); i >= (j); --i)
template <typename T> inline void ckmin(T &a, const T &b) { a = min(a, b); }
template <typename T> inline void ckmax(T &a, const T &b) { a = max(a, b); }
//#define IOFILE "filename"
//#define MULTI
const int N = 505;
int a[2][N][N];

inline void sol() {
  a[0][1][1] = 1;
  int n, p;
  rd(n,p);
  --n;
  FOR(i,1,n) {
    int ans = 0;
    auto &f = a[i&1];
    auto &g = a[~i&1];
    FOR(j,1,i+1) FOR(k,1,i+1) {
      int &cur = f[j][k];
      cur = 2ll * j * k * g[j][k] % p;
      if (j) cur = (cur + 1ll * (p-1) * (j-1) * k % p * g[j-1][k]) % p;
      if (k) cur = (cur + 1ll * (p-1) * j * (k-1) % p * g[j][k-1]) % p;
      if (j && k) cur = (cur + 1ll * (j-1) * (k-1) * g[j-1][k-1]) % p;
      ans = (ans+ cur) % p;
    }
    O(ans);
  }
}

int main() {
#ifndef MISAKA
#ifdef IOFILE
  freopen(IOFILE ".in", "r", stdin);
  freopen(IOFILE ".out", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif
#ifdef MULTI
  int T;
  cin >> T;
  while (T--)
#endif
    sol();
  return 0;
}

