# SoftwareEngineeringCA

I did some preliminary testing from class examples. 
I attempted to add a randomly moving circle as is seen in the 'Pang' and 'Asteroids' Raylib example games. 
I first tried to copy relevant code from the 'Asteroids' game, but then chose to use the 'Pang' example as I wanted the circle to not go past the edge of the screen.
I removed the gravity instruction as I didn't want any gravity to be applied
After copying what seemed to be the relevant code and testing and adjusting, I am left with five warning errors including four similar:
''narrowing conversion of 'posx', 'posy', 'velx' and 'vely' from 'int' to 'float'' 
I found this link (https://bbs.archlinux.org/viewtopic.php?id=219747) and tried adjusting to unsigned ints
Game is no longer showing anything so checked draw section against the 'Pang' game for any discrepancies.
Tried changing 'posx', 'posy', 'velx' and 'vely' to numbers - errors went but still nothing drawn
Added 'static int score' to initialisation
Abandoning this and returning to last working commit

