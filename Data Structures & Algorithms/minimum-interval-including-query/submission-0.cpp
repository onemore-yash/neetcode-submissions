class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n=queries.size();
        int m=intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto&a,auto&b){
            return a[0]<b[0];
        });

        vector<int>sorted=queries;
        sort(sorted.begin(),sorted.end());
        map<int,int>res;

        auto cmp=[](const vector<int>&a,const vector<int>&b){
            return a[0]>b[0] || (a[0]==b[0] && a[1]>b[1]);
        };
        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>minHeap(cmp);
        int i=0;
        for(int q:sorted){
            while(i<m && intervals[i][0]<=q){
                int l=intervals[i][0];
                int r=intervals[i][1];
                minHeap.push({r-l+1,r});
                i++;
            }

            while(!minHeap.empty() && minHeap.top()[1]<q) minHeap.pop();

            res[q]=minHeap.empty()?-1:minHeap.top()[0];
        }

        vector<int>result(n);
        for(int j=0;j<n;j++)result[j]=res[queries[j]];
        return result;
    }
};
