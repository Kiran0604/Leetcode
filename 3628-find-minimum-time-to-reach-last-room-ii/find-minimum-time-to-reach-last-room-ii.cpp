class Solution {
public:
    typedef vector<int> P; // {time, {row, col}}
    
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        
        dist[0][0] = 0;
        pq.push({0,0,0,0});
        
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        
        while (!pq.empty()) {
            auto X = pq.top(); 
            int curTime=X[0],r=X[1],c=X[2],flag=X[3];
            pq.pop();    
            if (r == n - 1 && c == m - 1)
                return curTime;
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc]==INT_MAX) {
                    if(dist[r][c]<=moveTime[nr][nc])
                    {
                        if(flag==1)
                            dist[nr][nc]=moveTime[nr][nc]+2;
                        else 
                            dist[nr][nc]=moveTime[nr][nc]+1;
                    }
                    else 
                    {
                        if(flag==1)
                            dist[nr][nc]=min(dist[r][c]+2,dist[nr][nc]);
                        else 
                            dist[nr][nc]=min(dist[r][c]+1,dist[nr][nc]);
                    }
                    
                    pq.push({dist[nr][nc],nr,nc,!flag});
                }
            }
        }
        return -1;
    }
};
