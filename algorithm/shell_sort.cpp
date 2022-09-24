//
// Created by song on 2022/9/24.
//

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        int n = nums.size();
        for (int step = n / 2; step >= 1; step /= 2) {  // steps
            for (int i = 0; i < step; i++) {  // groups (i is the start idx)
                for (int j = i + step; j < n; j += step) {  // iter a group
                    for (int k = j; k - step >= 0; k -= step) {
                        if (nums[k] >= nums[k - step]) {
                            break;
                        }
                        swap(nums[k], nums[k - step]);
                    }
                }

            }
        }
        return nums;
    }
};