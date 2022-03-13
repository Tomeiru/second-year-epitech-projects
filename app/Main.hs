module Main where

import System.Exit
import System.Environment
import Data.Maybe
import Text.Read
import Text.Printf (FormatParse(FormatParse))

data Conf = Conf {
    rule :: Maybe Int,
    start :: Maybe Int,
    nbLines :: Maybe Int,
    window :: Maybe Int,
    move :: Maybe Int
}

defaultConf :: Conf
defaultConf = Conf{rule = Nothing, start = Just 0, nbLines = Just (
    -1), window = Just 80, move = Just 0}


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

spacePad :: String -> Int -> String
spacePad str window
 | (window > length str) && ((window - length str) `mod` 2 == 1) = replicate ((
     (window - length str) `div` 2) + 1) ' ' ++ str ++ replicate ((
         window - length str) `div` 2) ' '
 | window > length str = replicate ((
     window - length str) `div` 2) ' ' ++ str ++ replicate ((
         window - length str) `div` 2) ' '
 | otherwise = take window (drop ((length str - window) `div` 2) str)

wolframMove :: String -> String -> Int -> Int -> String
wolframMove str ss i win
 | win >= length ss && i < 0 = drop (-i) str ++ replicate (-i) ' '
 | win >= length ss = replicate i ' ' ++ take (length str - i) str
 | i < 0 && (-i - ((length ss - win + 1))`div` 2) > 0 = drop (-i) str ++ drop (
     length ss - ((length ss - win + 1))`div` 2) ss ++ replicate (-i - ((
         length ss - win + 1))`div` 2) ' '
 | i < 0 = drop (-i) str ++ take (-i) (drop (length ss - ((
     length ss - win + 1))`div` 2) ss)
 | (i - ((length ss - win))`div` 2) > 0 = replicate (i - ((
     length ss - win))`div` 2) ' ' ++ take (((
         length ss - win))`div` 2) ss ++ take (length str - i) str
 | otherwise = drop (-(i - ((length ss - win))`div` 2)) (take (((
     length ss - win))`div` 2) ss) ++ take (length str - i) str

printRecallFirst :: String -> Int -> Int -> Int -> Int -> Int -> String -> IO ()
printRecallFirst str inc max start window moveVar rule
 | start <= 0 = putStrLn (wolframMove (
     spacePad "*" window) "*" moveVar window) >>
                putStrLn (wolframMove (
                    spacePad str window) str moveVar window) >>
                printWolframPad (
                    inc + 1) max (start - 1) window moveVar str rule
 | otherwise = printWolframPad (
     inc + 1) max (start - 1) window moveVar (cLT 0 [] rule) rule

printRecallOther :: String -> Int -> Int -> Int -> Int -> Int -> String -> IO ()
printRecallOther str inc max start window moveVar rule
 | start <= 0 = putStrLn (wolframMove (
     spacePad str window) str moveVar window) >>
               printWolframPad (
                   inc + 1) max (start - 1) window moveVar str rule
 | otherwise = printWolframPad (
     inc + 1) max (start - 1) window moveVar str rule

printWolframPad :: Int -> Int -> Int -> Int -> Int -> String -> String -> IO()
printWolframPad inc max start window moveVar "*" rule = printRecallFirst (
    cLT 0 [] rule) inc max start window moveVar rule
printWolframPad inc max start window moveVar pStr rule
 | inc == max = exitSuccess
 | otherwise = printRecallOther (
     cL 0 pStr [] rule) inc max start window moveVar rule

algo :: Conf -> IO ()
algo conf = printWolframPad 0 (delMaybeInt (nbLines conf) + delMaybeInt (
    start conf) - 1) (delMaybeInt (start conf) - 1) (delMaybeInt (
        window conf)) (delMaybeInt (move conf)) "*" (
    binaryToRule (padToEight (intToBinary (delMaybeInt (rule conf)) [])) [])


getRule :: [String] -> Maybe Int
getRule ("--rule":x':_) = readMaybe x' :: Maybe Int
getRule (x:x':xs) = getRule xs
getRule _ = Nothing

getStart :: [String] -> Maybe Int
getStart ("--start":x':_) = readMaybe x' :: Maybe Int
getStart (x:x':xs) = getStart xs
getStart _ = Nothing

getLines :: [String] -> Maybe Int
getLines ("--lines":x':_) = readMaybe x' :: Maybe Int
getLines (x:x':xs) = getLines xs
getLines _ = Nothing

getWindow :: [String] -> Maybe Int
getWindow ("--window":x':_) = readMaybe x' :: Maybe Int
getWindow (x:x':xs) = getWindow xs
getWindow _ = Nothing

getMove :: [String] -> Maybe Int
getMove ("--move":x':_) = readMaybe x' :: Maybe Int
getMove (x:x':xs) = getMove xs
getMove _ = Nothing

aConfVal :: Conf -> Maybe Int -> [Maybe Int] -> Int -> Maybe Conf
aConfVal conf _ _ 0 = Just conf
aConfVal conf rule (Nothing:list) 4 = aConfVal conf{rule = rule} rule list 3
aConfVal conf rule (start:list) 4 = aConfVal conf{
    rule = rule, start = start} rule list 3
aConfVal conf rule (Nothing:list) 3 = aConfVal conf rule list 2
aConfVal conf rule (lines:list) 3 = aConfVal conf{nbLines = lines} rule list 2
aConfVal conf rule (Nothing:list) 2 = aConfVal conf rule list 1
aConfVal conf rule (window:list) 2 = aConfVal conf{window = window} rule list 1
aConfVal conf rule [Nothing] 1 = aConfVal conf rule [] 0
aConfVal conf rule [move] 1 = aConfVal conf{move = move} rule [] 0
aConfVal conf rule _ _ = aConfVal conf rule [] 0

getOpts :: Conf -> Maybe Int -> 
    Maybe Int -> Maybe Int -> Maybe Int -> Maybe Int -> Maybe Conf
getOpts conf Nothing _ _ _ _ = Nothing
getOpts conf rule start lines window move
 | rule < Just 0 || rule > Just 255 = Nothing
 | isJust start && start < Just 0 = Nothing
 | isJust window && window < Just 0 = Nothing
 | otherwise = aConfVal conf rule [start,lines,window,move] 4

checkArgContentSecond :: [String] -> [String] -> Maybe Conf
checkArgContentSecond [] copy = getOpts defaultConf (getRule copy) (
    getStart copy) (getLines copy) (getWindow copy) (getMove copy)
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
