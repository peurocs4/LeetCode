#ifndef Trapping_Rain_Water_h__
#define Trapping_Rain_Water_h__


#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int trap(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int leftMax = 0;
    int rightMax = 0;

    int trapAmount = 0;
    while (left < right) {
      if (height[left] > height[right]) {
        rightMax = max(rightMax, height[right]);
        trapAmount += max(0, rightMax - height[right]);
        --right;
      }
      else {
        leftMax = max(leftMax, height[left]);
        trapAmount += max(0, leftMax - height[left]);
        ++left;
      }
    }

    return trapAmount;
  }
};


#endif // Trapping_Rain_Water_h__
