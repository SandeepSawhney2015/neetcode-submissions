class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products(nums.size(), -1);
        //pass one basically initializes the vector that is why we replace all the -1's with the base prod
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
        //pass 2 fixes it with a foreward pass to update both sides of the multiplication (excluding the current one)
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
