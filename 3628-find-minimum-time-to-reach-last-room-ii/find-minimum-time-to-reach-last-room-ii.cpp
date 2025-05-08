class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        using P = tuple<int, int, int, int>; // time, moves, row, col
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(2, false)));
        
        pq.push({0, 0, 0, 0}); // start at (0,0) with 0 time and 0 moves
        vis[0][0][0] = true;
        int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [time, moves, r, c] = pq.top(); pq.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dy[i], nc = c + dx[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                
                int newMoves = moves + 1;
                int parity = newMoves % 2;
                if (vis[nr][nc][parity]) continue;
                
                int cost = (newMoves % 2 == 1) ? 1 : 2; // odd moves: 1, even moves: 2
                int wait = max(0, moveTime[nr][nc] - time); // wait if arriving early
                int newTime = time + wait + cost;
                
                if (nr == n-1 && nc == m-1) return newTime;
                
                vis[nr][nc][parity] = true;
                pq.push({newTime, newMoves, nr, nc});
            }
        }
        return -1;
    }
};