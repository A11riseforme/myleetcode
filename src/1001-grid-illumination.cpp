class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> result;
        unordered_map<int, int> row, col, diagonal1, diagonal2;
        unordered_map<int, unordered_set<int>> lampOn;
        int r, c;
        for (auto i : lamps) {
            r = i[0];
            c = i[1];
            lampOn[r].insert(c);
            ++row[r];
            ++col[c];
            ++diagonal1[r + c];
            ++diagonal2[r - c];
        }
        for (auto i : queries) {
            r = i[0];
            c = i[1];
            if (row[r] || col[c] || diagonal1[r + c] || diagonal2[r - c]) {
                result.push_back(1);
                for (auto y = r - 1; y <= r + 1; ++y) {
                    for (auto x = c - 1; x <= c + 1; ++x) {
                        if (lampOn[y].find(x) != end(lampOn[y])) {
                            lampOn[y].erase(x);
                            --row[y];
                            --col[x];
                            --diagonal1[y + x];
                            --diagonal2[y - x];
                        }
                    }
                }
            } else {
                result.push_back(0);
            }
        }
        return result;
    }
};
