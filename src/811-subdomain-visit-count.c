#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
// hash_map is the best data structure for this problem
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> result;
        unordered_map<string,int> asdf;
        for (auto &i: cpdomains) {
            auto pos = i.find(' ');
            int cnt = stoi(i.substr(0,pos));
            cout << cnt << endl;
            while (pos != string::npos) {
                cout << i.substr(pos+1) << endl;
                asdf[i.substr(pos+1)] += cnt;
                pos = i.find('.', pos+1);
            }
        }
        for (auto &[i,j]: asdf) {
            result.push_back(to_string(j) + " " + i);
        }
        return result;
    }
    vector<std::string> split(const string& s, char delimiter = ' ') {
        vector<string> result;
        string tmp;
        istringstream ss(s);
        while (getline(ss, tmp, delimiter)) {
            result.push_back(tmp);
        }
        return result;
    }
};
*/

int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }

    return 0;
}