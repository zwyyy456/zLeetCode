// Created by zwyyy456 at 2023/07/19 09:39
// leetgo: 1.3.1
// https://leetcode.com/problems/walking-robot-simulation-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Robot {
  public:
    Robot(int width, int height) {
        wid_ = width;
        hei_ = height;
    }

    void step(int num) {
        total += num;
        if (total == 0) {
            return;
        }
        int realmove = total % (wid_ - 1 + hei_ - 1 + wid_ - 1 + hei_ - 1);
        if (realmove == 0) {
            direct = 3;
            posx = 0;
            posy = 0;
        } else if (realmove > 0 && realmove <= wid_ - 1) {
            direct = 0;
            posx = realmove;
            posy = 0;
        } else if (realmove > wid_ - 1 && realmove <= wid_ - 1 + hei_ - 1) {
            posx = wid_ - 1;
            posy = realmove - (wid_ - 1);
            direct = 1;
        } else if (realmove > wid_ - 1 + hei_ - 1 && realmove <= wid_ - 1 + hei_ - 1 + wid_ - 1) {
            posy = hei_ - 1;
            posx = wid_ - 1 - (realmove - (wid_ - 1 + hei_ - 1));
            direct = 2;
        } else {
            posx = 0;
            posy = hei_ - 1 - (realmove - (wid_ - 1 + hei_ - 1 + wid_ - 1));
            direct = 3;
        }
    }

    vector<int> getPos() {
        return {posx, posy};
    }

    string getDir() {
        switch (direct % 4) {
        case 0:
            return "East";
        case 1:
            return "North";
        case 2:
            return "West";
        case 3:
            return "South";
        }
        return "";
    }

  private:
    int posx = 0;
    int posy = 0;
    int direct = 0;
    int wid_;
    int hei_;
    int total = 0;
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<string> method_names;
    LeetCodeIO::scan(cin, method_names);

    Robot *obj;

    const unordered_map<string, function<void()>> methods = {
        {"Robot", [&]() {
             int width;
             LeetCodeIO::scan(cin, width);
             cin.ignore();
             int height;
             LeetCodeIO::scan(cin, height);
             cin.ignore();
             obj = new Robot(width, height);
             out_stream << "null,";
         }},
        {"step", [&]() {
             int num;
             LeetCodeIO::scan(cin, num);
             cin.ignore();
             obj->step(num);
             out_stream << "null,";
         }},
        {"getPos", [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->getPos());
             out_stream << ',';
         }},
        {"getDir", [&]() {
             cin.ignore();
             LeetCodeIO::print(out_stream, obj->getDir());
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

    cout << "
        output : " << out_stream.rdbuf() << endl;

                 delete obj;
    return 0;
}
