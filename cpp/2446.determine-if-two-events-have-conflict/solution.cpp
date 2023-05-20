// Created by zwyyy456 at 2023/05/17 10:55
// https://leetcode.com/problems/determine-if-two-events-have-conflict/

/*
2446. Determine if Two Events Have Conflict (Easy)
You are given two arrays of strings that represent two inclusive events that happened **on the same
day**, `event1` and `event2`, where:

- `event1 = [startTime₁, endTime₁]` and
- `event2 = [startTime₂, endTime₂]`.

Event times are valid 24 hours format in the form of `HH:MM`.

A **conflict** happens when two events have some non-empty intersection (i.e., some moment is common
to both events).

Return `true` if there is a conflict between two events. Otherwise, return  `false`.

**Example 1:**

```
Input: event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
Output: true
Explanation: The two events intersect at time 2:00.

```

**Example 2:**

```
Input: event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
Output: true
Explanation: The two events intersect starting from 01:20 to 02:00.

```

**Example 3:**

```
Input: event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
Output: false
Explanation: The two events do not intersect.

```

**Constraints:**

- `evnet1.length == event2.length == 2.`
- `event1[i].length == event2[i].length == 5`
- `startTime₁ <= endTime₁`
- `startTime₂ <= endTime₂`
- All the event times follow the `HH:MM` format.

*/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> event1; LeetCodeIO::scan(cin, event1);
	vector<string> event2; LeetCodeIO::scan(cin, event2);

	Solution *obj = new Solution();

	auto res = obj->haveConflict(event1, event2);

	LeetCodeIO::print(out_stream, res);
	cout << "output: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
