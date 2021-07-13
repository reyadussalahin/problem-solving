## Solutions
```racket
; problem name: Multiples of 3 and 5
; problem link: https://projecteuler.net/problem=1
; contest link: (?)
; time: (?)
; author: reyad


; other_tags: (?)
; difficulty_level: beginner


#lang racket

; answer: 233168


(define mul-sum
  (lambda (n)
    (cond
      ((= n 0)
       0)
      ((or (= (remainder n 3) 0)
           (= (remainder n 5) 0))
       (+ n (mul-sum (- n 1))))
      (#t
       (mul-sum (- n 1))))))

(mul-sum 999)


```
