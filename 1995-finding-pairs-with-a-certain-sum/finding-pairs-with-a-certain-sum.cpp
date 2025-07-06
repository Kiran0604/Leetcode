class FindSumPairs {
private:
    vector<int> nums1, nums2;
    unordered_map<int, int> freq2; 

public:
    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        nums1 = n1;
        nums2 = n2;
        for (int num : nums2) {
            freq2[num]++;
        }
    }

    void add(int index, int val) {
        int oldVal = nums2[index];
        freq2[oldVal]--; // decrease old value frequency
        if (freq2[oldVal] == 0) {
            freq2.erase(oldVal);
        }

        nums2[index] += val;
        freq2[nums2[index]]++; // increase new value frequency
    }

    int count(int tot) {
        int count = 0;
        for (int a : nums1) {
            int target = tot - a;
            if (freq2.count(target)) {
                count += freq2[target];
            }
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */