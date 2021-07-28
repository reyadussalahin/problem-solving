## Solutions
#### 1
##### Source Code
```racket
; problem name: Summation of primes
; problem link: https://projecteuler.net/problem=10
; contest link: (?)
; time: (?)
; author: reyad


; other_tags: primes
; difficulty_level: beginner


#lang racket

; answer: 142913828922

(define mark-primes
  (lambda (d n v)
    (cond
      [(<= d n)
       (cond
         [(= 0 (vector-ref v d))
          (let loop [(i (* d d))]
            (cond
              [(<= i n)
               (vector-set! v i 1)
               (loop (+ i d))]))])
       (mark-primes (add1 d) n v)])))

(letrec [(n (sub1 2000000))
         (v (make-vector (+ 4 n)))]
  (vector-set! v 0 1)
  (vector-set! v 1 1)
  (mark-primes 2 n v)
  (let loop [(i n)]
    (cond
      [(= i 0)
       0]
      [#t
       (cond
         [(= 0 (vector-ref v i))
          (+ i (loop (sub1 i)))]
         [#t
          (loop (sub1 i))])])))

```
