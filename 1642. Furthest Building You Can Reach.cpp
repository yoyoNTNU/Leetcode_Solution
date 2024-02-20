class Solution {
public:
    Solution(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> p;
        int i=0;

        for(i=1;i<heights.size();++i){
            int t=heights[i]-heights[i-1];
            if(t<=0)continue;
            
            bricks-=t;
            p.push(t); 

            if(bricks<0){
                bricks+=p.top();
                ladders--;
                p.pop();
            }

            if(ladders<0) break;
        }
        return i-1;
    }
};
