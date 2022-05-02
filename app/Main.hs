import Text.Read
import System.Environment
import System.Exit
import Foreign.Marshal.Unsafe
import System.IO.Error
import Control.Exception
import GHC.Base

data TempConf = TempConf {
    nbColor' :: Maybe Int,
    limit' :: Maybe Int,
    path' :: Maybe String
} deriving (Show)

data Conf =  Conf {
    nbColor :: Int,
    limit :: Int,
    path :: String
} deriving (Show)

defaultConf :: TempConf
defaultConf = TempConf{nbColor' = Nothing, limit' = Nothing, path' = Nothing}

validateConf :: TempConf -> Maybe Conf
validateConf (TempConf (Just a) (Just b) (Just c)) =
    Just Conf{nbColor = a, limit = b, path = c}
validateConf _ = Nothing

checkPath :: IO String -> Maybe String
checkPath file = if unsafeLocalState file == "" then Nothing else Just (unsafeLocalState file)

getOpts :: TempConf -> [String] -> Maybe TempConf
getOpts conf a = go conf a where
    go conf [] = Just conf
    go conf ("-n" : x : val) = go conf{nbColor' = readMaybe x :: Maybe Int} val
    go conf ("-l" : x : val) = go conf{limit' = readMaybe x :: Maybe Int} val
    go conf ("-f" : x : val) = go conf{path' = checkPath (readFile x)} val
    go conf _ = Nothing

compressor :: Conf -> Conf
compressor = compressor

main :: IO ()
main = do
    args <- getArgs
    case getOpts defaultConf args of
        Nothing -> exitWith (ExitFailure 84)
        Just conf -> case validateConf conf of
            Nothing -> exitWith (ExitFailure 84)
            Just realconf -> putStrLn "Yo"