// Optimal, time O(N), space O(1)

package leetcode

func findDuplicates(nums []int) []int {
	var resultSet []int
	for i := range nums {
		// Get the index, the element corresponds to
		index := abs(nums[i]) - 1
		// If the number is already negative, it means we are
		// encountering it twice
		if nums[index] < 0 {
			resultSet = append(resultSet, index+1)
		} else {
			// Flip the number at the index to negative
			nums[index] = -1 * nums[index]
		}
	}
	return resultSet
}

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}
