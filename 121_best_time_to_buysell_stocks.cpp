
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices) {
  int sm = prices[0];
  int diff = 0;
  for (auto x : prices)
    if (sm > x)
      sm = x;
    else {
      diff = max(diff, x - sm);
    }
  return diff;
}

int maxProfit2(vector<int> &prices) {
  int sm = prices[0], diff = 0;
  for (auto pr : prices) {
    diff = max(diff, pr - sm);
    sm = min(sm, pr);
  }

  return diff;
}