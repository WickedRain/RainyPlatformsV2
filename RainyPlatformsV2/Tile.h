#pragma once
#include "Define.h"

//This is used in the file handling to see what type of block goes where
enum {
	TILE_TYPE_NONE = 0,
	TILE_TYPE_NORMAL,
	TILE_TYPE_BLOCK
};

class Tile
{
public:
	int TileID;
	int TypeID;

	Tile();

	
};