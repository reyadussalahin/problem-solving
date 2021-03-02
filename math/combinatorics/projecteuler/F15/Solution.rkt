; problem name: Lattice paths
; problem link: https://projecteuler.net/problem=15
; contest link: (?)
; time: (?)
; author: reyad


; other_tags: dynamic programming
; difficulty_level: beginner


#lang racket

; answer: 137846528820

(define v (make-vector 44))

(let loop [(n 40)]
  (cond
    [(>= n 0)
     (vector-set! v n (make-vector 44))
     (loop (sub1 n))]))


(let ncr [(n 40)
          (r 20)]
  (cond
    [(or (= n 0) (= r 0) (= n r))
     1]
    [#t
     (cond
       [(= 0 (vector-ref (vector-ref v n) r))
        (vector-set! (vector-ref v n) r (+ (ncr (sub1 n) r)
                                        (ncr (sub1 n) (sub1 r))))])
     (vector-ref (vector-ref v n) r)]))

(vector-ref (vector-ref v 40) 20)
