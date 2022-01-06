import Data.Maybe
import Data.Char
import System.Exit
import System.Environment

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

myCheckNeg :: Char -> Bool
myCheckNeg '-' = True
myCheckNeg _ = False

myCheckNumber :: [Char] -> Bool
myCheckNumber "" = True
myCheckNumber (chara:string)
 | myIsDigit chara == True = myCheckNumber(string)
 | otherwise = False

myFinalCheck :: [Char] -> Bool -> Bool
myFinalCheck (chara:string) neg
 | neg == True = myCheckNumber(string)
 | otherwise = myCheckNumber(chara:string)

readInt :: [Char] -> Maybe Int
readInt "" = Nothing
readInt "-" = Nothing
readInt (chara:string)
 | myFinalCheck (chara:string) (myCheckNeg chara) == False = Nothing
 | otherwise = Just (read (chara:string) :: Int)

getLineLength :: IO Int
getLineLength = do
    line <- getLine
    return $ length line

printAndGetLength :: String -> IO Int
printAndGetLength string = do
    putStrLn string
    return $ length string

printCorner :: Int -> IO ()
printCorner _ = putChar '+' >>
    return ()

printHorizLine :: Int -> IO ()
printHorizLine 0 = return ()
printHorizLine size = putChar '-' >>
    putChar '-' >>
    printHorizLine (size - 1)

printHorizontal :: Int -> IO ()
printHorizontal size = printCorner 1 >>
    printHorizLine (size - 1) >>
    printCorner 1 >>
    putChar '\n' >>
    return ()


printVerticalSide :: Int -> IO ()
printVerticalSide _ = putChar '|' >>
    return ()

printVerticalSpace :: Int -> IO ()
printVerticalSpace 0 = return ()
printVerticalSpace size = putChar ' ' >>
    putChar ' ' >>
    printVerticalSpace (size - 1)

printVerticalLines :: Int -> Int -> IO ()
printVerticalLines size 0 = return ()
printVerticalLines size (-1) = return ()
printVerticalLines size remaining = printVerticalSide 1 >>
    printVerticalSpace (size - 1) >>
    printVerticalSide 1 >>
    putChar '\n' >>
    printVerticalLines size (remaining - 1)

printVertical :: Int -> IO ()
printVertical size = printVerticalLines size (size - 2)

realPrintBox :: Int -> IO ()
realPrintBox size = printHorizontal size >>
    printVertical size >>
    printHorizontal size >>
    return ()

printBox :: Int -> IO ()
printBox 1 = putStrLn "++"
printBox size
 | size <= 0 = return ()
 | otherwise = realPrintBox size >>
    return ()

myLength :: [a] -> Int
myLength [] = 0
myLength (x:y) = myLength y + 1

myAppend :: [a] -> [a] -> [a]
myAppend (x:y) [] = (x:y)
myAppend [] (x:y) = (x:y)
myAppend [] [] = []
myAppend (a:b) (x:y)
 | myLength (a:b) > 1 = (a:myAppend (b) (x:y))
 | otherwise = (a:x:y)

createConcatString :: Int -> String -> IO String
createConcatString 0 string = return (string)
createConcatString lines string = do
    line <- getLine
    createConcatString (lines - 1) (myAppend string line)

concatLines :: Int -> IO String
concatLines lines
 | lines <= 0 = return("")
 | otherwise = createConcatString lines ""

getInt :: IO (Maybe Int)
getInt = do
    line <- getLine
    return (Just (read line :: Int))

isOperand :: Char -> Bool
isOperand '+' = True
isOperand '-' = True
isOperand '*' = True
isOperand '/' = True
isOperand '%' = True
isOperand _ = False

checkOperand :: String -> Bool
checkOperand (chara:string)
 | isOperand chara == True = True
 | otherwise = False

checkDoOpThirdArg :: [String] -> Bool
checkDoOpThirdArg ((sign:arg):args)
 | myFinalCheck (sign:arg) (myCheckNeg sign) == False = False
 | otherwise = True

checkDoOpSecondArg :: [String] -> Bool
checkDoOpSecondArg (arg:args)
 | checkOperand arg == False = False
 | otherwise = checkDoOpThirdArg args

checkDoOpFirstArg :: [String] -> Bool
checkDoOpFirstArg ((sign:arg):args)
 | myFinalCheck (sign:arg) (myCheckNeg sign) == False = False
 | otherwise = checkDoOpSecondArg args

whichOperation :: [Char] -> Int
whichOperation "+" = 0
whichOperation "-" = 1
whichOperation "*" = 2
whichOperation "/" = 3
whichOperation "%" = 4

doAddition :: [String] -> IO ()
doAddition (first:sign:second:rest) = print ((read first :: Int) + (read second :: Int)) >>
    exitWith(ExitSuccess)

doSubstraction :: [String] -> IO ()
doSubstraction (first:sign:second:rest) = print ((read first :: Int) - (read second :: Int)) >>
    exitWith(ExitSuccess)

doMultiplication :: [String] -> IO ()
doMultiplication (first:sign:second:rest) = print ((read first :: Int) * (read second :: Int)) >>
    exitWith(ExitSuccess)

doDivision :: [String] -> IO ()
doDivision (first:sign:second:rest)
 | second == "0" = exitWith(ExitFailure 84)
doDivision (first:sign:second:rest) = print
    ((read first :: Int) `div` (read second :: Int)) >>
    exitWith(ExitSuccess)

doModulo :: [String] -> IO ()
doModulo (first:sign:second:rest)
 | second == "0" = exitWith(ExitFailure 84)
doModulo (first:sign:second:rest) = print
    ((read first :: Int) `mod` (read second :: Int)) >>
    exitWith(ExitSuccess)

doOperation :: [String] -> IO ()
doOperation (first:sign:second)
 | whichOperation(sign) == 0 = doAddition(first:sign:second)
 | whichOperation(sign) == 1 = doSubstraction(first:sign:second)
 | whichOperation(sign) == 2 = doMultiplication(first:sign:second)
 | whichOperation(sign) == 3 = doDivision(first:sign:second)
 | otherwise = doModulo(first:sign:second)

doOp :: [String] -> IO ()
doOp (arg:args)
 | length (arg:args) /= 3 = exitWith(ExitFailure 84)
 | checkDoOpFirstArg (arg:args) == False = exitWith(ExitFailure 84)
 | otherwise = doOperation (arg:args)

main :: IO()
main = do
    args <- getArgs
    doOp args