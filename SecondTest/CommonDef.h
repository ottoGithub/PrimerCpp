#ifndef _COMMON_DEF_H_
#define _COMMON_DEF_H_


class Point
{
public:
	Point(int xx, int yy)
	{
		x = xx;
		y = yy;
	}
	int x;
	int y;
};

enum eActorDir
{
	eUp = 0,
	eRight,
	eDwon,
	eLeft,
};


#endif