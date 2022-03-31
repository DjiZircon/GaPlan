#ifndef GAPLAN_TEST_UTILS_H
#define GAPLAN_TEST_UTILS_H

#include "public.h"
#include "pts.h"
#include "data_type.h"
#include "params.h"

extern Pts pts;
extern Tips tips;

double distance(int pt1, int pt2, int tip1, int tip2)	// 计算两城市间距离
{
	int pt_diff_x = pts.getByIdx(pt2).x - pts.getByIdx(pt1).x;
	int pt_diff_y = pts.getByIdx(pt2).y - pts.getByIdx(pt1).y;
	int tip_diff_x = tips.getByIdx(tip2).x - tips.getByIdx(tip1).x;
	int tip_diff_y = tips.getByIdx(tip2).y - tips.getByIdx(tip1).y;
	int vec_diff_x = pt_diff_x - tip_diff_x;
	int vec_diff_y = pt_diff_y - tip_diff_y;
	return abs(sqrt(vec_diff_x^2 +  vec_diff_y^2));
	// return abs((pts.getByIdx(a).x - pts.getByIdx(b).x) ^ 2 + (pts.getByIdx(a).y - pts.getByIdx(b).y) ^ 2);
}

#endif