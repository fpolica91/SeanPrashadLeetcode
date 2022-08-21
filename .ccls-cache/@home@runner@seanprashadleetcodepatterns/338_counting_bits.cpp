#include <bits/stdc++.h>
using namespace std;
static vector<int> dp(1e5 + 5, -1);

vector<int> countBitsNaive(int n) {
  int k = 0;
  vector<int> ans(n + 1);
  while (k < n) {
    int b = k;
    int bc = 0;
    while (b != 0) {
      if ((b & 1) != 0) {
        bc++;
      }
      // right shift bit
      b = (b >> 1);
    }
    ans[k] = bc;
  }
  return ans;
}

vector<int> countBits(int n) {
  int k = 0;
  vector<int> ans(n + 1);
  while (k < n) {
    int b = k;
    int bc = 0;
    while (b != 0) {
      b = (b & (b - 1));
      bc++;
    }
    ans[k] = bc;
  }
  return ans;
}

vector<int> countBitsMemo(int n) {
  int k = 0;
  vector<int> ans(n + 1);
  while (k <= n) {
    int b = k;
    int cc = 0;
    while (b != 0) {
      if (dp[b] != -1) {
        cc += dp[b];
        b = (b & (b - 1));
      } else {
        b = (b & (b - 1));
        cc++;
        dp[b] = cc;
      }
    }
    ans[k] = cc;
    k++;
  }
  return ans;
}
