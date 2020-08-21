/* 1092 To Buy or Not to Buy (20分)
 * 1. 单词
 *  which belong 分属
 *  respectively 分别
 *  whole pieces 整个
 *  There must be exactly 1 space between the answer and the number. 答案与数字之间必须恰好有1个空格。
 * 2. 题意理解
 *  1. 给出两个字符串，求串一中是否包含串二的所有字符，若缺少，则输出No,并给出缺少多少个；若足够，则打印多余多少个
 * 3. 考点
 *  字符串，数组
 * 4. 具体思路
 *  1. 先遍历str1,统计每种字符个数到cnt_arr
 *  2. 遍历str2,比较cnt_crr统计缺少或超出个数
 * 5. 注意
 *  1. 对于"Yes",多余的字符是len2-len1
 *  2. 对于"No",缺少的字符是需要而没有的那部分
 */

#include <iostream>

using namespace std;

int cnt_arr[256] = {0};

int main() {
    int less_cnt = 0, ex_cnt = 0;
    string str1, str2;

    getline(cin, str1);
    getline(cin, str2);
    for (int i = 0; i < str1.length(); ++i) cnt_arr[str1[i]]++;
    for (int i = 0; i < str2.length(); ++i) if (cnt_arr[str2[i]]-- <= 0) less_cnt++;

    if (less_cnt) cout << "No " << less_cnt << endl;
    else cout << "Yes " << str1.length()-str2.length() << endl;
    return 0;
}
