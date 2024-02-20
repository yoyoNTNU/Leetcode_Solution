class Solution {
public:
    Solution(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int missingNumber(vector<int>& nums) {
        int n=nums.size();

        int sum=n*(n+1)/2;

        return sum-accumulate(nums.begin(),nums.end(),0);
    }
};
