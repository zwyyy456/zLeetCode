#include <string>
#include <vector>
#include <unordered_map>
using std::string, std::vector, std::unordered_map;

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<string, int> map;
        vector<int> answer(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                map[words[i].substr(0, j + 1)]++;
            }
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                answer[i] += map[words[i].substr(0, j + 1)];
            }
        }
        return answer;
    }
};