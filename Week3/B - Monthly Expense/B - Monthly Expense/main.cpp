//
//  main.cpp
//  B - Monthly Expense
//
//  Created by Kieran Will on 10/13/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#define INF 0x7fffffff
using namespace std;
int N, M, tmp, _l, _r, _m_r, _m_l, _tmp_sum;
vector<int> _v;
int main(int argc, const char * argv[]) {
    cout << (int)INF << "\n";
    // insert code here...
    //std::cout << "Hello, World!\n";
    while (scanf("%d%d", &N, &M) != EOF) {
        _v.clear();
        int _sum = 0, _max = 0, _min = INF;
        for (int i = 0; i < N; ++ i) {
            scanf("%d", &tmp);
            _v.push_back(tmp);
            _sum += tmp;
            if (tmp > _max) { _max = tmp; }
        }
        //使用二分法
        _l = _max; _r = _sum;//范围是最大的单个项~全部项的和(分N组到分一组)（1 < M < N）
        while (_r > _l) {//二分法结束条件，注意左右不能相等，r + 1 == l
            unsigned _count = 0;
            _m_r = (_l + _r) / 2;
            _m_l = (_l + _r) / 2 + 1;
            _tmp_sum = 0;
            for(int i = 0; i < N; ++ i) {
                _tmp_sum += _v[i];
                if(_tmp_sum > _m_r) { ++ _count; _tmp_sum = _v[i]; }//如果某几个连续的项大于中间值，认为这是一种暂时的合适分组的情况，_count记录分组的组数
            }
            if (_count < M) { _r = _m_r; }//如果暂时的分组比要求M少了，让 right =  middle， 就是缩小右限
            else            { _l = _m_l; }//如果暂时的分组比要求M多了， 同理；如果恰好count == M,但是我们关心的是二分的左右界是否相同（相差1），来保证min是最小的
            _min = _l;
        }
        
        printf("%d\n", _min);
        
    
    }
    
    return 0;
}

/*
 7 5
 100
 400
 300
 100
 500
 101
 400
 
 */
