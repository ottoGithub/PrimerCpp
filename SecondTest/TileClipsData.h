#ifndef _TILES_CLIPS_DATA_H_
#define _TILES_CLIPS_DATA_H_

// x: 640 32 * 20;
// y: 864 32 * 27
//The different tile 


const int TILE_WIDTH = 32;
const int TILE_HEIGHT = 32;

enum TileType
{
	TILE_Floor0,
	TILE_Floor1,
	TILE_Floor2,
	TILE_Floor3,
	TILE_Floor4,
	TILE_Floor5,
	TILE_Floor6,
	TILE_Floor7,
	TILE_Floor8,
	TILE_Floor9,
	TILE_Floor10,
	TILE_Floor11,

	TILE_SIZE,
};

extern SDL_Rect gTileClips[ TILE_SIZE ];

extern void InitTileClipsData();


#endif
