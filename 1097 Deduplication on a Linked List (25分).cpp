/* 1097 Deduplication on a Linked List (25分)
 * 1. 单词
 *  Deduplication 去重
 *  singly linked list 单链表
 *  absolute values 绝对值
 *  nonnegative integer 非负整数
 *  represented 表示
 *  describes 描述
 *  At the mean time 同时
 *  occupies 占用
 *  a separate list 一个单独的（另外的，不同的）链表
 * 2. 题意理解
 *  1. 去除链表中绝对值重复的节点
 *  2. 先后分别输出去重后的链表，被去除的部分组成的链表
 * 3. 考点
 *  链表遍历
 * 4. 具体思路
 *  1. 遍历链表，将没出现过的值打印，出现过的节点push到vector容器中
 *  2. 输出vector容器中的节点即可
 * 5. 注意
 *  1. 遍历链表应使用while (p != -1) p = list[p].next;
 *  2. 测试点1：链表中实际节点数小于n,用for (i to n) p = list[p].next; 会出错
 *  3. 测试点2：不存在被删除的节点，故应注意最后的"-1"输出格式
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int data, next, addr;
};
int n, root;
ListNode list[100000];
int cnt[10001] = {0};
vector<ListNode> rm;

int main() {
    cin >> root >> n;
    for (int i = 0; i < n; ++i) {
        int addr; cin >> addr; list[addr].addr = addr;
        cin >> list[addr].data >> list[addr].next;
    }
    // 输出删除后的剩余链表
    int p = root;
    while (p != -1) {
        if (cnt[abs(list[p].data)]++ == 0) {
            if (p != root) printf(" %05d\n", p);
            printf("%05d %d", p, list[p].data);
        }
        else rm.push_back(list[p]);

        p = list[p].next;
    }
    cout << " -1" << endl;
    // 被删除的链表
    for (int i = 0; i < rm.size(); ++i) {
        if (i != 0) printf(" %05d\n", rm[i].addr);
        printf("%05d %d", rm[i].addr, rm[i].data);
    }
    if (!rm.empty())
        cout << " -1" << endl;
    return 0;
}
