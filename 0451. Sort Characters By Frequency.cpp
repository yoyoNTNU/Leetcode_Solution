class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> v;
        int mp[75]={};
        for(char c:s){
            mp[c-'0']++;
        }

        for(int i=0;i<75;++i){
            v.emplace_back(make_pair(mp[i],i+'0'));
        }
        sort(v.rbegin(),v.rend());

        string res="";
        for(auto t:v){
            for(int i=0;i<t.first;++i){
                res+=t.second;
            }
        }
        return res;
    }
};
