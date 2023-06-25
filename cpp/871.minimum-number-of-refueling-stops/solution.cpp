// Created by Bob at 2023/02/14 19:51
// https://leetcode.com/problems/minimum-number-of-refueling-stops/

/*
871. Minimum Number of Refueling Stops (Hard)

A car travels from a starting position to a destination which is `target` miles east of the starting
position.
There are gas stations along the way. The gas stations are represented as an array `stations` where
`stations[i] = [positionᵢ, fuelᵢ]` indicates that the `ith` gas station is `positionᵢ` miles east of
the starting position and has `fuelᵢ` liters of gas.
The car starts with an infinite tank of gas, which initially has `startFuel` liters of fuel in it.
It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may
stop and refuel, transferring all the gas from the station into the car.
Return the minimum number of refueling stops the car must make in order to reach its destination. If
it cannot reach the destination, return `-1`.
Note that if the car reaches a gas station with `0` fuel left, the car can still refuel there. If
the car reaches the destination with `0` fuel left, it is still considered to have arrived.
**Example 1:**
```
Input: target = 1, startFuel = 1, stations = []
Output: 0
Explanation: We can reach the target without refueling.
```
**Example 2:**
```
Input: target = 100, startFuel = 1, stations = [[10,100]]
Output: -1
Explanation: We can not reach the target (or even the first gas station).
```
**Example 3:**
```
Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
Explanation: We start with 10 liters of fuel.
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.
```
**Constraints:**
- `1 <= target, startFuel <= 10⁹`
- `0 <= stations.length <= 500`
- `1 <= positionᵢ < positionᵢ+₁ < target`
- `1 <= fuelᵢ < 10⁹`
*/

// @lc code=begin
#include <functional>
#include <queue>
#include <vector>
using std::priority_queue;
using std::vector;
class Solution {
  public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
        int n = stations.size();
        if (n == 0) {
            if (startFuel >= target)
                return 0;
            return -1;
        }
        if (startFuel < stations[0][0])
            return -1;
        int res = 0;
        auto cmp = [&](vector<int> &v1, vector<int> &v2) {
            return v1[1] <= v2[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp); // 油最多的加油站在堆顶
        pq.push(stations[0]);
        int cur_fuel = startFuel - stations[0][0];
        for (int i = 1; i < n; i++) {
            while (!pq.empty() && cur_fuel < stations[i][0] - stations[i - 1][0]) {
                cur_fuel += pq.top()[1];
                pq.pop();
                res++;
            }
            if (cur_fuel < stations[i][0] - stations[i - 1][0]) {
                return -1;
            }
            pq.push(stations[i]);
            cur_fuel = cur_fuel - (stations[i][0] - stations[i - 1][0]);
        }
        while (!pq.empty() && cur_fuel < target - stations[n - 1][0]) {
            cur_fuel += pq.top()[1];
            res++;
            pq.pop();
        }
        if (cur_fuel < target - stations[n - 1][0])
            return -1;
        return res;
    }
};
// @lc code=end
