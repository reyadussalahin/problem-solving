## Solutions
#### 1
##### Source Code
```ruby
# problem name: Unique Bid Auction
# problem link: https://codeforces.com/contest/1454/problem/B
# contest link: https://codeforces.com/contest/1454
# author: reyad
# time: (?)


# other_tags: sorting, data structures, trees
# difficulty_level: easy


require 'set'

tc = gets.chomp.to_i
(1..tc).each do |i|
  n = gets.chomp.to_i
  al = Set.new
  du = Set.new
  a = gets.split.map{ |v| v.to_i }
  a.each do |v|
    if al === v
      du << v
    else
      al << v
    end
  end
  uq = al - du
  ans = -1
  a.each_with_index do |v, k|
    if uq === v
      if ans === -1
        ans = k
      else
        if v < a[ans]
          ans = k
        end
      end
    end
  end
  ans === -1 ? (puts ans) : (puts ans+1)
end
```
