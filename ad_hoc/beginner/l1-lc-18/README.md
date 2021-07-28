## Solutions
#### 1
##### Source Code
```python
# problem name: Maximum Ascending Subarray Sum
# problem link: https://leetcode.com/contest/weekly-contest-233/problems/maximum-ascending-subarray-sum/
# contest link: https://leetcode.com/contest/weekly-contest-233/
# time: (?)
# author: reyad


# other_tags: two pointers
# difficulty_level: beginner



class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        temp_sum = nums[0]
        max_sum = temp_sum
        for i in range(1, len(nums)):
            if nums[i-1] >= nums[i]:
                temp_sum = 0
            temp_sum += nums[i]
            max_sum = max(max_sum, temp_sum)
        return max_sum

```
