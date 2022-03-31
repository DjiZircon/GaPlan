#ifndef GAPLAN_TEST_CHRO_H
#define GAPLAN_TEST_CHRO_H

#include "public.h"

class Chro	// Chromoesome染色体
{
public:
	Chro();	// 构造函数，将适应度初始化为0
	void RandomInit();	// 随机初始化
	double fx();		// 适应度函数
	void display();		// 展示基因序列
	void copy(Chro s);	// 复制
	void exchange(Chro &s);// 互换
	void variation();	// 变异
	friend int find(int gene[], int start, int end, int x);	// 寻找基因x在染色体上的位置
	friend class Population;
private:
	int *gene; // 未析构掉
	double fits = 0;	// 适应度
	const float q_const = 10000; // 作为distance和fit转换的常量
};

#endif