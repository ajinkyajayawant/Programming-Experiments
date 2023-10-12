f :: [Int] -> [Int]
f lst = new_lst where
    zip_lst = zip [0..] lst
    new_lst = [x | (i,x) <- zip_lst, mod i 2 == 1]

-- This part deals with the Input and Output and can be used as it is. Do not modify it.
main = do
	inputdata <- getContents
	mapM_ (putStrLn. show). f. map read. lines $ inputdata
