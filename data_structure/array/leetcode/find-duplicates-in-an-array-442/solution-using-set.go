package main

// https://leetcode.com/problems/find-all-duplicates-in-an-array/
// time O(N) space O(N)
// Runtime: 3 ms

func findDuplicatesLinearSpace(nums []int) []int {
	var resultSet []int
	uniqueSet := make(map[int]bool)
	for _, num := range nums {
		_, ok := uniqueSet[num]
		// If already present, then it is a duplicate
		if ok == true {
			resultSet = append(resultSet, num)
		}
		// Add the number to the set
		uniqueSet[num] = true
	}
	return resultSet
}

/*
Algorithm:
Create a uniqueSet that will store all the unique integers.
Create a resultSet that will have all the duplicate integers.
Iterate through all elements of the slice and add it to the set.
If the element is already present in the set, you can add the element to the result set.
Return the result set.
*/
