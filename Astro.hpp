#pragma once
 
/**************************************************************************************************************************************************************************		
 *	
 *		Astro SDL Framework v1.0 - Game Development Framework 
 *		
 *		DESCRIPTION:
 *		
 *		Behold Astro SDL Framework, a header only celestial game development framework like non other on our 
 * 		planet to make your games shine. it's a universe of stars at your fingertips for effortlessly enhancing 
 * 		your game's shining as you travel though the cosmic universe of game development and anticipate even 
 * 		more stars on the horizon to make your games shine even more joining the constellation of possibilities, 
 * 		expanding your cosmic playground.
 *		
 * 		WHY CHOOSE ASTRO?
 * 		+ Simple
 * 		+ Header Only
 * 		+ Customization
 * 		+ Fastest Installation
 * 		+ No Forced Dependencies Expect SDLmain
 * 		+ Rectangle Manipulation
 * 		+ Scene Management
 * 		+ Sprite Management
 * 		+ Audio Management
 * 		+ Network Management
 * 		+ Physics Integration
 * 
 * 		WHY NOT CHOOSE ASTRO?
 * 		+ You found something better
 * 		+ You want to get low level access to SDL
 * 		+ You want to learn deeply
 * 		- You like to waste time.
 * 		
 *		CONFIGURATION: [ Read Carefully ]
 *
 *		#define _ASTRO_IMPLEMENTATION		
 *			Generates the implementation of Astro and physac into the included file.
 *      	If not defined, the library is in header only mode and can be included in other headers
 *      	or source files without problems. But only ONE file should hold the implementation.	
 *		
 * 		#define _ASTRO_SHAPE_DECONSTRUCTER(SHAPE_CLASS)
 * 			DON'T YOU DARE TRY THIS, 
 * 			THIS IS JUST HERE TO LET YOU KNOW THAT
 * 
 *		BELOW MENTIONED ONCE DEFAULT EVERYTHING
 *		
 *		#define SDL_INIT_FLAGS [ Predefined ]
 *			Flags to initialize SDL with.
 *		
 *		#define IMG_INIT_FLAGS [ Predefined ]
 *			Flags to intialize IMG with.
 *			
 *		#define MIX_INIT_FLAGS [ Predefined ]
 *			Flags to intialize MIX with.
 *		
 *		BELOW MENTIONED ONCE DEFAULT TO 0
 *		
 *		#define WIN_INIT_FLAGS [ Predefined ]
 *			Flags to initialize Astro::Window with.
 *		
 *		#define REN_INIT_FLAGS [ Predefined ]
 *			Flags to initialize Astro::Renderer with.
 *		
 *		BELOW MENTIONED ONCE SHOULD BE PASSED AS CXX FLAGS
 *		AND WILL INITIALIZE && UNINITIALIZE THE LIBRARIES THEY INCLUDE 
 *		
 *		-D_ASTRO_TTF
 *			+ Adds Text named class in Astro::
 *			+ Adds Text* member in Astro::Rect
 *			- Includes TTF 
 *			
 *		-D_ASTRO_IMG
 *			+ Textured Rects
 *			- Includes IMG
 *			
 *		-D_ASTRO_MIX
 *			+ Enables AudioManager::
 *			- Includes MIX
 *			
 *		-D_ASTRO_NET
 *			+ Enables Network::
 *			- Includes NET	
 *			- Includes vector
 *	
 *		-D_ASTRO_PHY
 *			+ Adds physics support
 *			- Includes PHYSAC https://github.com/victorfisac/Physac/blob/master/src/physac.h
 *			- Must be in same directory
 * 			* Defines PHYSAC_STANDALONE to avoid raylib
 * 			* Defines and undefines _STDBOOL_H else physac tries to define bool
 * 			* Undefines min & max defined by physac
 *			
 *		-D_ASTRO_LOG
 *			+ Logs logs
 *			- Includes iostream
 * 			* Defines PHYSAC_DEBUG
 *			
 *		-D_ASTRO_EXPERIEMTNAL
 *			+ Adds Broken Circles
 *			+ Adds Broken Polygons
 *			- Includes algorithm
 *			* OVERALL, DO NOT USE
 *		
 *		Also includes unordered_map
 *		
 *		YOU DON'T NEED DOCUMENTATION, EVERYTHING IS PLAIN AND SIMPLE AND YOU CAN FIND IT ABOVE THE FUNCTION IN CASE ITS HARD TO UNDERSTAND
 *************************************************************************************************************************************************************************/

#include <unordered_map>
#include <memory>

#ifndef SDL_INIT_FLAGS
#	define SDL_INIT_FLAGS SDL_INIT_EVERYTHING
#endif

#ifndef WIN_INIT_FLAGS
#	define WIN_INIT_FLAGS 0
#endif

#ifndef REN_INIT_FLAGS
#	define REN_INIT_FLAGS 0
#endif

#ifndef _ASTRO_NO_CORE
#	include <SDL2/SDL.h>
#endif

#ifdef _ASTRO_TTF
#	include <SDL2/SDL_ttf.h>
#endif // _ASTRO_TTF

