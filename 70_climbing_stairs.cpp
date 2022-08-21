#include <bits/stdc++.h>
using namespace std;

vector<int> dp(1e10, -1);

int climbStairs(int n) {
  if (n <= 1) {
    return 1;
  }

  if (dp[n] != -1) {
    return dp[n];
  }

  int current = climbStairs(n - 1) + climbStairs(n - 2);
  dp[n] = current;
  return current;
}