#include "StdAfx.h"
#include "TileClipsData.h"


SDL_Rect gTileClips[ TILE_SIZE ];

void InitTileClipsData()
{
	gTileClips[ TILE_Floor0 ].x = 0;
	gTileClips[ TILE_Floor0 ].y = 0;
	gTileClips[ TILE_Floor0 ].w = TILE_WIDTH;
	gTileClips[ TILE_Floor0 ].h = TILE_HEIGHT;


	gTileClips[ TILE_Floor1 ].x = 32 * 1;
	gTileClips[ TILE_Floor1 ].y = 0;
	gTileClips[ TILE_Floor1 ].w = TILE_WIDTH;
	gTileClips[ TILE_Floor1 ].h = TILE_HEIGHT;


	gTileClips[ TILE_Floor2 ].x = 32 * 2;
	gTileClips[ TILE_Floor2 ].y = 0;
	gTileClips[ TILE_Floor2 ].w = TILE_WIDTH;
	gTileClips[ TILE_Floor2 ].h = TILE_HEIGHT;


	gTileClips[ TILE_Floor3 ].x = 32 * 3;
	gTileClips[ TILE_Floor3 ].y = 0;
	gTileClips[ TILE_Floor3 ].w = TILE_WIDTH;
	gTileClips[ TILE_Floor3 ].h = TILE_HEIGHT;

	gTileClips[ TILE_Floor4 ].x = 32 * 4;
	gTileClips[ TILE_Floor4 ].y = 0;
	gTileClips[ TILE_Floor4 ].w = TILE_WIDTH;
	gTileClips[ TILE_Floor4 ].h = TILE_HEIGHT;


	gTileClips[ TILE_Floor5 ].x = 32 * 5;
	gTileClips[ TILE_Floor5 ].y = 0;
	gTileClips[ TILE_Floor5 ].w = TILE_WIDTH;
	gTileClips[ TILE_Floor5 ].h = TILE_HEIGHT;


	gTileClips[ TILE_Floor6 ].x = 32 * 6;
	gTileClips[ TILE_Floor6 ].y = 0;
	gTileClips[ TILE_Floor6 ].w = TILE_WIDTH;
	gTileClips[ TILE_Floor6 ].h = TILE_HEIGHT;


	gTileClips[ TILE_Floor7 ].x = 32 * 7;
	gTileClips[ TILE_Floor7 ].y = 0;
	gTileClips[ TILE_Floor7 ].w = TILE_WIDTH;
	gTileClips[ TILE_Floor7 ].h = TILE_HEIGHT;


	gTileClips[ TILE_Floor8 ].x = 32 * 8;
	gTileClips[ TILE_Floor8 ].y = 0;
	gTileClips[ TILE_Floor8 ].w = TILE_WIDTH;
	gTileClips[ TILE_Floor8 ].h = TILE_HEIGHT;


	gTileClips[ TILE_Floor9 ].x = 32 * 9;
	gTileClips[ TILE_Floor9 ].y = 0;
	gTileClips[ TILE_Floor9 ].w = TILE_WIDTH;
	gTileClips[ TILE_Floor9 ].h = TILE_HEIGHT;


	gTileClips[ TILE_Floor10 ].x = 32 * 10;
	gTileClips[ TILE_Floor10 ].y = 0;
	gTileClips[ TILE_Floor10 ].w = TILE_WIDTH;
	gTileClips[ TILE_Floor10 ].h = TILE_HEIGHT;


	gTileClips[ TILE_Floor11 ].x = 32 * 11;
	gTileClips[ TILE_Floor11 ].y = 0;
	gTileClips[ TILE_Floor11 ].w = TILE_WIDTH;
	gTileClips[ TILE_Floor11 ].h = TILE_HEIGHT;
}