#ifdef _ASTRO_IMG
#   ifndef IMG_INIT_FLAGS
#		define IMG_INIT_FLAGS IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP | IMG_INIT_JXL | IMG_INIT_AVIF
#	endif
#	include <SDL2/SDL_image.h>
#	ifndef _STL_VECTOR_H
#		include <vector>
#	endif
#endif // _ASTRO_TTF

#ifdef _ASTRO_MIX
#	ifndef MIX_INIT_FLAGS
# 		define MIX_INIT_FLAGS MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_MID | MIX_INIT_OPUS
#	endif
#	include <SDL2/SDL_mixer.h>
#endif // _ASTRO_MIX

#ifdef _ASTRO_NET
#	include <SDL2/SDL_net.h>
#	ifndef _STL_VECTOR_H
#		include <vector>
#	endif
#endif // _ASTRO_NET

#ifdef _ASTRO_PHY
#	define PHYSAC_STANDALONE
#	define _STDBOOL_H
#	ifdef _ASTRO_IMPLEMENTATION
#		define PHYSAC_IMPLEMENTATION
#	endif // _ASTRO_IMPLEMENTATION
#	include "physac.h"
#	undef _STDBOOL_H
#	undef min
#	undef max
#endif // _ASTRO_PHY

#ifdef _ASTRO_LOG
#	include <iostream>
#	ifdef _ASTRO_PHY
#		define PHYSAC_DEBUG
#	endif
#	undef _ASTRO_LOG
#	define _ASTRO_LOG(MESSAGE) std::cout << "Astro Framework: " << (MESSAGE) << std::endl
#else
#	define _ASTRO_LOG(MESSAGE)
#endif

#ifndef _ASTRO_SHAPE_DECONSTRUCTER
#	ifdef _ASTRO_PHY
#		define _ASTRO_SHAPE_DECONSTRUCTER(SHAPE_CLASS) SHAPE_CLASS::~SHAPE_CLASS() {\
			DestroyPhysicsBody(this->PhyBody);\
		}
#	else
#		define _ASTRO_SHAPE_DECONSTRUCTER(SHAPE_CLASS) SHAPE_CLASS::~SHAPE_CLASS() {}
#	endif
#endif

#ifdef _ASTRO_EXPERIMENTAL
#	include <algorithm>
#endif

#ifndef _ASTRO_NO_CORE
namespace Astro {
	enum { /*WindowSize = -1,*/ SizeOnly = false };
	extern SDL_Window* Window;
	extern SDL_Renderer* Renderer;
	extern SDL_Point Mouse;
	extern Uint8 MaximumFPS;
	extern bool Loop;
	extern std::unordered_map<int, bool> Events;
	extern std::unordered_map<int, bool> Keys;
	#ifdef _ASTRO_IMG
		extern std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> Textures;
	#endif

	SDL_Color RandomColor();
	bool InRange(int Number, int Minimum, int Maximum);
	bool Hovering(SDL_FRect* Rect);
	bool Clicked(SDL_FRect* Rect, Uint32 Key = SDL_BUTTON_LEFT);
	void ToggleFullscreen();
	struct Rect;
	void CenterRectInRect(SDL_FRect * ToCenter, SDL_FRect * ToCenterIn);
	SDL_FRect * GetWindowRect(bool ReturnPosition = true);

	#ifdef _ASTRO_IMG
		std::shared_ptr<SDL_Texture> LoadSprite(std::string ImageFileName);
	#endif

	struct Size { float w, h; };

	class Scene {
		public:
			Scene();
			int ReturnCode = 0;
			virtual void Loop();
			virtual void Event(SDL_Event& Event);
			~Scene();
	}; // Scene

	#ifdef _ASTRO_TTF
		struct Text : public SDL_FRect {
			double Angle = 0.0;
			std::string Value;

			Text();
			~Text();
			void Render();

			void Add(TTF_Font* Font, std::string Text, SDL_Color Color = {0, 0, 0});
			void Pop(TTF_Font* Font, SDL_Color Color = {0, 0, 0});
			void Set(TTF_Font* Font, std::string Text, SDL_Color Color = {0, 0, 0});
			void Set(TTF_Font* Font, SDL_Color Color = {0, 0, 0});

			private: SDL_Texture * Texture;
		}; // Text
	#endif // _ASTRO_TTF

	class Rect : public SDL_FRect {

		void Init(SDL_FRect Rect);
		std::shared_ptr<SDL_Texture> Texture;

		public:

			Astro::Rect * Layer = nullptr;

			#ifdef _ASTRO_TTF
				Astro::Text * Text = nullptr;
			#endif

			#ifdef _ASTRO_PHY
				PhysicsBody PhyBody;
			#endif // _ASTRO_PHY

			bool Filled = true;
			SDL_Color Color;
			double Angle = 0.0;


			Rect(SDL_FRect RectToInitalizeWith, std::string ImageFileName);
			Rect(SDL_FRect RectToInitalizeWith, SDL_Color Color = Astro::RandomColor());
			~Rect();

