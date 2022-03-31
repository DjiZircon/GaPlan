// 参考链接: https://blog.csdn.net/LeopoldZhang2000/article/details/104339931

#include <public.h>
#include "chro.h"
#include "pts.h"
#include "population.h"
#include "data_type.h"
#include "params.h"

#define ERROR -1

Chro solution;	// 用于记录有史以来最好的染色体
int best_generation = 0;	// 用于记录最好的染色体所在的代数
Pts pts(gene_sum);
Tips tips(tip_rows, tip_cols, tip_gap_x, tip_gap_y);

int main()
{
	Population P0;
	cout << "\n  Generation=" << P0.generation << endl;
	P0.display();
	P0.best_fit(solution);
	int T;	// 进化的代数
	cout << "  Input the Iteration:  ";
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout << endl << "  After select: ";	// 选择
		P0.select();
		P0.display();
		cout << endl << "  After cross: ";	// 交叉
		P0.cross();
		P0.display();
		cout << endl << "  After variation: ";// 变异
		P0.variation();
		cout << "  Generation=" << P0.generation << endl;
		P0.display();
		P0.best_fit(solution); // 挑选并打印本轮迭代最优解
	}
	cout << "  The best solution in history is:" << endl;	// 打印进化过程中最好的染色体，即解决方案
	cout << "  in generation" << best_generation;	
	solution.display();
	cout << endl;
	return 0;
}

