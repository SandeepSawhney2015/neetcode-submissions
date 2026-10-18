class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> integers;
        for(int i = 0; i < nums.size(); i++){
            if(integers.count(nums[i]) == 0){
                integers.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};