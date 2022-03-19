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
fibonacci n
  | n == 0 = 0
  | n == 1 = 1
  | otherwise = fibonacci (n-1) + fibonacci (n-2)

-- Johnson Trotter's Algorithm:
-- Takes in a list of integers
-- johnsonTrotter :: Integer -> [Integer]

main :: IO ()
main = print (fibonacci 20)
