// https://leetcode.com/problems/merge-intervals/discuss/1561393/Go-Submission-with-Explanation
// Time: O(n log(n))  Space: O(n)

package leetcode

import "sort"

func merge(intervals [][]int) [][]int {
	var n = len(intervals)
	if n == 1 {
		return intervals
	}
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	var res [][]int

	// intervals = [[1,3],[2,6],[8,10],[15,18]]   -> [[1,6],[8,10],[15,18]]
	// intervals = [[1,3],[2,6],[3,7][15,18]      -> [[1,7],[15,18]]
	tmpInterval := intervals[0]
	for i := 1; i < n; i++ {
		var ok = isOverlap(tmpInterval, intervals[i])
		if ok {
			// overlap detected, as intervals are sorted, just update maximum Ending index
			tmpInterval[1] = max(intervals[i][1], tmpInterval[1])
		} else {
			// append stored tmpInterval to res and continue with next iteration
			res = append(res, tmpInterval)
			tmpInterval = intervals[i]
		}
	}
	// merge last interval
	res = append(res, tmpInterval)
	return res
}

// Stored: (1,3)  and curr(i) : (2,6)
// Stored ending time >= (i) starting time    -> Overlap detected
func isOverlap(i1 []int, i2 []int) bool {
	if i1[1] >= i2[0] {
		return true
	}
	return false
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
