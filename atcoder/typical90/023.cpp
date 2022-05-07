// Original Author: misaka18931
// Date: $DATE
// tag:
//

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define MX
const long long mod = 1000000007;

char C[600];
int dp[1 << 25][2];
vector<int> s[26];

void solve() {
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; ++i) {
    scanf("%s", C + i * w);
  }
  dp[0][0] = 1;
  if (C[0] == '.')
    dp[1][0] = 1;
  int mask = (1 << (w + 1)) - 1;
  s[0].push_back(0);
  s[1].push_back(1);
  s[1].push_back(0);
  for (int i = 2; i <= 1 + w; ++i) {
    for (auto t : s[i - 1])
      s[i].push_back(t << 1);
    for (auto t : s[i - 2])
      s[i].push_back((t << 2) | 1);
  }
  for (int i = 1; i < w * h; ++i) {
    int ts = (i - 1) % w + 1;
    for (auto j1 : s[w + 1 - ts])
      for (auto j2 : s[ts]) {
        int j = (j1 << ts) | j2;
        dp[(j << 1) & mask][1] += dp[j][0];
        dp[(j << 1) & mask][1] %= mod;
      }
    if (C[i] == '.') {
      int valid = 1 << (w - 1);
      if (i % w)
        valid |= (1 << w) | 1;
      if ((i + 1) % w)
        valid |= 1 << (w - 2);
      for (auto j1 : s[w + 1 - ts])
        for (auto j2 : s[ts]) {
          int j = (j1 << ts) | j2;
          if (valid & j)
            continue;
          dp[(j << 1) & mask | 1][1] += dp[j][0];
          dp[(j << 1) & mask | 1][1] %= mod;
        }
    }
    for (auto j1 : s[w + 1 - ts])
      for (auto j2 : s[ts]) {
        int j = (j1 << ts) | j2;
        dp[j][0] = 0;
      }
    ts = i % w + 1;
    for (auto j1 : s[w + 1 - ts])
      for (auto j2 : s[ts]) {
        int j = (j1 << ts) | j2;
        dp[j][0] = dp[j][1];
        dp[j][1] = 0;
      }
  }
  int ans = 0;
  for (int i = 0; i <= mask; ++i) {
    ans += dp[i][0];
    ans %= mod;
  }
  cout << ans << endl;
}

int main() {
  int T = 1;
  while (T--)
    solve();
  return 0;
}

