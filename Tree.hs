-- Task 11

data Tree a = Empty | Node (Tree a) a (Tree a) 
    deriving (Show)

instance Functor Tree where
    fmap f Empty = Empty
    fmap f (Node tree x tree') = Node (fmap f tree) (f x) (fmap f tree') 

-- Task 12

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree value Empty = Node Empty value Empty
addInTree value (Node tree y tree')
 | value < y = (Node (addInTree value tree) y tree')
 | otherwise = (Node tree y (addInTree value tree'))

-- Task 14

listToTree :: Ord a => [a] -> Tree a
listToTree [] = Empty
listToTree (element:list) = addInTree element (listToTree list)