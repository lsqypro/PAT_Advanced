/* 1090 Highest Price in Supply Chain (25分)
 * 1. 单词
 *  supply chain 供应链
 *  the percentage rate of price increment 价格增量百分率
 *  involved 参与 v. 涉及；使参与
 *  It is guaranteed that the price will not exceed 10 保证它的价格不超过10
 *  highest 最高的
 *  accurate adj. 精确的
 *  accurate up to 2 decimal places 精确到2位小数
 *  the number of retailers that sell at the highest price 以最高价格销售的零售商的数量
 * 2. 题意理解
 *  1. 经销商或零售商从他们的供应商进价商品后以r%的增量销售给下一级经销商或零售商
 *  2. each number Si is the index of the supplier for the i-th member.
 *      每个数字Si是第i个成员的供应商的编号
 * 3. 考点
 *  树的遍历，求树高
 * 4. 具体思路
 *  1. 使用数组保存树节点，下标为该节点的编号，childs为它的子节点
 *  2. DFS 求树高，以及统计最高树数量
 * 5. 注意
 *  百分率r即百分号%前的数字，使用需要除以100
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
    vector<int> childs;
};
vector<TreeNode> trv;
int root, n, max_level = 0, max_cnt = 0;
double p, r;

void dfs(int r, int level) {
    if (level > max_level) max_level = level, max_cnt = 1;
    else if (level == max_level) max_cnt++;
    for (auto &i : trv[r].childs) dfs(i, level+1);
}

int main() {
    cin >> n >> p >> r;
    trv.resize(n);
    for (int i = 0; i < n; ++i) {
        int index; cin >> index;
        if (index == -1) root = i;
        else trv[index].childs.push_back(i);
    }
    // 统计树高，节点数
    dfs(root, 1);
    printf("%.2f %d\n", p * pow(1+r/100, max_level-1), max_cnt);
    return 0;
}
