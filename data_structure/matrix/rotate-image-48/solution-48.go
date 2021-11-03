package main

import "fmt"

func reverse(nums []int) []int {
	var lp, rp = 0, len(nums) - 1

	for lp < rp {
		nums[lp], nums[rp] = nums[rp], nums[lp]
		lp++
		rp--
	}
	return nums
}

func rotate(matrix [][]int) {
	n := len(matrix)
	if n == 1 {
		return
	}
	/* rotate clock-wise = 1. transpose matrix => 2. reverse(matrix[i])

	1   2  3  4      1   5  9  13        13  9  5  1
	5   6  7  8  =>  2   6  10 14  =>    14  10 6  2
	9  10 11 12      3   7  11 15        15  11 7  3
	13 14 15 16      4   8  12 16        16  12 8  4

	*/

	for i := 0; i < n; i++ {
		// transpose, i=rows, j=columns
		for j := i + 1; j < n; j++ {
			tmp := matrix[i][j]
			matrix[i][j] = matrix[j][i]
			matrix[j][i] = tmp
		}
		// reverse each row of the image
		matrix[i] = reverse(matrix[i])
	}
}

func main() {
	var matrix = [][]int{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},
	}

	rotate(matrix)
	fmt.Println(matrix)
}
