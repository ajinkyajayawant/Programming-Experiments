{-# LANGUAGE FlexibleInstances, UndecidableInstances, DuplicateRecordFields #-}

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



main :: IO()
main = do
    n <- readLn :: IO Int

    forM_ [1..n] $ \n_itr -> do
        x <- readLn :: IO Double


my_max x = x_max where
    xmax = if x_max > 1
        then x
        else 1

cal_trunc iter pow x = result where
    new_temp = if iter < 10
        then pow * x / my_max x
        else 0
    new_iter = iter +1
    new_pow = if iter < 10
        then pow + call_trunc new_iter new_temp x
