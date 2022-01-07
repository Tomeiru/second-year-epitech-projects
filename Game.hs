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
    deriving (Eq, Show)

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