mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x
 | x < 0 = True
 | otherwise = False

myAbs :: Int -> Int
myAbs x
 | x < 0 = x * (-1)
 | otherwise = x

myMin :: Int -> Int -> Int
myMin x y
 | x <= y = x
 | otherwise = y

myMax :: Int -> Int -> Int
myMax x y
 | x >= y = x
 | otherwise = y

myTuple :: a -> b -> (a, b)
myTuple x y = (x, y)

myTruple :: a -> b -> c -> (a, b, c)
myTruple x y z = (x, y, z)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead [] = error "List is Empty"
myHead (x:y) = x

myTail :: [a] -> [a]
myTail [] = error "List is Empty"
myTail (x:y) = y

myLength :: [a] -> Int
myLength [] = 0
myLength (x:y) = myLength y + 1

myNth :: [a] -> Int -> a
myNth [] z = error("List is Empty or your N is to high")
myNth (x:y) z
 | z < 0 = error("N is negative")
 | z == 0 = x
 | z > 0 = myNth y (z - 1)

myTake :: Int -> [a] -> [a]
myTake z (x:y)
 | z < 0 = error("Z can't be inferior to 0")
 | z >= myLength (x:y) = (x:y)
 | z > 0 = (x:(myTake (z - 1) (y)))
 | z == 0 = []

myDrop :: Int -> [a] -> [a]
myDrop z [] = []
myDrop z (x:y)
 | z >= myLength (x:y) = []
 | z == 0 = (x:y)
 | otherwise = myDrop (z - 1) (y)

myAppend :: [a] -> [a] -> [a]
myAppend (x:y) [] = (x:y)
myAppend [] (x:y) = (x:y)
myAppend (a:b) (x:y)
 | myLength (a:b) > 1 = (a:myAppend (b) (x:y))
 | otherwise = (a:x:y)