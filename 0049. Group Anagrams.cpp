class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;

        for(string s:strs){
            string temp=s;
            sort(temp.begin(),temp.end());
            mp[temp].emplace_back(s);
        }

        for(auto it:mp){
            res.emplace_back(it.second);
        }
        return res;
    }
};
