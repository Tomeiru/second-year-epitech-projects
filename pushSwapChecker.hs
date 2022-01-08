-- imports
import Data.Maybe
import System.Exit
import System.Environment
import Text.Read

-- functions for error handling
checkArgsAreNum :: [String] -> Bool
checkArgsAreNum [] = True
checkArgsAreNum (arg:args)
 | (readMaybe arg :: Maybe Int) == Nothing = False
 | otherwise = checkArgsAreNum args

checkArgs :: [String] -> Bool
checkArgs [] = False
checkArgs (args) = checkArgsAreNum args

checkOpIsCorrect :: String -> [String] -> Bool
checkOpIsCorrect _ [] = False
checkOpIsCorrect op_arg (op:op_next)
 | op_arg == op = True
 | otherwise = checkOpIsCorrect op_arg op_next

checkOpsAreCorrect :: [String] -> Bool
checkOpsAreCorrect [] = True
checkOpsAreCorrect (op:op_next)
 | checkOpIsCorrect op ["sa","sb","sc","pa","pb","ra","rb","rr","rra",
    "rrb","rrr"] == True = checkOpsAreCorrect(op_next)
 | otherwise = False

checkOps :: String -> Bool
checkOps [] = True
checkOps ops = checkOpsAreCorrect (words ops)
-- end of functions for error handling

-- pushSwapInstructions
swapInstr :: [Int] -> [Int]
swapInstr list
 | length list < 2 = list
swapInstr (first:second:list) = (second:first:list)

pushInstr :: ([Int],[Int]) -> ([Int],[Int])
pushInstr ([],listB) = ([],listB)
pushInstr ((firstA:listA),listB) = (listA,(firstA:listB))

invPushInstr :: ([Int],[Int]) -> ([Int],[Int])
invPushInstr (listA,[]) = (listA,[])
invPushInstr (listA,(firstB:listB)) = ((firstB:listA),listB)

rotateInstr :: [Int] -> [Int]
rotateInstr [] = []
rotateInstr (element:list) = (list ++ [element])

revRotInstr :: [Int] -> [Int]
revRotInstr [] = []
revRotInstr list = reverse (rotateInstr(reverse list))

-- works with swap rotate and revRot
instrToBothList :: ([Int] -> [Int]) -> ([Int],[Int]) -> ([Int],[Int])
instrToBothList function (listA,listB) = ((function listA),(function listB))

-- end of pushSwapInstructions

checkList :: [Int] -> Bool
checkList (current:[]) = True
checkList (current:next:list)
 | current <= next = checkList (next:list)
 | otherwise = False

checkResult :: ([Int],[Int]) -> Bool
checkResult ([], _) = False
checkResult (listA,listB)
 | listB /= [] = False
 | otherwise = checkList listA

printResult :: ([Int],[Int]) -> IO ()
printResult (listA,listB)
 | checkResult (listA,listB) == True = putStrLn "OK"
 | otherwise = putStr "KO:" >>
    print (listA,listB)

execSwap :: ([Int],[Int]) -> String -> ([Int],[Int])
execSwap (listA,listB) "sa" = ((swapInstr listA),listB)
execSwap (listA,listB) "sb" = (listA,(swapInstr listB))
execSwap (listA,listB) "sc" = instrToBothList swapInstr (listA,listB)

execPush :: ([Int],[Int])-> String -> ([Int],[Int])
execPush (listA,listB) "pa" = invPushInstr (listA,listB)
execPush (listA,listB) "pb" = pushInstr (listA,listB)

execRotate :: ([Int],[Int])-> String -> ([Int],[Int])
execRotate (listA,listB) "ra" = ((rotateInstr listA),listB)
execRotate (listA,listB) "rb" = (listA,(rotateInstr listB))
execRotate (listA,listB) "rr" = instrToBothList rotateInstr (listA,listB)
execRotate (listA,listB) "rra" = ((revRotInstr listA),listB)
execRotate (listA,listB) "rrb" = (listA,(revRotInstr listB))
execRotate (listA,listB) "rrr" = instrToBothList revRotInstr (listA,listB)

execInstr :: ([Int],[Int]) -> String -> ([Int],[Int])
execInstr (listA,listB) ('s':string) = execSwap (listA,listB) ('s':string)
execInstr (listA,listB) ('p':string) = execPush (listA,listB) ('p':string)
execInstr (listA,listB) ('r':string) = execRotate (listA,listB) ('r':string)

doInstr :: ([Int],[Int]) -> [String] -> ([Int],[Int])
doInstr (listA,listB) [] = (listA,listB)
doInstr (listA,listB) (op:next) = doInstr (execInstr (listA,listB) op) next

pushSwapChecker :: ([Int],[Int]) -> [String] -> IO ()
pushSwapChecker (listA,listB) ops = printResult (doInstr (listA,listB) ops)

cvtStrArrToIntArr :: [String] -> [Int]
cvtStrArrToIntArr [] = []
cvtStrArrToIntArr (str:arr) = ((read str :: Int):(cvtStrArrToIntArr arr))

prelimininaries :: [String] -> String -> IO ()
prelimininaries args ops
 | checkArgs args == False = exitWith(ExitFailure 84)
 | checkOps ops == False = exitWith(ExitFailure 84)
 | otherwise = pushSwapChecker ((cvtStrArrToIntArr args),[]) (words ops)

main :: IO()
main = do
    args <- getArgs
    ops <- getLine
    prelimininaries args ops