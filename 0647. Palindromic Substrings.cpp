class Solution {
public:
    
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.length();++i){
            int shift=0;
            //odd
            while(i-shift>=0 && i+shift<=s.length()){
                if(s[i-shift]==s[i+shift]){
                    ans++;
                    shift++;
                }
                else{
                    break;
                }
            }
            //even
            shift=0;
            while(i-shift>=0 && i+1+shift<=s.length()){
                if(s[i-shift]==s[i+1+shift]){
                    ans++;
                    shift++;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};
