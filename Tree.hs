-- Task 11

data Tree a = Empty | Node (Tree a) a (Tree a) 
    deriving (Show)

instance Functor Tree where
    fmap f Empty = Empty
    fmap f (Node tree x tree') = Node (fmap f tree) (f x) (fmap f tree')

instance Foldable Tree where
    foldMap f Empty = mempty
    foldMap f (Node tree x tree') = ((foldMap f tree) `mappend` (f x)
     `mappend` (foldMap f tree'))

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

-- Task 15

treeToList :: Ord a => Tree a -> [a]
treeToList Empty = []
treeToList (Node tree y tree') = (treeToList(tree) ++ y:treeToList(tree'))

-- Task 16
treeSort :: Ord a => [a] -> [a]
treeSort list = treeToList(listToTree list)