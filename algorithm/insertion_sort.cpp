//
// Created by song on 2022/9/24.
//

class Solution {
public:
    // [已排序，未排序]
    // 每次为第一个未排序的值在已排序区寻找插入点
    vector<int> sortArray(vector<int> &nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j + 1] >= nums[j]) {
                    break;
                }
                swap(nums[j + 1], nums[j]);
            }
        }
        return nums;
    }
};