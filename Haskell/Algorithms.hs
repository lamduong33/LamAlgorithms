import           Control.Arrow                  ( ArrowChoice(right) )
import           Data.IntMap                    ( size )
import           GHC.Integer                    ( absInteger )
-- Euclid's algorithm
greatestCommonDivisor :: Int -> Int -> Int
greatestCommonDivisor a 0 = abs a
greatestCommonDivisor a b = greatestCommonDivisor b (mod a b)

-- Factorial algorithm

-- Quick sort algorithm
qsort :: [Int] -> [Int]
qsort []       = []
qsort (n : ns) = qsort smaller ++ [n] ++ qsort bigger
 where
  smaller = [ a | a <- ns, a <= n ]
  bigger  = [ b | b <- ns, b > n ]

-- Factorial
factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n - 1)

factorialIter :: Int -> Int
factorialIter 0 = 1
factorialIter n = n

-- Fibonacci sequence
fibonacci :: Int -> Int
fibonacci n | n == 0    = 0
            | n == 1    = 1
            | otherwise = fibonacci (n - 1) + fibonacci (n - 2)

-- Coin Row Problem: maximum amount of coins that could be picked up
coinRow :: [Int] -> Int
coinRow []    = 0
coinRow coins = maxCoinRow coins (length coins)

-- The actual recurrence to solve the coin row problem using dynamic programming
maxCoinRow :: [Int] -> Int -> Int
maxCoinRow coins (-1) = 0
maxCoinRow coins 0    = head coins
maxCoinRow coins n =
  max (coins !! n + maxCoinRow coins (n - 2)) (maxCoinRow coins (n - 1))

-- coinRow will take in a lsit of Coins [0..n]

-- Johnson Trotter's Algorithm:
-- Takes in a list of integers
-- johnsonTrotter :: Integer -> [Integer]

main :: IO ()
main = print (fibonacci 40)
