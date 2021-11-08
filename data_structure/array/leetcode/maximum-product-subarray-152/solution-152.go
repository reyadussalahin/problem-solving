// https://leetcode.com/problems/maximum-product-subarray/

package leetcode

import "fmt"

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a int, b int) int {
	if a > b {
		return b
	}
	return a
}

// [-2,0,-1]
func maxProduct(nums []int) int {
	currMin, currMax, res := nums[0], nums[0], nums[0]
	for i := 1; i < len(nums); i++ {
		if nums[i] < 0 {
			currMax, currMin = currMin, currMax
		}
		currMax = max(nums[i], currMax*nums[i])
		currMin = min(nums[i], currMin*nums[i])
		res = max(res, currMax)
	}
	return res
}

func main() {
	in := []int{-2, 0, -1}
	fmt.Println(maxProduct(in))
}
