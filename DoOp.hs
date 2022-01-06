import Data.Maybe
import Data.Char

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

getLineLength :: IO Int
getLineLength = do
    line <- getLine
    return $ length line

printAndGetLength :: String -> IO Int
printAndGetLength string = do
    putStrLn string
    return $ length string

printCorner :: Int -> IO ()
printCorner _ = do
    putChar '+'
    return ()

printHorizLine :: Int -> IO ()
printHorizLine 0 = return ()
printHorizLine size = do
    putChar '-'
    putChar '-'
    printHorizLine (size - 1)

printHorizontal :: Int -> IO ()
printHorizontal size = do
    printCorner 1
    printHorizLine (size - 1)
    printCorner 1
    putChar '\n'
    return ()


printVerticalSide :: Int -> IO ()
printVerticalSide _ = do
    putChar '|'
    return ()

printVerticalSpace :: Int -> IO ()
printVerticalSpace 0 = return ()
printVerticalSpace size = do
    putChar ' '
    putChar ' '
    printVerticalSpace (size - 1)

printVerticalLines :: Int -> Int -> IO ()
printVerticalLines size 0 = return ()
printVerticalLines size (-1) = return ()
printVerticalLines size remaining = do
    printVerticalSide 1
    printVerticalSpace (size - 1)
    printVerticalSide 1
    putChar '\n'
    printVerticalLines size (remaining - 1)

printVertical :: Int -> IO ()
printVertical size = printVerticalLines size (size - 2)

realPrintBox :: Int -> IO ()
realPrintBox size = do
    printHorizontal size
    printVertical size
    printHorizontal size
    return ()

printBox :: Int -> IO ()
printBox 1 = putStrLn "++"
printBox size
 | size <= 0 = return ()
 | otherwise = do
    realPrintBox size
    return ()