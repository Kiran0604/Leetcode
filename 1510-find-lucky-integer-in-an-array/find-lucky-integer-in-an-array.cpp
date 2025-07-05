class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> hash;
        int res = -1;
        for (int num : arr) {
            hash[num]++;
        }
        for (int num : arr) {
            if (num == hash[num])
                res = max(res, num);
        }
        return res;
    }
};