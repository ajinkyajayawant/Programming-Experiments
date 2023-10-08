f :: Int -> [Int] -> [Int]
f n arr = arr_new where
    arr_el = head arr
    arr_part = tail arr
    arr_new_part = if arr_part == []
    then []
    else f n arr_part
    arr_first = [arr_el | i <- [1..n]]
    arr_new = arr_first ++ arr_new_part

-- This part handles the Input and Output and can be used as it is. Do not modify this part.
main :: IO ()
main = getContents >>=
       mapM_ print. (\(n:arr) -> f n arr). map read. words
