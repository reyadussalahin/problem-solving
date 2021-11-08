package leetcode

import (
	"fmt"
	"testing"
)

type question53 struct {
	para53
	ans53
}

type para53 struct {
	one []int
}

type ans53 struct {
	one int
}

func Test_Problem53(t *testing.T) {

	qs := []question53{

		{
			para53{[]int{-2, 1, -3, 4, -1, 2, 1, -5, 4}},
			ans53{6},
		},
		{
			para53{[]int{2, 7, 9, 3, 1}},
			ans53{22},
		},

		{
			para53{[]int{2}},
			ans53{2},
		},

		{
			para53{[]int{-1, -2}},
			ans53{-1},
		},
	}

	fmt.Printf("------------------------Leetcode Problem 53------------------------\n")

	for _, q := range qs {
		_, p := q.ans53, q.para53
		fmt.Printf("【input】:%v       【output】:%v\n", p, maxSubArray(p.one))
	}
	fmt.Printf("\n\n\n")
}