			bool Render();
			#ifdef _ASTRO_IMG
				void SetImage(std::string ImageFileName);
			#endif
	}; // Rect 

	#ifdef _ASTRO_EXPERIMENTAL
		struct Circle : public SDL_FPoint {
			float Radius;
			SDL_Color Color;

			#ifdef _ASTRO_PHY
				PhysicsBody PhyBody;
			#endif // _ASTRO_PHY
			Circle(SDL_FPoint Center, float Radius, SDL_Color Color = Astro::RandomColor());
		}; // class Circle
		
		struct Polygon : public SDL_FPoint {

			float Radius;
			int Sides;
			SDL_Color Color;

			#ifdef _ASTRO_PHY 
				PhysicsBody PhyBody;
			#endif // _ASTRO_PHY
			
			Polygon(SDL_FPoint Center, float Radius, int Sides, SDL_Color Color = Astro::RandomColor());
		}; // class Polygon
	#endif

	void Init(std::string WindowTitle, SDL_Rect WindowRect = {
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOW_MAXIMIZED, SDL_WINDOW_MAXIMIZED
	}/*, Astro::Size RendererSize = { Astro::WindowSize, Astro::WindowSize }*/);
	int Render(Scene * SceneToRender);
	bool Quit();
} // namespace Astro
#endif

namespace SpriteManager {
	#ifdef _ASTRO_IMG
		extern std::unordered_map<std::string, SDL_Texture*> Sprites;
		bool Load(std::string ImageFileName);
		bool Load(std::string TextureKeyword, std::string SpriteSheetFileName, SDL_Rect SpriteRect);
		void Free();
	#else
		#warning _ASTRO_IMG is undefined so SpriteManager is just a shape renderer.
	#endif // _ASTRO_IMG

	#ifdef _ASTRO_EXPERIMENTAL
		bool Render(Astro::Circle* Circle);
		bool Render(Astro::Polygon* Polygon);
	#endif
} // namespace SpriteManager

#ifdef _ASTRO_MIX
namespace AudioManager {
	extern std::unordered_map<std::string, Mix_Chunk*> Chunks;
	extern std::unordered_map<std::string, Mix_Music*> Musics;

	void Play(std::string AudioFileName, bool IsChunk = true);
	void Free();
} // namespace AudioManager
#endif // _ASTRO_MIX

#ifdef _ASTRO_NET
// CURRENTLY ONLY SUPPORTS SERVER-CLIENT RELATION
namespace Network {
    extern TCPsocket OurSocket;
    extern std::vector<TCPsocket> Clients;

    bool Init(int Port = 7777, const char* Host = nullptr);
    /**
     * @brief      Links a client to us [ SERVER ] if anyone's trying
     *
     * @return     Client position in the vector, or -1 on failure
     */
    int Link();
    void Drop(int ClientPositionInTheVector);
    bool Send(std::string Data, int ClientPositionInTheVector = -1); // Returns success or faliure
    void Cast(std::string Data, int ClientPositionInTheVectorToSkip = -1);
    std::string Recv(int ClientPositionInTheVector = -1);
} // namespace AudioManager
#endif

#ifdef _ASTRO_IMG
namespace UI {
        void LoadWindow(std::string Prefix, std::string FileAddress, int WidthAndHeight);
        std::vector<Astro::Rect*> CreateWindow(std::string Prefix, SDL_Rect R, int Size);
} //namespace UI
#endif

#ifdef _ASTRO_IMPLEMENTATION
namespace Astro {

	SDL_Window* Window = nullptr;
	SDL_Renderer* Renderer = nullptr;
	SDL_Point Mouse = { 0, 0 };
	Uint8 MaximumFPS = 60;
	bool Loop = false;
	std::unordered_map<int, bool> Events;
	std::unordered_map<int, bool> Keys;
	#ifdef _ASTRO_IMG
		std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> Textures;
	#endif

	Scene::Scene() {
		Astro::Loop = true; 
		_ASTRO_LOG("A New Scene Initialized.");
	}
	void Scene::Event(SDL_Event&) { if(Astro::Events[SDL_QUIT]) Astro::Loop = false; }
	void Scene::Loop() {}
	Scene::~Scene() {
		_ASTRO_LOG("A Scene Uninitialized With ReturnCode: " + std::to_string(this->ReturnCode));
	} // Scene::~Scene

	SDL_Color RandomColor() {
		SDL_Color Color;
		Color.r = rand() % 256;
		Color.g = rand() % 256;
		Color.b = rand() % 256;
		Color.a = rand() % 256;
		return Color;
	} // RandomColor

	bool InRange(int Number, int Minimum, int Maximum) {
		return (Number >= Minimum && Number <= Maximum);
	} // InRange

	bool Hovering(SDL_FRect * Rect) {
		return InRange(Mouse.x, Rect->x, Rect->x + Rect->w) && InRange(Mouse.y, Rect->y, Rect->y + Rect->h);
	} // Hovering

	bool Clicked(SDL_FRect * Rect, Uint32 Key) {
		return Astro::Keys[Key] && Hovering(Rect);
	} // Clicked

