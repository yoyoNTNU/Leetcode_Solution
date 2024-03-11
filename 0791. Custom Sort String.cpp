class Solution {
public:
    string customSortString(string order, string s) {
        int count[26]={};
        unordered_map<char,int> mp;
        int i=0;
        for(char c:order){
            mp[c]=i++;
        }
        vector<pair<int,char>> ans;
        for(char c:s){
            ans.emplace_back(make_pair(mp[c],c));
        }

        sort(ans.begin(),ans.end());

        string res="";
        for(pair<int,char> p:ans){
            res=res+p.second;
        }
        return res;
    }
};
