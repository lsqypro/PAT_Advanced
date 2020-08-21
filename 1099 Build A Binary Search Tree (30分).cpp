//
// Created by lsqy on 2020/8/18.
//

/* 1099 Build A Binary Search Tree (30分)
 * 1. 单词
 *  recursively 递归地；递回地
 *  properties  性能；道具，内容（property的复数形式）
 *  must also be 还必须
 *  distinct integer keys 不同的整数键
 *  so that 以便；所以
 *  satisfies v. 满足（satisfy的第三人称单数）
 *  provided that the nodes are numbered from 0 to N−1, 假设节点编号从0到N−1
 * 2. 题意理解
 *  1. 根据输入的二叉搜索树结构建立二叉搜索树
 *  2. 层序遍历输出
 * 3. 考点
 *  二叉搜索树，二叉搜索树的中序遍历，完全二叉树
 * 4. 具体思路
 *  1. 将输入的结构按顺序保存到数组中 left, right, data分别保存左右子节点的需要，键值
 *  2. 最后一行输入的不同节点值顺序是混乱的，但考虑二叉搜索树的中序遍历是键值升序的，
 *      所以先将输入节点值升序排序，再中序遍历顺序給二叉树給节点赋值
 *  3. 最后层序遍历输出即可
 * 5. 注意
 *  对于测试点1,2，使用index排序需要标记level
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int left, right, data, index, level;
    TreeNode() {
        left = right = data = index = level = -1;
    }
};
vector<TreeNode> tree;
int n, cnt = 0, data[100];

void in_order_traversal(int index) {
    if (index == -1) return;
    in_order_traversal(tree[index].left);
    tree[index].data = data[cnt++];
    in_order_traversal(tree[index].right);
}

void level_order_traversal() {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int i = q.front(); q.pop();
        cout << tree[i].data;
        if (tree[i].left != -1) q.push(tree[i].left);
        if (tree[i].right != -1) q.push(tree[i].right);
        if (q.empty()) cout << endl;
        else cout << " ";
    }
}

int main() {
    cin >> n;
    tree.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> tree[i].left >> tree[i].right;
    }
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    sort(data, data+n);
    in_order_traversal(0);
    level_order_traversal();

    return 0;
}
