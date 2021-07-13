## Solutions
```python
# problem name: Longest Substring Without Repeating Characters
# problem link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
# contest link: (?)
# time: (?)
# author: phase7/ratul14


# other_tags: (?)
# difficulty_level: medium


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        #returns 0 if there is no string
        if len(s) == 0:
             return 0;


        start_c = 0 #start index for longest substring
        end_c = 0  #end index for longest substring
        data = dict() #keep track of index and characters
        longest_substr_len = 0; #longest substr so far
        current_lsl = 0; #longest substr we're currently keeping track of

        idx = 0;
        for char in s:
            if char not in data: #new char, so not a repeated char
                data[char] = idx;
                current_lsl += 1;
                longest_substr_len = max(longest_substr_len, current_lsl) #taking the greater value of LS if there is another longer value we've encountered before
            else:
                start_c = max(data[char] + 1, start_c); #counting the substring which is currently on the most right position
                end_c = idx;
                data[char] = idx;
                current_lsl = end_c - start_c + 1;
                longest_substr_len = max(longest_substr_len, current_lsl) #for the same reason above
                
            idx += 1;

        return longest_substr_len;
```
