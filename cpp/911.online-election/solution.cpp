// Created by zwyyy456 at 2023/10/10 10:41
// leetgo: 1.3.8
// https://leetcode.com/problems/online-election/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class TopVotedCandidate {
  public:
    TopVotedCandidate(vector<int> &persons, vector<int> &times) :
        winner(times.size()), time(times) {
        unordered_map<int, int> cnt;
        for (int i = 0; i < times.size(); ++i) {
            ++cnt[persons[i]];
            if (cnt[persons[i]] >= mx) {
                mx = cnt[persons[i]];
                mx_id = persons[i];
                winner[i] = mx_id;
            } else {
                winner[i] = mx_id;
            }
        }
    }
    int bfind(vector<int> &time, int target) {
        int l = 0, r = time.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (time[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (l < time.size() && time[l] == target) {
            return l;
        }
        return l - 1;
    }
    int q(int t) {
        int const idx = bfind(time, t);
        return winner[idx];
    }

  private:
    vector<int> winner;
    vector<int> time;
    int mx = 0;
    int mx_id = -1;
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    TopVotedCandidate *obj;
    const unordered_map<string, function<void()>> methods = {
        {"TopVotedCandidate", [&]() {
             vector<int> persons;
             LeetCodeIO::scan(cin, persons);
             cin.ignore();
             vector<int> times;
             LeetCodeIO::scan(cin, times);
             cin.ignore();
             obj = new TopVotedCandidate(persons, times);
             out_stream << "null,";
         }},
        {"q", [&]() {
             int t;
             LeetCodeIO::scan(cin, t);
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->q(t));
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
