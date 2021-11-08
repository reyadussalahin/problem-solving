package single_number_III_260

func singleNumber(nums []int) []int {
	var res = make([]int, 0, 2)
	ctr := map[int]int{}

	for _, val := range nums {
		ctr[val]++
		if ctr[val] == 2 {
			delete(ctr, val)
		}
	}
	for k := range ctr {
		res = append(res, k)
	}
	return res
}
