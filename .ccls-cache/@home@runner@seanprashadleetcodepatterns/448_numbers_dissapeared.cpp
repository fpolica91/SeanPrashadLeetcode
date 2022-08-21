#include <bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums) {
  vector<int> ans;
  for (int i = 0; i < nums.size(); i++) {
    int element = abs(nums[i]);
    if (element > 0 and element <= nums.size() and nums[element - 1] > 0) {
      nums[element - 1] *= -1;
    }
  }
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > 0) {
      ans.push_back(i + 1);
    }
  }

  return ans;
}

// approach using cycle sort
vector<int> findDisappearedNumbers2(vector<int> &nums) {
  int n = nums.size();
  vector<int> ans;
  int i = 0;
  while (i < n) {
    if (nums[i] == i + 1 or nums[i] == nums[nums[i] - 1])
      i++;
    else if (nums[i] != i + 1) {
      swap(nums[i], nums[nums[i] - 1]);
    } else {
      i++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (nums[i] != i + 1) {
      ans.push_back(i + 1);
    }
  }
}