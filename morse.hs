import Data.Char
morse::[String]
morse= [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
getchar::Char->String
getchar x = getchar' (toLower x)
 where getchar' x = morse!!((fromEnum x)-97)
 
translate::String->String
translate [] = []
translate (x:xs) = (getchar x)++translate xs

main = do
 tap<-getLine
 jor<-getLine
 putStrLn ( if (translate tap == translate jor) then "Es lo mesmo" else "No es lo mesmo")
