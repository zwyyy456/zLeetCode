// Created by zwyyy456 at 2023/11/12 14:15
// leetgo: 1.3.8
// https://leetcode.com/problems/range-module/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class RangeModule {
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        
    }
    
    bool queryRange(int left, int right) {
        
    }
    
    void removeRange(int left, int right) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names;
	LeetCodeIO::scan(cin, method_names);

	RangeModule *obj;
	const unordered_map<string, function<void()>> methods = {
		{ "RangeModule", [&]() {
			cin.ignore();
			obj = new RangeModule();
			out_stream << "null,";
		} },
		{ "addRange", [&]() {
			int left; LeetCodeIO::scan(cin, left); cin.ignore();
			int right; LeetCodeIO::scan(cin, right); cin.ignore();
			obj->addRange(left, right);
			out_stream << "null,";
		} },
		{ "queryRange", [&]() {
			int left; LeetCodeIO::scan(cin, left); cin.ignore();
			int right; LeetCodeIO::scan(cin, right); cin.ignore();
			LeetCodeIO::print(out_stream, obj->queryRange(left, right)); out_stream << ',';
		} },
		{ "removeRange", [&]() {
			int left; LeetCodeIO::scan(cin, left); cin.ignore();
			int right; LeetCodeIO::scan(cin, right); cin.ignore();
			obj->removeRange(left, right);
			out_stream << "null,";
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
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
