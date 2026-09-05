class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>ans;

        while(true){
            int sum = 0;

            while(n > 0){
                int last_dig = n % 10;
                sum = sum + last_dig*last_dig;
                n = n/10;
            }

            n = sum;

            if (n == 1) return true;

            if(ans.find(n) != ans.end()) return false;

            ans.insert(n);
        }
    }
};