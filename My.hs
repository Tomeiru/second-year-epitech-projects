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
myNth (x:y) 0 = x
myNth (x:y) z
 | z < 0 = error("N is negative")
 | z > 0 = myNth y (z - 1)

myTake :: Int -> [a] -> [a]
myTake 0 (x:y) = []
myTake z (x:y)
 | z < 0 = error("Z can't be inferior to 0")
 | z >= myLength (x:y) = (x:y)
 | z > 0 = (x:(myTake (z - 1) (y)))

myDrop :: Int -> [a] -> [a]
myDrop z [] = []
myDrop 0 (x:y) = (x:y)
myDrop z (x:y)
 | z >= myLength (x:y) = []
 | otherwise = myDrop (z - 1) (y)

myAppend :: [a] -> [a] -> [a]
myAppend (x:y) [] = (x:y)
myAppend [] (x:y) = (x:y)
myAppend [] [] = []
myAppend (a:b) (x:y)
 | myLength (a:b) > 1 = (a:myAppend (b) (x:y))
 | otherwise = (a:x:y)

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (a:b) = myAppend (myReverse(b)) (a:[])

myInit :: [a] -> [a]
myInit [] = error "List is Empty"
myInit (x:y) = myTake (myLength(x:y) - 1) (x:y)

myLast :: [a] -> a
myLast [] = error "List is Empty"
myLast (a:b)
 | myLength(a:b) > 1 = (myLast(b))
 | otherwise = a

myZip :: [a] -> [b] -> [(a, b)]
myZip _ [] = []
myZip [] _ = []
myZip (w:x) (y:z) = ((myTuple w y):(myZip x z))

myUnzip :: [(a,b)] -> ([a], [b])
myUnzip [] = ([],[])
myUnzip ((w,x):b) = ((w:myFst(myUnzip(b))), (x:mySnd(myUnzip(b))))

myMap :: (a -> b) -> [a] -> [b]
myMap function [] = []
myMap function (a:b) = function a:myMap function b

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter function [] = []
myFilter function (a:b)
 | function a == True = a:myFilter function b
 | otherwise = myFilter function b

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl function z [] = z
myFoldl function z (a:b) = myFoldl function (function z a) (b) 

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr function z [] = z
myFoldr function z (a:b) = function a (myFoldr function z b)

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition function [] = ([],[])
myPartition function (a:b)
 | function a == True = ((a:myFst(myPartition function b)),
 (mySnd(myPartition function b)))
 | otherwise = ((myFst(myPartition function b)),
 (a:mySnd(myPartition function b)))

myPartQuickSort :: (a -> a -> Bool) -> a -> [a] -> ([a], [a])
myPartQuickSort function a [] = ([],[])
myPartQuickSort function x (a:b)
 | function x a == True = ((a:myFst(myPartQuickSort function x b)),
 (mySnd(myPartQuickSort function x b)))
 | otherwise = ((myFst(myPartQuickSort function x b)),
 (a:mySnd(myPartQuickSort function x b)))

myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort function [] = []
myQuickSort function (a:b) = myAppend (myAppend(myQuickSort function (
    mySnd(myPartQuickSort function a b)))
    [a]) (myQuickSort function (myFst(myPartQuickSort function a b)))