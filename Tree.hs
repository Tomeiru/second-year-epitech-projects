-- Task 11

data Tree a = Empty | Node (Tree a) a (Tree a) 
    deriving (Show)

-- Task 12

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree value Empty = Node Empty value Empty
addInTree value (Node tree y tree')
 | value < y = (Node (Node Empty value Empty) y tree')
 | otherwise = (Node tree y (Node Empty value Empty))