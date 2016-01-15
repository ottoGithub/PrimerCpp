#include "StdAfx.h"
#include <stdio.h>
#include "LTexture.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

void renderMap();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Scene sprites
SDL_Rect gSpriteClips[ 4 ];
LTexture gSpriteSheetTexture;
LTexture gCharacterTexture;


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load Foo' texture
	if( !gCharacterTexture.loadFromFile( "c00.png" ) )
	{
		printf( "Failed to load Foo' texture image!\n" );
		success = false;
	}

	//Load sprite sheet texture
	if( !gSpriteSheetTexture.loadFromFile( "ytty.png" ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	else
	{
		//Set top left sprite
		gSpriteClips[ 0 ].x =   0;
		gSpriteClips[ 0 ].y =   0;
		gSpriteClips[ 0 ].w = 32;
		gSpriteClips[ 0 ].h = 32;

		//Set top right sprite
		gSpriteClips[ 1 ].x = 32;
		gSpriteClips[ 1 ].y =   0;
		gSpriteClips[ 1 ].w = 32;
		gSpriteClips[ 1 ].h = 32;

		//Set bottom left sprite
		gSpriteClips[ 2 ].x =   32 * 11;
		gSpriteClips[ 2 ].y = 0;
		gSpriteClips[ 2 ].w = 32;
		gSpriteClips[ 2 ].h = 32;

		//Set bottom right sprite
		gSpriteClips[ 3 ].x = 32 * 17;
		gSpriteClips[ 3 ].y = 0;
		gSpriteClips[ 3 ].w = 32;
		gSpriteClips[ 3 ].h = 32;
	}

	return success;
}

void renderMap()
{
	for(int x = 0; x < SCREEN_WIDTH; x+=32)
		for(int y = 0; y < SCREEN_HEIGHT; y+=32)
		{
			gSpriteSheetTexture.render( x, y, &gSpriteClips[ 2 ] );
		}
}
void close()
{
	//Free loaded images
	gSpriteSheetTexture.free();
	gCharacterTexture.free();
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				renderMap();
				gCharacterTexture.render(SCREEN_WIDTH/2 - 32,SCREEN_HEIGHT/2 - 32);
				////Render top left sprite
				//gSpriteSheetTexture.render( 0, 0, &gSpriteClips[ 0 ] );

				////Render top right sprite
				//gSpriteSheetTexture.render( SCREEN_WIDTH - gSpriteClips[ 1 ].w, 0, &gSpriteClips[ 1 ] );

				////Render bottom left sprite
				//gSpriteSheetTexture.render( 0, SCREEN_HEIGHT - gSpriteClips[ 2 ].h, &gSpriteClips[ 2 ] );

				////Render bottom right sprite
				//gSpriteSheetTexture.render( SCREEN_WIDTH - gSpriteClips[ 3 ].w, SCREEN_HEIGHT - gSpriteClips[ 3 ].h, &gSpriteClips[ 3 ] );

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}