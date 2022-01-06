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

myLookup :: Eq a => a -> [(a,b)] -> Maybe b
myLookup _ [] = Nothing
myLookup argument (element:list)
 | argument == fst(element) = Just (snd(element))
 | otherwise = myLookup argument list

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ _ Nothing = Nothing
maybeDo _ Nothing _ = Nothing
maybeDo function (Just a) (Just b) = Just (function a b)


myIsDigit :: Char -> Bool
myIsDigit '0' = True
myIsDigit '1' = True
myIsDigit '2' = True
myIsDigit '3' = True
myIsDigit '4' = True
myIsDigit '5' = True
myIsDigit '6' = True
myIsDigit '7' = True
myIsDigit '8' = True
myIsDigit '9' = True
myIsDigit x = False

myCheckNumber :: [Char] -> Bool
myCheckNumber "" = True
myCheckNumber (chara:string)
 | myIsDigit chara == True = myCheckNumber(string)
 | otherwise = False

readInt :: [Char] -> Maybe Int
readInt "" = Nothing
readInt string
 | myCheckNumber string == False = Nothing
 | otherwise = Just (read string :: Int)
 