	void ToggleFullscreen() {
		static bool IsFullscreen = false;
		IsFullscreen = !IsFullscreen;
		SDL_SetWindowFullscreen(Window, IsFullscreen ? SDL_WINDOW_FULLSCREEN : 0);
	} // ToggleFullscreen

	void CenterRectInRect(SDL_FRect * A, SDL_FRect * B) {
		#ifndef _ASTRO_PHY
		    A->x = (B->x + (B->w / 2.0f)) - (A->w / 2.0f);
		    A->y = (B->y + (B->h / 2.0f)) - (A->h / 2.0f);
		#else
		   	A->PhyBody->position.x = (B->x + (B->w / 2.0f)) - (A->w / 2.0f);
		    A->PhyBody->position.y = (B->y + (B->h / 2.0f)) - (A->h / 2.0f);
		#endif
	} // CenterRectInRect

	SDL_FRect * GetWindowRect(bool ReturnPosition) {

		SDL_Rect RawWindowRect = { 0, 0, 0, 0 };
		if(ReturnPosition) SDL_GetWindowPosition(Astro::Window, &RawWindowRect.x, &RawWindowRect.y);
		SDL_GetWindowSize(Astro::Window, &RawWindowRect.w, &RawWindowRect.h);

		static SDL_FRect WindowRect = {
			RawWindowRect.x,
			RawWindowRect.y,
			RawWindowRect.w,
			RawWindowRect.h
		};
		return &WindowRect;
	} // GetWindowRect

	#ifdef _ASTRO_IMG
		std::shared_ptr<SDL_Texture> LoadSprite(std::string ImageFileName) {
		    if (Astro::Textures[ImageFileName]) return Astro::Textures[ImageFileName];

		    SDL_Texture* Texture = IMG_LoadTexture(Astro::Renderer, ("Resources/GFX/" + ImageFileName).c_str());
		    if (Texture == nullptr) {
		        _ASTRO_LOG("Image file " + ImageFileName + " was unable to load.");
		        return nullptr;
		    }

		    Astro::Textures[ImageFileName] = std::shared_ptr<SDL_Texture>(Texture, SDL_DestroyTexture);
		    return Astro::Textures[ImageFileName];
		}
	#endif

	Rect::Rect(SDL_FRect Rect, std::string ImageFileName) {
		this->Init(Rect);
		#ifdef _ASTRO_IMG
			this->Texture = Astro::LoadSprite(ImageFileName);
		#endif
	} // Rect::Rect

	Rect::Rect(SDL_FRect Rect, SDL_Color Color) {
		this->Init(Rect);
		this->Color = Color;
		this->Texture = nullptr;
	} // Rect::Rect

	bool Rect::Render() {

		#ifdef _ASTRO_PHY
			this->x = this->PhyBody->position.x - this->w/2.0f, this->y = this->PhyBody->position.y - this->h/2.0f;
		#endif // _ASTRO_PHY

		if(this->Texture == nullptr) {
			SDL_SetRenderDrawColor(Astro::Renderer, this->Color.r, this->Color.g, this->Color.b, this->Color.a);
			this->Filled ? SDL_RenderFillRectF(Astro::Renderer, this) : SDL_RenderDrawRectF(Astro::Renderer, this);
			SDL_SetRenderDrawColor(Astro::Renderer, 0, 0, 0, 255);
		}
		#ifdef _ASTRO_IMG 
			else {
				if(this->Texture.get() == nullptr) return false;
				SDL_RenderCopyExF(Astro::Renderer,
                    this->Texture.get(),
                    nullptr,
                    this,
                    this->Angle,
                    nullptr,       
					SDL_FLIP_NONE
				);
			}
		#endif // _ASTRO_IMG
		if(this->Layer != nullptr) {
			Astro::CenterRectInRect(this->Layer, this);
			this->Layer->Render();
		}
		#ifdef _ASTRO_TTF
			if(this->Text != nullptr) {
				Astro::CenterRectInRect(this->Text, this);
				this->Text->Render();
			}
		#endif // _ASTRO_TTF
		return true;
	} // Rect::Render

	#ifdef _ASTRO_IMG
		void Rect::SetImage(std::string ImageFileName) {
			this->Texture = Astro::LoadSprite(ImageFileName);
		} // Rect::SetImage
	#endif

	void Rect::Init(SDL_FRect Rect) {
		this->x = Rect.x;
		this->y = Rect.y;

		this->w = Rect.w;
		this->h = Rect.h;

		#ifdef _ASTRO_PHY
			this->PhyBody = CreatePhysicsBodyRectangle((Vector2){ Rect.x + Rect.w / 2.0f, Rect.y + Rect.h / 2.0f }, Rect.w, Rect.h, 1.0f);
		#endif
	} // Rect::Init

	_ASTRO_SHAPE_DECONSTRUCTER(Rect);

