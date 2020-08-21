/* 1091 Acute Stroke (30分)
 * 1. 单词
 *  total volume of the stroke core stroke core的总容积
 *  obtain 获得
 * 2. 题意理解
 *  1. 给出一个三维像素矩阵，求每个像素值为1的相连区域大小（上下左右前后像素为相连区域）
 *  2. 统计相连区域大于一定阈值的T的所有区域总大小
 * 3. 考点
 *  广度优先搜索，深度优先搜索
 * 4. 具体思路
 *  1. 读入三维像素素组，对每个像素点广度优先搜索，累加大于t的区域体积
 * 5. 注意
 *  1. queue<PixPosition> que; 构造队列的开销可能导致超时，因此在之前判断BFS条件
 *  2. 使用DFS递归层次太多可能导致内存超限而参数段错误（测试点4,5）
 */

#include <iostream>
#include <queue>

using namespace std;

int m, n, l, t;
struct PixPosition {
    int x, y, z, pix, visit;
    static bool judge(int dx, int dy, int dz) {
        return dx >= 0 && dx < m && dy >= 0 && dy < n && dz >= 0 && dz < l;
    }
};
PixPosition matrix[1300][130][70];
int dir[6][3] = {{0, 0, -1}, {0, 0, 1}, {-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}};  // 上 下 左 右 前 后

int bfs(int x, int y, int z) {
    if (!(PixPosition::judge(x, y, z) && matrix[x][y][z].visit != 1 && matrix[x][y][z].pix == 1))
        return 0;
    int cnt = 0;
    queue<PixPosition> que;
    que.push(matrix[x][y][z]), matrix[x][y][z].visit = 1, cnt++;
    while (!que.empty()) {
        PixPosition p = que.front(); que.pop();
        for (int i = 0; i < 6; ++i) {
            x = p.x + dir[i][0]; y = p.y + dir[i][1]; z = p.z + dir[i][2];
            if (PixPosition::judge(x, y, z) && matrix[x][y][z].visit != 1 && matrix[x][y][z].pix == 1)
                que.push(matrix[x][y][z]), matrix[x][y][z].visit = 1, cnt++;
        }
    }
    return cnt >= t ? cnt : 0;
}

int main(void) {
    int volume = 0;
    cin >> m >> n >> l >> t;

    for (int i = 0; i < l; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < n; ++k)
                cin >> matrix[j][k][i].pix, matrix[j][k][i].x = j, matrix[j][k][i].y = k, matrix[j][k][i].z = i;
    for (int i = 0; i < l; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < n; ++k)
                volume += bfs(j, k, i);

    cout << volume << endl;
    return 0;
}