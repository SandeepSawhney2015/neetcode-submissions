class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums2indecies;
        for(int i = 0; i < nums.size(); i++){
            int toFind = target - nums[i];
            if(nums2indecies.count(toFind) == 1){
                return {nums2indecies[toFind], i};
            } else {
                nums2indecies[nums[i]] = i;
            }
        }
        return {};
    }
};
