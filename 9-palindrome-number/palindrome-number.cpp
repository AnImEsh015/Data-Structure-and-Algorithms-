class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        long long remainder = 0;
        long long compare = x;
        while(x != 0){
            remainder = remainder*10 + x%10;
            x = x/10;
        }
        return compare == remainder;
    }
};