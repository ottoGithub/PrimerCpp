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
	TILE_Floor12,
	TILE_Floor13,
	TILE_Floor14,
	TILE_Floor15,
	TILE_Floor16,
	TILE_Floor17,
	TILE_Floor18,
	TILE_Floor19,

	TILE_Tree0,
	TILE_Tree1,
	TILE_Tree2,
	TILE_Tree3,
	TILE_Tree4,
	TILE_Tree5,
	TILE_Tree6,
	TILE_Tree7,
	TILE_Tree8,
	TILE_Tree9,
	TILE_Tree10,
	TILE_Tree11,

	TILE_Straw0,
	TILE_Straw1,
	TILE_Straw2,
	TILE_Straw3,
	TILE_Straw4,
	TILE_Straw5,
	TILE_Straw6,
	TILE_Straw7,
	TILE_Straw8,
	TILE_Straw9,
	TILE_Straw10,
	TILE_Straw11,
	TILE_Straw12,
	TILE_Straw13,
	TILE_Straw14,
	TILE_Straw15,

	TILE_Room0,
	TILE_Room1,
	TILE_Room2,
	TILE_Room3,
	TILE_Room4,
	TILE_Room5,
	TILE_Room6,
	TILE_Room7,
	TILE_Room8,
	TILE_Room9,
	TILE_Room10,

	TILE_Solid00,
	TILE_Solid01,
	TILE_Solid02,
	TILE_Solid03,
	TILE_Solid04,
	TILE_Solid05,
	TILE_Solid06,
	TILE_Solid07,
	TILE_Solid08,
	TILE_Solid09,
	TILE_Solid0A,
	TILE_Solid0B,
	TILE_Solid0C,
	TILE_Solid0D,
	TILE_Solid0E,
	TILE_Solid0F,
	TILE_Solid0G,
	TILE_Solid0H,
	TILE_Solid0I,
	TILE_Solid0J,

	TILE_Solid10,
	TILE_Solid11,
	TILE_Solid12,
	TILE_Solid13,
	TILE_Solid14,
	TILE_Solid15,
	TILE_Solid16,
	TILE_Solid17,
	TILE_Solid18,
	TILE_Solid19,
	TILE_Solid1A,
	TILE_Solid1B,
	TILE_Solid1C,
	TILE_Solid1D,
	TILE_Solid1E,
	TILE_Solid1F,
	TILE_Solid1G,
	TILE_Solid1H,
	TILE_Solid1I,
	TILE_Solid1J,

	TILE_Solid20,
	TILE_Solid21,
	TILE_Solid22,
	TILE_Solid23,
	TILE_Solid24,
	TILE_Solid25,
	TILE_Solid26,
	TILE_Solid27,
	TILE_Solid28,
	TILE_Solid29,
	TILE_Solid2A,
	TILE_Solid2B,
	TILE_Solid2C,
	TILE_Solid2D,
	TILE_Solid2E,
	TILE_Solid2F,
	TILE_Solid2G,
	TILE_Solid2H,
	TILE_Solid2I,
	TILE_Solid2J,

	TILE_Solid30,
	TILE_Solid31,
	TILE_Solid32,
	TILE_Solid33,
	TILE_Solid34,
	TILE_Solid35,
	TILE_Solid36,
	TILE_Solid37,
	TILE_Solid38,
	TILE_Solid39,
	TILE_Solid3A,
	TILE_Solid3B,
	TILE_Solid3C,
	TILE_Solid3D,
	TILE_Solid3E,
	TILE_Solid3F,
	TILE_Solid3G,
	TILE_Solid3H,
	TILE_Solid3I,
	TILE_Solid3J,

	TILE_Solid40,
	TILE_Solid41,
	TILE_Solid42,
	TILE_Solid43,
	TILE_Solid44,
	TILE_Solid45,
	TILE_Solid46,
	TILE_Solid47,
	TILE_Solid48,
	TILE_Solid49,
	TILE_Solid4A,
	TILE_Solid4B,
	TILE_Solid4C,
	TILE_Solid4D,
	TILE_Solid4E,
	TILE_Solid4F,
	TILE_Solid4G,
	TILE_Solid4H,
	TILE_Solid4I,
	TILE_Solid4J,

	TILE_Solid50,
	TILE_Solid51,
	TILE_Solid52,
	TILE_Solid53,
	TILE_Solid54,
	TILE_Solid55,
	TILE_Solid56,
	TILE_Solid57,
	TILE_Solid58,
	TILE_Solid59,
	TILE_Solid5A,
	TILE_Solid5B,
	TILE_Solid5C,
	TILE_Solid5D,
	TILE_Solid5E,
	TILE_Solid5F,
	TILE_Solid5G,
	TILE_Solid5H,
	TILE_Solid5I,
	TILE_Solid5J,

	TILE_Solid60,
	TILE_Solid61,
	TILE_Solid62,
	TILE_Solid63,
	TILE_Solid64,
	TILE_Solid65,
	TILE_Solid66,
	TILE_Solid67,
	TILE_Solid68,
	TILE_Solid69,
	TILE_Solid6A,
	TILE_Solid6B,
	TILE_Solid6C,
	TILE_Solid6D,
	TILE_Solid6E,
	TILE_Solid6F,
	TILE_Solid6G,
	TILE_Solid6H,
	TILE_Solid6I,
	TILE_Solid6J,

	TILE_Solid70,
	TILE_Solid71,
	TILE_Solid72,
	TILE_Solid73,
	TILE_Solid74,
	TILE_Solid75,
	TILE_Solid76,
	TILE_Solid77,
	TILE_Solid78,
	TILE_Solid79,
	TILE_Solid7A,
	TILE_Solid7B,
	TILE_Solid7C,
	TILE_Solid7D,
	TILE_Solid7E,
	TILE_Solid7F,
	TILE_Solid7G,
	TILE_Solid7H,
	TILE_Solid7I,
	TILE_Solid7J,

	TILE_SIZE,
};
struct TileInfo
{
	TileInfo()
	{
		nColliderType = 0;
//��ײ����
	}
	int nColliderType;
	SDL_Rect gTileRect;
};
extern TileInfo gTileData[TILE_SIZE];

extern void InitTileClipsData();


#endif
