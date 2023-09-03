
# Astro SDL Framework v1.0

Behold Astro SDL Framework, a header only celestial game development framework like non other on our 
planet to make your games shine. it's a universe of stars at your fingertips for effortlessly enhancing 
your game's shining as you travel though the cosmic universe of game development and anticipate even 
more stars on the horizon to make your games shine even more joining the constellation of possibilities, 
expanding your cosmic playground.


## Features

+ Simple
+ Header Only
+ Customization
+ Fastest Installation
+ No Forced Dependencies
+ Rectangle Manipulation
+ Scene Management
+ Sprite Management
+ Audio Management
+ Network Management
+ Physics Includation


## Configuration [ Important ]

`#define _ASTRO_IMPLEMENTATION`		

	Generates the implementation of Astro and physac into the included file.
	If not defined, the library is in header only mode and can be included in other headers
	or source files without problems. But only ONE file should hold the implementation.	

`#define _ASTRO_SHAPE_DECONSTRUCTER(SHAPE_CLASS)` [ Predefined ]

	DON'T YOU DARE TRY THIS, THIS IS JUST HERE TO LET YOU KNOW THAT.

**BELOW MENTIONED ONCE DEFAULT TO EVERYTHING**

`#define SDL_INIT_FLAGS` [ Predefined ]

	Flags to initialize SDL with.
    
`#define IMG_INIT_FLAGS` [ Predefined ]

	Flags to intialize IMG with.
	
`#define MIX_INIT_FLAGS` [ Predefined ]

	Flags to intialize MIX with.

**BELOW MENTIONED ONCE DEFAULT TO NOTHING**

`#define WIN_INIT_FLAGS` [ Predefined ]

	Flags to initialize Astro::Window with.

`#define REN_INIT_FLAGS` [ Predefined ]

	Flags to initialize Astro::Renderer with.

**BELOW MENTIONED ONCE SHOULD BE PASSED AS CXX FLAGS AND WILL INITIALIZE && UNINITIALIZE THE LIBRARIES THEY INCLUDE**

`-D_ASTRO_TTF`

	+ Adds Text named class in Astro::
	+ Adds Text* member in Astro::Rect
	- Includes TTF 
	
`-D_ASTRO_IMG`

	+ Textured Rects
	- Includes IMG
	
`-D_ASTRO_MIX`

	+ Enables AudioManager::
	- Includes MIX
	
`-D_ASTRO_NET`

	+ Enables Network::
	- Includes NET	
	- Includes vector

`-D_ASTRO_PHY`

	+ Adds physics support
	- Includes PHYSAC https://github.com/victorfisac/Physac/blob/master/src/physac.h
	- Must be in same directory
	* Defines PHYSAC_STANDALONE to avoid raylib
	* Defines and undefines _STDBOOL_H else physac tries to define bool
	* Undefines min & max defined by physac
	
`-D_ASTRO_LOG`

	+ Logs logs
	- Includes iostream
	* Defines PHYSAC_DEBUG
	
`-D_ASTRO_EXPERIEMTNAL`

	+ Adds Broken Circles
	+ Adds Broken Polygons
	- Includes algorithm
	* OVERALL, DO NOT USE

Also includes `unordered_map`
## Documentation

You don't need it, everything is plain and simple and if it isn't then it has information above or next to it.


## Usage/Examples

```cpp

```

