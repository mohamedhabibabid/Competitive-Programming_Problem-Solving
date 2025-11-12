//https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/description/comments/3227414/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> monotonic_stack;
        map<bool, bool> mp{{{1, 1}, {0, 0}}};
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            
            if (monotonic_stack.empty()) {
                monotonic_stack.push_back(nums[i]);
                count += mp[nums[i]];
            } else {
                if (nums[i] > monotonic_stack.back()) {
                    count++;
                    monotonic_stack.push_back(nums[i]);
                } else if (nums[i] < monotonic_stack.back()) {
                    while (monotonic_stack.size() &&
                           monotonic_stack.back() > nums[i]) {
                        monotonic_stack.pop_back();
                    }
                    if ((monotonic_stack.size() &&
                        monotonic_stack.back() != nums[i]) || monotonic_stack.empty()) {
                        monotonic_stack.push_back(nums[i]);
                        count += mp[nums[i]]; 
                    }
                }
            }
           
        }
        return count;
    }
};
