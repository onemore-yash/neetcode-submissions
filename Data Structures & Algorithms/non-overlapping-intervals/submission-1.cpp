class Solution {

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        sort(intervals.begin(),intervals.end());
        vector<int>temp=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(temp[1]>intervals[i][0]){
                if(temp[1]>intervals[i][1])temp=intervals[i];
                ans++;
            }else{
                temp=intervals[i];
            }
        }
        return ans;
    }
};
