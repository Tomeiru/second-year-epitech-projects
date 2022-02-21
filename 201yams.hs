-- imports
import Data.Maybe
import System.Exit
import System.Environment
import Text.Read
import Text.Printf
import Data.List

-- functions for error handling
checkStringFull :: String -> Bool
checkStringFull (a:b:c:[])
 | b /= '_' = False
 | a == c = False
 | elem a ("123456") == False = False
 | elem c ("123456") == False = False
 | otherwise = True
checkStringFull _ = False

checkLastChar :: String -> Bool -> Bool
checkLastChar (a:[]) False = elem a ("123456")
checkLastChar (a:[]) True = elem a ("56")
checkLastChar _ _ = False

checkExpectedCombination :: String -> [String] -> Bool
checkExpectedCombination _ [] = False
checkExpectedCombination arg (comb:comb_next)
 | take 5 arg == comb && comb == "full_" = checkStringFull (drop 5 arg)
 | take 5 arg == comb = checkLastChar (drop 5 arg) False
 | take 6 arg == comb = checkLastChar (drop 6 arg) False
 | take 9 arg == comb = checkLastChar (drop 9 arg) True
 | otherwise = checkExpectedCombination arg comb_next

checkArgsContent :: [String] -> Bool
checkArgsContent (arg:[]) = checkExpectedCombination arg ["pair_","four_","yams_","full_","three_","straight_"]
checkArgsContent (arg:args)
 | (readMaybe arg :: Maybe Int) == Nothing = False
 | elem arg ["0","1","2","3","4","5","6"] == False = False
 | otherwise = checkArgsContent args

checkArgs :: [String] -> Bool
checkArgs [] = False
checkArgs ("-h":[]) = True
checkArgs (args)
 | length args /= 6 = False
 | otherwise = checkArgsContent args
-- end of functions for error handling

-- functions to print help text
checkHelp :: [String] -> Bool
checkHelp ("-h":[]) = True
checkHelp _ = False

printHelp :: [String] -> Int -> IO ()
printHelp [] 84 = exitWith(ExitFailure 84)
printHelp [] 0 = exitWith(ExitSuccess)
printHelp (arg:args) returnValue = putStrLn(arg) >>
                                   printHelp args returnValue

printUsage :: Int -> IO()
printUsage returnValue = do
    usage <- readFile "usage"
    printHelp (lines usage) returnValue
-- end of functions to print help text

-- functions to parse args
argsToDice :: [String] -> [Int]
argsToDice (arg:[]) = []
argsToDice (arg:args) = ((read arg :: Int):(argsToDice args))

operationToTuple :: String -> (String,[Int])
operationToTuple ('f':'u':'l':'l':'_':a:b:c:[]) = ("full", ((read (a:[]) :: Int):(read (c:[]) :: Int):[]))
operationToTuple str = ((take ((length str) - 2) str), ((read ((last str):[]) :: Int):[]))
-- end of functions to parse args

-- main functions

printFunction :: [Int] -> String -> Double -> Bool -> IO ()
printFunction (a:[]) str pourcentage False = printf "Chances to get a %i %s: %.2f%%\n" (a) (str) (pourcentage)
printFunction (a:b:[]) str pourcentage True = printf "Changes to get a %i %s %i: %.2f%%\n" (a) (str) (b) (pourcentage)

--calculate :: Int -> Int -> Double
--calculate 0 _ = 0
--calculate 1 nbSuccess = 

perfectDices :: [Int] -> Int -> Int
perfectDices dices value = length $ filter (== value) dices

full :: [Int] -> [Int] -> IO ()
full dices (a:b:[])
 | perfectDices dices a == 3 && perfectDices dices b == 2 = printFunction (a:b:[]) "full of" 100 True
 | otherwise = exitWith(ExitFailure 84)

pair :: [Int] -> Int -> IO ()
pair dices a
 | perfectDices dices a >= 2 = printFunction (a:[]) "pair" 100 False
 | otherwise = exitWith(ExitFailure 84)

three :: [Int] -> Int -> IO ()
three dices a
 | perfectDices dices a >= 3 = printFunction (a:[]) "three-of-a-kind" 100 False
 | otherwise = exitWith(ExitFailure 84)

four :: [Int] -> Int -> IO ()
four dices a
 | perfectDices dices a >= 4 = printFunction (a:[]) "four-of-a-kind" 100 False
 | otherwise = exitWith(ExitFailure 84)

checkStraightSix :: [Int] -> Int -> Int -> Int
checkStraightSix _ 1 ret = ret
checkStraightSix dices rest ret
 | find (==rest) dices == Nothing = checkStraightSix dices (rest - 1) ret
 | otherwise = checkStraightSix dices (rest - 1) (ret + 1)

checkStraightFive :: [Int] -> Int -> Int -> Int
checkStraightFive _ 0 ret = ret
checkStraightFive dices rest ret
 | find (==rest) dices == Nothing = checkStraightFive dices (rest - 1) ret
 | otherwise = checkStraightFive dices (rest - 1) (ret + 1)

straight :: [Int] -> Int -> IO ()
straight dices 6
 | checkStraightSix dices 6 0 == 5 = printFunction (6:[]) "straight" 100 False
 | otherwise = exitWith(ExitFailure 84)
straight dices 5
 | checkStraightFive dices 5 0 == 5 = printFunction (5:[]) "straight" 100 False
 | otherwise = exitWith(ExitFailure 84)

yamsComb :: [Int] -> Int -> IO ()
yamsComb dices a
 | perfectDices dices a >= 5 = printFunction (a:[]) "yams" 100 False
 | otherwise = exitWith(ExitFailure 84)

yams :: [Int] -> (String,[Int]) -> IO ()
yams dices ("full", list) = full dices list
yams dices ("pair", (a:[])) = pair dices a
yams dices ("three", (a:[])) = three dices a
yams dices ("four", (a:[])) = four dices a
yams dices ("straight", (a:[])) = straight dices a
yams dices ("yams", (a:[])) = yamsComb dices a


prelimininaries :: [String] -> IO ()
prelimininaries args
 | checkArgs args == False = printUsage 84
 | checkHelp args == True = printUsage 0
 | otherwise = yams (argsToDice args) (operationToTuple (last args))

main :: IO()
main = do
    args <- getArgs
    prelimininaries args