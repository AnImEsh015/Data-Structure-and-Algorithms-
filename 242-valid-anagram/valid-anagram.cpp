class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp;
        int n = s.size();
        int m = t.size();
        
        if (m != n) return false;

        for(int i = 0; i < s.size(); i++){
            mpp[s[i]]++;
        }

        for(int i = 0 ; i < m; i++){
            if(mpp.find(t[i]) != mpp.end() && mpp[t[i]] != 0){
                mpp[t[i]]--;
            }
            else return false;
        }
        return true;
    }
};