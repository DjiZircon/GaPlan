#ifndef GAPLAN_TEST_DATATYPE_H
#define GAPLAN_TEST_DATATYPE_H

typedef struct Pt{
	Pt() = default;
	Pt(int x_, int y_):x(x_), y(y_){}
	int x,y;	// 城市坐标
}Pt;

typedef struct Tip{
public:
	Tip() = default;
	Tip(int x_, int y_):x(x_), y(y_){}
	int x;
	int y;	// 吸头坐标
}Tip;

typedef struct Plate{
	int x;
	int y;
	int w;
	int h;
} Plate;

#endif