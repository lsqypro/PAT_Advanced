/* 1094 The Largest Generation (25分)
 * 1. 单词
 *  largest population 人数最多的
 *  pedigree tree 谱系树
 *  presented 表示 提出（present的过去分词）；呈递，提供
 *  hierarchy n. 层级；等级制度
 *  A family hierarchy is usually presented by a pedigree tree where
 *  representing 表示
 *  For the sake of simplicity 为了简单起见
 *  corresponding 相应的
 * 2. 题意理解
 *  1. 根据输入的家谱图（树），计算人数最多的一代
 * 3. 考点
 *  树 层序遍历 广度优先搜索
 * 4. 具体思路
 *  1. 根据输入建立多子节点树，TreeNode数组储存节点，下标为节点编号，TreeNode中的childs存储子节点编号
 *  2. 使用层序遍历（广度优先搜索），遍历计算最大节点层
 * 5. 注意
 *  使用last,tail标记每一层的最后一个编号，当遍历到该编号时层数加一
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    vector<int> childs;
} tree[100];

void level_order_traversal(int root) {
    queue<int> q;
    int max_level = 0, level = 0, last = root, tail, max_cnt = 0, cnt = 0;

    q.push(root);
    while (!q.empty()) {
        root = q.front(); q.pop(); cnt++;
        for (auto &i : tree[root].childs) {
            q.push(i); tail = i;
        }
        if (last == root) {
            level++, last = tail;
            if (max_cnt < cnt) max_cnt = cnt, cnt = 0, max_level = level;
        }
    }
    cout << max_cnt << " " << max_level << endl;
}

int main() {
    int n, m, k, id, child;

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> id >> k;
        for (int j = 0; j < k; ++j) {
            cin >> child;
            tree[id].childs.push_back(child);
        }
    }
    level_order_traversal(1);
    return 0;
}
