#ifndef GAPLAN_TEST_POPULATION_H
#define GAPLAN_TEST_POPULATION_H

#include "public.h"
#include "chro.h"

class Population
{
public:
	Population();	// 构造函数
	void best_fit(Chro& solution);// 查找适应度最高的染色体
	void select();	// 选择
	void cross();	// 交叉
	void variation();// 种群变异
	void display();	// 显示种群内染色体
	int generation; // 种群代数
private:
	Chro *chromoesomes;	// 染色体
	double sigmaf;	// 种群适应度之和
	double *P;	// 选择概率
};

#endif