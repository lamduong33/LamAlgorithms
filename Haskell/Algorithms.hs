-- Euclid's algorithm
greatestCommonDivisor :: Integer -> Integer -> Integer
greatestCommonDivisor a 0 = abs a
greatestCommonDivisor a b = greatestCommonDivisor b (mod a b)

-- Quick sort algorithm
qsort :: [Integer] -> [Integer]
qsort [] = []
qsort (n : ns) = qsort smaller ++ [n] ++ qsort bigger
  where
    smaller = [a | a <- ns, a <= n]
    bigger = [b | b <- ns, b > n]

-- Fibonacci sequence
fibonacci :: Integer -> Integer
fibonacci n =
  if n == 0 then 0
  else if  n == 1 then 1
  else fibonacci n-1 + fibonacci n-2

-- Johnson Trotter's Algorithm:
-- johnsonTrotter :: (Integer, Integer) -> [[Integer]]

main :: IO ()
main = print (fibonacci 20)
