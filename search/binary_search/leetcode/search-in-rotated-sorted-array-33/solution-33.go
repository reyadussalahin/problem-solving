// https://leetcode.com/problems/search-in-rotated-sorted-array
// Time: O(logN)  Space: O(1)
// Input: nums = [4,5,6,7,0,1,2], target = 0

package leetcode

func findSmallestElement(nums []int, lo int, hi int) int {
	for lo < hi {
		mid := lo + (hi-lo)/2

		if nums[mid] > nums[hi] {
			lo = mid + 1 // that's how we reach a sorted array
		} else {
			hi = mid // that's normal, then we can use left sub-list
		}
	}
	return lo
}

func search(nums []int, target int) int {
	if len(nums) == 0 {
		return -1
	}
	lo := 0
	hi := len(nums) - 1

	pivot := findSmallestElement(nums, lo, hi) // smallest element

	if target >= nums[pivot] && target <= nums[hi] {
		lo = pivot
	} else {
		hi = pivot
	}

	// regular binary search
	for lo <= hi {
		mid := lo + (hi-lo)/2
		if nums[mid] == target {
			return mid
		} else if nums[mid] > target {
			// use left sub-list
			hi = mid - 1
		} else {
			// use right sub-list
			lo = mid + 1
		}
	}
	return -1
}
