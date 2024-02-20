class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& m) {
        sort(m.begin(),m.end());

        vector<long long> RoomCanBeUsedTime(n,0);
        vector<int> RoomUseCount(n,0);

        for(auto& v:m){
            long long time=LLONG_MAX;
            int roomNum=-1;
            for(int i=0;i<n;++i){
                if(RoomCanBeUsedTime[i]<=v[0]){
                    roomNum=i;
                    time=RoomCanBeUsedTime[i];
                    break;
                }
                if(time>RoomCanBeUsedTime[i]){
                    roomNum=i;
                    time=RoomCanBeUsedTime[i];
                }
            }
            if(time<v[0]){
                RoomCanBeUsedTime[roomNum]=v[1];
            }
            else{
                int duration=v[1]-v[0];
                RoomCanBeUsedTime[roomNum]+=duration;
            }
            
            RoomUseCount[roomNum]++;
        }

        int ans=INT_MIN;
        int roomNum=-1;
        for(int i=0;i<n;++i){
            if(ans<RoomUseCount[i]){
                ans=RoomUseCount[i];
                roomNum=i;
            }
        }

        return roomNum;
    }
};
