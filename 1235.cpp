class Solution {
public:
    struct Interval{
        int start, finish, weight;
    };

    int binarySearch(vector<Interval> &intervals, int j) {
    int start = 0;
    int end = j - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (intervals[mid].finish <= intervals[j].start) {
        if (intervals[mid + 1].finish <= intervals[j].start) {
            start = mid + 1;
        } else {
            return mid;
        }
        } else {
        end = mid - 1;
        }
    }
    return -1;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
        int n = startTime.size();
        vector<Interval> intervals(n);
        for(int i = 0; i<n;i++){
            intervals[i]={startTime[i],endTime[i],profit[i]};
        }
        vector<int> M(n+1,0);
        vector<int> p(n+1,0);

          sort(intervals.begin(), intervals.end(),
       [](const Interval &a, const Interval b) { return a.finish < b.finish; });

        for (int j = 1; j <= n; ++j) {
            int w_j = intervals[j - 1].weight;
            p[j] = binarySearch(intervals, j - 1) + 1;
            M[j] = max(w_j + M[p[j]], M[j - 1]);
        }
                
        return M[n];
    }
};