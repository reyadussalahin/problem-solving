; problem name: Largest prime factor
; problem link: https://projecteuler.net/problem=3
; contest link: (?)
; time: (?)
; author: reyad


; other_tags: primes
; difficulty_level: beginner


#lang racket

; answer: 6857

(define mark-primes
  (lambda (s e v)
    (cond
      ((> s e)
       #t)
      ((and (= 0 (vector-ref v s))
            (>= e (* s s)))
       (let loop ((s (+ s s))
                  (e e)
                  (i s))
         (cond
           ((> s e)
            #t)
           (#t
            (vector-set! v s 1)
            (loop (+ s i) e i))))
       (mark-primes (add1 s) e v))
      (#t
       (mark-primes (add1 s) e v)))))

(define max-prime-div
  (lambda (n)
    (letrec ((sq (add1 (integer-sqrt n)))
             (v (make-vector (add1 sq))))
      (vector-set! v 0 1)
      (vector-set! v 1 1)
      (mark-primes 2 sq v)
      (let loop ((d sq)
                 (n n)
                 (v v))
        (cond
          ((= d 0)
           n)
          ((and (= 0 (vector-ref v d))
                (= 0 (remainder n d)))
           (max d (loop (sub1 d)
                        (let loop2 ((n n))
                          (if (= 0 (remainder n d))
                              (loop2 (/ n d))
                              n))
                        v)))
          (#t
           (loop (sub1 d) n v)))))))

(max-prime-div 600851475143)
