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
const int N = 2005;
int a[N];
int n;
typedef list<int> vi;
bool vis[N];

vi dfs(int u) {
  vis[u] = 1;
  vi ret;
  FOR(i,1,n) if (!vis[i] && (!u ||  __gcd(a[i], a[u]) > 1)) {
    auto v = dfs(i);
    vi tmp;
    insert_iterator<list<int> > it(tmp, tmp.begin());
    merge(begin(ret), end(ret), begin(v), end(v), it, greater<int>{});
    ret.swap(tmp);
  }
  ret.push_front(a[u]);
  return ret;
}

inline void solve() {
  rd(n);
  FOR(i,1,n) rd(a[i]);
  sort(a + 1, a + n + 1);
  for (auto i : dfs(0)) {
    if (i) cout << i << ' ';
  }
  cout << '\n';
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

