class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> s;
        for(auto str: strs){
            string temp = str;
            sort(temp.begin(),temp.end());
            s[temp].push_back(str);
        }
        vector<vector<string>> res;
        for(auto p : s){
            res.push_back(p.second);
        }
        return res;
    }
};