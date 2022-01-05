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