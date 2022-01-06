import Data.Maybe

myElem :: Eq a => a -> [a] -> Bool
myElem argument [] = False
myElem argument (element:list)
 | argument == element = True
 | argument /= element = myElem argument list

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv dividend divisor = Just (dividend `div` divisor)

safeNth :: [a] -> Int -> Maybe a
safeNth [] z = Nothing
safeNth (x:y) 0 = Just x
safeNth (x:y) z
 | z < 0 = Nothing
 | z > 0 = safeNth y (z - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just x) = Just (x + 1)