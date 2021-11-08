// https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/1559279/Go-Submission-with-Explanation

package leetcode

// abcabcbb -> 3 (abc)
// bbbbbbb  -> 1 (b)

func lengthOfLongestSubstring(s string) int {
	var n = len(s)
	if n <= 1 {
		return n
	}
	var lp, rp, res = 0, 0, 1
	var seen = map[byte]int{}
	for rp < n {
		if idx, ok := seen[s[rp]]; ok && idx >= lp {
			lp = idx + 1
		}
		seen[s[rp]] = rp
		rp++
		res = max(res, rp-lp)
	}
	return res
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
