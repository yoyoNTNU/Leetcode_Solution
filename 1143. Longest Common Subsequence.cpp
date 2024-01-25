class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1len=text1.length();
        int t2len=text2.length();
        vector<vector<int>> dp(t1len,vector<int>(t2len,0));

        bool check=false;
        for(int i=0;i<t2len;++i){
            if(check || text2[i]==text1[0]){
                check=true;
                dp[0][i]=1;
            }
        }

        check=false;
        for(int i=0;i<t1len;++i){
            if(check || text1[i]==text2[0]){
                check=true;
                dp[i][0]=1;
            }
        }

        for(int i=1;i<t1len;++i){
            for(int j=1;j<t2len;++j){
                if(text1[i]==text2[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[t1len-1][t2len-1];
    }
};
