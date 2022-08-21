
#include <bits/stdc++.h>
using namespace std;

// using simple map to store occurence of number
int singleNumber(vector<int> &nums) {
  unordered_map<int, int> a;
  for (auto x : nums)
    a[x]++;
  for (auto z : a)
    if (z.second == 1)
      return z.first;
  return -1;
}

// using stack and sorting

int singleNumber2(vector<int> &nums) {
  // array must be sorted
  stack<int> s;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); i++) {
    // number has already been seen
    if (!s.empty() and s.top() == nums[i]) {
      s.pop();
    } else {
      s.push(nums[i]);
    }
  }
  return s.top();
}

// sorting without using extra space

int singleNumber3(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  for (int i = 1; i < nums.size(); i += 2) {
    if (nums[i] >= nums[i - 1]) {
      return nums[i - 1];
    }
  }
  return nums[nums.size() - 1];
}

// using xor operator
// background: a ^ a = 0 a ^ b = b a ^ a ^ b = b

int singleNumber4(vector<int> &nums) {
  int ans = 0;
  for (auto x : nums) {
    ans ^= x;
  }
  return ans;
}