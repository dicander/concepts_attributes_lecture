-- Definiera en Printable-typklass med en toString-funktion
class Printable a where
    toString :: a -> String

-- Definiera en instans av Printable för typen Int
instance Printable Int where
    toString x = show x

-- Definiera en instans av Printable för typen Bool
instance Printable Bool where
    toString True = "true"
    toString False = "false"

-- En funktion som tar en Printable-typ och skriver ut dess strängrepresentation
printValue :: (Printable a) => a -> IO ()
printValue x = putStrLn (toString x)

main :: IO ()
main = do
    printValue (42 :: Int)    -- Skriver ut "42"
    printValue True           -- Skriver ut "true"
