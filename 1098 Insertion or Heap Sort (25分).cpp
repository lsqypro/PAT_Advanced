/* 1098 Insertion or Heap Sort (25分)
 * 1. 单词
 *  initial sequence of integers 初始整数序列
 *  several iterations 几次迭代
 *  ascending 升序
 *  assumed 假设
 *  iteration 迭代
 *  It is guaranteed that the answer is unique for each test case. 保证每个测试案例有唯一的答案
 *  guaranteed 保证
 * 2. 题意理解
 *  1. 给出连个整数序列，求第二个序列是第一个序列通过哪种排序方法得到的
 *  2. 输出使用的排序方法，并给出再迭代一次改方法的结果
 * 3. 考点
 *  插入排序，堆排序
 * 4. 具体思路
 *  1. 根据输入序列进行插入排序，并判断中间结果，若判断成功，则再迭代一次输出结果
 *  2. 若非插入排序，则进行堆排序，同第一步
 * 5. 注意
 *  1. 一次插入排序：前有序段+1
 *  2. 一次堆排序：后有序段+1
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr1, arr2, arr3;

bool insert_sort() {
    arr3 = arr1;
    bool ans = false;
    for (int i = 1; i < arr3.size(); ++i) {
        int tmp = arr3[i], j = i;
        while (j-1 >= 0 && tmp < arr3[j-1])
            arr3[j] = arr3[j-1], j--;
        arr3[j] = tmp;
        if (ans) return true;
        if (arr2 == arr3) ans = true;
    }
    return false;
}

void down_pass(int parent, int n) {
    int tmp = arr3[parent], child;

    while (parent*2 < n) {
        child = parent * 2;
        if (child+1 < n && arr3[child+1] > arr3[child])
            child++;
        if (tmp >= arr3[child]) break;
        arr3[parent] = arr3[child];
        parent = child;
    }
    arr3[parent] = tmp;
}

void heap_sort() {
    arr3 = arr1;
    arr3.insert(arr3.begin(), INT32_MAX);
    arr2.insert(arr2.begin(), INT32_MAX);
    // create max heap
    for (int i = (arr3.size()-1)/2; i > 0; --i)
        down_pass(i, arr3.size());

    bool ans = false;
    for (int i = arr3.size()-1; i > 0; --i) {
        swap(arr3[1], arr3[i]);
        down_pass(1, i);
        if (ans) break;
        if (arr2 == arr3) ans = true;
    }
    arr3.erase(arr3.begin());
}

int main() {
    int n;
    cin >> n;
    arr1.resize(n); arr2.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr2[i];
    }
    if (insert_sort()) cout << "Insertion Sort" << endl;
    else heap_sort(), cout << "Heap Sort" << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr3[i];
        if (i == n-1) cout << endl;
        else cout << " ";
    }

    return 0;
}
