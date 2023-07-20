// Created by zwyyy456 at 2023/07/19 09:58
// leetgo: 1.3.1
// https://leetcode.cn/problems/walking-robot-simulation-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Robot {
public:
    Robot(int width, int height) {

    }
    
    void step(int num) {

    }
    
    vector<int> getPos() {

    }
    
    string getDir() {

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names; LeetCodeIO::scan(cin, method_names);

	Robot *obj;

	const unordered_map<string, function<void()>> methods = {
		{ "Robot", [&]() {
			int width; LeetCodeIO::scan(cin, width); cin.ignore();
			int height; LeetCodeIO::scan(cin, height); cin.ignore();
			obj = new Robot(width, height);
			out_stream << "null,";
		} },
		{ "step", [&]() {
			int num; LeetCodeIO::scan(cin, num); cin.ignore();
			obj->step(num);
			out_stream << "null,";
		} },
		{ "getPos", [&]() {
			cin.ignore();
			LeetCodeIO::print(out_stream, obj->getPos()); out_stream << ',';
		} },
		{ "getDir", [&]() {
			cin.ignore();
			LeetCodeIO::print(out_stream, obj->getDir()); out_stream << ',';
		} },
	};
	cin >> ws;
	out_stream << '[';
	for (auto &&method_name : method_names) {
		cin.ignore(2);
		methods.at(method_name)();
	}
	cin.ignore();
	out_stream.seekp(-1, ios_base::end); out_stream << ']';

	cout << "
output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
