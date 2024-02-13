class Solution {
public:
    Solution(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int dp[r][c][c];

        for(int i=0;i<r;i++){
            for(int j=0;j<c;++j){
                for(int k=0;k<c;++k){
                    dp[i][j][k]=-1;
                }
            }
        }

        for(int i=0;i<r;++i){
            for(int j=i+1;j<c-i-1;++j){
                grid[i][j]=-1;
            }
        }
        dp[0][0][c-1]=grid[0][0]+grid[0][c-1];
        for(int i=1;i<r;++i){
            for(int j=0;j<c;++j){
                for(int k=0;k<c;++k){
                    for(int l=-1;l<2;++l){
                        for(int m=-1;m<2;++m){
                            if(j+l>=0 && j+l<c && k+m>=0 && k+m<c){
                                if(j==k){
                                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j+l][k+m]+grid[i][j]);
                                    //printf("same row:%d R1:%d R2:%d val:%d\n",i,j+l,k+m,dp[i-1][j+l][k+m]+grid[i][j+l]);
                                }
                                else{
                                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j+l][k+m]+grid[i][j]+grid[i][k]);
                                    //printf("not same row:%d R1:%d R2:%d val:%d\n",i,j+l,k+m,dp[i-1][j+l][k+m]+grid[i][j+l]+grid[i][k+m]);
                                }
                                
                            }
                        }
                    }
                }
            }
        }

        int res=-1;

        for(int i=0;i<c;++i){
            for(int j=0;j<c;++j){
                res=max(res,dp[r-1][i][j]);
            }
        }
        
        return res;
    }
};
