// https://leetcode.com/problems/container-with-most-water/
// Time : O(N) Space: O(N)

package main

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

func shiftPointer(lp int, rp int, height []int) (int, int) {
	if height[lp] > height[rp] {
		rp--
	} else if height[lp] < height[rp] {
		lp++
	} else {
		// if equal,check whichever next index's height is higher,shift lp/rp towards it
		if height[lp+1] > height[rp-1] {
			lp++
		} else {
			rp--
		}
	}
	return lp, rp
}

// [1,8,6,2,5,4,8,3,7]  [3,6]
func maxArea(height []int) int {
	var maxA = 0
	if len(height) == 2 {
		maxA = min(height[0], height[1])
		return maxA
	}
	var lp, rp = 0, len(height) - 1
	for lp < rp {
		// container height = min(height[lp], height[rp])
		// container width = rp - lp,coz rp index is higher
		var area = min(height[lp], height[rp]) * (rp - lp)
		maxA = max(maxA, area)
		lp, rp = shiftPointer(lp, rp, height)
	}
	return maxA
}
