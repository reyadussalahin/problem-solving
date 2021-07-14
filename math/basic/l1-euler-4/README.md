## Solutions
#### 1
##### Source Code
```racket
; problem name: Largest palindrome product
; problem link: https://projecteuler.net/problem=4
; contest link: (?)
; time: (?)
; author: reyad


; other_tags: palindromes, recursion, loop
; difficulty_level: beginner


#lang racket

; answer: 906609

(define palindrome?
  (lambda (n x m)
    (cond
      ((= x 0)
       (= n m))
      (#t
       (palindrome? n (quotient x 10) (+ (* m 10) (remainder x 10)))))))

(define largest-palindrome-product
  (lambda (a s e)
    (cond
      ((< a s)
       0)
      (#t
       (max (let loop ((b e))
              (cond
                ((< b s)
                 0)
                ((palindrome? (* a b) (* a b) 0)
                 (max (* a b) (loop (sub1 b))))
                (#t
                 (loop (sub1 b)))))
            (largest-palindrome-product (sub1 a) s e))))))

(largest-palindrome-product 999 100 999)
; 999 100 999
; (iterator low high) format input

; problem description:
; ----------------------------------------------
; A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
;
; Find the largest palindrome made from the product of two 3-digit numbers.

```
