/*
Given an integer array arr, count element x if x+1 is also in array.
If there're duplicates, count the element separately.
*/

class Solution {
public:
    int countElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        int sum = 0;
        for (int i : nums) {
            if (mp[i+1] >= 1)
                sum += mp[i];
        }
        return sum;
    }
};
