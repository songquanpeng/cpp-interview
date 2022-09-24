//
// Created by song on 2022/9/24.
//

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int idx = i;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[idx]) {
                    idx = j;
                }
            }
            swap(nums[idx], nums[i]);
        }
        return nums;
    }
};