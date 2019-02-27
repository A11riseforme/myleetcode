class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> result;
        unordered_map<string, int> table;
        stringstream ss(A+" "+B);
        string tmp;
        while (ss >> tmp) {
            ++table[tmp];
        }
        for (auto i: table) {
            if (i.second == 1) {
                result.push_back(i.first);
            }
        }
        return result;
    }
};