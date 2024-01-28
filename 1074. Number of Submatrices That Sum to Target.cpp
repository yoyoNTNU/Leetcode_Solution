class Solution {
public:
    Solution(){
        std::ios::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> prefix(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                prefix[i][j]=prefix[i-1][j]-prefix[i-1][j-1]+prefix[i][j-1]+matrix[i-1][j-1];
            }
        }
        

        int res=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                for(int k=i;k<=n;++k){
                    for(int l=j;l<=m;++l){
                        res+=target==(prefix[k][l]-prefix[i-1][l]-prefix[k][j-1]+prefix[i-1][j-1]);
                    }
                }
            }
        }

        return res;


    }
};
