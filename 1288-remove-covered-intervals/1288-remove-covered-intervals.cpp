class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        int cnt = 0, end = 0;

        for (auto& i : inter) {
            if (i[1] > end) {
                cnt++;
                end = i[1];
            }
        }

        return cnt;
    }
};