	#ifdef _ASTRO_EXPERIMENTAL
		Circle::Circle(SDL_FPoint Center, float Radius, SDL_Color Color) {
			this->x = Center.x;
			this->y = Center.y;
			this->Radius = Radius;
			this->Color = Color;

			#ifdef _ASTRO_PHY
				this->PhyBody = CreatePhysicsBodyCircle({this->x, this->y}, this->Radius, 1.0f);
			#endif
		} // Circle::Circle

		_ASTRO_SHAPE_DECONSTRUCTER(Circle);

		Polygon::Polygon(SDL_FPoint Center, float Radius, int Sides, SDL_Color Color) {
			this->x = Center.x;
			this->y = Center.y;
			this->Radius = Radius;
			this->Sides = Sides;
			this->Color = Color;

			#ifdef _ASTRO_PHY
				this->PhyBody = CreatePhysicsBodyPolygon({this->x, this->y}, Radius, Sides, 1.0f);
			#endif
		} // Polygon::Polygon

		_ASTRO_SHAPE_DECONSTRUCTER(Polygon);
	#endif

	#ifdef _ASTRO_TTF

		Text::Text() {}

		Text::~Text() {
			SDL_DestroyTexture(Texture);
			Texture = nullptr;
		} // Text::~Text

		void Text::Add(TTF_Font * Font, std::string Text, SDL_Color Color) {
			this->Value += Text;
			this->Set(Font, Color);
		} // Text::Add
		void Text::Pop(TTF_Font * Font, SDL_Color Color) {
			if(this->Value.length() > 0) this->Value.pop_back();
			this->Set(Font, Color);
		} // Text::Pop

		void Text::Set(TTF_Font * Font,  std::string Text, SDL_Color Color) {
			this->Value = Text;
			this->Set(Font, Color);
		} // Text::Set
		void Text::Set(TTF_Font * Font,  SDL_Color Color) {
			if(this->Value.empty()) { 
				this->w = 0;
				this->h = 0;
				return;
			}
			// if(Texture != nullptr) {
			// 	SDL_DestroyTexture(Texture);
			// 	Texture = nullptr;
			// }

			SDL_Surface * Surface = TTF_RenderText_Solid(Font, this->Value.c_str(), Color);
			if(Surface == nullptr) _ASTRO_LOG("Failed to render text '" + this->Value + "' because SDL_Surface* was nullptr");
			Texture = SDL_CreateTextureFromSurface(Renderer, Surface);
			this->w = Surface->w;
			this->h = Surface->h;
			SDL_FreeSurface(Surface);
		} // Text::Set

		void Text::Render() { SDL_RenderCopyExF(Astro::Renderer, Texture, nullptr, this, Angle, nullptr, SDL_FLIP_NONE); } // Text::Draw
	#endif // _ASTRO_TTF

	void Init(std::string Title, SDL_Rect WindowRect/*, Astro::Size RendererSize*/) {

		_ASTRO_LOG("********************");
		_ASTRO_LOG("* STARTING PROGRAM *");
		_ASTRO_LOG("********************");

	    _ASTRO_LOG(SDL_Init(SDL_INIT_FLAGS) == 0 ? "SDL Initialized." : SDL_GetError());

		#ifdef _ASTRO_TTF
		    _ASTRO_LOG(TTF_Init() == 0 ? "TTF Initialized." : TTF_GetError());
		#endif // _ASTRO_TTF

		#ifdef _ASTRO_IMG
		    IMG_Init(IMG_INIT_FLAGS);
		    _ASTRO_LOG("IMG Initialized.");
		#endif // _ASTRO_IMG

		#ifdef _ASTRO_MIX
		    Mix_Init(MIX_INIT_FLAGS);
		    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);
		    _ASTRO_LOG("MIX Initialized.");
		#endif // _ASTRO_MIX

		#ifdef _ASTRO_NET
		    _ASTRO_LOG(SDLNet_Init() == 0 ? "NET Initialized." : SDLNet_GetError());
		#endif // _ASTRO_NET
		    
		#ifdef _ASTRO_PHY
			InitPhysics();
			_ASTRO_LOG("PHY Initialized");
		#endif

	   Astro::Window = SDL_CreateWindow(
	    	Title.c_str(), WindowRect.x, WindowRect.y, WindowRect.w, WindowRect.h, 
	    	(
	    		WindowRect.w == SDL_WINDOW_MAXIMIZED && 
	    		WindowRect.h == SDL_WINDOW_MAXIMIZED
	    	) ? (SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED | WIN_INIT_FLAGS) : (WIN_INIT_FLAGS)
	    );
	    _ASTRO_LOG(Astro::Window == nullptr ? SDL_GetError() : "Astro::Window* Initialized");
	    
	    if(WindowRect.w == SDL_WINDOW_MAXIMIZED && WindowRect.h == SDL_WINDOW_MAXIMIZED) 
	    	SDL_SetWindowResizable(Astro::Window, SDL_FALSE);
	    
	    Astro::Renderer = SDL_CreateRenderer(Astro::Window, -1, REN_INIT_FLAGS);
	    _ASTRO_LOG(Renderer == nullptr ? SDL_GetError() : "Astro::Renderer* Initialized");

