class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        unordered_set<int> inRange;
        for(int i : nums){
            inRange.insert(i);
        }
        int longestSequence = 1;
        for(int i : nums){
            if(inRange.count(i - 1) == 0){
                bool notFound = false;
                int sequence = 1;
                int current = i;
                while(!notFound){
                    if(inRange.count(current + 1) != 0){
                        sequence++;
                        current++;
                    } else {
                        notFound = true;
                    }
                }
                if(longestSequence < sequence){
                    longestSequence = sequence;
                }
            } else {
                continue;
            }
        }
        return longestSequence;
    }
};
