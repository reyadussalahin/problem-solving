package leetcode

import (
	"fmt"
	"testing"
)

type question48 struct {
	para48
	ans48
}

type para48 struct {
	s [][]int
}

type ans48 struct {
	s [][]int
}

func Test_Problem48(t *testing.T) {

	qs := []question48{

		{
			para48{[][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}},
			ans48{[][]int{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}},
		},

		{
			para48{[][]int{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}}},
			ans48{[][]int{{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}}},
		},
	}

	fmt.Printf("------------------------Leetcode Problem 48------------------------\n")

	for _, q := range qs {
		_, p := q.ans48, q.para48
		fmt.Printf("【input】:%v \n", p)
		rotate(p.s)
		fmt.Printf("【output】:%v\n", p)
		fmt.Printf("\n")
	}
	fmt.Printf("\n\n\n")
}
