class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        int prodPre;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(i == nums.size() - 1){
                result[i] = 1;
                prodPre = nums[i];
            } else {
                //replacement init
                result[i] = prodPre;
                prodPre *= nums[i];
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                prodPre = nums[i];
            } else {
                result[i] *= prodPre;
                prodPre *= nums[i];
            }
        }
        return result;
    }
};
