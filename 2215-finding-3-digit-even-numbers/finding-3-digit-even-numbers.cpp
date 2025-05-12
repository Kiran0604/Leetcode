class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
    set<int> result;
    int n = digits.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == i) continue;
            for (int k = 0; k < n; ++k) {
                if (k == i || k == j) continue;

                int a = digits[i];
                int b = digits[j];
                int c = digits[k];

                if (a == 0) continue;       
                if (c % 2 != 0) continue;  

                int number = a * 100 + b * 10 + c;
                result.insert(number);
            }
        }
    }
    return vector<int>(result.begin(), result.end());
}
};