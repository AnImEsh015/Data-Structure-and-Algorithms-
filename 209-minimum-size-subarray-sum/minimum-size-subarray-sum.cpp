class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int total_sum = 0;
        int total_size = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            total_sum += nums[i];

            while (total_sum >= target) {
                total_size = min(i - left + 1, total_size);

                total_sum -= nums[left];
                left++;
            }
        }

        return total_size == INT_MAX ? 0 : total_size;
    }
};