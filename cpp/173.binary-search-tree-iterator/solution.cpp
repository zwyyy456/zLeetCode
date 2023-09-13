// Created by zwyyy456 at 2023/09/13 09:54
// leetgo: 1.3.8
// https://leetcode.com/problems/binary-search-tree-iterator/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        
    }
    
    int next() {
        
    }
    
    bool hasNext() {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names;
	LeetCodeIO::scan(cin, method_names);

	BSTIterator *obj;
	const unordered_map<string, function<void()>> methods = {
		{ "BSTIterator", [&]() {
			TreeNode* root; LeetCodeIO::scan(cin, root); cin.ignore();
			obj = new BSTIterator(root);
			out_stream << "null,";
		} },
		{ "next", [&]() {
			cin.ignore();
			LeetCodeIO::print(out_stream, obj->next()); out_stream << ',';
		} },
		{ "hasNext", [&]() {
			cin.ignore();
			LeetCodeIO::print(out_stream, obj->hasNext()); out_stream << ',';
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
