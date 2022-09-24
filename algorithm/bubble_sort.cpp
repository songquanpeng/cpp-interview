//
// Created by song on 2022/9/24.
//

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                }
            }
        }
        return nums;
    }
};