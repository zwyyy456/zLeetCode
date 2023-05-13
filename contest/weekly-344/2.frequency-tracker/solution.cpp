// Created by zwyyy456 at 2023/05/07 14:28
// https://leetcode.com/problems/frequency-tracker/
// https://leetcode.com/contest/weekly-contest-344/problems/frequency-tracker/

/*
2671. Frequency Tracker (Medium)
Design a data structure that keeps track of the values in it and answers some queries regarding
their frequencies.

Implement the `FrequencyTracker` class.

- `FrequencyTracker()`: Initializes the `FrequencyTracker` object with an empty array initially.
- `void add(int number)`: Adds `number` to the data structure.
- `void deleteOne(int number)`: Deletes **one** occurence of `number` from the data structure. The
data structure **may not contain** `number`, and in this case nothing is deleted.
- `bool hasFrequency(int frequency)`: Returns `true` if there is a number in the data structure that
occurs `frequency` number of times, otherwise, it returns `false`.

**Example 1:**

```
Input
["FrequencyTracker", "add", "add", "hasFrequency"]
[[], [3], [3], [2]]
Output
[null, null, null, true]

Explanation
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.add(3); // The data structure now contains [3]
frequencyTracker.add(3); // The data structure now contains [3, 3]
frequencyTracker.hasFrequency(2); // Returns true, because 3 occurs twice

```

**Example 2:**

```
Input
["FrequencyTracker", "add", "deleteOne", "hasFrequency"]
[[], [1], [1], [1]]
Output
[null, null, null, false]

Explanation
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.add(1); // The data structure now contains [1]
frequencyTracker.deleteOne(1); // The data structure becomes empty []
frequencyTracker.hasFrequency(1); // Returns false, because the data structure is empty

```

**Example 3:**

```
Input
["FrequencyTracker", "hasFrequency", "add", "hasFrequency"]
[[], [2], [3], [1]]
Output
[null, false, null, true]

Explanation
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.hasFrequency(2); // Returns false, because the data structure is empty
frequencyTracker.add(3); // The data structure now contains [3]
frequencyTracker.hasFrequency(1); // Returns true, because 3 occurs once

```

**Constraints:**

- `1 <= number <= 10⁵`
- `1 <= frequency <= 10⁵`
- At most, `2 * 10⁵` calls will be made to `add`, `deleteOne`, and `hasFrequency` in **total**.

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class FrequencyTracker {
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        int freq = nums_[number]++;
        if(--freq_[freq] == 0) {
        	freq_.erase(freq);
        }
        ++freq_[freq + 1];
    }
    
    void deleteOne(int number) {
        if (nums_.find(number) != nums_.end()) {
        	int freq = nums_[number];
        	if (--nums_[number] == 0) {
        		nums_.erase(number);
        		--freq_[freq];
        		if (freq_[freq] == 0) {
        			freq_.erase(freq);
        		}
        	} else {
        		if (--freq_[freq] == 0) {
        			freq_.erase(freq);
        		}
        		++freq_[freq - 1];
        	}

        }
    }
    
    bool hasFrequency(int frequency) {
        return freq_.find(frequency) != freq_.end();
    }
private:
	unordered_map<int, int> nums_;
	unordered_map<int, int> freq_;
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names; LeetCodeIO::scan(cin, method_names);

	FrequencyTracker *obj;

	const unordered_map<string, function<void()>> methods = {
		{ "FrequencyTracker", [&]() {
			cin.ignore();
			obj = new FrequencyTracker();
			out_stream << "null,";
		} },
		{ "add", [&]() {
			int number; LeetCodeIO::scan(cin, number); cin.ignore();
			obj->add(number);
			out_stream << "null,";
		} },
		{ "deleteOne", [&]() {
			int number; LeetCodeIO::scan(cin, number); cin.ignore();
			obj->deleteOne(number);
			out_stream << "null,";
		} },
		{ "hasFrequency", [&]() {
			int frequency; LeetCodeIO::scan(cin, frequency); cin.ignore();
			LeetCodeIO::print(out_stream, obj->hasFrequency(frequency)); out_stream << ',';
		} },
	};
	out_stream << '[';
	for (auto &&method_name : method_names) {
		cin.ignore(2);
		methods.at(method_name)();
	}
	cin.ignore();
	out_stream.seekp(-1, ios_base::end); out_stream << ']';

	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
