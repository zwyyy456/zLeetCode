// Created by zwyyy456 at 2023/06/15 10:33
// leetgo: 1.3.1
// https://leetcode.cn/problems/longest-uncommon-subsequence-ii/

package main

import (
	"bufio"
	"fmt"
	"os"

	. "github.com/j178/leetgo/testutils/go"
)

// @lc code=begin

func findLUSlength(strs []string) (ans int) {

	return
}

// @lc code=end

func main() {
	stdin := bufio.NewReader(os.Stdin)
	strs := Deserialize[[]string](ReadLine(stdin))
	ans := findLUSlength(strs)

	fmt.Println("\noutput:", Serialize(ans))
}
