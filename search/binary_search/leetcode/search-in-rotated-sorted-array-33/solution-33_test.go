package leetcode

import (
	"fmt"
	"testing"
)

type question33 struct {
	para33
	ans33
}

type para33 struct {
	nums   []int
	target int
}

type ans33 struct {
	one int
}

func Test_Problem33(t *testing.T) {

	qs := []question33{

		{
			para33{[]int{3, 1}, 1},
			ans33{1},
		},

		{
			para33{[]int{4, 5, 6, 7, 0, 1, 2}, 0},
			ans33{4},
		},

		{
			para33{[]int{4, 5, 6, 7, 0, 1, 2}, 3},
			ans33{-1},
		},
	}

	fmt.Printf("------------------------Leetcode Problem 33------------------------\n")

	for _, q := range qs {
		_, p := q.ans33, q.para33
		fmt.Printf("【input】:%v    【output】:%v\n", p, search(p.nums, p.target))
	}
	fmt.Printf("\n\n\n")
}
