//
// Created by song on 2022/9/24.
//

class Solution {
public:
    vector<int> nums;

    vector<int> sortArray(vector<int> &nums) {
        this->nums = nums;
        helper(0, nums.size() - 1);
        return this->nums;
    }

    void helper(int l, int r) {
        if (l >= r) return;
        int m = (l + r) / 2;
        helper(l, m);
        helper(m + 1, r);
        int li = l, ri = m + 1, i = 0;
        vector<int> tmp(r - l + 1);
        while (li <= m && ri <= r) {
            if (nums[li] < nums[ri]) {
                tmp[i++] = nums[li++];
            } else {
                tmp[i++] = nums[ri++];
            }
        }
        while (li <= m) tmp[i++] = nums[li++];
        while (ri <= r) tmp[i++] = nums[ri++];
        for (int i = 0; i < tmp.size(); i++) nums[l + i] = tmp[i];
    }
};