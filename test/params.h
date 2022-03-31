#ifndef GAPLAN_TEST_PARAMS_H
#define GAPLAN_TEST_PARAMS_H

#include "data_type.h"
#include "tips.h"

// 设置振动盘的x y w h
const Plate plate = {0, 0, 600, 300};
const int tip_rows = 30;
const int tip_cols = 40;
const int tip_gap_x = 30;
const int tip_gap_y = 30;

// GA参数
const int gene_sum = tip_rows*tip_cols;	// 染色体上的基因数
const int chro_sum = 20;	// 种群中染色体数
const float cross_ratio = 0.8; // 交叉率
const float mutation_ratio = 0.05; // 变异率


#endif