data SetOrd a = Vacio | Elem a SetOrd deriving (Show)

add :: (Ord a) => SetOrd a -> a -> SetOrd a
add Vacio i = Elem i Vacio
add (Elem e es) i
            | i < e = 
