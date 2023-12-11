// Created by zwyyy456 at 2023/11/10 21:49
// leetgo: 1.3.8
// https://leetcode.cn/problems/minimum-limit-of-balls-in-a-bag/

package main

import (
	"bufio"
	"fmt"
	"os"

	. "github.com/j178/leetgo/testutils/go"
)

// @lc code=begin

func minimumSize(nums []int, maxOperations int) (ans int) {

	return
}

// @lc code=end

func main() {
	stdin := bufio.NewReader(os.Stdin)
	nums := Deserialize[[]int](ReadLine(stdin))
	maxOperations := Deserialize[int](ReadLine(stdin))
	ans := minimumSize(nums, maxOperations)

	fmt.Println("\noutput:", Serialize(ans))
}
