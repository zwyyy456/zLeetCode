// Created by zwyyy456 at 2023/05/07 16:38
// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

/*
1010. Pairs of Songs With Total Durations Divisible by 60 (Medium)
You are given a list of songs where the `ith` song has a duration of `time[i]` seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by `60`.
Formally, we want the number of indices `i`, `j` such that `i < j` with `(time[i] + time[j]) % 60 ==
0`.

**Example 1:**

```
Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60

```

**Example 2:**

```
Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.

```

**Constraints:**

- `1 <= time.length <= 6 * 10⁴`
- `1 <= time[i] <= 500`

*/

#include <bits/stdc++.h>
#include <unordered_map>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  public:
    int numPairsDivisibleBy60(vector<int> &time) {
        vector<int> arr(21);
        for (int i = 1; i <= 20; ++i) {
            arr[i] = i * 60;
        }
        int n = time.size();
        unordered_map<int, int> song;
        for (int i = 0; i < n; ++i) {
        	song[time[i]]++;
        }
        long res = 0;
        for (int i = 0; i < n; ++i) {
        	int dura = time[i];
        	--song[dura];
        	for (int i = 1; i <= 20; ++i) {
        		if (song.find(arr[i] - dura) != song.end()) {
        			res += song[arr[i] - dura];
        		}
        	}
        	++song[dura];
        }
        return res / 2;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> time;
    LeetCodeIO::scan(cin, time);

    Solution *obj = new Solution();

    auto res = obj->numPairsDivisibleBy60(time);

    LeetCodeIO::print(out_stream, res);
    cout << "output: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
