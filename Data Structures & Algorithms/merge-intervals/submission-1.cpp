class Solution {
    bool overlap(vector<int>&l,vector<int>&r){
        return l[1]>=r[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        vector<int>temp=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(overlap(temp,intervals[i])){
                temp[0]=min(temp[0],intervals[i][0]);
                temp[1]=max(temp[1],intervals[i][1]);
            }else{
                ans.push_back(temp);
                temp=intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
