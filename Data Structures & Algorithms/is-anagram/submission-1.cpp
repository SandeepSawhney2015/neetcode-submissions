class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> letterFreq1;
        unordered_map<char, int> letterFreq2;
        for(char i : s){
            letterFreq1[i] += 1;
        }
        for(char j : t){
            letterFreq2[j] += 1;
        }
        for(auto lf1 : letterFreq1){
            if(letterFreq2[lf1.first] != lf1.second){
                return false;
            }
        }
        for(auto lf2 : letterFreq2){
            if(letterFreq1[lf2.first] != lf2.second){
                return false;
            }
        }
        return true;
    }
};
