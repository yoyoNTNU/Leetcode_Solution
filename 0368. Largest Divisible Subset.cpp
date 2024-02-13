class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> dp(nums.size(),1);

        sort(nums.begin(),nums.end());
        int max_=1;
        for(int i=0;i<nums.size();++i){
            for(int j=i-1;j>=0;--j){
                if(!(nums[i]%nums[j])){
                    dp[i]=max(dp[j]+1,dp[i]);
                    max_=max(max_,dp[i]);
                }
            }
        }

        vector<int> res;
        int num=-1;
        for(int i=nums.size()-1;i>=0;--i){
            if(dp[i]==max_&&(num==-1 || !(num%nums[i]))){
                res.insert(res.begin(),nums[i]);
                max_--;
                num=nums[i];
            }
        }
        return res;
    }
};
