// Created by zwyyy456 at 2023/07/18 23:04
// leetgo: 1.3.2
// https://leetcode.cn/problems/walking-robot-simulation-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Robot {
  public:
    Robot(int width, int height) :
        wid_(width), hei_(height) {
    }

    void step(int num) {
        int tmp = direct % 4;
        switch (direct % 4) {
        case 0:
            // 回到原点之后，就统一了
            if (num <= wid_ - 1 - posx) {
                posx += num;
                return;
            } else if (num > wid_ - 1 - posx && num <= wid_ - 1 - posx + hei_ - 1 - posy) {
                posy += num - (wid_ - 1 - posx);
                posx = wid_ - 1;
                direct += 1;
                return;
            } else if (num > wid_ - 1 - posx + hei_ - 1 - posy && num <= hei_ - 1 - posy + wid_ - 1 - posx + wid_ - 1) {
                posx = wid_ - 1 - (num - (hei_ - 1 - posy) - (wid_ - 1 - posx));
                posy = hei_ - 1;
                direct += 2;
                return;
            } else if (num > hei_ - 1 - posy + wid_ - 1 - posx + wid_ - 1 && num <= hei_ - 1 - posy + wid_ - 1 - posx + wid_ - 1 + hei_ - 1) {
                posy = hei_ - 1 - (num - (hei_ - 1 - posy + wid_ - 1 + wid_ - 1 - posx));
                posx = 0;
                direct += 3;
                return;
            }
        case 1: {
            if (num <= hei_ - 1 - posy) {
                posy += num;
                return;
            } else if (num > hei_ - 1 - posy && num <= hei_ - 1 - posy + posx) {
                posx = posx - (num - (hei_ - 1 - posy));
                posy = hei_ - 1;
                direct += 1;
                return;
            } else if (num > hei_ - 1 - posy + posx && num <= hei_ - 1 - posy + posx + hei_ - 1) {
                posy = hei_ - 1 - (num - (hei_ - 1 - posy + posx));
                posx = 0;
                direct += 2;
                return;
            }
        }
        case 2: {
            if (num <= posx) {
                posx -= num;
                return;
            } else if (num > posx && num <= posx + posy) {
                posy -= num - posx;
                posx = 0;
                direct += 1;
                return;
            }
        }
        case 3: {
            if (num <= posy) {
                posy -= num;
                return;
            } else if (num > posy && num <= posy + (wid_ - 1 - posx)) {
                posx += num - posy;
                posy = 0;
                direct += 1;
                return;
            } else if (num > posy + (wid_ - 1 - posx) && num <= posy + (wid_ - 1 - posx) + hei_ - 1) {
                posy = num - (posy + wid_ - 1 - posx);
                posx = wid_ - 1;
                direct += 2;
                return;
            } else if (num > posy + (wid_ - 1 - posx) + hei_ - 1 && num < posy + (wid_ - 1 - posx) + hei_ - 1 + wid_ - 1) {
                posx = wid_ - 1 - (num - (posy + wid_ - 1 - posx + hei_ - 1 + wid_ - 1));
                posy = hei_ - 1;
                direct += 3;
                return;
            } else if (num > posy + (wid_ - 1 - posx) + hei_ - 1 + wid_ - 1 && num < posy + (wid_ - 1 - posx) + hei_ - 1 + wid_ - 1 + hei_ - 1) {
                posy = hei_ - 1 - (num - (posy + (wid_ - 1 - posx) + hei_ - 1 + wid_ - 1 + hei_ - 1));
                posx = 0;
                direct += 4;
                return;
            }
        }
        }
        switch (tmp) {
        case 0:
            num -= hei_ - 1 - posy + wid_ - 1 - posx + wid_ - 1 + hei_ - 1;
            break;
        case 1:
            num -= hei_ - 1 - posy + posx + hei_ - 1;
            break;
        case 2:
            num -= posx + posy;
            break;
        case 3:
            num -= posy + (wid_ - 1 - posx) + hei_ - 1 + wid_ - 1 + hei_ - 1;
            break;
        }
        num = num % (wid_ - 1 + hei_ - 1 + wid_ - 1 + hei_ - 1);
        direct = 0;
        if (num == 0) {
            direct = 3;
        } else if (num > 0 && num <= wid_ - 1) {
            posx = num;
            posy = 0;
            direct = 0;
        } else if (num > wid_ - 1 && num <= wid_ - 1 + hei_ - 1) {
            posx = wid_ - 1;
            posy = num - (wid_ - 1);
            direct = 1;
        } else if (num > wid_ - 1 + hei_ - 1 && num <= wid_ - 1 + hei_ - 1 + wid_ - 1) {
            posx = (wid_ - 1) - (num - (wid_ - 1 + hei_ - 1));
            posy = hei_ - 1;
            direct = 2;
        } else {
            posx = 0;
            posy = hei_ - 1 - (wid_ - 1 + hei_ - 1 + wid_ - 1);
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
        return "right";
    }

  private:
    int direct = 0;
    using pii = pair<int, int>;
    pii pos = {0, 0};
    int posx = 0;
    int posy = 0;
    int wid_;
    int hei_;
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
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
