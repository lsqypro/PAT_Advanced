/* 1096 Consecutive Factors (20分)
 * 1. 单词
 *  Among all the factors of a positive integer N, 在正整数N的所有因子中
 *  there may exist several consecutive numbers 可能存在几个连续的数字
 * 2. 题意理解
 *  求出最长连续因子的个数，并输出最小的连续因子序列
 * 3. 考点
 * 4. 具体思路
 *  1. 连续的因子个数在区间 [1, sqrt(n))
 *  2. 对于相同长度的连续因子，输出最小的连续因子序列，因此从2(1 is NOT included)开始连乘到sqrt(n)，
 *      判断是否能被n整除，迭代过程中记录最大序列长度和连乘的起始数字
 * 5. 注意
 *  1. 对于n为质数,最大连续因子序列长度为1,最小子序除1外为n本身,迭代过程中length不变
 *  2. 直接使用int连乘过程中可能出现浮点错误
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long guard = sqrt(n), length = 0, num = 1, begin = 0;
    for (int i = 2; i <= guard; ++i) {
        num = 1;
        for (int j = i; j <= guard; ++j) {
            num = num * j;
            if (num > n) break;
            else if (n % num != 0) continue;
            if (j-i+1 > length) {
                length = j-i+1;
                begin = i;
            }
        }
    }
    if (length == 0) cout << 1 << endl << n << endl;
    else {
        cout << length << endl;
        for (int i = 0; i < length; ++i) {
            cout << begin++;
            if (i != length-1) cout  << "*";
        }
        cout << endl;
    }
    return 0;
}
