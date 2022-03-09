module Main where

import System.Exit
import System.Environment
import Data.Maybe
import Text.Read

data Conf = Conf {
    rule :: Maybe Int,
    start :: Maybe Int,
    nbLines :: Maybe Int,
    window :: Maybe Int,
    move :: Maybe Int
}

defaultConf :: Conf
defaultConf = Conf{rule = Nothing, start = Just 0, nbLines = Just (-1), window = Just 80, move = Just 0}


wGVFC :: Char -> Int
wGVFC '*' = 1;
wGVFC _ = 0;

mP :: [Int] -> String -> Char
mP [1, 1, 1] [a, b, c, d, e, f, g, h] = a
mP [1, 1, 0] [a, b, c, d, e, f, g, h] = b
mP [1, 0, 1] [a, b, c, d, e, f, g, h] = c
mP [1, 0, 0] [a, b, c, d, e, f, g, h] = d
mP [0, 1, 1] [a, b, c, d, e, f, g, h] = e
mP [0, 1, 0] [a, b, c, d, e, f, g, h] = f
mP [0, 0, 1] [a, b, c, d, e, f, g, h] = g
mP [0, 0, 0] [a, b, c, d, e, f, g, h] = h
mP _ _ = 'k'

cLT :: Int -> String -> String -> String
cLT 3 aStr rule = aStr
cLT 2 aStr rule = cLT 3 (aStr ++ [mP [wGVFC '*', 0, 0] rule]) rule
cLT 1 aStr rule = cLT 2 (aStr ++ [mP [0, wGVFC '*', 0] rule]) rule
cLT 0 aStr rule = cLT 1 (aStr ++ [mP [0, 0, wGVFC '*'] rule]) rule
cLT _ _ _ = []

