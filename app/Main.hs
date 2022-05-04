import Text.Read
import System.Environment
import System.Exit
import Foreign.Marshal.Unsafe
import System.IO.Error
import Control.Exception
import GHC.Base
import Data.List
import Data.Maybe
import Data.Word
import System.Random
import Data.Typeable

data TempConf = TempConf {
    nbColor' :: Maybe Int,
    limit' :: Maybe Double,
    path' :: Maybe String
} deriving (Show)

data Conf =  Conf {
    nbColor :: Int,
    limit :: Double,
    path :: String
} deriving (Show)

defaultConf :: TempConf
defaultConf = TempConf{nbColor' = Nothing, limit' = Nothing, path' = Nothing}

validateConf :: TempConf -> Maybe Conf
validateConf (TempConf (Just a) (Just b) (Just c)) =
    Just Conf{nbColor = a, limit = b, path = c}
validateConf _ = Nothing

getOpts :: TempConf -> [String] -> Maybe TempConf
getOpts conf a = go conf a where
    go conf [] = Just conf
    go conf ("-n" : x : val) = go conf{nbColor' = readMaybe x :: Maybe Int} val
    go conf ("-l" : x : val) = go conf{limit' = readMaybe x :: Maybe Double} val
    go conf ("-f" : x : val) = go conf{path' = Just x} val
    go conf _ = Nothing

createRandomMeanList :: [((Int, Int),(Int, Int, Int))] -> [Int] -> [(Int, Int, Int)]
createRandomMeanList list [] = []
createRandomMeanList list (actual:next) = ((snd (list !! actual)):(
    createRandomMeanList (take actual list ++ drop (1 + actual) list) next))

initListOfListWithMeans :: [(Int, Int, Int)] -> [[((Int, Int),(Int, Int, Int))]]
initListOfListWithMeans ((a,b,c):[]) = [[((0,0),(a,b,c))]]
initListOfListWithMeans ((a,b,c):means) = ([((0,0),(a,b,c))]:initListOfListWithMeans means)

calculateDistance :: (Double, Double, Double) -> (Double, Double, Double) -> Double
calculateDistance (r1, g1, b1) (r2, g2, b2) = sqrt (((r1 - r2) ** 2) + ((g1 - g2) ** 2) + ((b1 - b2) ** 2))

colorToDouble :: (Int, Int, Int) -> (Double, Double, Double)
colorToDouble (a, b, c) = ((fromIntegral a), (fromIntegral b), (fromIntegral c))

getClosest :: [(Int, Int, Int)] -> (Int, Int, Int) -> Int -> Int -> Double -> Int
getClosest [] _ index _ _ = index
getClosest (mean:means) point index 0 value = getClosest means point 0 1 (calculateDistance (colorToDouble mean) (colorToDouble point))
getClosest (mean:means) point index actual value =
    let distance = calculateDistance (colorToDouble mean) (colorToDouble point)
    in if (distance < value)
        then getClosest means point actual (actual + 1) distance
        else getClosest means point index (actual + 1) value

addAtBeginningOfListIndex :: Int -> [[a]] -> a -> [[a]]
addAtBeginningOfListIndex index list element =
    let (a,b) = splitAt (index + 1) list
    in init a ++ [(element:last a)] ++ b

generateRelatedPoints :: [(Int, Int, Int)] -> [((Int, Int),(Int, Int, Int))] -> [[((Int, Int),(Int, Int, Int))]] -> [[((Int, Int),(Int, Int, Int))]]
generateRelatedPoints _ [] sortedPoints = sortedPoints
generateRelatedPoints means (point:allPoints) sortedPoints =
    let index = (getClosest means (snd point) (-1) 0 0)
    in generateRelatedPoints means allPoints (addAtBeginningOfListIndex index sortedPoints point)

calculateIndMean :: ([Int],[Int],[Int]) -> (Int, Int, Int)
calculateIndMean (a, b, c) = ((round ((fromIntegral (sum a)) / (fromIntegral (length a)))), (round ((fromIntegral (sum b)) / (fromIntegral (length b)))), (round ((fromIntegral (sum c)) / (fromIntegral (length c)))))

calculateNewMeans :: [[((Int, Int),(Int, Int, Int))]] -> [(Int, Int, Int)]
calculateNewMeans [] = []
calculateNewMeans (actual:next) = let (a,b) = unzip actual
    in (calculateIndMean (unzip3 b):calculateNewMeans next)

isLastIt :: [(Int, Int, Int)] -> [(Int, Int, Int)] -> Double -> Bool
isLastIt [] [] _ = True
isLastIt (mean:means) (newMean:newMeans) limit =
    let distance = calculateDistance (colorToDouble mean) (colorToDouble newMean)
    in if (distance <= limit)
        then isLastIt means newMeans limit
        else False

printPixel :: [((Int, Int),(Int, Int, Int))] -> IO ()
printPixel (result:[]) = return ();
printPixel ((a,b):results) = (putStr . show $ a) >>
    putStr " " >>
    print b >>
    printPixel results


printCluster :: [((Int, Int),(Int, Int, Int))] -> (Int, Int, Int) -> IO ()
printCluster result mean = putStrLn "--" >>
    print mean >>
    putStrLn "-" >>
    printPixel result

printResult :: [[((Int, Int),(Int, Int, Int))]] -> [(Int, Int, Int)] -> IO ()
printResult [] [] = exitWith (ExitSuccess)
printResult (result:results) (mean:means) = printCluster result mean >>
    printResult results means

iteration :: [(Int, Int, Int)] -> [((Int, Int),(Int, Int, Int))] -> Double -> IO ()
iteration means allPoints limit =
    let relatedPoints = generateRelatedPoints means allPoints (initListOfListWithMeans means)
    in let newMeans = calculateNewMeans relatedPoints
    in let lastIt = isLastIt means newMeans limit
    in if (lastIt == True)
        then printResult relatedPoints means
        else iteration newMeans allPoints limit

generateRandomIndexList :: Int -> Int -> IO [Int]
generateRandomIndexList max 0 = return ([])
generateRandomIndexList max k = do
    index <- randomRIO(0, max)
    indexNext <- generateRandomIndexList (max - 1) (k - 1)
    return (index:indexNext)

compressor :: Conf -> [((Int, Int),(Int, Int, Int))] -> IO ()
compressor conf list = do
    randomIndexList <- generateRandomIndexList ((length list) - 1) (nbColor conf)
    iteration (createRandomMeanList list randomIndexList) list (limit conf)

checkLineFromFile :: [String] -> Bool
checkLineFromFile [first,second]
 | isNothing (readMaybe first :: Maybe (Word, Word)) || isNothing (
    readMaybe second :: Maybe (Word8, Word8, Word8)) = False
 | otherwise = True
checkLineFromFile _ = False

checkFileContent :: [String] -> Bool
checkFileContent [] = True
checkFileContent (line:lines)
 | not (checkLineFromFile (words line)) = False
 | otherwise = checkFileContent lines

checkPath :: String -> String -> IO String
checkPath def filePath = readFile filePath `catch`
    \e -> const (return def) (e :: IOException)

lineToContent :: [String] -> ((Word, Word),(Word8, Word8, Word8))
lineToContent [first, second] = ((read first ::(Word, Word)), (
    read second :: (Word8, Word8, Word8)))
lineToContent _ = ((0,0),(0,0,0))

wordContentToInt :: ((Word, Word),(Word8, Word8, Word8)) -> ((Int, Int), (Int, Int, Int))
wordContentToInt ((a, b),(c, d, e)) = ((fromIntegral a, fromIntegral b),(
    fromIntegral c, fromIntegral d, fromIntegral e))

fileToContent :: [String] -> [((Int, Int),(Int, Int, Int))]
fileToContent [] = []
fileToContent (line:lines) = (wordContentToInt (lineToContent (words line)):fileToContent lines)

checkFilePath :: Conf -> IO ()
checkFilePath conf = do
    str <- checkPath "" (path conf)
    case str of
        "" -> exitWith (ExitFailure 84)
        _ -> case checkFileContent (lines str) of
            False -> exitWith (ExitFailure 84)
            True -> compressor conf (fileToContent (lines str))

main :: IO ()
main = do
    args <- getArgs
    case getOpts defaultConf args of
        Nothing -> exitWith (ExitFailure 84)
        Just conf -> case validateConf conf of
            Nothing -> exitWith (ExitFailure 84)
            Just realconf -> checkFilePath realconf