	    // SDL_GetWindowSize(Window, &WindowRect.w, &WindowRect.h);

	    // RendererSize.w = (RendererSize.w == Astro::WindowSize) ? WindowRect.w : RendererSize.w;
		// RendererSize.h = (RendererSize.h == Astro::WindowSize) ? WindowRect.h : RendererSize.h;

		// if (WindowRect.w != -1 || WindowRect.h != -1) SDL_RenderSetLogicalSize(Renderer,
	    //     (RendererSize.w == Astro::WindowSize) ? WindowRect.w : RendererSize.w,
	    //     (RendererSize.h == Astro::WindowSize) ? WindowRect.h : RendererSize.h
	    // );

		// RendererSize.w = WindowRect.w / RendererSize.w;
		// RendererSize.h = WindowRect.h / RendererSize.h;

		// SDL_RenderSetScale(Astro::Renderer, RendererSize.w, RendererSize.h);

	} // Init
	int Render(Scene * SceneToRender) {
		while (Astro::Loop) {
			Uint32 frameStart = SDL_GetTicks();

			//Event Handling
			SDL_Event Event;
			Astro::Events.clear();
			while (SDL_PollEvent(&Event)) {

				Astro::Events[Event.type] = true;

				if(Event.type == SDL_MOUSEMOTION) Astro::Mouse.x = Event.motion.x, Astro::Mouse.y = Event.motion.y;

				if(Event.type == SDL_MOUSEBUTTONDOWN) Astro::Keys[Event.button.button] = true;
				if(Event.type == SDL_MOUSEBUTTONUP) Astro::Keys[Event.button.button] = false;

				if(Event.type == SDL_KEYDOWN) Astro::Keys[Event.key.keysym.sym] = true;
				if(Event.type == SDL_KEYUP) Astro::Keys[Event.key.keysym.sym] = false;


				SceneToRender->Event(Event);
			}
			//Rendering
			SDL_RenderClear(Astro::Renderer);
			SceneToRender->Loop();
			SDL_RenderPresent(Astro::Renderer);

			Uint32 frameTime = SDL_GetTicks() - frameStart;
			if (frameTime < 1000/MaximumFPS) SDL_Delay(1000/MaximumFPS - frameTime);
		}
		int ReturnCode = SceneToRender->ReturnCode;
		delete SceneToRender;
		return ReturnCode;
	} // Render

	bool Quit() {

		_ASTRO_LOG("*******************");
		_ASTRO_LOG("* QUITING PROGRAM *");
		_ASTRO_LOG("*******************");


		SDL_DestroyWindow(Window);
		_ASTRO_LOG("Astro::Window* Uninitialized.");
		
		SDL_DestroyRenderer(Renderer);
		_ASTRO_LOG("Astro::Renderer* Uninitialized.");

		SDL_Quit();
		_ASTRO_LOG("SDL Uninitialized.");

		#ifdef _ASTRO_TTF
			TTF_Quit();
			_ASTRO_LOG("TTF Uninitialized.");
		#endif // _ASTRO_TTF

		#ifdef _ASTRO_IMG
			IMG_Quit();
			_ASTRO_LOG("IMG Uninitialized.");
		#endif // _ASTRO_IMG

		#ifdef _ASTRO_MIX
			Mix_Quit();
			_ASTRO_LOG("TTF Uninitialized.");
		#endif // _ASTRO_MIX

		#ifdef _ASTRO_NET 
			SDLNet_Quit();
			_ASTRO_LOG("NET Uninitialized.");
		#endif // _ASTRO_NET

		#ifdef _ASTRO_PHY
			ClosePhysics();
			_ASTRO_LOG("PHY Uninitialized.");
		#endif // _ASTRO_PHY

		return EXIT_SUCCESS;
	} // Quit
} // namespace Astro

namespace SpriteManager {
#ifdef _ASTRO_IMG
	std::unordered_map<std::string, SDL_Texture*> Sprites;

	bool Load(std::string File) {
		if(SpriteManager::Sprites[File]) return true;

	    SDL_Texture* Texture = IMG_LoadTexture(Astro::Renderer, ("Resources/GFX/" + File).c_str());
	    if(Texture == nullptr) _ASTRO_LOG("Image file named " + File + " was unable to load.");
	    if (!Texture) return false;

	    SpriteManager::Sprites[File] = Texture;
	    return true;
	}

	bool Load(std::string TextureKeyword, std::string File, SDL_Rect SpriteRect) {
	    if(SpriteManager::Sprites[TextureKeyword]) return true;

	    SDL_Texture* SheetTexture = IMG_LoadTexture(Astro::Renderer, ("Resources/GFX/" + File).c_str());
	    if(SheetTexture == nullptr) _ASTRO_LOG("Sprite sheet file named " + File + " was unable to load.");
	    if (SheetTexture == nullptr) return false;

	    SDL_Texture* SpriteTexture = SDL_CreateTexture(Astro::Renderer, SDL_PIXELFORMAT_UNKNOWN, SDL_TEXTUREACCESS_TARGET, SpriteRect.w, SpriteRect.h);
	    if (SpriteTexture == nullptr) {
	        SDL_DestroyTexture(SheetTexture);
	        if(SpriteTexture == nullptr) _ASTRO_LOG("Sprite with keyword " + TextureKeyword + " was unable to load.");
	        return false;
	    }

	    SDL_SetRenderTarget(Astro::Renderer, SpriteTexture);
	    SDL_RenderCopy(Astro::Renderer, SheetTexture, &SpriteRect, nullptr);
	    SDL_SetRenderTarget(Astro::Renderer, nullptr);
	    SpriteManager::Sprites[TextureKeyword] = SpriteTexture;

	    SDL_DestroyTexture(SheetTexture);

	    return true;
	}