cL :: Int -> String -> String -> String -> String
cL _ [] aStr _ = aStr
cL 0 (char:pStr) aStr r = cL 1 (char:pStr) (aStr ++ [mP [0, 0, wGVFC char] r]) r
cL 1 (char:char':pStr) aStr r = cL 2 (char:char':pStr) (aStr ++ [
    mP [0, wGVFC char, wGVFC char'] r]) r
cL inc (char:char':char'':pStr) aStr r = cL (inc + 1) (char':char'':pStr) (
    aStr ++ [mP [wGVFC char, wGVFC char', wGVFC char''] r]) r
cL inc [char,char'] aStr r = cL (inc + 1) [char'] (aStr ++ [
    mP [wGVFC char, wGVFC char', 0] r]) r
cL inc [char] aStr r = cL (inc + 1) [] (aStr ++ [mP [wGVFC char, 0, 0] r]) r

createArr :: Int -> Int -> String -> [String] -> String -> [String]
createArr 0 max "*" [] rule = createArr 1 max (cLT 0 [] rule) ["*"] rule
createArr inc max pStr arr rule
 | inc == max - 1 = arr ++ [pStr]
 | otherwise = createArr (inc + 1) max (cL 0 pStr [] rule) (arr ++ [pStr]) rule

printWolfram :: [String] -> IO ()
printWolfram = foldr ((>>) . putStrLn) exitSuccess

printBTR :: String -> IO()
printBTR = foldr (\ x -> (>>) (putChar x >> putChar '\n')) exitSuccess

intToBinary :: Int -> [Int] -> [Int]
intToBinary 0 result = result
intToBinary i result = intToBinary (i `div` 2) ((i `mod` 2):result)

padToEight :: [Int] -> [Int]
padToEight list
 | length list == 8 = list
 | otherwise = padToEight (0:list)

binaryToRule :: [Int] -> String -> String
binaryToRule [] rule = rule
binaryToRule (1:xs) rule = binaryToRule xs (rule ++ ['*'])
binaryToRule (0:xs) rule = binaryToRule xs (rule ++ [' '])
binaryToRule _ _ = []

spacePad :: String -> Int -> Bool -> String
spacePad (char:str) window left
 | length (char:str) == window = char:str
 | length (char:str) < window && left = spacePad (' ':char:str) window False
 | length (char:str) < window = spacePad ((char:str) ++ " ") window True
 | length (char:str) > window && left = spacePad str window False
 | length (char:str) > window = spacePad (take (length (char:str) - 1) (char:str)) window True
spacePad _ _ _ = ""

wolframMove :: String -> Int -> String
wolframMove str 0 = str
wolframMove (char:str) index
 | index < 0 = wolframMove (str ++ " ") (index + 1)
 | otherwise =  wolframMove (take (length (' ':char:str) - 1) (' ':char:str)) (index - 1)
wolframMove _ _ = ""

printWolframPadding :: Int -> Int -> Int -> Int -> Int -> String -> String -> IO()
printWolframPadding inc max start window moveVar "*" rule
 | start <= 0 = putStrLn (wolframMove (spacePad "*" window True) moveVar) >>
                putStrLn (wolframMove (spacePad (cLT 0 [] rule) window True) moveVar) >>
                printWolframPadding (inc + 1) max (start - 1) window moveVar (cLT 0 [] rule) rule
 | otherwise = printWolframPadding (inc + 1) max (start - 1) window moveVar (cLT 0 [] rule) rule
printWolframPadding inc max start window moveVar pStr rule
 | inc == max = exitSuccess
 | start <= 0 =putStrLn (wolframMove(spacePad (cL 0 pStr [] rule) window True) moveVar) >>
               printWolframPadding (inc + 1) max (start - 1) window moveVar (cL 0 pStr [] rule) rule
 | otherwise = printWolframPadding (inc + 1) max (start - 1) window moveVar (cL 0 pStr [] rule) rule

algo :: Conf -> IO ()
algo conf = printWolframPadding 0 ((delMaybeInt (nbLines conf)) + (delMaybeInt (start conf)) - 1) (delMaybeInt (start conf) - 1) (delMaybeInt (window conf)) (delMaybeInt (move conf)) "*" (
    binaryToRule (padToEight (intToBinary (delMaybeInt (rule conf)) [])) [])


getRule, getStart, getLines, getWindow, getMove :: [String] -> Maybe Int
getRule ("--rule":x':_) = readMaybe x' :: Maybe Int
getRule (x:x':xs) = getRule xs
getRule _ = Nothing
getStart ("--start":x':_) = readMaybe x' :: Maybe Int
getStart (x:x':xs) = getStart xs
getStart _ = Nothing
getLines ("--lines":x':_) = readMaybe x' :: Maybe Int
getLines (x:x':xs) = getLines xs
getLines _ = Nothing
getWindow ("--window":x':_) = readMaybe x' :: Maybe Int
getWindow (x:x':xs) = getWindow xs
getWindow _ = Nothing
getMove ("--move":x':_) = readMaybe x' :: Maybe Int
getMove (x:x':xs) = getMove xs
getMove _ = Nothing

assignConfValue :: Conf -> Maybe Int -> [Maybe Int] -> Int -> Maybe Conf
assignConfValue conf _ _ 0 = Just conf
assignConfValue conf rule (Nothing:list) 4 = assignConfValue conf{rule = rule} rule list 3
assignConfValue conf rule (start:list) 4 = assignConfValue conf{rule = rule, start = start} rule list 3
assignConfValue conf rule (Nothing:list) 3 = assignConfValue conf rule list 2
assignConfValue conf rule (lines:list) 3 = assignConfValue conf{nbLines = lines} rule list 2
assignConfValue conf rule (Nothing:list) 2 = assignConfValue conf rule list 1
assignConfValue conf rule (window:list) 2 = assignConfValue conf{window = window} rule list 1
assignConfValue conf rule [Nothing] 1 = assignConfValue conf rule [] 0
assignConfValue conf rule [move] 1 = assignConfValue conf{move = move} rule [] 0
assignConfValue conf rule _ _ = assignConfValue conf rule [] 0

getOpts :: Conf -> Maybe Int -> Maybe Int -> Maybe Int -> Maybe Int -> Maybe Int -> Maybe Conf
getOpts conf Nothing _ _ _ _ = Nothing
getOpts conf rule start lines window move
 | rule < Just 0 || rule > Just 255 = Nothing
 | start /= Nothing && start < Just 0 = Nothing
 | window /= Nothing && window < Just 0 = Nothing
 | otherwise = assignConfValue conf rule [start,lines,window,move] 4

checkArgContentSecond :: [String] -> [String] -> Maybe Conf
checkArgContentSecond [] copy = getOpts defaultConf (getRule copy) (getStart copy) (getLines copy) (getWindow copy) (getMove copy)
checkArgContentSecond (x:x':xs) copy
 | x `notElem` ["--rule","--start","--lines","--window","--move"] = Nothing
 | isNothing (readMaybe x' :: Maybe Int) = Nothing
 | otherwise = checkArgContentSecond xs copy
checkArgContentSecond _ _ = Nothing

checkArgContent :: [String] -> Maybe Conf
checkArgContent args
 | length (filter (=="--rule") args) /= 1 = Nothing
 | length (filter (=="--start") args) > 1 = Nothing
 | length (filter (=="--lines") args) > 1 = Nothing
 | length (filter (=="--window") args) > 1 = Nothing
 | length (filter (=="--move") args) > 1 = Nothing
 | otherwise = checkArgContentSecond args args

checkArgs :: [String] -> Maybe Conf
checkArgs [] = Nothing
checkArgs args
 | length args `mod` 2 == 1 || length args > 10 = Nothing
 | otherwise = checkArgContent args

delMaybeInt :: Maybe Int -> Int
delMaybeInt (Just value) = value
delMaybeInt _ = -1

main :: IO()
main = do
    args <- getArgs
    case checkArgs args of
        Just conf -> algo conf
        _ -> exitWith (ExitFailure 84)
