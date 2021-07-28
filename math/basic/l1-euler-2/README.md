## Solutions
#### 1
##### Source Code
```racket
; problem name: Even Fibonacci numbers
; problem link: https://projecteuler.net/problem=2
; contest link: (?)
; time: (?)
; author: reyad


; other_tags: (?)
; difficulty_level: beginner


#lang racket

; answer: 4613732

(define fib-sum
  (lambda (a b)
    (cond
      ((> b 4000000)
       0)
      ((= (remainder b 2) 0)
       (+ b (fib-sum b (+ a b))))
      (#t
       (fib-sum b (+ a b))))))

(fib-sum 1 2)
```
