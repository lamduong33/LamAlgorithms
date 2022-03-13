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

main :: IO ()
main = print (greatestCommonDivisor 74224 1232)
