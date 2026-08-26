class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0;
        int right = n-1;

        while((left < right) && (numbers[left] + numbers[right] != target)){
            if(numbers[left] + numbers[right] < target){
                left++;
            }
            else{
                right--;
            }
        }
        vector<int> ans ={left+1,right+1};
        return ans;


    }
};