// https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/1546976/Go-Solution-using-Min-Heap

package main

import "container/heap"

type minHeap []int

func (h minHeap) Len() int           { return len(h) }
func (h minHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h minHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *minHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *minHeap) Pop() interface{} {
	var old = *h
	var n = len(old)
	var x = old[n-1]
	*h = old[0 : n-1]
	return x
}

func findKthLargest(nums []int, k int) int {
	h := &minHeap{}
	heap.Init(h)
	for _, num := range nums {
		heap.Push(h, num)
		if h.Len() > k {
			heap.Pop(h)
		}
	}
	return (*h)[0]
}

//func main() {
//	var in1 = []int{3, 2, 3, 1, 2, 4, 5, 5, 6} // k=4  out=4
//	var in2 = []int{3, 2, 1, 5, 6, 4}          // k=2  out =5
//	var res1 = findKthLargest(in1, 4)
//	var res2 = findKthLargest(in2, 2)
//	if res1 == 4 {
//		fmt.Println("Testcase 1 passed", "Output is : ", res1)
//	}
//	if res2 == 5 {
//		fmt.Println("Testcase 2 pass", "Output is : ", res2)
//	}
//}
