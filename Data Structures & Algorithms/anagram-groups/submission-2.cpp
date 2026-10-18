class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> lexCommons;
        for(int i = 0; i < strs.size(); i++){
            string dupe = strs[i];
            sort(dupe.begin(), dupe.end());
            lexCommons[dupe].push_back(strs[i]);
        }
        vector<vector<string>> returnVec;
        for(auto i : lexCommons){
            returnVec.push_back(i.second);
        }
        return returnVec;
    }
};
