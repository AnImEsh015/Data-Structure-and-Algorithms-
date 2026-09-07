class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        vector<string>arr;

        if(nums.empty()) return arr;

        for(int i = 1; i < n; i++){
            if((long long)nums[i] != (long long)nums[i-1] + 1){
                if(nums[l] == nums[i-1]){
                    arr.push_back(to_string(nums[l]));
                }
                else{
                    arr.push_back(to_string(nums[l]) + "->" + to_string(nums[i-1]));
                }
                l = i;   
            }
        }
        if(l == n-1){
            arr.push_back(to_string(nums[l]));
        }
        else{
            arr.push_back(to_string(nums[l]) + "->" + to_string(nums[n-1]));
        }
        return arr;
    }
};