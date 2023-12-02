# SoftwareEngineeringCA

I did some preliminary testing from class examples. 
I attempted to add a randomly moving circle as is seen in the 'Pang' and 'Asteroids' Raylib example games. 
I first tried to copy relevant code from the 'Asteroids' game, but then chose to use the 'Pang' example as I wanted the circle to not go past the edge of the screen.
I removed the gravity instruction as I didn't want any gravity to be applied
After copying what seemed to be the relevant code and testing and adjusting, I am left with five warning errors including four similar:
''narrowing conversion of 'posx', 'posy', 'velx' and 'vely' from 'int' to 'float'' 
I found this link (https://bbs.archlinux.org/viewtopic.php?id=219747) and tried adjusting to unsigned ints
Game is no longer showing anything at all so I checked draw section against the 'Pang' game for any discrepancies.
Tried changing 'posx', 'posy', 'velx' and 'vely' to numbers - errors went but still nothing drawn
Added 'static int score' to initialisation
Abandoning this and returning to last working commit
I found later that the Asteroids game in Raylib also shows these errors while still running, so I may not have needed to spend so much time trying to resolve the narrowing conversion errors and wreck my game in the process.

After attempting a number of starting points such as trying to insert animated texture into Raylib asteroids game, and trying to assign different textures by using header files, I have reverted back to starting from the example shown in class which includes an animated character, two different textures and a collision function and intend to build out from there. 

