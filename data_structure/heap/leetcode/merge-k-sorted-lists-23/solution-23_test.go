package leetcode

import (
	"fmt"
	"testing"
)

type question23 struct {
	para23
	ans23
}

type para23 struct {
	one [][]int
}

type ans23 struct {
	one []int
}

func Test_Problem23(t *testing.T) {

	qs := []question23{

		{
			para23{[][]int{}},
			ans23{[]int{}},
		},

		{
			para23{[][]int{
				{1},
				{1},
			}},
			ans23{[]int{1, 1}},
		},

		{
			para23{[][]int{
				{1, 2, 3, 4},
				{1, 2, 3, 4},
			}},
			ans23{[]int{1, 1, 2, 2, 3, 3, 4, 4}},
		},

		{
			para23{[][]int{
				{1, 2, 3, 4, 5},
				{1, 2, 3, 4, 5},
			}},
			ans23{[]int{1, 1, 2, 2, 3, 3, 4, 4, 5, 5}},
		},

		{
			para23{[][]int{
				{1},
				{9, 9, 9, 9, 9},
			}},
			ans23{[]int{1, 9, 9, 9, 9, 9}},
		},

		{
			para23{[][]int{
				{9, 9, 9, 9, 9},
				{1},
			}},
			ans23{[]int{1, 9, 9, 9, 9, 9}},
		},

		{
			para23{[][]int{
				{2, 3, 4},
				{4, 5, 6},
			}},
			ans23{[]int{2, 3, 4, 4, 5, 6}},
		},

		{
			para23{[][]int{
				{1, 3, 8},
				{1, 7},
			}},
			ans23{[]int{1, 1, 3, 7, 8}},
		},
	}

	fmt.Printf("------------------------Leetcode Problem 23------------------------\n")

	for _, q := range qs {
		var ls []*ListNode
		for _, qq := range q.para23.one {
			ls = append(ls, Ints2List(qq))
		}
		fmt.Printf("【input】:%v       【output】:%v\n", q.para23.one, List2Ints(mergeKLists(ls)))
	}
	fmt.Printf("\n\n\n")
}
