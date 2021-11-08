package leetcode

import (
	"fmt"
	"testing"
)

type question75 struct {
	para75
	ans75
}

type para75 struct {
	one []int
}

type ans75 struct {
	one []int
}

func Test_Problem75(t *testing.T) {

	qs := []question75{

		{
			para75{[]int{}},
			ans75{[]int{}},
		},

		{
			para75{[]int{1}},
			ans75{[]int{1}},
		},

		{
			para75{[]int{2, 0, 2, 1, 1, 0}},
			ans75{[]int{0, 0, 1, 1, 2, 2}},
		},

		{
			para75{[]int{2, 0, 1, 1, 2, 0, 2, 1, 2, 0, 0, 0, 1, 2, 2, 2, 0, 1, 1}},
			ans75{[]int{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2}},
		},
	}

	fmt.Printf("------------------------Leetcode Problem 75------------------------\n")

	for _, q := range qs {
		_, p := q.ans75, q.para75
		fmt.Printf("【input】:%v      ", p)
		sortColors(p.one)
		fmt.Printf("【output】:%v      \n", p)
	}
	fmt.Printf("\n\n\n")
}
