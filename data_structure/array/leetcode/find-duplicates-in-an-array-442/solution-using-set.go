package leetcode

// https://leetcode.com/problems/find-all-duplicates-in-an-array/
// time O(N) space O(N)

func findDuplicatesLinearSpace(nums []int) []int {
	var res []int
	var seen = map[int]bool{}
	for _, num := range nums {
		if _, ok := seen[num]; ok {
			// If already present, then it is a duplicate
			res = append(res, num)
		}
		// Add the number to the set
		seen[num] = true
	}
	return res
}

/*
Algorithm:
Create set seen that will store all the unique integers.
Create a res slice that will have all the duplicate integers.
Iterate through all elements of the slice and add it to the set.
If the element is already present in the set, you can add the element to the result set.
Return the result set.
*/
