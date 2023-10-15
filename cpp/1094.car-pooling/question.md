# [1094. Car Pooling][link] (Medium)

[link]: https://leetcode.com/problems/car-pooling/

There is a car with `capacity` empty seats. The vehicle only drives east (i.e., it cannot turn
around and drive west).

You are given the integer `capacity` and an array `trips` where `trips[i] = [numPassengersᵢ, fromᵢ,
toᵢ]` indicates that the `iᵗʰ` trip has `numPassengersᵢ` passengers and the locations to pick them
up and drop them off are `fromᵢ` and `toᵢ` respectively. The locations are given as the number of
kilometers due east from the car's initial location.

Return `true` if it is possible to pick up and drop off all passengers for all the given trips, or
`false` otherwise.

**Example 1:**

```
Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
```

**Example 2:**

```
Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
```

**Constraints:**

- `1 <= trips.length <= 1000`
- `trips[i].length == 3`
- `1 <= numPassengersᵢ <= 100`
- `0 <= fromᵢ < toᵢ <= 1000`
- `1 <= capacity <= 10⁵`
