class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(trainers.begin(), trainers.end());
        sort(players.begin(), players.end());
        int m = players.size(), n = trainers.size(), j = 0, c = 0, i = 0;
        while (i < m && j < n) {
            if (players[i] <= trainers[j]) {
                c++;
                i++;
            }
            j++;
        }
        return c;
    }
};