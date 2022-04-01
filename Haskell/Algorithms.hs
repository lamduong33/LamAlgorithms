-- Euclid's algorithm
greatestCommonDivisor :: Int -> Int-> Int
greatestCommonDivisor a 0 = abs a
greatestCommonDivisor a b = greatestCommonDivisor b (mod a b)

-- Quick sort algorithm
qsort :: [Int] -> [Int]
qsort [] = []
qsort (n : ns) = qsort smaller ++ [n] ++ qsort bigger
  where
    smaller = [a | a <- ns, a <= n]
    bigger = [b | b <- ns, b > n]

-- Fibonacci sequence
fibonacci :: Int-> Int
fibonacci n
  | n == 0 = 0
  | n == 1 = 1
  | otherwise = fibonacci (n-1) + fibonacci (n-2)
  | otherwise = fibonacci (n -1) + fibonacci (n -2)

maxAmountInRow :: [Int] -> Int -> Int
maxAmountInRow coins (-1) = 0
maxAmountInRow coins 0 = head coins
-- n is the index of the last element
maxAmountInRow coins n =
  max (coins !! n + maxAmountInRow coins (n -2)) (maxAmountInRow coins (n -1))

-- Johnson Trotter's Algorithm:
-- Takes in a list of integers
-- johnsonTrotter :: Integer -> [Integer]

main :: IO ()
main = print (maxAmountInRow [5,1,2,10,6,2] 5)
