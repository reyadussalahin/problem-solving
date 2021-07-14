## Solutions
#### 1
##### Source Code
```racket
; problem name: Two Sum
; problem link: https://leetcode.com/problems/two-sum/
; contest link: (?)
; time: (?)
; author: reyad


; other_tags: loop, binary search, sorting
; difficulty_level: easy



(define find-second
  (lambda (nums idx first-num first-idx target)
    (cond
      ((null? nums)
       -1)
      ((and (not (= idx first-idx))
            (= target (+ first-num (car nums))))
       idx)
      (#t
       (find-second (cdr nums)
                    (+ 1 idx)
                    first-num
                    first-idx
                    target)))))

(define solve
  (lambda (tail-nums idx target all-nums)
    (let ((second-idx (find-second all-nums
                               0
                               (car tail-nums)
                               idx
                               target)))
      (if (= second-idx -1)
          (solve (cdr tail-nums)
                 (+ 1 idx)
                 target
                 all-nums)
          (list idx second-idx)))))

(define/contract (two-sum nums target)
  (-> (listof exact-integer?) exact-integer? (listof exact-integer?))
  (solve nums 0 target nums)
)
```
