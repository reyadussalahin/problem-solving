; problem name: 10001st prime
; problem link: https://projecteuler.net/problem=7
; contest link: (?)
; time: (?)
; author: reyad


; other_tags: primes
; difficulty_level: beginner


#lang racket

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

(define nth-prime
  (lambda (n v bsz)
    (vector-set! v 0 1)
    (vector-set! v 1 1)
    (mark-primes 2 bsz v)
    (let loop [(c 0)
               (i 2)]
      (cond
        [(= 0 (vector-ref v i))
         ;(writeln i)
         (cond
           [(= (add1 c) n)
            i]
           [#t
            (loop (add1 c) (add1 i))])]
        [#t
         (loop c (add1 i))]))))

; max-buf-size: 200000
; nth-prime: 10001
(define max-buf-size 200000)
(define v (make-vector (+ 4 max-buf-size)))
(nth-prime 10001 v max-buf-size)

