class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest_seq = 1;

        if (n == 0) return 0;

        unordered_set<int> ans;

        for(int i = 0; i < n; i++){
            ans.insert(nums[i]);
        }

        for(auto it: ans){
            if(ans.find(it-1) == ans.end()){
                int count = 1;
                int x = it;
                while(ans.find(x+1) != ans.end()){
                    x += 1;
                    count++;
                }
                longest_seq = max(longest_seq,count);
            }
        }
        return longest_seq;
    }
};