-- How to run a haskell program
-- For interpreter type access: Type ghci at terminal

-- Load/import a file
:load basic_usage

:t myconcat
-- myconcat :: t -> t1 -> (t, t1)
-- So looks like haskell functions return only one value. To read the -> notation basically only the last value is the value retuned by the function. Since in FP functions are ideally one argument one output, -> aptly represents the currying.

tupConstAdd (2, 3)
tupConstAdd ("aj", "dj")

:t tupAdd
-- This returns the exact same thing as :t tupConstAdd, haskell does type inference here I think
-- Something to note is that Haskell does not allow me to define the type of tupAdd as tupAdd :: (a,a) -> a. I think that is because the type cannot be a generic one a.

tup2lst (2, 3)
tup2lst ("aj", "dj")
tup2lst (2,"zj")
-- The last command gives back an error as expected

-- Output of accumulation using partial application
((accum 2) 3) 4


-- Try fixNum with and without numeric input
fixNum 4
fixNum "four"

-- Try fixNum with and without numeric input
noFixNum 4
noFixNum "four"

-- Try fixNum with and without numeric input
dirFixNum 4
dirFixNum "four"

-- All the functions with integer call run effortlessly
-- We get more informative message for the third function dirFixNum
