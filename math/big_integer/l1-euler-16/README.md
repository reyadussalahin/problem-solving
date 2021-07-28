## Solutions
#### 1
##### Source Code
```racket
; problem name: Power digit sum
; problem link: https://projecteuler.net/problem=16
; contest link: (?)
; time: (?)
; author: reyad


; other_tags: loop, recursion
; difficulty_level: beginner


#lang racket

; answer: 1366

(define char-digit-to-int-digit
  (lambda (ch)
    (- (char->integer ch)
       (char->integer #\0))))

(define reduce
  (lambda (fn l init)
    (cond
      [(null? l)
       init]
      [#t
       (fn (car l)
           (reduce fn (cdr l) init))])))

(reduce (lambda (x y)
          (+ (char-digit-to-int-digit x)
             y))
        (string->list (number->string (expt 2 1000)))
        0)

```
