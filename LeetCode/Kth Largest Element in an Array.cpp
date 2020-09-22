#ifndef Kth_Largest_Element_in_an_Array_h__
#define Kth_Largest_Element_in_an_Array_h__



#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }
};



#endif // Kth_Largest_Element_in_an_Array_h__