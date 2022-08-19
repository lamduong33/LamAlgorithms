;; Euclid's algorithm
(define (greatestCommonDivisor a b)
  (if (= b 0)
      (abs a)
      (greatestCommonDivisor b (modulo a b))))
