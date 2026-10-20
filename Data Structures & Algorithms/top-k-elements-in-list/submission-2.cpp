class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> groups;
        for(int i : nums){
            groups[i]++;
        }
        vector<vector<int>> buckets(nums.size());
        buckets.resize(nums.size());
        for(auto i : groups){
            buckets[i.second - 1].push_back(i.first);
        }
        vector<int> res;
        int i = buckets.size() - 1;
        while(res.size() != k){
            if(buckets[i].size() != 0){
                for(int j = 0; j < buckets[i].size(); j++){
                    res.push_back(buckets[i][j]);
                }
            }
            i--;
        }
        return res;
    }
};
