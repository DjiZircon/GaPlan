#include "population.h"
#include "params.h"

extern int best_generation;
extern Chro solution;

Population::Population()
{
	int i;
	generation = 1;
	chromoesomes = new Chro[chro_sum];
	for ( i = 0; i < chro_sum; i++){
		chromoesomes[i].RandomInit();
	}
	sigmaf = 0;
	P = new double[chro_sum];
	for (i = 0; i < chro_sum; i++) {
		sigmaf += chromoesomes[i].fits;
	}
	for (i = 0; i < chro_sum; i++) {
		P[i] = chromoesomes[i].fits / sigmaf;
	}
}
void Population::best_fit(Chro& solution)	// 查找适应度最大的染色体并返回其编号
{
	int best = 0;
	for (int i = 1; i < chro_sum; i++){
		if (chromoesomes[best].fx() < chromoesomes[i].fx()) {
			best = i;
		}
	}
	// 与历史迭代的最优解对比
	if (chromoesomes[best].fx() > solution.fits) {
		solution.copy(chromoesomes[best]);
		best_generation = generation;
	}
	cout << "  The best fit in generation" << generation << " is: " << endl;
	cout << "  chromoesomes" << best + 1 << ": ";
	chromoesomes[best].display();
	cout << endl;
}
void Population::select()	// 种群选择
{
	int i, j;
	double r;
	vector<int> selected(chro_sum); // 用于记录被选中的染色体号
	vector<double> q(chro_sum); // 用于记录积累概率
	vector<Chro> cp(chro_sum); // 存储所有的染色体的备份
	q[0] = P[0];	// 积累概率
	cout << endl;
	cout << "  Accumulation of probabilities" << endl;	// 打印积累概率
	cout << "  q1= " << q[0] << endl;
	// 轮盘赌算法
	for (i = 1; i < chro_sum; i++) {
		q[i] = q[i - 1] + P[i];
		cout << "  q" << i + 1 << "= " << q[i] << endl;
	}
	cout << "\n  Roulette wheel" << endl;// 轮盘赌，产生随机数
	// srand(time(NULL));//设置随机数种子，使每次产生的随机序列不同
	for (int i = 0; i < chro_sum; i++){
		r = rand() % (10000) / (double)(10000);
		cout << "  r" << i + 1 << "= " << r << endl;
		if (r <= q[0]) {
			selected[i] = 0;	// 选中第一个染色体
		}
		for (j = 0; j < chro_sum - 1; j++){
			if (q[j] <= r && r <= q[j + 1]) {
				selected[i] = j + 1;	// 选中第j+1个基因
				break;
			}
		}
		cp[i].copy(chromoesomes[i]);
	}
	for (i = 0; i < chro_sum; i++){
		chromoesomes[i].copy(cp[selected[i]]);
	}
}
void Population::cross()	// 种群交叉
{	
	// 优先将经过选择后排列在前面的优质染色体进行交叉
	for (int i = 0; i < min(chro_sum, static_cast<int>(chro_sum*cross_ratio)); i += 2) {
		chromoesomes[i].exchange(chromoesomes[i + 1]);
	}
}
void Population::variation()	// 种群变异
{
	for(int i=0; i<chro_sum; i++){
		if (rand()%100/100.f < mutation_ratio){
			cout << "  The chromoesome " << i << " is variated!" << endl;
			chromoesomes[i].variation();
		}	
	}
	generation++;	// 至此，种群进化一代
}
void Population::display()// 依次输出每一条染色体（每种方案）
{
	cout << endl;
	int i;
	for (i = 0; i < chro_sum; i++) {	
		cout << "  chromoesomes" << i + 1 << ": ";
		chromoesomes[i].display();
		cout << endl;
	}
	cout << endl;
}