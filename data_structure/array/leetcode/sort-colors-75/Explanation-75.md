We iterate from the beginning as long as the one pointer is less than the two pointer.

If the one pointer is zero (nums[one] == 0), we swap with the zero pointer 
and move both one and zero pointer forward. If the pointer is one 
(nums[one] == 1), the element is already in correct place, 
so we don't have to swap, just move the one pointer forward. 
If the one pointer is two, we swap with the two and two--.