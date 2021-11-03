package find_minimum_in_rotated_sorted_array_153

func findMin(nums []int) int {
	if len(nums) == 1 {
		return nums[0]
	}

	lo := 0
	hi := len(nums) - 1

	for lo < hi {
		mid := lo + (hi-lo)/2
		if nums[mid] > nums[hi] {
			lo = mid + 1 // that's how we reach a sorted array
		} else {
			hi = mid // that's normal, then we can use left sub-list
		}
	}
	return nums[lo]
}
