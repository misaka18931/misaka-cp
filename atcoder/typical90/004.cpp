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
#define MX 2005

int r[MX], c[MX];

void solve() {
  long long H;
  scanf("%lld", &H);
  long long W;
  scanf("%lld", &W);
  std::vector<std::vector<long long>> A(H, std::vector<long long>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf("%lld", &A[i][j]);
      c[j] += A[i][j];
      r[i] += A[i][j];
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << r[i] + c[j] - A[i][j] << ' ';
    }
    cout << endl;
  }
}

int main() {
  int T = 1;
  /* cin >> T; */
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