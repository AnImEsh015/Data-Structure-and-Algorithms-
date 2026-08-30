class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_ele = INT_MAX;
        int max_ele = INT_MIN;

        for(int i = 0; i < nums.size() ; i++){
            min_ele = min(min_ele,nums[i]);
            max_ele = max(max_ele,nums[i]);
        }

        int max_val_idx = 0;
        int min_val_idx = 0;

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] == min_ele){
                min_val_idx = i;
            }

            if(nums[i] == max_ele){
                max_val_idx = i;
            }
        }
        int n = nums.size();

        int left = max(min_val_idx, max_val_idx) + 1;
        int right = n - min(min_val_idx, max_val_idx);

        int first = min(min_val_idx, max_val_idx);
        int last = max(min_val_idx, max_val_idx);

        int both = first + 1 + n - last;

        return min({left, right, both});
    }
};