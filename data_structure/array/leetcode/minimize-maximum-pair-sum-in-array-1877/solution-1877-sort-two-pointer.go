// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/discuss/1554515/Go-Submission-with-Sort-and-Two-Pointer-Approach

package main

import "sort"

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func minPairSum(nums []int) int {
	sort.Ints(nums)
	var maxPair = 0
	var lp, rp = 0, len(nums) - 1
	for lp < rp {
		maxPair = max(maxPair, nums[lp]+nums[rp])
		lp++
		rp--
	}
	return maxPair
}
