## Solutions
#### 1
##### Source Code
```racket
; problem name: Largest prime factor
; problem link: https://projecteuler.net/problem=3
; contest link: (?)
; time: (?)
; author: reyad


; other_tags: primes
; difficulty_level: beginner


; note:
;   - solution_no: 002
;   - goal: its a bit cleaner than the previous than solution_no 001


#lang racket

; answer: 6857

(define mark-primes
  (lambda (d n v)
    (cond
      ((<= d n)
       (cond
         ((and (= 0 (vector-ref v d))
               (<= (* d d) n))
          (let loop ((i (* d d)))
            (cond
              ((<= i n)
               (vector-set! v i 1)
               (loop (+ i d)))))))
       (mark-primes (add1 d) n v)))))

(define max-prime-div
  (lambda (n)
    (letrec ((r (add1 (integer-sqrt n)))
             (v (make-vector (add1 r))))
      (vector-set! v 0 1)
      (vector-set! v 1 1)
      (mark-primes 2 r v)
      (let loop ((d r) (n n) (x -1))
        (cond
          ((= d 1)
           (max n x))
          (#t
           (cond
             ((and (= 0 (vector-ref v d))
                   (= 0 (remainder n d)))
              (let loop ()
                (cond
                  ((= 0 (remainder n d))
                   (set! n (/ n d))
                   (loop))))
              (set! x (max x d))))
           (loop (sub1 d) n x)))))))

; 600851475143
(max-prime-div 600851475143)

```
