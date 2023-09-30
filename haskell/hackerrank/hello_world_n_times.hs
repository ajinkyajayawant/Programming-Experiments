{-# LANGUAGE FlexibleInstances, UndecidableInstances, DuplicateRecordFields #-}

-- Notes: Look into this :do should be used in each branch when there is a block of if and else.
-- return() is an alternative to no action. Look up.
-- I was not able to directly pass n-1 to the hello_worlds function. Why?
-- Looks like functions do not need return statement always?

module Main where

import Control.Monad
import Data.Array
import Data.Bits
import Data.List
import Data.List.Split
import Data.Set
import Debug.Trace
import System.Environment
import System.IO
import System.IO.Unsafe

hello_worlds n = do
    if n > 0
        then do
            putStrLn "Hello World"
            let n1 = n - 1
            hello_worlds n1
        else return()

main :: IO()
main = do
    n <- readLn :: IO Int
    hello_worlds n
    -- Print "Hello World" on a new line 'n' times.
