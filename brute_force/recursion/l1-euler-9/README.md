## Solutions
#### 1
##### Source Code
```racket
; problem name: Special Pythagorean triplet
; problem link: https://projecteuler.net/problem=9
; contest link: (?)
; time: (?)
; author: reyad


; other_tags: math
; difficulty_level: beginner


#lang racket

(let loop [(a 1)]
  (let [(res (let loop [(b (add1 a))]
               (cond
                 [(>= (+ a b) 1000)
                  -1]
                 [(= (+ (* a a) (* b b))
                     (* (- 1000 (+ a b))
                        (- 1000 (+ a b))))
                  ;(writeln a)
                  ;(writeln b)
                  ;(writeln (- 1000 (+ a b)))
                  (* a (* b
                          (- 1000 (+ a b))))]
                 [#t
                  (loop (add1 b))])))]
    (cond
      [(= res -1)
       (loop (add1 a))]
      [#t
       res])))

```
