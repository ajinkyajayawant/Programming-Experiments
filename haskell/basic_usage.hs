-- Practising from the Haskell wiki book

squareit x = x * x

addthree a b c = a + b + c

mymodulo x
  | x<0 = -x
  | otherwise = x

num_real_solns a b c
  | det >0 = 2
  | det ==0 = 1
  | otherwise = 0
    where
      det = b^2 - 4*a*c

area_triangle_heron a b c = result
  where
    result = sqrt (s*(s-a)*(s-b)*(s-c))
    s = (addthree a b c)/2

-- No specific indentation is needed for if else statements?? Textbook shows a different indentation
my_signum a =
  if a<0
  then -1
  else if a>0
  then 1
  else 0

pieces :: Int -> Int
pieces 1 = 10
pieces 2 = 11
pieces _ = 0

-- Composition seems to work with only single input functions
sq_signum x = (squareit.my_signum) x

-- Seeing the type of a function which returns three variables
myconcat a b = (a, b)

-- Tuple addition with constraints
tupConstAdd :: (Num a) => (a, a) -> a
tupConstAdd (a, b) = a + b

-- Trying to not explicitly define and see what happens
tupAdd (a, b) = a + b

-- Trying generic type definitions
tup2lst :: (a, a) -> [a]
tup2lst (x, y) = [x, y]
