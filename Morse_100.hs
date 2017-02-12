import Data.Char
morse::[String]
morse= [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
toMorse::Char->String
toMorse x = toMorse' (toLower x)
 where toMorse' x = morse!!((fromEnum x)-97)
 
translate::String->String
translate [] = []
translate (x:xs) = (toMorse x)++translate xs

main = do
 tap<-getLine
 jor<-getLine
 putStrLn ( if (translate tap == translate jor) then "Es lo mesmo" else "No es lo mesmo")
