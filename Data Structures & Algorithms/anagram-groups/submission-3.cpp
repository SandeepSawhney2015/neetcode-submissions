class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for(string i : strs){
            string x = i;
            sort(x.begin(), x.end());
            groups[x].push_back(i);
        }
        vector<vector<string>> returnVec;
        for(auto i : groups){
            returnVec.push_back(i.second);
        }
        return returnVec;
    }
};
