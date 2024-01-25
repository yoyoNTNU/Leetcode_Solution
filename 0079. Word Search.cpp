class Solution {
public:
    bool dfs(vector<vector<char>>& board,vector<vector<bool>>& visited,int r,int c,string& word,int cur){
        //cout<<r<<" "<<c<<" "<<board[r][c]<<" "<<cur<<" "<<word[cur]<<endl;
        if(board[r][c]==word[cur]){
            //cout<<r<<" "<<c<<" "<<board[r][c]<<endl;
            if(cur==word.length()-1){return true;}
            visited[r][c]=true;
            bool res=false;
            if(r>0 && !visited[r-1][c]){
                res=res||dfs(board,visited,r-1,c,word,cur+1);
            }
            if(c<board[0].size()-1 && !visited[r][c+1]){
                res=res||dfs(board,visited,r,c+1,word,cur+1);
            }
            if(r<board.size()-1 && !visited[r+1][c]){
                res=res||dfs(board,visited,r+1,c,word,cur+1);
            }
            if(c>0 && !visited[r][c-1]){
                res=res||dfs(board,visited,r,c-1,word,cur+1);
            }

            visited[r][c]=false;
            return res;
        }
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));

        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(dfs(board,visited,i,j,word,0))return true;
            }
        }
         return false;
    }
};
