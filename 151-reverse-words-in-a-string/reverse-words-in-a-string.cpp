class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        int i = 0;

        while(i < n){
            while(i < n && s[i] == ' ') i++;

            if(i >= n) break;
            string word = "";
            while(i < n && s[i] != ' '){
                word+= s[i];
                i++;
            }
            if (ans.size() == 0) ans = word;
            else{
                ans = word + ' ' + ans;
            }
        }
        return ans;
    }
};