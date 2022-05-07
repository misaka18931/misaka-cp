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

const int N = 2e4+5;
bitset<N> b[N];
int n, m;
char s[N];

inline void solve() {
  cin >> n >> m;
  while (m--) {
    cin >> s;
    bitset<N> cur, cur2;
    FOR(i, 0, n) if ((s[i] - '0') & 1) cur.set(i);
    FOR(i, 0, n) if ((s[i] - '0') & 2) cur2.set(i);
    FOR(i, 0, n) {
      if ((s[i] - '0') == 2) b[i] ^= cur;
      else if ((s[i] - '0') == 1) b[i] ^= cur2;
      else if (s[i] == '3') b[i] ^= cur | cur2;
    }
  }
  int ans = 0;
  bitset<N> msk;
  FOR(i, 0, n) ans += (b[i] & msk).count(), msk.set(i);
  cout << ans << '\n';
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
