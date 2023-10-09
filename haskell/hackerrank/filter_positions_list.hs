f :: [Int] -> [Int]
f lst = new_lst where
    new_lst = []

f_cond :: Int -> [Int] -> [Int]
f_cond flag arr = new_lst where
    new_arr = if arr == []
    then []
    else head_el = head arr
        rest_arr = tail arr


-- This part deals with the Input and Output and can be used as it is. Do not modify it.
main = do
    inputdata <- getContents
    mapM_ (putStrLn. show). f. map read. lines $ inputdata
