// https://leetcode.com/problems/single-number/description/?envType=problem-list-v2&envId=bit-manipulation
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int find=0;
        for(auto x: nums){
            find^=x;
        }
        return find;
    }
};
