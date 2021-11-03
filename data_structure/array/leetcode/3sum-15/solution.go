package main

import "sort"

func threeSum(nums []int) [][]int {
	sort.Ints(nums)

	var result [][]int
	//  Input: nums = [-1-1,0,0,1,2,-1,-4]
	for i := range nums {
		// not first element and previous element is same, SKIP
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		lp, rp := i+1, len(nums)-1

		for lp < rp {
			sum := nums[i] + nums[lp] + nums[rp]
			if sum > 0 {
				rp--
			} else if sum < 0 {
				lp++
			} else {
				result = append(result, []int{nums[i], nums[lp], nums[rp]})
				lp++
				for nums[lp] == nums[lp-1] && lp < rp {
					lp++
				}
			}
		}
	}
	return result
}
