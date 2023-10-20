len :: [a] -> Int
len lst = nn where
    nn = if null lst
        then 0
        else 1 + len (tail lst)
