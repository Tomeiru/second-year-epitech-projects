-- Task 01 and 02

data Item = Sword | Bow | MagicWand
    deriving (Eq)

-- Task 03

instance Show Item where
    show = showItem

showItem :: Item -> String
showItem Sword = "sword"
showItem Bow = "bow"
showItem MagicWand = "magic wand"

-- Task 04

data Mob = Mummy | Skeleton Item | Witch (Maybe Item)
    deriving (Eq)

-- Task 08

instance Show Mob where
    show = showMob

showMob :: Mob -> String
showMob Mummy = "mummy"
showMob (Skeleton Bow) = "doomed archer"
showMob (Skeleton Sword) = "dead knight"
showMob (Skeleton x) = "skeleton holding a " ++ (show x)
showMob (Witch Nothing) = "witch"
showMob (Witch (Just MagicWand)) = "sorceress"
showMob (Witch (Just x)) = "witch holding a " ++ (show x)

-- Task 05

createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

-- Task 06

create :: String -> Maybe Mob
create "mummy" = Just (createMummy)
create "doomed archer" = Just (createArcher)
create "dead knight" = Just (createKnight)
create "witch" = Just (createWitch)
create "sorceress" = Just (createSorceress)
create x = Nothing

-- Task 07

equip :: Item -> Mob -> Maybe Mob
equip _ (Mummy) = Nothing
equip Sword (Skeleton _) = Just (createKnight)
equip Sword (Witch _) = Just (Witch (Just Sword))
equip Bow (Skeleton _) = Just (createArcher)
equip Bow (Witch _) = Just (Witch (Just Bow))
equip MagicWand (Skeleton _) = Just (Skeleton MagicWand)
equip MagicWand (Witch _) = Just (createSorceress)

-- Task 09 and 10

class HasItem a where
    getItem :: a -> Maybe Item
    hasItem :: a -> Bool
    hasItem a = case getItem a of
        Nothing -> False
        _ -> True
 
instance HasItem Mob where
    hasItem Mummy = False
    hasItem (Witch Nothing) = False
    hasItem (Skeleton _) = True
    hasItem (Witch _) = True
    getItem Mummy = Nothing
    getItem (Witch Nothing) = Nothing
    getItem (Skeleton x) = Just x
    getItem (Witch (Just x)) = Just x