	void Free() {
		for (auto& Sprite : SpriteManager::Sprites) SDL_DestroyTexture(Sprite.second);
		SpriteManager::Sprites.clear();
	}
#endif // _ASTRO_IMG

	#ifdef _ASTRO_EXPERIMENTAL
		bool Render(Astro::Circle * Circle) {

			constexpr int tris = 225; // amount of triangles
			float mirror = 2.0f * static_cast<float>(M_PI); // 2 pi
			SDL_Vertex vertices[tris] = {0};

			for (int i = 0; i < tris; i += 3) {
				// the upper bound of the triangle
				vertices[i].position.x = Circle->x; // 0, 3, 6, 9 
				vertices[i].position.y = Circle->y;
				vertices[i].color = Circle->Color;

				// subtract 3 from tris so we don't operate on a triangle that is out of bounds

				// the lower right bound of the triangle
				vertices[i + 1].position.x = Circle->x + (std::cos(i * mirror / (tris - 3)) * Circle->Radius); // 1, 4, 7, 10
				vertices[i + 1].position.y = Circle->y + (std::sin(i * mirror / (tris - 3)) * Circle->Radius);
				vertices[i + 1].color = Circle->Color;

				// the lower left bound of the triangle
				if (i > 0) {
					vertices[i - 1].position.x = Circle->x + (std::cos(i * mirror / (tris - 3)) * Circle->Radius); // 2, 5, 8, 11
					vertices[i - 1].position.y = Circle->y + (std::sin(i * mirror / (tris - 3)) * Circle->Radius);
					vertices[i - 1].color = Circle->Color;
				}
			}

			SDL_RenderGeometry(Astro::Renderer, NULL, vertices, tris - 3, NULL, tris - 3);
		}
		bool Render(Astro::Polygon* Polygon) {

		    if (Polygon->Sides < 3) return false;

		    SDL_Point* polygonPoints = new SDL_Point[Polygon->Sides];
		    for (int i = 0; i < Polygon->Sides - 1; i++) { // Changed the loop condition to Polygon->Sides - 1
		        double angle = 2 * M_PI * i / Polygon->Sides;
		        polygonPoints[i].x = static_cast<int>(Polygon->x + Polygon->Radius * std::cos(angle));
		        polygonPoints[i].y = static_cast<int>(Polygon->y + Polygon->Radius * std::sin(angle));
		    }

		    // Set the last vertex of the polygon to close the shape
		    double angle = 2 * M_PI * (Polygon->Sides - 1) / Polygon->Sides;
		    polygonPoints[Polygon->Sides - 1].x = static_cast<int>(Polygon->x + Polygon->Radius * std::cos(angle));
		    polygonPoints[Polygon->Sides - 1].y = static_cast<int>(Polygon->y + Polygon->Radius * std::sin(angle));

		    // Draw lines between the points to form the polygon
		    SDL_SetRenderDrawColor(Astro::Renderer, Polygon->Color.r, Polygon->Color.g, Polygon->Color.b, Polygon->Color.a);
		    SDL_RenderDrawLines(Astro::Renderer, polygonPoints, Polygon->Sides);
		    SDL_SetRenderDrawColor(Astro::Renderer, 0, 0, 0, 255);

		    delete[] polygonPoints;
		    return true;
		}
	#endif
} // namespace SpriteManager

#ifdef _ASTRO_MIX
namespace AudioManager {
	std::unordered_map<std::string, Mix_Chunk*> Chunks;
	std::unordered_map<std::string, Mix_Music*> Musics;

	void Play(std::string fileName, bool chunk) {
		bool found = false;

		if(chunk) {
			if(!Chunks[fileName]) Chunks[fileName] = Mix_LoadWAV(("Resources/SFX/" + fileName).c_str());
			Mix_PlayChannel(-1, Chunks[fileName], 0);
		} else {
			if(!Musics[fileName]) Musics[fileName] = Mix_LoadMUS(("Resources/SFX/" + fileName).c_str());
			Mix_PlayMusic(Musics[fileName], 0);
		}
	}
	void Free() {
		for(auto& Chunk : Chunks) Mix_FreeChunk(Chunk.second);
		for(auto& Music : Musics) Mix_FreeMusic(Music.second);
	}
} // namespace AudioManager
#endif // _ASTRO_MIX

