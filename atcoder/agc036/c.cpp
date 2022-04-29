#include <bits/stdc++.h>
using namespace std;
#ifndef MISAKA
#define OO(x)
#else
#define OO(x) cout << __PRETTY_FUNCTION__ << ": " << #x << " : " << (x) << '\n';
#endif
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
void O(const A& a) {
  cout << a << '\n';
}
template<typename A, typename... B>
void O(const A& a, const B& ...b) {
  cout << a << ' ';
  O(b...);
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
#define FOR(i, j, k) for (int i = (j); i <= (k); ++i)
#define ROF(i, j, k) for (int i = (k); i >= (j); --i)
template<typename T>
inline void chkmin(T &a, const T b) {
  a = min(a, b);
}
template<typename T>
inline void chkmax(T &a, const T b) {
  a = max(a, b);
}

//#define MULTI
const int N = 5e6;
const int p = 998244353;
int fac[N], ifac[N], inv[N];

int C(int n, int k) {
  if (n < 0 || k < 0 || k > n) return 0;
  return 1ll * fac[n]*ifac[k]%p*ifac[n-k]%p;
}

int f(int n, int m) {
  return C(n+m-1,m);
}

inline void solve() {
  int n, m;
  rd(n,m);
  fac[0] = fac[1] = ifac[0] = ifac[1] = inv[1] = 1;
  FOR(i,2,N-1) {
    inv[i] = 1ll * inv[p%i]*(p-p/i)%p;
    fac[i] = 1ll * i * fac[i-1]%p;
    ifac[i] = 1ll * ifac[i-1] * inv[i] % p;
  }
  int ans = f(n,3*m);
  FOR(i,2*m+1,3*m) {
    ans = (ans + 1ll * (p-n) * f(n-1,3*m-i)) % p;
  }
  for (int i = m + 2; i <= n; i += 2) {
    ans = (ans + 1ll * (p-1) * C(n,i) % p * f(n,(3*m-i)/2)) % p;
  }
  O(ans);
}

int main() {
#ifndef MISAKA
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif
#ifdef MULTI
  int T;
  cin >> T;
  while (T--)
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