/****************************** Railgun *********************************
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠠⢀⠠⢀⠠⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠠⠐⠠⠈⠄⠨⠐⡀⠂⠄⠂⡁⠄⢁⠡⠐⢀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠄⡂⠄⠡⠈⠄⠡⠈⠄⠡⠐⡈⠄⠡⢀⠨⢀⠐⡈⢀⠂⠄⠄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⡀⠠⡀⡄⡔⣄⢦⢕⣔⢕⠔⡅⢅⠅⢅⠅⢅⠅⠅⢅⠂⠅⢌⠀⡂⠀⡂⢐⠀⡂⢐⠀⡂⠐⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⡄⣢⢪⣲⣲⣪⣞⣮⣾⣾⣷⣿⣿⣾⣷⡯⣪⢢⠱⡐⢅⠢⠡⡑⡐⢅⢑⢐⠡⡀⠅⡐⠄⡂⠢⠐⡀⢂⠁⠄⡐⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢤⢱⣼⣾⣿⢿⣿⣿⣿⣿⣿⣿⣻⣻⡻⡽⣻⡻⡿⣯⣧⣯⡪⣪⢸⠨⡢⠨⡂⡢⠡⡊⠔⡐⢀⢊⠔⠡⠡⠐⡀⠂⠅⢊⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢀⠠
⠀⠀⠀⠀⠀⠀⠀⢄⢕⣽⣿⣿⣿⣾⣿⡿⡯⡳⡳⡱⡣⡣⡒⢕⢑⠕⢕⢝⠪⢎⢯⡻⡷⣷⣝⣮⡳⡱⣑⠱⡐⡡⢂⢆⢂⠅⠅⠅⢅⢂⠁⠌⡀⢂⠡⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⡐⡌⣆⡖⡵
⠀⠀⠀⠀⠀⠄⡕⣵⣽⡟⡟⡞⡝⢞⠫⡚⡜⡑⠡⡃⡪⢐⢌⠂⠕⢌⠢⡡⡑⢕⠱⡱⡹⡽⣿⣷⣿⣯⢮⢪⠂⡜⡐⠌⡆⡥⡁⡃⢅⠢⠨⢀⠂⡐⢀⠂⡁⡀⠀⠀⠀⠀⠀⢀⢀⢂⢆⢧⣻⡪⢮⢛
⠀⠀⠀⢄⢱⣱⡽⡟⡕⠕⠁⠂⠈⠀⠂⡐⠐⢀⢕⠨⠢⡑⡔⢅⢋⠢⡑⡐⢄⠥⡑⢌⠎⠮⡿⡿⡿⡿⣿⣕⠕⡜⡎⢎⢸⢸⢌⠢⠡⡨⠨⢀⠂⡐⡀⢂⠐⡀⠅⢄⠠⡐⡨⡐⠴⠫⡙⢌⠢⠊⠐⠀
⠀⠠⢨⣪⣾⡯⡣⢑⠀⠁⠀⠀⠀⠀⠀⡊⠀⡐⡆⡣⡃⢕⢑⠄⢕⢑⠄⡊⡢⢑⢌⠢⡑⢱⢱⣫⢻⡊⡇⡎⡅⡏⣞⢎⢞⡵⡕⡕⢅⠢⡁⢂⠐⡀⡂⠢⡈⡢⡱⡱⣵⣳⡝⡍⠌⠂⠐⠀⠀⠀⠀⠀
⢀⢪⣲⢟⠕⠕⠈⠀⠀⠀⠀⠀⠀⠀⠐⠀⠀⡐⢅⠢⡊⡢⠂⢅⠣⢪⢀⢆⢊⢪⢐⠅⡕⢜⢜⡜⣕⢝⠨⡢⡁⢧⡓⡗⡹⣽⣮⣺⢸⡐⢌⢆⢂⢪⢨⣪⡪⡮⣺⢝⣾⢳⢑⠅⢂⠀⠀⠀⠀⠀⠀⠀
⢜⣶⡟⡜⠨⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢌⠢⢱⠨⠨⡈⢢⢑⢕⢐⢅⢎⠆⡅⢣⠁⡵⣕⢽⡸⡕⡇⡆⡪⡪⡪⡺⢜⠽⡽⣷⣯⡮⣪⣪⢺⢨⡣⡇⣗⡽⡗⡏⡎⡢⠡⠈⠄⠂⠄⠀⠀⠀⠀⠀
⡟⡏⡊⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡂⡃⢕⠨⡊⠌⡐⢌⢂⢕⣘⣑⠇⢪⡳⡸⡜⡮⣪⡺⣪⢳⠐⠜⡨⡀⠄⠢⢢⢧⣻⣿⣟⢾⣺⣪⢪⡎⡞⡕⢜⠘⢌⠢⡂⢅⠡⠈⠄⠡⢈⢀⠀⠀⠀
⠕⠡⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡢⠊⠀⢕⠨⡂⠌⡂⢕⢑⠴⢑⣁⠑⡐⠘⠌⢮⡫⡮⣺⢪⢮⢲⡹⣝⣀⢆⢀⢪⢇⣿⣿⣿⣿⣳⢗⢕⢑⢑⠌⡐⠨⢀⠑⢄⢑⠄⡡⠨⢐⠠⠀⡂⠀⠀
⠈⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠊⠀⠀⠀⢕⠨⡂⠅⠂⡕⡔⡁⣼⣺⠐⠘⠃⢳⢕⣎⢯⢮⡳⣝⢵⡹⣜⡺⠥⣕⢸⢽⢾⣿⣷⣿⣽⢱⢑⢐⢐⢐⠨⠐⡐⢈⠐⡠⠡⢂⠂⡁⡂⠡⠐⠠⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢂⠨⡂⢑⠠⢸⣊⢞⢮⡻⣞⢇⣊⢼⡳⡵⣝⢮⣺⡪⡳⣝⣜⢮⡫⣎⢯⢯⣿⣿⣿⢿⣺⢸⠐⠄⢂⢐⠠⢁⠂⢂⠂⠄⠡⠂⠅⠄⠂⠅⡈⠀⠀
⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡂⢅⠊⢄⢑⢈⢗⡲⡘⡷⡽⣝⢭⣲⡳⣝⣞⢮⡳⡵⣝⣝⢮⡺⣪⡺⣪⡫⣗⣿⣻⣿⣿⢯⠪⠌⠌⠄⡂⠌⡐⠨⢀⢂⠡⠁⠌⠨⠠⠁⠡⢀⠡⠀
⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠪⢐⠡⢊⠔⣐⢅⡢⡙⡗⡮⣻⢮⣻⣪⢾⣕⢷⢝⡮⣯⡺⣪⡳⣝⢮⡺⣪⢞⢵⡳⣻⣿⢿⢕⠕⢅⠑⠄⡂⠡⠠⢁⠕⡀⡂⠡⠨⠀⠅⢂⠀⠐⠀⠂
⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠢⡁⠢⢑⣖⣽⣺⢽⣫⡽⣾⢾⣾⢯⣞⢞⣷⢽⡽⡽⡽⡺⡮⣓⢭⢮⡳⣝⢮⡫⡪⣝⣽⡿⣝⢜⠌⠄⠅⠅⠄⠡⢁⠂⠄⠐⠄⠅⠌⡐⠈⠠⠀⠀⠀⠀
⠠⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠌⢀⣝⣗⡗⡗⣽⣻⢷⣻⡯⡿⣽⣻⡽⣿⢾⣟⡿⣻⡽⣝⢾⣕⢯⡳⣝⢮⠣⡣⣃⢮⣺⡯⡪⡢⠡⠡⢑⠨⢈⠈⡐⠨⢈⠀⠈⠂⠅⡐⠀⠀⠁⠀⠀⠀
⠨⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢈⠀⡼⣞⢞⣮⢿⣯⢿⢽⣳⢯⣟⣗⢷⣻⣽⣻⣽⡾⡕⣝⢽⢵⡳⡽⣺⠱⡱⡱⣕⢽⡺⣼⢣⠣⡊⠌⠌⡐⠨⢐⠀⠠⢁⢂⠀⠀⠈⢂⠂⡁⠀⠀⠀⠀⠀
⣕⢐⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡽⣕⣟⣾⢿⡽⣽⣻⣺⢽⣺⣺⢽⣞⣾⣳⡿⣽⣻⣊⣪⢳⢙⢝⢔⢝⣜⢞⡎⡧⣟⢷⢕⢑⠌⠌⢐⠨⠀⢂⠂⠀⠐⠠⠀⠀⠀⠀⢂⠀⠀⠀⠀⠀⠀
⡳⣕⣕⢀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣺⢸⡳⣕⣗⣿⢯⣟⣗⣗⡯⣟⡾⡽⣽⣺⣞⣷⢿⡽⣞⡆⣿⢷⡷⣵⢵⣓⡵⢫⡺⣽⡺⡯⡯⡦⠡⠁⠀⠂⠀⠐⠀⠀⠀⠨⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀:⠀
⠸⢮⡻⣜⢄⠅⠀⠀⠀⠀⠀⠀⢀⡼⣵⣳⡺⡜⡮⣺⢿⣻⣗⡿⣺⢱⡵⣯⢽⡳⣻⢾⣽⢿⡽⣯⢺⣟⣿⣻⣽⢿⢭⣞⡷⡽⣾⢽⡽⣝⡾⡐⡄⢄⠄⡀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠈⠪⡪⡳⡵⣑⠅⡂⠀⠀⠀⠀⡷⡽⣺⢮⢧⡣⣽⢽⣻⣻⣽⣟⣿⡸⣿⢽⡯⣟⣾⣟⡯⡿⣽⡳⡽⣿⣽⣻⡾⣿⣪⡷⣟⣿⣚⣿⢽⣳⣻⢨⡸⡐⢕⢌⠪⠪⡣⡢⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠁⡘⢜⢎⢎⢇⣆⠅⡂⡀⢠⢯⢞⣗⢯⢗⡽⡽⡽⡜⣟⣾⢽⣻⣷⡽⣿⣽⣿⢯⡗⡵⣻⡳⡯⣧⣳⢻⣽⣻⢣⣳⢟⣯⣿⣽⣺⣽⡓⣛⢜⡜⡎⡖⡔⡑⢅⢫⢮⡸⡄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⡑⡘⠽⡘⡔⢕⢆⡢⡯⣯⣳⢽⢭⣳⢯⣟⣕⢕⣟⣾⣻⢼⣟⣿⣯⡷⣻⡹⣜⢝⠬⠯⣻⡺⡮⣗⢶⢜⢿⣺⣟⣯⣷⡞⣾⣺⡅⡇⡧⡳⡹⣘⢌⢊⢢⢱⣓⢵⢝⢆⡀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠠⢁⠣⢇⢇⢇⣾⢿⣳⡯⡿⡽⣮⢻⣺⣺⣜⡾⣾⣽⣏⣿⣳⡯⣯⢳⡹⡸⡪⢍⡯⡎⢝⡙⡞⣗⡣⣗⣻⣟⣯⡷⣇⡿⡮⡇⢇⢗⢕⢝⢔⢕⢌⠢⡱⣘⢱⢹⢱⢱⢰⢰⢠⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠠⠁⡇⡯⣿⢾⣿⢯⣿⣻⢿⡽⣷⡽⣷⢿⣜⡿⣞⡷⡝⡾⡽⣽⡪⡪⣚⡬⣗⡯⣇⢧⢯⢾⣵⢿⡽⣾⣙⢷⣟⣗⡯⣟⣽⡨⢘⢜⢕⢵⢱⢱⢑⢜⢎⢯⢎⡗⣕⢧⢳⢱⢍⢆⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢅⠪⣝⢾⢿⣻⣟⣷⡿⣯⣿⢷⡷⣝⢯⡷⣏⡫⣯⢷⢹⡽⣺⢽⢪⣞⣽⣳⣻⣳⣟⡿⣽⣾⣻⡽⣗⠧⡇⢿⣺⢾⣹⡺⡆⡇⡇⡗⡕⡕⡕⡕⣜⢜⡬⢥⢍⡎⡮⣊⡊⣎⢪⠪⡂⠆
⠀⠀⠀⠀⠀⠌⢴⢑⢃⢃⢻⢽⣻⣾⢿⣿⣻⣿⣻⣽⣯⣏⣗⣵⢮⢿⢽⢽⡽⣯⢗⣷⢷⣯⢿⡹⣪⢫⢗⡯⣷⣻⢿⣫⣎⢣⣑⢟⡮⣫⢟⢜⢜⡜⡜⡜⡜⡜⡔⡕⣝⢕⢧⢳⢹⢸⡸⡸⡸⡱⡱⡱
⠀⠀⠀⠠⢈⢊⠣⢁⠂⠀⠀⠳⡭⣺⢿⠽⣻⡾⣯⡿⣞⠵⣻⢽⡫⣝⣻⣻⢹⡯⣏⣯⢿⣞⢏⡞⡜⡌⣗⢽⡺⣺⣻⣗⡷⡵⣈⠦⡙⢭⢯⢘⢜⢜⢜⢜⢜⢜⢜⢌⢪⢣⢳⢕⡝⣜⢜⢜⢎⢎⢎⢎
⠀⠀⡀⠪⡐⡫⢈⠀⠀⠀⠀⠀⠈⠑⠫⢯⡲⣖⣖⢮⡺⣝⣞⢽⡺⣝⢶⡹⡵⡭⡪⣺⢽⢫⢇⣇⢣⢚⣎⢧⡫⣳⢽⣞⣯⣟⢮⡣⡍⡪⡃⢰⡸⡸⡸⡸⡸⡸⡘⡜⡄⡇⡇⡇⡧⡣⡳⡱⡱⡱⡑⡕
⢀⢂⡊⡋⡂⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠘⠪⠗⠽⣕⢷⢝⡮⣗⢽⡺⣢⢯⢇⠯⡫⣓⢯⢲⢱⡱⣕⢵⢹⡪⣳⣻⣳⢯⢷⣫⢞⡆⡍⠎⢎⢎⢎⢎⢎⠎⢊⡈⠜⡰⢱⢑⢕⢕⢕⢕⢕⢕⢕⢕
⣰⠸⠨⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠑⠙⡮⣳⢝⡮⣳⠽⡑⡕⡕⣝⢷⢵⢝⡜⣎⢇⢯⢺⣪⢯⢏⡯⣞⢷⣝⢮⡊⡜⢜⢜⢜⢌⢎⠰⢍⠆⡂⢕⠕⡅⢇⢇⢇⢇⢇⢕⢜
⡣⡑⢁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠡⡙⣊⢪⢸⠨⡪⡪⡻⣞⡵⣝⢜⢎⢮⢣⡳⣽⢳⡹⣜⢵⠽⣗⢕⢜⢌⢆⢇⢕⢕⢱⢈⢀⢂⢇⢣⢱⠡⡣⡣⡣⢣⢱⢘

************************************************************************/