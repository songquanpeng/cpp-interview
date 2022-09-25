//
// Created by song on 2022/9/25.
//

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        helper(nums, 0, nums.size() - 1);
        return nums;
    }

    void helper(vector<int> &nums, int l, int r) {
        if (l >= r) return;
        int p = rand() % (r - l + 1) + l;
        swap(nums[p], nums[r]);
        int i = l;
        for (int j = l; j <= r - 1; j++) {
            if (nums[j] < nums[r]) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[r]);
        helper(nums, l, i - 1);
        helper(nums, i + 1, r);
    }

    // TODO: while based solution
};