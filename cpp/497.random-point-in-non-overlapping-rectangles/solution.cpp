// Created by zwyyy456 at 2023/10/14 19:09
// leetgo: 1.3.8
// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    Solution(vector<vector<int>> &rects) :
        recs(rects) {
        point_cnt.push_back(0); // 前缀和的概念
        for (auto &vec : rects) {
            long tmp = ((long)vec[3] - vec[1]) * ((long)vec[2] - vec[0]);
            total_cnt += tmp;
            point_cnt.push_back(total_cnt);
        }
    }

    vector<int> pick() {
        long cnt = (rand() % total_cnt + total_cnt) % total_cnt + 1;
        int idx = bfind(cnt);
        long new_id = cnt - point_cnt[idx - 1]; // 在矩形的第多少个点处
        long len = recs[idx - 1][3] - recs[idx - 1][1];
        long wid = recs[idx - 1][2] - recs[idx - 1][0];
        int x = (new_id - 1) % wid + recs[idx - 1][0];
        int y = (new_id - 1) / wid + recs[idx - 1][1];
        return {x, y};


    }

  private:
    vector<long> point_cnt;
    vector<vector<int>> recs;
    long total_cnt;
    int bfind(long target) {
    	int l = 0, r = point_cnt.size();
    	while (l < r) {
    		int mid = l + (r - l) / 2;
    		if (point_cnt[mid] < target) {
    			l = mid + 1;
    		} else {
    			r = mid;
    		}
    	}
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    Solution *obj;
    const unordered_map<string, function<void()>> methods = {
        {"Solution", [&]() {
             vector<vector<int>> rects;
             LeetCodeIO::scan(cin, rects);
             cin.ignore();
             int rectsSize;
             LeetCodeIO::scan(cin, rectsSize);
             cin.ignore();
             obj = new Solution(rects, rectsSize);
             out_stream << "null,";
         }},
        {"pick", [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->pick());
             out_stream << ',';
         }},
    };
    cin >> ws;
    out_stream << '[';
    for (auto &&method_name : method_names) {
        cin.ignore(2);
        methods.at(method_name)();
    }
    cin.ignore();
    out_stream.seekp(-1, ios_base::end);
    out_stream << ']';
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
