/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        for(int lastNonZero=0, curr=0; curr<size; ++curr) {
            if(nums[curr] != 0) {
                swap(nums[lastNonZero], nums[curr]);
                lastNonZero++;
            }
        }
    }
};
