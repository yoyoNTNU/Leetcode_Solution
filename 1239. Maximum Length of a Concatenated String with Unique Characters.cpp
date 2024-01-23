class Solution {
public:
    int res=0;

    int len(int* record){
        int ans=0;
        for(int i=0;i<26;++i){
            if(record[i]==1){
                ans++;
            }
        }
        return ans;
    }

    void select(vector<string>& arr, int* record,int cur){
        if(cur==arr.size()){
            res=max(len(record),res);
            return ;
        }
        int j=0;
        bool fail=false;
        for(;j<arr[cur].length();++j){
            record[arr[cur][j]-'a']++;
            if(record[arr[cur][j]-'a']==2){
                fail=true;
                break;
            }
        }
        if(!fail){
           select(arr,record,cur+1);
        }
        for(;j>=0;--j){
            record[arr[cur][j]-'a']--;
        }
        select(arr,record,cur+1);
        return ;
        
    
    }

    int maxLength(vector<string>& arr) {
        int record[26]={};
        select(arr,record,0);
        return res;
    }
};
