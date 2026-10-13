class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
            });
        vector<pair<int,int>> sortedq;
        for (int i = 0; i < queries.size(); i++){ 
            sortedq.push_back({queries[i], i});
        }
        sort(sortedq.begin(), sortedq.end()); 
        auto comp = [](auto& a, auto& b) {
            return (a.second - a.first + 1) > (b.second - b.first + 1);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq;

        int i = 0;
        int q = 0;
        vector<int> res(sortedq.size(), -1);

        while (q < sortedq.size()) {
            while (i < intervals.size() && (intervals[i][0] <= sortedq[q].first)) {
                pq.push({intervals[i][0], intervals[i][1]});
                i++;
            }

            while (!pq.empty() && pq.top().second < sortedq[q].first) {
                pq.pop();
            }
            if (pq.empty()) {
                res[sortedq[q].second] = -1;
            } else {
                res[sortedq[q].second] = pq.top().second - pq.top().first + 1;
            }
            q++;
        }


        return res;
    }
};
