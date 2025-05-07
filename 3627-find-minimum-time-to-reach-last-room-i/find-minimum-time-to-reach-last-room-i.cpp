class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        pq.push({0, {0, 0}});
        visited[0][0] = true;

        while (!pq.empty()) {
            P top = pq.top();
            pq.pop();

            int time = top.first;
            int row = top.second.first;
            int col = top.second.second;
            int y[4] = {-1, 1, 0, 0};
            int x[4] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {
                int newRow = row + y[i];
                int newCol = col + x[i];

                if (newRow < n && newRow >= 0 && newCol < m && newCol >= 0 &&
                    !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    int extraTime = 1;
                    if (moveTime[newRow][newCol] > time) {
                        extraTime += (moveTime[newRow][newCol] - time);
                    }
                    extraTime += time;
                    if (newRow == n - 1 && newCol == m - 1) {
                        return extraTime;
                    }
                    pq.push({extraTime, {newRow, newCol}});
                }
            }
        }
        return -1;
    }
};