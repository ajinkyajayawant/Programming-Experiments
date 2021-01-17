data Anniversary = Birthday String Int Int Int
                 | Wedding String String Int Int Int

-- example
johnSmith :: Anniversary
johnSmith = Birthday "John Smith" 1968 7 3

-- access
showDate :: Int -> Int -> Int -> String
showDate y m d = show y ++ "-" ++ show m ++ "-" ++ show d

showAnniversary :: Anniversary -> String

showAnniversary (Birthday name year month day) =
  name ++ " born " ++ showDate year month day

showAnniversary (Wedding name1 name2 year month day) =
  name1 ++ " married " ++ name2 ++ " on " ++ showDate year month day

-- My solution
data Date = Ymd Int Int Int

-- access
myshowDate :: Date -> String
myshowDate (Ymd y m d) = show y ++ "-" ++ show m ++ "-" ++ show d

data MyAnniversary = MyBirthday String Date
                   | MyWedding String String Date

myshowAnniversary :: MyAnniversary -> String

myshowAnniversary (MyBirthday name fixedDate) =
  name ++ " born " ++ myshowDate fixedDate

myshowAnniversary (MyWedding name1 name2 fixedDate) =
  name1 ++ " married " ++ name2 ++ " on " ++ myshowDate fixedDate

-- Initialization
date1 = Ymd 1970 10 24
janniversary = MyBirthday "John" date1

-- Execution
-- :load ./HaskellWikibook/date_pg111
-- myshowAnniversary janniversary
