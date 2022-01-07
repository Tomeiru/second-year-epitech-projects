data Item = Sword | Bow | MagicWand
    deriving (Eq)

instance Show Item where
    show = showItem

showItem :: Item -> String
showItem Sword = "sword"
showItem Bow = "bow"
showItem MagicWand = "magic wand"
