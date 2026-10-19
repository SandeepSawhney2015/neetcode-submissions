class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products(nums.size(), -1);
        int prod;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(i == nums.size() - 1){
                products[i] = 1;
                prod = nums[i];
            } else {
                products[i] = prod;
                prod *= nums[i];
            }
        }
        prod = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                products[i] *= 1;
                prod = nums[i];
            } else {
                products[i] *= prod;
                prod *= nums[i];
            }
        }
        return products;
    }
};
