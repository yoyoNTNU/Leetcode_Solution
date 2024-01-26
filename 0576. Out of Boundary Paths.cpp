class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove==0)return 0;
        int dp[51][51][51]={};
        int mod=1e9+7;
        for(int i=0;i<n;++i){
            dp[0][i][0]++;
            dp[m-1][i][0]++;
        }
        for(int i=0;i<m;++i){
            dp[i][0][0]++;
            dp[i][n-1][0]++;
        }

        for(int i=1;i<maxMove;++i){
            for(int j=0;j<m;++j){
                for(int k=0;k<n;++k){
                    if(j-1>=0){
                        dp[j][k][i]+=dp[j-1][k][i-1]%mod;
                        dp[j][k][i]%=mod;
                    }
                    if(j+1<m){
                        dp[j][k][i]+=dp[j+1][k][i-1]%mod;
                        dp[j][k][i]%=mod;
                    }
                    if(k-1>=0){
                        dp[j][k][i]+=dp[j][k-1][i-1]%mod;
                        dp[j][k][i]%=mod;
                    }
                    if(k+1<n){
                        dp[j][k][i]+=dp[j][k+1][i-1]%mod;
                        dp[j][k][i]%=mod;
                    }
                }
            }
        }
        int res=0;
        for(int i=0;i<maxMove;++i){
            res+=dp[startRow][startColumn][i]%mod;
            res%=mod;
        }

        return res;
    }
};
