class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> max_ele(n);
        vector<int> min_ele(n);

        max_ele[0] = nums[0];
        min_ele[n-1] = nums[n-1];

        for(int i = 1; i < n; i++){
            max_ele[i] = max(max_ele[i-1],nums[i]);
        }

        for(int i = n-2; i >= 0; i--){
            min_ele[i] = min(min_ele[i+1],nums[i]);
        }

        for(int i = 0; i < n; i++){
            int ans = max_ele[i] - min_ele[i];
            if(ans <= k){
                return i;
            }
        }
        return -1;
    }
};