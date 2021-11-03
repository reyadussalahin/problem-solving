package main

import (
	"container/heap"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

type ListNodeHeap []*ListNode

func (h ListNodeHeap) Len() int           { return len(h) }
func (h ListNodeHeap) Less(i, j int) bool { return h[i].Val < h[j].Val }
func (h ListNodeHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *ListNodeHeap) Push(x interface{}) {
	*h = append(*h, x.(*ListNode))
}

func (h *ListNodeHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
func mergeKLists(lists []*ListNode) *ListNode {
	// Terminal case.
	if len(lists) == 0 {
		return nil
	}
	if len(lists) == 1 {
		return lists[0]
	}

	var h = &ListNodeHeap{}
	heap.Init(h)

	for _, node := range lists {
		if node != nil {
			heap.Push(h, node)
		}
	}

	var sentinel = &ListNode{Val: -1} // sentinel node initialization, sentinel.next = head element
	var cur *ListNode = sentinel
	for h.Len() != 0 {
		var node = heap.Pop(h).(*ListNode)
		if node.Next != nil {
			heap.Push(h, node.Next)
		}
		cur.Next = node
		cur = cur.Next
	}
	return sentinel.Next
}
