class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        
        if(n == 0) return 0;

        for(int i = 1; i <= 32; i++){
            ans <<= 1;
            ans = (ans | (n & 1));
            n >>= 1;
        }
        return ans;
    }
};