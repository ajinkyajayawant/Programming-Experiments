data Anniversary = Birthday String Int Int Int
                 | Wedding String String Int Int Int

-- example
johnSmith :: Anniversary
johnSmith = Birthday "John Smith" 1968 7 3

-- access
showDate :: Int -> Int -> Int -> String
showDate y m d = show y ++ "-" ++ show m ++ "-" ++ show d

showAnniversary :: Anniversary -> String

showAnniversary :: (Birthday name year month day) =
  name ++ " born " ++ showDate year month day

showAnniversary :: (Wedding name1 name2 year month day) =
  name ++ " married " ++ name2 ++ " on " ++ showDate year month day
