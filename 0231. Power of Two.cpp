class Solution {
public:
    bool isPowerOfTwo(int n) {
        int t=1;
        for(int i=0;i<31;++i){
            
            if(t==n){
                return true;
            }
            else if(t>n){
                return false;
            }
            if(i!=30)t*=2;
        }
    return false;
    }
};
