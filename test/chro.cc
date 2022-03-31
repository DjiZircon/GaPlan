#include "params.h"
#include "chro.h"
#include "utils.h"

Chro::Chro()
{
	gene = new int[gene_sum];
	fits = 0;
}
void Chro::RandomInit()	// 随机初始化染色体上的基因序列
{
	int i;
	time_t t;
	vector<int> gene_vec(gene_sum);
	for (i = 0; i < gene_sum; i++) {
		gene_vec[i] = i;
	}
	// 随机初始化零件点的序列
	unsigned seed = std::chrono::system_clock::now ().time_since_epoch ().count ();
    std::shuffle (gene_vec.begin (), gene_vec.end (), std::default_random_engine (seed));
	for (i = 0; i < gene_sum; i++) {
		gene[i] = gene_vec[i];
	}
	// 随机初始化吸头的序列
	seed = std::chrono::system_clock::now ().time_since_epoch ().count ();
	std::shuffle (gene_vec.begin (), gene_vec.end (), std::default_random_engine (seed));
	for (i = gene_sum; i < 2*gene_sum; i++) {
		gene[i] = gene_vec[i-gene_sum];
	}
	cout << endl;
	fx();
}
double Chro::fx()	//	适应度函数fx
{
	// 修改为耦合吸头矩阵的向量总距离
	double dis = 0;
	for (int i = 0; i < gene_sum-1; i++){
		// dis += distance(gene[i], gene[(i + 1) % gene_sum]);
		dis += distance(gene[i], gene[i + 1], gene[i+gene_sum], gene[(i+gene_sum)]);
	}
	fits = 1.0 / dis;// 总距离越大，适应度越小
	return fits;
} 
void Chro::display()	// 展示基因序列和该染色体适应度
{
	cout << "    [";
	for (int i = 0; i < gene_sum; i++) {
		cout << " " << gene[i];
	}
	cout << " ],  ";
	if(abs(fits)<1e-5)
		cout << "fits= " << fits <<", distance= "<<1/fx();
	else
		cout << "fits= " << fx()<<", distance= "<<1/fx();
}
void Chro::copy(Chro s)	//复制
{
	for (int i = 0; i < gene_sum; i++){
		gene[i] = s.gene[i];
	}
	fits = fx();	// 重新计算适应度
}
int find(int gene[], int start, int end, int x)// 在gene序列中查找x基因的位置并返回
{
	for (int i = start; i <= end; i++) {
		if (gene[i] == x) {
			return i;
		}
	}
	return ERROR;
}
void Chro::exchange(Chro &s)	//将当前染色体与另一染色体s进行基因片段交换
{
	int i, j = 0, k = 0, repeat;
	int pos = rand() % (gene_sum - 4);	// 随机选择交叉位置（由于要交换3或4个基因，所以交叉位置只能在[1，n-4]内）
	int num = 3 + rand() % 2;	// 随机选择交叉的基因数，最小为3，最大为4
	/*
	cout << endl; 查看发生交换的位置和位数
	cout << "pos: " << pos << ", num: " << num << endl;*/

	int *segment1 = new int[gene_sum];	// 用于记录交换后当前染色体上的基因
	int *segment2 = new int[gene_sum];	// 用于记录交换后另一染色体上的基因
	for (i = 0; i < gene_sum; i++) {
		if (i >= pos && i < pos + num) {
			segment1[i] = s.gene[i];
			segment2[i] = gene[i];
		}
		else {
			segment1[i] = gene[i];
			segment2[i] = s.gene[i];
		}
	}

	int *mapping1 = new int[4];	// 当前染色体中间段的映射
	int *mapping2 = new int[4];	// 另一染色体中间段的映射
	for (i = 0; i < 4; i++) {
		mapping1[i] = ERROR;	// 初值全部为-1
		mapping2[i] = ERROR;
	}
	for (i = pos; i < pos + num; i++) {
		repeat = find(segment1, pos, pos + num - 1, gene[i]);
		if (repeat == ERROR) {
			mapping1[j++] = gene[i];	
		}
		repeat = find(segment2, pos, pos + num - 1, s.gene[i]);
		if (repeat == ERROR) {
			mapping2[k++] = s.gene[i];
		}
	}
	/* 查看映射
	cout << "map1   " << "map2" << endl;
	for (k = 0; k < 4; k++) {
		cout << mapping1[k] << "     " << mapping2[k] << endl;
	}*/

	j = k = 0;
	for (i = pos; i < pos + num; i++) {// 将重复的基因替换为映射中的基因
		repeat = find(gene, 0, pos - 1, segment1[i]);
		if (repeat != ERROR) {
			segment1[repeat] = mapping1[j++];
		}
		repeat = find(gene, pos + num, gene_sum - 1, segment1[i]);
		if (repeat != ERROR) {
			segment1[repeat] = mapping1[j++];
		}
		repeat = find(s.gene, 0, pos - 1, segment2[i]);
		if (repeat != ERROR) {
			segment2[repeat] = mapping2[k++];
		}
		repeat = find(s.gene, pos + num, gene_sum - 1, segment2[i]);
		if (repeat != ERROR) {
			segment2[repeat] = mapping2[k++];
		}
	}
	for (i = 0; i < gene_sum; i++) {
		gene[i] = segment1[i];	// 交叉后的该染色体
		s.gene[i] = segment2[i];// 交叉后的另一染色体
	}
	delete segment1;
	delete segment2;
	delete mapping1;
	delete mapping2;
}
void Chro::variation()
{
	int pos1 = rand() % gene_sum;	// 随机选择变异位置
	int pos2 = rand() % gene_sum;	// 随机选择变异位置
	int temp = gene[pos1];	// 将被选中的基因和后面一位基因交换
	gene[pos1] = gene[pos2];
	gene[pos2] = temp;
}