#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views) {
        map<string, vector<int>> my_map;
        for (int i = 0; i < creators.size(); i++) {
            my_map[creators[i]][0] += views[i];
        }
        vector<string> author;
        int sum = 0;
        for (auto cur = my_map.cbegin(); cur != my_map.cend(); cur++) {
            if (cur->second > sum) {
                author.clear();
                author.push_back(cur->first);
                sum = cur->second;
            } else if (cur->second == sum) {
                author.push_back(cur->first);
            }
        }
        // unordered_set<string> myset(author.begin(), author.end());
        int max_view = -1;
        string max_id;
        vector<vector<string>> res;
        for (int i = 0; i < author.size(); i++) {
            for (int j = 0; j < creators.size(); j++) {
                if (creators[j] == author[i]) {
                    if (views[j] > max_view) {
                        max_id = ids[j];
                        max_view = views[j];
                    }
                }
            }
            res.push_back({author[i], max_id});
            max_view = -1;
        }
        return res;
    }
};