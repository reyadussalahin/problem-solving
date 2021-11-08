// https://leetcode.com/problems/maximum-subarray
// Time O(N) , Space O(N)

package leetcode

func maxSubArray(nums []int) int {
	currSum, maxSum := 0, nums[0]
	if len(nums) == 1 {
		return maxSum
	}
	// Input: nums = [-2,1,-3, 4,-1,2,1, -5,4]
	for _, num := range nums {
		// if currSum is negative, ignore it from subArray
		// reset it to zero
		if currSum < 0 {
			currSum = 0
		}
		currSum += num
		maxSum = max(maxSum, currSum)
	}
	return maxSum
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