#ifdef _ASTRO_NET
namespace Network {
    TCPsocket Socket;
    std::vector<TCPsocket> Clients;
    IPaddress ip;

    bool Init(int port, const char* host) {
        if (SDLNet_ResolveHost(&ip, host, port) < 0)
            return false;
        
        Socket = SDLNet_TCP_Open(&ip);
        return Socket != nullptr;
    }
    int Link() {
        TCPsocket client = SDLNet_TCP_Accept(Socket);
        if (!client)
            return -1;
        
        Clients.push_back(client);
        return Clients.size() - 1;
    }

    void Drop(int clientPosition) {
        SDLNet_TCP_Close(Clients[clientPosition]);
        Clients.erase(Clients.begin() + clientPosition);
    }


    bool Send(std::string data, int clientPosition) {
        int dataSize = data.length() + 1;
        int bytesSent = SDLNet_TCP_Send((clientPosition == -1) ? Socket : Clients[clientPosition], data.c_str(), dataSize);
        return bytesSent == dataSize;
    }

    void Cast(std::string data, int ClientNotToSend) {
        for (int Client = 0; Client < Clients.size(); Client++) {
            if(ClientNotToSend == Client) continue;
            Send(data, Client);
        }
    }

    std::string Recv(int clientPosition) {
        const int bufferSize = 1024;
        char buffer[bufferSize];
        
        int bytesRead = SDLNet_TCP_Recv((clientPosition == -1) ? Socket : Clients[clientPosition], buffer, bufferSize - 1);
        std::string receivedData;
        
        if (bytesRead > 0) {
            receivedData = buffer;
            buffer[bytesRead] = '\0';
        }
        
        return receivedData;
    }
} // namespace Network
#endif

#ifdef _ASTRO_IMG
namespace UI {
        void LoadWindow(std::string Prefix, std::string FileAddress, int WidthAndHeight) {
                SpriteManager::Load(Prefix + "TOP_LEFT", FileAddress, {0, 0, WidthAndHeight/3, WidthAndHeight/3});
                SpriteManager::Load(Prefix + "TOP_MID", FileAddress, {WidthAndHeight/3, 0, WidthAndHeight/3, WidthAndHeight/3});
                SpriteManager::Load(Prefix + "TOP_RIGHT", FileAddress, {WidthAndHeight/3 * 2, 0, 100/3, 100/3});

                SpriteManager::Load(Prefix + "MID_LEFT", FileAddress, {0, WidthAndHeight/3, WidthAndHeight/3, WidthAndHeight/3});
                SpriteManager::Load(Prefix + "MID_MID", FileAddress, {WidthAndHeight/3, WidthAndHeight/3, WidthAndHeight/3, WidthAndHeight/3});
                SpriteManager::Load(Prefix + "MID_RIGHT", FileAddress, {WidthAndHeight/3 * 2, WidthAndHeight/3, WidthAndHeight/3, WidthAndHeight/3});

                SpriteManager::Load(Prefix + "BTM_LEFT", FileAddress, {0, WidthAndHeight/3 * 2, WidthAndHeight/3, WidthAndHeight/3});
                SpriteManager::Load(Prefix + "BTM_MID", FileAddress, {WidthAndHeight/3, WidthAndHeight/3 * 2, WidthAndHeight/3, WidthAndHeight/3});
                SpriteManager::Load(Prefix + "BTM_RIGHT", FileAddress, {WidthAndHeight/3 * 2, WidthAndHeight/3 * 2, WidthAndHeight/3, WidthAndHeight/3});
        }
        std::vector<Astro::Rect*> CreateWindow(std::string Prefix, SDL_Rect R, int Size) { return {
                        new Astro::Rect({ R.x, R.y, Size, Size }, Prefix + "TOP_LEFT"), 
                        new Astro::Rect({ R.x + Size, R.y, Size * (R.w - 2), Size }, Prefix + "TOP_MID"), 
                        new Astro::Rect({ R.x + Size * (R.w - 1), R.y, Size, Size }, Prefix + "TOP_RIGHT"),

                        new Astro::Rect({ R.x, R.y + Size, Size, Size * (R.h - 2) }, Prefix + "MID_LEFT"), 
                        new Astro::Rect({ R.x + Size, R.y + Size, Size * (R.w - 2), Size * (R.h - 2) }, Prefix + "MID_MID"), 
                        new Astro::Rect({ R.x + Size * (R.w - 1), R.y + Size, Size, Size * (R.h - 2) }, Prefix + "MID_RIGHT"), 

                        new Astro::Rect({ R.x, R.y + Size * (R.h - 1), Size, Size }, Prefix + "BTM_LEFT"), 
                        new Astro::Rect({ R.x + Size, R.y + Size * (R.h - 1), Size * (R.w - 2), Size }, Prefix + "BTM_MID"),
                        new Astro::Rect({ R.x + Size * (R.w - 1), R.y + Size * (R.h - 1), Size, Size }, Prefix + "BTM_RIGHT"),
                }; }
} // namespace UI
#endif

#endif

#undef _ASTRO_LOG
#undef _ASTRO_SHAPE_DECONSTRUCTER