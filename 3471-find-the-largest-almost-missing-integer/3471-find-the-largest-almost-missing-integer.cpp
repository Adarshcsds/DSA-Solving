class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        int n = nums.size();

        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> st;

            // Elements in current window
            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            // Count this window once for every distinct element
            for (int x : st) {
                count[x]++;
            }
        }

        int ans = -1;

        for (auto &[x, freq] : count) {
            if (freq == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};