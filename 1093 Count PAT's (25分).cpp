/* 1093 Count PAT's (25分)
 * 1. 单词
 *  Since the result may be a huge number 因为结果可能是一个巨大的数字
 *  you only have to output the result moded by 1000000007 你只需要输出被1000000007取余后的余数
 * 2. 题意理解
 *  1. 输出一行字符串，找出字符串中"PAT"子串个数
 * 3. 考点
 *  字符串，数组
 * 4. 具体思路
 *  1. 输入字符串，统计所有的"T"字符数
 *  2. 遍历字符串，当遍历到"A"字符时，该字符前的"P"个数乘以该字符后的"T"个数，即为当前字符能组成的最多"PAT"数
 * 5. 注意
 *  1. cnt % 1000000007
 *  2. 暴力破解可能超时
 */

#include <iostream>

using namespace std;

int main() {
    string str;
    int t_cnt = 0, p_cnt = 0, cnt = 0, len;

    getline(cin, str);
    len = str.length();
    for (int i = 0; i < len; ++i) {
        if (str[i] == 'T') t_cnt++;
    }
    for (int i = 0; i < len; ++i) {
        if (str[i] == 'P') p_cnt++;
        else if (str[i] == 'T') t_cnt--;
        else if (str[i] == 'A') cnt += p_cnt * t_cnt;
        if (cnt > 1000000007) cnt %= 1000000007;
    }
    cout << cnt << endl;
    return 0;
}
