// https://leetcode.com/problems/product-of-array-except-self/
// Time: O(N) Space: O(N)

package leetcode

// lp[i] = nums[i-1] * lp[i-1]
func getLeftProducts(nums []int) []int {
	size := len(nums)
	lp := make([]int, size)
	_ = copy(lp, nums) // coz, slice is pass by reference
	lp[0] = 1          // default, has no left products
	for i := 1; i < size; i++ {
		lp[i] = nums[i-1] * lp[i-1]
	}
	return lp
}

// rp[i] = nums[i-1] * rp[i-1]
func getRightProducts(nums []int) []int {
	size := len(nums)
	rp := make([]int, size) // coz, slice is pass by reference
	_ = copy(rp, nums)
	rp[size-1] = 1 // default, has no right products
	for i := size - 2; i >= 0; i-- {
		rp[i] = nums[i+1] * rp[i+1]
	}
	return rp
}

func productExceptSelf(nums []int) []int {
	size := len(nums)
	if size == 2 {
		return []int{nums[1], nums[0]}
	}

	answer := make([]int, size)
	leftProducts := getLeftProducts(nums)
	rightProducts := getRightProducts(nums)

	// answer[i] = leftProducts[i]*rightProducts[i]
	for i := range nums {
		answer[i] = leftProducts[i] * rightProducts[i]
	}
	return answer
}
