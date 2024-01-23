class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i:nums){
            ++mp[i];
        }
        vector<int> res(2,0);
        for(auto it:mp){
            res[0]+=(it.second/2);
        }
        res[1]=n-(res[0]*2);
        return res;
    }
};
