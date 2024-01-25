class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1=m-1;
        int idx2=n-1;
        int i;
        for(i=m+n-1;i>=0&&idx1>=0&&idx2>=0;--i){
            if(nums2[idx2]>=nums1[idx1]){
                nums1[i]=nums2[idx2];
                idx2--;
            }
            else{
                nums1[i]=nums1[idx1];
                idx1--;
            }
        }

        while(idx1>=0){
            nums1[i--]=nums1[idx1--];
        }

        while(idx2>=0){
            nums1[i--]=nums2[idx2--];
        }
        return;
    }
};
