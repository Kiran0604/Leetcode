class Solution {
public:
    void dfs(int node, vector<int>& edges, vector<int>& dist, int d) {
        while (node != -1 && dist[node] == -1) {
            dist[node] = d++;
            node = edges[node];
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);

        dfs(node1, edges, dist1, 0);
        dfs(node2, edges, dist2, 0);

        int minDist = INT_MAX, answer = -1;

        for (int i = 0; i < n; ++i) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    answer = i;
                }
            }
        }

        return answer;
    }
};
