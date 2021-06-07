/**********************************************************************
 * This file is the c++ solution to a particular CP problem written by
 * misaka18931 and was hosted on GitHub Repository below:
 * URL: https://github.com/misaka18931/competitive-programming
 *
 * Original Author: misaka18931
 * Date: Jun 06, 2021
 * Algorithm: n/a
 * Difficulty: eazy
 *
 *********************************************************************/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define MX

// clang-format off
// clang-format on

int ans[3][3] = {
{0, 2, 1},
{2, 1, 0},
{1, 0, 2}
};

void solve() {
  int x, y;
  cin >> x >> y;
  cout << ans[x][y] << endl;
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
