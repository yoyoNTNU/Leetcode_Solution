class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        int count;
        for(int i:arr){
            mp[i]++;
        }
        count=mp.size();

        vector<int> v(1e5+1,0);
        for(auto it:mp){
            v[it.second]++;
        }

        for(int i=1;i<1e5+1;++i){
            if(k<=0) return count;
            else{
                if(k<v[i]*i){
                    count-=(k/i);
                    return count;
                }
                else{
                    k-=v[i]*i;
                    count-=v[i];
                }
            }
        }
        return 0;
    }
};
