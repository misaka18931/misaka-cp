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
#define MULTI
const int N = 0;
const int mod = 1e9+7;

int phi(int n) {
  if (n == 1) return 1;
  int ret = n - 1;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      --ret;
      if (i * i != n) --ret;
    }
  }
  return ret;
}

int q_pow(i64 a, int x) {
  i64 ret = 1;
  while (x) {
    if (x & 1) ret = ret * a % mod;
    a = a * a % mod;
    x >>= 1;
  }
  return ret;
}
i64 euler_phi(i64 n) { //欧拉函数
	i64 res=1;
	for(i64 i=2; i*i<=n; i++)
		if(n%i==0) {
			n/=i,res=res*(i-1);
			while(n%i==0) n/=i,res=res*i;
		}
	if(n>1) res=res*(n-1);
	return res;
}

void solve() {
  int n = rd();
  i64 ans = 0;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      ans = (ans + 1ll * euler_phi(i) * q_pow(n, n / i)) % mod;
      if (i * i != n) ans = (ans + 1ll * euler_phi(n / i) * q_pow(n, i)) % mod;
    }
  }
  cout << 1ll * ans * q_pow(n, mod - 2) % mod << '\n';
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