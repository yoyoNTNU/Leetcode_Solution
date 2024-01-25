class Solution {
public:
    void solve(int i,int& n,vector<int> &v){
        if(i>n)return ;

        v.emplace_back(i);
        for(int j=0;j<=9;++j){
            solve(i*10+j,n,v);
        }
    }


    vector<int> lexicalOrder(int n) {
        vector <int> res;
        
        for(int i=1;i<=9;++i){
            solve(i,n,res);
        }
        return res;
    }
};
