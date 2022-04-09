import Data.IntMap (size)
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

coinRow :: [Int] -> Int -> Int
coinRow coins (-1) = 0
coinRow coins 0 = head coins
-- n is the index of the last element
coinRow coins n =
  max (coins !! n + coinRow coins (n -2)) (coinRow coins (n -1))

-- coinRow will take in a lsit of Coins [0..n]

-- Johnson Trotter's Algorithm:
-- Takes in a list of integers
-- johnsonTrotter :: Integer -> [Integer]


main :: IO ()
main = print (coinRow [5,1,2,10,6,2] 5)
