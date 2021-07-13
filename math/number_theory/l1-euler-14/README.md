## Solutions
```racket
; problem name: Longest Collatz sequence
; problem link: https://projecteuler.net/problem=14
; contest link: (?)
; time: (?)
; author: reyad


; other_tags: dynamic programming, data structure
; difficulty_level: beginner


#lang racket

; answer: 837799

(define d (make-hash))

(define collatz
  (lambda (n)
    (cond
      [(dict-has-key? d n)
       ; (writeln n)
       (dict-ref d n)]
      [(= n 1)
       (dict-set! d 1 1)
       1]
      [(= 1 (remainder n 2))
       (dict-set! d n (add1 (collatz (add1 (* 3 n)))))
       (dict-ref d n)]
      [#t
       (dict-set! d n (add1 (collatz (/ n 2))))
       (dict-ref d n)])))

(let loop [(n (sub1 1000000))]
  (cond
    [(= n 1)
     1]
    [#t
     (cond
       [(not (dict-has-key? d n))
        (collatz n)])
     (let [(x (loop (sub1 n)))]
       (cond
         [(> (dict-ref d n)
             (dict-ref d x))
          n]
         [#t
          x]))]))

```
