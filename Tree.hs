-- Task 01

data Tree a = Empty | Node (Tree a) a (Tree a) 
    deriving (Show)