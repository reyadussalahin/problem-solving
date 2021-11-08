package leetcode

func swap(nums []int, i, j int) {
	nums[i], nums[j] = nums[j], nums[i]
}

func sortColors(nums []int) {
	var n = len(nums)
	if n == 1 {
		return
	}
	zero, one, two := 0, 0, n-1
	for one <= two {
		switch nums[one] {
		case 0:
			swap(nums, zero, one)
			zero++
			one++
		case 1:
			one++
		case 2:
			swap(nums, one, two)
			two--
		}
	}
}

/*

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

*/
