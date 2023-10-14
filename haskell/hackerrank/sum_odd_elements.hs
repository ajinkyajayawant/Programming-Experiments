f arr = sum_list where
    new_lst = [x | x<-arr, mod x 2 == 1]
    sum_list = foldr (+) 0 new_lst

-- This part handles the Input/Output and can be used as it is. Do not change or modify it.
main = do
	inputdata <- getContents
	putStrLn $ show $ f $ map (read :: String -> Int) $ lines inputdata
