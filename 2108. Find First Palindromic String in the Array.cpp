class Solution {
public:
    Solution(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    bool isPalindromic(string &s){
        int n=s.length();
        if(n%2==0){
            for(int i=0;i<n/2;++i){
                if(s[n/2+i]!=s[n/2-1-i]){
                    return false;
                }
            }
            return true;
        }
        else{
            for(int i=0;i<=n/2;++i){
               if(s[n/2+i]!=s[n/2-i]){
                    return false;
                }
            }
            return true;
        }
    }
    string firstPalindrome(vector<string>& words) {
        for(string s:words){
            if(isPalindromic(s)){
                return s;
            }
        }
        return "";
    }
};
