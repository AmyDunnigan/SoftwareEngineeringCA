# SoftwareEngineeringCA

Raylib Project 

Initial attempts 

I did some preliminary testing from class examples. My original goal to add a randomly moving circle as is seen in the 'Pang' and 'Asteroids' raylib example games. I first tried to copy relevant code from the 'Asteroids' game, but then chose to use the 'Pang' example as I wanted the circle to not go past the edge of the screen.  After copying what seemed to be the relevant code and testing and adjusting, I was left with five warning errors including four similar: ''narrowing conversion of 'posx', 'posy', 'velx' and 'vely' from 'int' to 'float' I found some tips online and tried adjusting to unsigned ints but after doing so the game was no longer showing anything at all so I checked draw section against the 'Pang' game for any discrepancies. Tried changing 'posx', 'posy', 'velx' and 'vely' to numbers - errors went but still nothing drawn. I tried adding 'static int score' to initialisation but decided to abandon this attempt and return to my last working commit. I discovered later that the Asteroids game in raylib also shows these errors while still running, so I may not have needed to spend so much time trying to resolve the narrowing conversion errors and wreck my game in the process. 

After attempting a number of starting points such as trying to insert animated texture into the raylib asteroids game, and trying to assign different textures by using header files, I have reverted back to starting from the example shown in class which includes an animated character, two different textures and a collision function and intend to build out from there. 

I spent a number of weeks going back and forth trying to find the best starting point and in the process beginning to understand how the code was working. In the end it seems I had been overly ambitious at the start and began from scratch with a simple game. Therefore, I have decided to embrace the trend of  “cozy gaming”, where gamers seek out more relaxed and comforting experiences. 

Game features 

My main success was being able to copy the asteroids from the raylib game and adjust the size and number to give a snow effect.  In theory I should have been then able to reduce the number of snowflakes to one to achieve my original goal of one randomly moving object, but by this point I had scarfy animating so the snow fit the theme. 

Unfortunately, I was not then able to extract the snow elements into source and header files. I also attempted to do this with the player animation, but decided the small amount of associated code in my main.cpp file didn’t warrant the effort as there were other improvements I wanted to make to the game. Some of these being: 

    Either having the penguin reappear or turn back after hitting screen width 
    Adding collision effects 
    Updating text after collision 

I spent the most time on the penguin movement and experimented with setting setting the screenwidth parameters for the penguin. I was able to make the penguin stop at the edge of the screen, but not able to make him turn around 

References 

Bueno Ltd. (2023). Realistic Text-to-Speech AI converter. [Online]. https://speechgen.io. Last Updated: 2023. Available at: https://speechgen.io [Accessed 1 December 2023]. 

Ian Eito, Albert Martos and Ramon Santamaria. (2015). raylib - classic game: asteroids survival. [Online]. https://www.raylib.com. Last Updated: 2015. Available at: https://github.com/raysan5/raylib-games/blob/master/classics/src/asteroids.c [Accessed 9 November 2023]. 

Ramon Santamaria. (2015). raylib [textures] example - Sprite animation. [Online]. https://www.raylib.com. Last Updated: 2023. Available at: https://github.com/raysan5/raylib/blob/master/examples/textures/textures_sprite_anim.c [Accessed 17 November 2023]. 

