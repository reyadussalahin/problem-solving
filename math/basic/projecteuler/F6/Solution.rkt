; problem name: Sum square difference
; problem link: https://projecteuler.net/problem=6
; contest link: (?)
; time: (?)
; author: reyad


; other_tags: number theory
; difficulty_level: beginner


#lang racket

(define sum-of-square
  (lambda (n)
    (cond
      [(= n 0)
       0]
      [#t
       (+ (* n n) (sum-of-square (sub1 n)))])))

(define sum-square-difference
  (lambda (n)
    (- (expt (/ (* n (add1 n)) 2) 2)
       (sum-of-square n))))

(sum-square-difference 100)
