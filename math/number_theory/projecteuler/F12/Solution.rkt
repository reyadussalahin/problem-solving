; problem name: Highly divisible triangular number
; problem link: https://projecteuler.net/problem=12
; contest link: (?)
; time: (?)
; author: reyad


; other_tags: (?)
; difficulty_level: beginner


#lang racket

(define count-divs
  (lambda (i n)
    (cond
      [(= n 1)
       1]
      [(> (* i i) n)
       2]
      [#t
       (* (let loop []
              (cond
                [(= 0 (remainder n i))
                 (set! n (/ n i))
                 (add1 (loop))]
                [#t
                 1]))
            (count-divs (add1 i) n))])))

(let loop [(i 1)
           (n 1)]
  (cond
    [(> (count-divs 2 n) 500)
     n]
    [#t
     (loop (add1 i) (+ n (add1 i)))]))
