## Solutions
#### 1
##### Source Code
```racket
; problem name: Smallest multiple
; problem link: https://projecteuler.net/problem=5
; contest link: (?)
; time: (?)
; author: reyad


; other_tags: gcd, lcm
; difficulty_level: beginner


#lang racket

(define gcd
  (lambda (a b)
    (cond
      [(= b 0)
       a]
      [#t
       (gcd b (remainder a b))])))

(define lcm
  (lambda (a b)
    (/ (* a b) (gcd a b))))

(define smallest-multiple
  (lambda (n)
    (cond
      [(= n 1)
       1]
      [#t
       (lcm n (smallest-multiple (sub1 n)))])))

(smallest-multiple 20)

```
