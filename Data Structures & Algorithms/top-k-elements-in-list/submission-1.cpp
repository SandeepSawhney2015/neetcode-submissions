class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashTable;
        for(int i = 0; i < nums.size(); i++){
            hashTable[nums[i]]++;
        }
        vector<vector<int>> watchFrequencies;
        watchFrequencies.resize(nums.size());
        for(auto i : hashTable){
            watchFrequencies[i.second - 1].push_back(i.first);
        }
        vector<int> backTrackReturn;
        int i = watchFrequencies.size() - 1;
        while(backTrackReturn.size() < k){
            if(watchFrequencies[i].size() == 0){
                i--;
            } else {
                for(int j = 0; j < watchFrequencies[i].size(); j++){
                    backTrackReturn.push_back(watchFrequencies[i][j]);
                }
                i--;
            }
        }
        return backTrackReturn;
    }
};
