// Created by zwyyy456 at 2023/10/11 09:38
// leetgo: 1.3.8
// https://leetcode.com/problems/reward-top-k-students/

#include <bits/stdc++.h>
#include <queue>
#include <string>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int getnum(string &str, unordered_set<string> &pos, unordered_set<string> &neg) {
        int n = str.size();
        int l = 0, r = 0;
        int cnt_pos = 0, cnt_neg = 0;
        while (r < n) {
            while (r < n && str[r] != ' ') {
                ++r;
            }
            if (pos.find(str.substr(l, r - l)) != pos.end()) {
                ++cnt_pos;
            }
            if (neg.find(str.substr(l, r - l)) != neg.end()) {
                ++cnt_neg;
            }
            l = ++r;
        }
        return cnt_pos - cnt_neg;
    }
    vector<int> topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback, vector<string> &report, vector<int> &student_id, int k) {
        unordered_set<string> pos(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> neg(negative_feedback.begin(), negative_feedback.end());
        auto cmp = [](pair<int, int> p1, pair<int, int> p2) {
            if (p1.second == p2.second) {
                return p1.first > p2.first;
            }
            return p1.second < p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < report.size(); ++i) {
            pq.emplace(student_id[i], getnum(report[i], pos, neg));
        }
        vector<int> res;
        for (int i = 0; i < k && !pq.empty(); ++i) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> positive_feedback;
    LeetCodeIO::scan(cin, positive_feedback);
    vector<string> negative_feedback;
    LeetCodeIO::scan(cin, negative_feedback);
    vector<string> report;
    LeetCodeIO::scan(cin, report);
    vector<int> student_id;
    LeetCodeIO::scan(cin, student_id);
    int k;
    LeetCodeIO::scan(cin, k);

    Solution *obj = new Solution();
    auto res = obj->topStudents(positive_feedback, negative_feedback, report, student_id, k);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
