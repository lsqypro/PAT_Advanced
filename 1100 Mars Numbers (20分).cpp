//
// Created by lsqy on 2020/8/18.
//

/* 1100 Mars Numbers (20分)
 * 1. 单词
 *  1100 Mars Numbers (20分) 火星数字
 *  respectively 分别地；各自地，独自地
 *  For the next higher digit 对于下一个高位数字
 *  corresponds 符合，一致；相应；通信
 *  you are supposed to write a program 你需要写一个程序
 *  mutual translation 相互转换
 *  a positive integer N 正整数N
 *  corresponding number 相应的数量
 * 2. 题意理解
 *  火星计数按照13进制
 *  个位："jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec"
 *  十位："tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou"
 * 3. 考点
 *  进制转换
 * 4. 具体思路
 *  1. 输入N，循环N次读入一行字符串，字符串转换后输出
 *  2. 火星数字与地球数字判断第一个字符是否为数字
 * 5. 注意
 *  1. 只有两位，即数字范围 0-12*13+12 [0,168]
 *  2. 高位存在且低位为0时，只写高位 （如13对应tam 而不是tam tret）
 *
 */

#include <iostream>

using namespace std;

string num_map_1[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string num_map_2[] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

string transform(int num) {
    string ans;
    ans = num_map_2[num/13];
    if (ans.empty()) ans += num_map_1[num%13];
    else if (num%13) ans += " " + num_map_1[num%13];
    return ans;
}

string transform(string num) {
    int i = 0;
    for (; i < 169 && num != transform(i); ++i) {}
    return to_string(i);
}

int main() {
    int n;
    string str;

    cin >> n; getchar();
    for (int i = 0; i < n; ++i) {
        getline(cin, str);
        if ( isdigit(str[0]) ) cout << transform(stoi(str)) << endl;
        else cout << transform(str) << endl;
    }

    return 0;
}
