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

data Mob a = Mummy | Skeleton Item | Witch (Maybe Item)
    deriving (Eq)

-- Task 05

createMummy :: Mob a
createMummy = Mummy

createArcher :: Mob a
createArcher = Skeleton Bow

createKnight :: Mob a
createKnight = Skeleton Sword

createWitch :: Mob a
createWitch = Witch Nothing

createSorceress :: Mob a
createSorceress = Witch (Just MagicWand)