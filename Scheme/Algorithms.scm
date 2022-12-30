;; Euclid's algorithm
(define (greatestCommonDivisor a b)
  (if (= b 0)
      (abs a) ;; base case
      (greatestCommonDivisor b (modulo a b))))

;; Factorial definition
(define (factorial n)
  (if (= n 1)
      1
      (* n (factorial (- n 1)))))

;; Pythagorean theorem: a^2 + b^2 = c^2. Find c.
(define (findHypotenuse a b)
  (sqrt (+ (* a a) (* b b))))

;; Dijkstra's algorithm
