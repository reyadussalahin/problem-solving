// https://leetcode.com/problems/search-insert-position/discuss/249092/Come-on-forget-the-binary-search-patterntemplate!-Try-understand-it!

package leetcode

func searchInsert(nums []int, target int) int {
	var l, r = 0, len(nums) - 1
	for l < r {
		mid := l + (r-l)/2

		if nums[mid] == target {
			return mid
		} else if nums[mid] > target {
			r = mid // right could be the result
		} else {
			l = mid + 1 // mid + 1 could be the result
		}
	}
	// 1 element left at the end
	// post-processing
	if nums[l] < target {
		return l + 1
	} else {
		return l
	}
}
