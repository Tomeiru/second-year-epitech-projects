import Text.Read
import System.Environment
import System.Exit
import Foreign.Marshal.Unsafe
import System.IO.Error
import Control.Exception
import GHC.Base
import Data.List
import Data.Maybe

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

compressor :: Conf -> [String] -> IO ()
compressor = compressor

checkLineFromFile :: [String] -> Bool
checkLineFromFile [first,second]
 | isNothing (readMaybe first :: Maybe (Int, Int)) || isNothing (
    readMaybe second :: Maybe (Int, Int, Int)) = False
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

checkFilePath :: Conf -> IO ()
checkFilePath conf = do
    str <- checkPath "" (path conf)
    case str of
        "" -> exitWith (ExitFailure 84)
        _ -> case checkFileContent (lines str) of
            False -> exitWith (ExitFailure 84)
            True -> compressor conf (lines str)

main :: IO ()
main = do
    args <- getArgs
    case getOpts defaultConf args of
        Nothing -> exitWith (ExitFailure 84)
        Just conf -> case validateConf conf of
            Nothing -> exitWith (ExitFailure 84)
            Just realconf -> checkFilePath realconf