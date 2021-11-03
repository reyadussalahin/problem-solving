// https://leetcode.com/problems/next-permutation/discuss/1554932/Go-Submission-with-Explanation

package main

import "fmt"

// [2,(3),6,5,4,1] -> 2,(4),6,5,(3),1 -> 2,4, 1,3,5,6
func nextPermutation(nums []int) {
	var n = len(nums)
	var pIdx = permutationPossible(nums)
	if pIdx == -1 {
		reverse(nums, 0, n-1)
		return
	}

	var rp = len(nums) - 1
	// start from right most to leftward,find the first number which is larger than PIVOT
	for rp > 0 {
		if nums[rp] > nums[pIdx] {
			nums[rp], nums[pIdx] = nums[pIdx], nums[rp]
			break
		} else {
			rp--
		}
	}
	// Finally, Reverse all elements which are right from pivot
	reverse(nums, pIdx+1, n-1)
}

func reverse(nums []int, s int, e int) {
	for s < e {
		nums[s], nums[e] = nums[e], nums[s]
		s++
		e--
	}
}

// permutationPossible returns 1st occurrence Index where value is not in increasing order
// searches Right to Left
// 1,3,2 out: 2,3,1
func permutationPossible(nums []int) (idx int) {
	// search right to left for 1st number(from right) that is not in increasing order
	var rp = len(nums) - 1
	for rp > 0 {
		if nums[rp-1] < nums[rp] {
			idx = rp - 1
			return idx
		}
		rp--
	}
	return -1
}

func main() {
	var in = []int{1, 3, 2} // 2,1,3
	nextPermutation(in)
	fmt.Println(in)
}
