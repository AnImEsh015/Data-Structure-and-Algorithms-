class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> freq;
        for (string word : words) {
            freq[word]++;
        }

        vector<int> ans;

        int n = words.size();
        int wordSize = words[0].size();
        int windowSize = n * wordSize;

        if (windowSize > s.size()) {
            return ans;
        }

        for (int offset = 0; offset < wordSize; offset++) {
            int left = offset;
            int right = offset;
            int count = 0;

            unordered_map<string, int> curr;

            while (right + wordSize <= s.size()) {
                string word = s.substr(right, wordSize);
                right += wordSize;

                if (freq.count(word)) {
                    curr[word]++;
                    count++;

                    while (curr[word] > freq[word]) {
                        string leftWord = s.substr(left, wordSize);
                        curr[leftWord]--;
                        left += wordSize;
                        count--;
                    }

                    if (count == n) {
                        ans.push_back(left);

                        string leftWord = s.substr(left, wordSize);
                        curr[leftWord]--;
                        left += wordSize;
                        count--;
                    }
                }
                else {
                    curr.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return ans;
    }
};