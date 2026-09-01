class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mpp1;
        unordered_map<string,char> mpp2;

        stringstream ss(s);
        string word;

        int i = 0;

        while(ss >> word){
            if(i >= pattern.size()) return false;

            char ch = pattern[i];

            if(mpp1.count(ch) && mpp1[ch] != word) return false;

            if(mpp2.count(word) && mpp2[word] != ch) return false;

            mpp1[ch] = word;
            mpp2[word] = ch;

            i++;
        }
        return i == pattern.size();
    }
};