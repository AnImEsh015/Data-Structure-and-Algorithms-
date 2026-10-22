class Solution {
public:
    int minOperations(string s) {
        if(is_sorted(s.begin(),s.end())) return 0;

        int n = s.size();

        if(n <= 2) return -1;

        char min = *min_element(s.begin(),s.end());
        char maxi = *max_element(s.begin(), s.end());

        if(s[0] == min || s[n-1] == maxi) return 1;

        if(s[0] == maxi && s[n-1] == min){
            int count_min = 0;
            int count_maxi = 0;

            for(int i = 0; i < n; i++){
                if(s[i] == min) count_min++;

                if(s[i] == maxi) count_maxi++;
            }

            if(count_min == 1 && count_maxi == 1){
                return 3;
            }
        }

        return 2;
    }
};