/* 1095 Cars on Campus (30分)
 * 1. 单词
 *  capital letters 大写字母
 *  alphabetical order 字母序
 *  plate numbers 车牌号
 *  If such a car is not unique 假如这样的车不唯一
 *  longest time period 最长时间
 *  the corresponding time length 响应的时间长度
 *  within a single day 一天之内
 *  least one car 至少有一辆车
 * 2. 题意理解
 *  1. 首先输入车牌号，进出时间，进出状态，然后根据后输入的时间点判断该时间点校园内车辆的数量
 *  2. 将每辆车的每条记录按时间升序，in与下一个时间的out配对，不成对的in,out记录将被忽略（多条in记录只记录最后一条，多条out记录只记录第一条）
 *  3. 停车时间为多次停车时间总和，根据停车时间为主序降序，车牌为次序升序排序，输出停车时间最长的几个车牌
 * 3. 考点
 *  排序，散列存储
 * 4. 具体思路
 *  1. 读入每条记录，根据记录的车牌号和记录时间排序，筛选出成对的有效记录
 *  2. 筛选出成对的记录,标记flag为true, 忽略不成对的记录,并累加停车时间（s为单位）
 *  3. 再次对每条记录以记录时间排序，统计每条记录时间点校园内车数
 *  4. 对于任意时间点校园车辆数，遍历cnt_v容器得到
 *  5. 停车最长时间：unordered_map导入到vector后排序，输出最大者
 * 5. 注意
 *  1. Each in record is paired with the chronologically next record for the same car provided it is an out record.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Record {
    string id, status;
    int time;
    bool flag;
    static int input_time() {
        int hh, mm, ss;
        scanf(" %d:%d:%d", &hh, &mm, &ss);
        return hh*3600 + mm*60 + ss;
    }
    static string get_time_str(int time) {
        int hh = time/3600, mm = time%3600/60, ss = time%3600%60;
        char buf[10]; sprintf(buf, "%02d:%02d:%02d", hh, mm, ss);
        return buf;
    }
};

int main(void) {
    int n, k;

    cin >> n >> k;
    // 输入记录
    vector<Record> rv(n);
    for (int i = 0; i < n; ++i) {
        cin >> rv[i].id; rv[i].time = Record::input_time(); cin >> rv[i].status;
    }
    // 筛选成对有效记录
    sort(rv.begin(), rv.end(), [](Record &r1, Record &r2){
        if (r1.id != r2.id) return r1.id < r2.id;
        return r1.time < r2.time;
    });
    unordered_map<string, int> tmap;
    for (int i = 0; i < rv.size(); ++i) {
        for (int j = i+1; j < rv.size(); ++j) {
            if (rv[i].id != rv[j].id) break;
            if (rv[i].status == "in" && rv[j].status == "out") {
                rv[i].flag = rv[j].flag = true;
                tmap[rv[i].id] += rv[j].time - rv[i].time;
            }
            i = j;
        }
    }
    // 计算每个时间点车辆数
    vector<pair<int, int>> cntv;
    sort(rv.begin(), rv.end(), [](Record &r1, Record &r2){
        return r1.time < r2.time;
    });
    int pre = -1;
    for (auto &i : rv) {
        if (i.flag) {
            int cnt = 0; if (pre != -1) cnt = cntv[pre].second;
            if (i.status == "in") cnt++;
            else cnt--;
            cntv.push_back(make_pair(i.time, cnt)); pre++;
        }
    }
    // 输入时间点
    int index = 0;
    for (int i = 0; i < k; ++i) {
        int time = Record::input_time();
        for (; index < cntv.size() && time >= cntv[index].first; ++index) ;
        if (index == 0) cout << 0 << endl;
        else if (index == cntv.size()) cout << cntv.back().second << endl;
        else cout << cntv[index-1].second << endl;
    }
    // 得出最长停车时间
    vector<pair<string, int>> tv;
    for (auto &i : tmap) tv.push_back(i);
    sort(tv.begin(), tv.end(), [](pair<string, int> &p1, pair<string, int> &p2){
        if (p1.second != p2.second) return p1.second > p2.second;
        return p1.first < p2.first;
    });
    int max_time = tv[0].second;
    for (int i = 0; i < tv.size() && tv[i].second == max_time; ++i) {
        if (i != 0) cout << " ";
        cout << tv[i].first;
    }
    cout << " " << Record::get_time_str(max_time) << endl;
    return 0;
}
