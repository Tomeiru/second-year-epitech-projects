-- imports
import Data.Maybe
import System.Exit
import System.Environment
import Text.Read

-- functions for error handling
checkStringFull :: String -> Bool
checkStringFull (a:b:c:[])
 | b /= '_' = False
 | a == c = False
 | elem a ("123456") == False = False
 | elem c ("123456") == False = False
 | otherwise = True
checkStringFull _ = False

checkLastChar :: String -> Bool
checkLastChar (a:[]) = elem a ("123456")
checkLastChar _ = False

checkExpectedCombination :: String -> [String] -> Bool
checkExpectedCombination _ [] = False
checkExpectedCombination arg (comb:comb_next)
 | take 5 arg == comb && comb == "full_" = checkStringFull (drop 5 arg)
 | take 5 arg == comb = checkLastChar (drop 5 arg)
 | take 6 arg == comb = checkLastChar (drop 6 arg)
 | take 9 arg == comb = checkLastChar (drop 9 arg)
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

full :: [Int] -> [Int] -> IO ()
full dices (a:b:[]) = exitWith(ExitSuccess)

pair :: [Int] -> Int -> IO ()
pair dices a = exitWith(ExitSuccess)

three :: [Int] -> Int -> IO ()
three dices a = exitWith(ExitSuccess)

four :: [Int] -> Int -> IO ()
four dices a = exitWith(ExitSuccess)

straight :: [Int] -> Int -> IO ()
straight dices a = exitWith(ExitSuccess)

yamsComb :: [Int] -> Int -> IO ()
yamsComb dices a = exitWith(ExitSuccess)

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