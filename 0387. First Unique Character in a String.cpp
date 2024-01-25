//array
class Solution {
public:
    int firstUniqChar(string s) {
        int v[26]={};

        for(char c:s){
            v[c-'a']++;
        }

        for(int i=0;i<s.length();++i){
            if(v[s[i]-'a']==1) return i;
        }
        return -1;
    }
};

//map
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> count;
        unordered_map<char,int> poi;
        
        for(int i=0;i<s.length();++i){
            count[s[i]]++;
            poi[s[i]]=i;
        }
        int res=INT_MAX;
        for(auto it:count){
            if(it.second==1){
                res=min(res,poi[it.first]);
            }
        }
        return res==INT_MAX?-1:res;
    }
};

