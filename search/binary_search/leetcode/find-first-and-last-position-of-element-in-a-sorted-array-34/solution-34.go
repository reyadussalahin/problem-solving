// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Time: O(logN)  Space: O(1)
// 98.7% faster than other go submissions

package leetcode

func searchRange(nums []int, target int) []int {
	result := []int{-1, -1}
	if len(nums) == 0 {
		return result
	}
	lo, hi := 0, len(nums)-1
	result[0] = findStartingIndex(nums, target, lo, hi)
	if result[0] == -1 {
		return result
	}
	if result[0] == hi {
		result[1] = hi
		return result
	}
	result[1] = findEndingIndex(nums, target, result[0], hi)

	return result
}

func findStartingIndex(nums []int, target int, lo int, hi int) (index int) {
	index = -1
	for lo <= hi {
		mid := lo + (hi-lo)/2
		if nums[mid] >= target {
			hi = mid - 1
		} else {
			lo = mid + 1
		}

		// save the lowest target index
		if nums[mid] == target {
			index = mid
		}
	}
	return index
}

// Input: nums = [5,7,7,8,8,8,8,9,10], target = 8 , Output: [3,6]
func findEndingIndex(nums []int, target int, lo int, hi int) (index int) {
	index = -1
	for lo <= hi {
		mid := lo + (hi-lo)/2
		if nums[mid] <= target {
			lo = mid + 1
		} else {
			hi = mid - 1
		}
		// save the highest target index
		if nums[mid] == target {
			index = mid
		}
	}
	return index
}
