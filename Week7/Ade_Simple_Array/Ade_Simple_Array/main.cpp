//
//  main.cpp
//  Ade_Simple_Array
//
//  Created by Kieran Will on 11/16/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

#include <iostream>
#define SIZE 10
using std::cin;
using std::cout;

class MyArray {
public:
    
    MyArray();
    /*
     插入一个元素content到数组的第position个位置，注意position从0开始
     如原始数组是 1 2 3，insert(0, 5)之后变成 5 1 2 3
     如果插入的位置在数组末尾或者之后，则直接将元素插入到数组末尾
     如原始数组是 1 2 3，insert(50, 6)之后变成 1 2 3 6
     第50个位置在当前数组大小之后，所以直接插入到数组末尾，也就是第3个位置
     */
    
    void insert(int position, int content);
    /*
     删除数组的第position个元素
     如果数组没有第position个元素，则不删除任何元素
     */
    
    void deleteByPosition(int position);
    
    /*
     将数组内容打印到屏幕，每个元素后面都跟着一个制表符，
     并且最后一个元素的制表符后面需要换行
     ﻿﻿空数组也需要换行
     */
    void print();
private:
    int contents[100];                   // 数组，用来存放元素
    int size;                            // 数组内元素个数
};

MyArray::MyArray() {
    size = 0;
}

void MyArray::insert(int position, int content) {
    if (position < 0 or position >= 100) return;//exit(1);
    if (position >= size) {
        contents[size] = content; size ++; return;
    }
    int tmp_cntt = contents[position];
    contents[position] = content;
    size ++;
    for (int i = size; i > position; -- i) {
        contents[i] = contents[i-1];
    }
    contents[position+1] = tmp_cntt;
}

void MyArray::deleteByPosition(int position) {
    if (position < 0 or position >= 100) return;//exit(1);
    if (position >= size) {
        return;
    }
    for (int i = position; i < size - 1; ++ i) {
        contents[i] = contents[i+1];
    }
    size --;
}

void MyArray::print() {
    for (int i = 0; i < size; ++ i) {
        cout << contents[i] << "\t";
    }
    cout << "\n";
}


int main(int argc, const char * argv[]) {
    MyArray a;
    a.insert(10, 1);a.insert(10, 2);a.insert(10, 3);
    a.print();
    a.insert(0, 5);
    a.print();
    a.insert(50, 6);
    a.print();
    
    a.deleteByPosition(0);
    a.print();
    
    a.deleteByPosition(90);
    a.print();

    
    std::cout << "Hello, World!\n";
    return 0;
}
