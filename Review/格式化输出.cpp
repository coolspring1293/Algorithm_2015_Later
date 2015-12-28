#Detail:
/*关于浮点数的格式*/
#include <iostream.h>
void main()
{
    float f=2.0/3.0,f1=0.000000001,f2=-9.9;
    cout<<f<<' '<<f1<<' '<<f2<<endl;      //正常输出
    cout.setf(ios::showpos);              //强制在正数前加+号
    cout<<f<<' '<<f1<<' '<<f2<<endl;
    cout.unsetf(ios::showpos);            //取消正数前加+号
    cout.setf(ios::showpoint);            //强制显示小数点后的无效0
    cout<<f<<' '<<f1<<' '<<f2<<endl;
    cout.unsetf(ios::showpoint);          //取消显示小数点后的无效0
    cout.setf(ios::scientific);           //科学记数法
    cout<<f<<' '<<f1<<' '<<f2<<endl;  
    cout.unsetf(ios::scientific);         //取消科学记数法
    cout.setf(ios::fixed);                //按点输出显示
    cout<<f<<' '<<f1<<' '<<f2<<endl;
    cout.unsetf(ios::fixed);              //取消按点输出显示
    cout.precision(18);                   //精度为18，正常为6
    cout<<f<<' '<<f1<<' '<<f2<<endl;
    cout.precision(6);                    //精度恢复为6
} 

操纵算子：
/*关于浮点数的格式*/
#include <iomanip.h>
void main()
{
    float f=2.0/3.0,f1=0.000000001,f2=-9.9;
    cout<<f<<' '<<f1<<' '<<f2<<endl;      //正常输出
    cout<<setiosflags(ios::showpos);      //强制在正数前加+号
    cout<<f<<' '<<f1<<' '<<f2<<endl;
    cout<<resetiosflags(ios::showpos);    //取消正数前加+号
    cout<<setiosflags(ios::showpoint);    //强制显示小数点后的无效0
    cout<<f<<' '<<f1<<' '<<f2<<endl;
    cout<<resetiosflags(ios::showpoint);  //取消显示小数点后的无效0
    cout<<setiosflags(ios::scientific);   //科学记数法
    cout<<f<<' '<<f1<<' '<<f2<<endl;  
    cout<<resetiosflags(ios::scientific); //取消科学记数法
    cout<<setiosflags(ios::fixed);        //按点输出显示
    cout<<f<<' '<<f1<<' '<<f2<<endl;
    cout<<resetiosflags(ios::fixed);       //取消按点输出显示
    cout<<setprecision(18);               //精度为18，正常为6
    cout<<f<<' '<<f1<<' '<<f2<<endl;
    cout<<setprecision(6);                //精度恢复为6
}

1.打印浮点数控制位数

  
setf: set flag   
  
＃incluce <iomanip>// 操作元manipulator   
cout.setf(ios::fixed);   
cout.setf(ios::showpoint);   
cout.precision(2); //用两位小数显示   
cout<< your_double_variable<<endl;   
cout.precision(5); //再次改变时只需加这一句就可以了。    
cout::setf(ios::showpos);//正数显示时加正号   
cout::setf(ios::scientific);//用科学计数法表示   
cout::setf(ios::left);//左对齐   
cout::setf(ios::right);//右对齐   
cout.width(4);//只对一次有用   
cout<<setw(4)<<4<<endl;//控制输出宽度   
cout.unsetf(ios::showpos);//取消设置标志位 

setf: set flag

＃incluce <iomanip>// 操作元manipulator
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2); //用两位小数显示
cout<< your_double_variable<<endl;
cout.precision(5); //再次改变时只需加这一句就可以了。 
cout::setf(ios::showpos);//正数显示时加正号
cout::setf(ios::scientific);//用科学计数法表示
cout::setf(ios::left);//左对齐
cout::setf(ios::right);//右对齐
cout.width(4);//只对一次有用
cout<<setw(4)<<4<<endl;//控制输出宽度
cout.unsetf(ios::showpos);//取消设置标志位
  
 

2.不同类型占的位数：

long double 12个字节：sizeof(long double) = 12;//devc++ 
double 8个字节 ：sizeof(double)=8;//devc++ 
short int 2字节：sizeof(short int) = 2;//devc++

variable op= expression  <=> variable = variable op (expression);


 

3.取余数问题：

正整数%负整数=正整数

负整数%正整数=负整数

负整数%负整数=负整数

4.重载：

当定义一个这样的两个函数时

  
double sum(int a, int b)   
{   
        return a + b;   
}   
  
double sum(double a, double b)   
{   
       return a + b;   
} 

double sum(int a, int b)
{
        return a + b;
}

double sum(double a, double b)
{
       return a + b;
}当调用 

  

  
sum(2, 2.5); 

sum(2, 2.5); 时编译器会报错：

 error: call of overloaded ‘mp(int, double)’ is ambiguous

5.string

      string类有两个构造函数：一个是可以初始化为一个空字符串，另一个接收字符数组，将字符数组转换成string

  
cin.getline(char_array);   
cin.get(char_var);   
getline(cin, string_var);//第一种录入一行   
getline(cin, string_var, '?');//第二种遇到指定字符结束   
  
string 的一些函数：   
  
str.at(i) 等价于str[i]，但是会检查是否越界，更安全   
  
str.substr(position, length);//返回调用对象的一个子字符串，它起始于position,总共包含length个字符   
  
str.empty();//如果是空返回true，否则返回false   
  
str.insert(pos, str2);//   
  
str.remove(pos, length);//   
  
str.c_str();//string转换成字符串   
  
比较：   
  
==, != , > , >= , < , <=   
  
查找：   
  
str.find(str1);//返回str1在str中首次出现时的索引   
  
str.find(str1, pos);//返回str1在str中首次出现时的索引，从位置pos处开始查找   
  
str.find_first_of(str1, pos);//返回str1的【【任何字符】】在str中首次出现时的索引，从位置pos处开始查找   
  
str.find_first_not_of(str1, pos);//返回不属于str1的【【任何字符】】在str中首次出现时的索引，从位置pos处开始查找 

cin.getline(char_array);
cin.get(char_var);
getline(cin, string_var);//第一种录入一行
getline(cin, string_var, '?');//第二种遇到指定字符结束

string 的一些函数：

str.at(i) 等价于str[i]，但是会检查是否越界，更安全

str.substr(position, length);//返回调用对象的一个子字符串，它起始于position,总共包含length个字符

str.empty();//如果是空返回true，否则返回false

str.insert(pos, str2);//

str.remove(pos, length);//

str.c_str();//string转换成字符串

比较：

==, != , > , >= , < , <=

查找：

str.find(str1);//返回str1在str中首次出现时的索引

str.find(str1, pos);//返回str1在str中首次出现时的索引，从位置pos处开始查找

str.find_first_of(str1, pos);//返回str1的【【任何字符】】在str中首次出现时的索引，从位置pos处开始查找

str.find_first_not_of(str1, pos);//返回不属于str1的【【任何字符】】在str中首次出现时的索引，从位置pos处开始查找

  
6.vector

  
#include <vector>   
using namespace std;   
  
vector 添加元素：v.push_back();   
  
vector只能更改一个已经赋值的元素。   
  
可以初始化由参数指定的位置数目：   
  
vector<int> v(10);   
  
    为构造函数提供哦你一个整数参数时，向量会初始化成相应数据类型的零值。如果向量的基类型是一个类，就会用那个类的默认构造函数来进行初始化。   
向量的长度和容量：   
     向量的长度是向量中元素的个数，容量则是当前实际分配了内存的元素个数。   
  
    v.size();     
    v.capacity();   
改变大小：       
v.reserve(32);//到达不少于32的容量   
v.resize(32);//调整到32， 多的删掉，少的增加。 

#include <vector>
using namespace std;

vector 添加元素：v.push_back();

vector只能更改一个已经赋值的元素。

可以初始化由参数指定的位置数目：

vector<int> v(10);

    为构造函数提供哦你一个整数参数时，向量会初始化成相应数据类型的零值。如果向量的基类型是一个类，就会用那个类的默认构造函数来进行初始化。
向量的长度和容量：
     向量的长度是向量中元素的个数，容量则是当前实际分配了内存的元素个数。

    v.size();  
    v.capacity();
改变大小：    
v.reserve(32);//到达不少于32的容量
v.resize(32);//调整到32， 多的删掉，少的增加。

  
7. 字符串转数字

  
#include <stdlib.h>   
  
atoi();//转换成整数   
  
atol();//转换成长整型   
  
atof();//转换成浮点，double 

#include <stdlib.h>

atoi();//转换成整数

atol();//转换成长整型

atof();//转换成浮点，double  
12.const使用时注意

  
一个在形参声明为const的变量在函数内部调用其他函数时，如果用到这个变量，那么将要调用的函数对此参数也要声明为const 

   一个在形参声明为const的变量在函数内部调用其他函数时，如果用到这个变量，那么将要调用的函数对此参数也要声明为const  
8. new动态变量和数组

  
p = new int;//动态变量   
delete p ;   
  
p = new int[10];//动态数组   
delete []p;//释放，删除数组   
  
注意：int* p1, p2;实际上声明了一个p1 为int型指针，p2为int型变量。   
而    
typedef int* IntPtr;   
IntPtr p1, p2；//则声明了两个指针。   
  
数组变量实际是指针变量：   
IntPtr p;   
int a[10];   
p = a;   
但区别是不可更改数组变量中的指针值。   
例：a  = p2//非法 

p = new int;//动态变量
delete p ;

p = new int[10];//动态数组
delete []p;//释放，删除数组

注意：int* p1, p2;实际上声明了一个p1 为int型指针，p2为int型变量。
而 
typedef int* IntPtr;
IntPtr p1, p2；//则声明了两个指针。

数组变量实际是指针变量：
IntPtr p;
int a[10];
p = a;
但区别是不可更改数组变量中的指针值。
例：a  = p2//非法
  
9.多维动态数组

  
typedef int* IntArrayPtr;   
IntArrayPtr *m = new IntArrayPtr[3];   
m[i] = new int[4];   
  
删除多维数组：   
delete []m[i];   
delete []m;   
  
  
typedef int* IntArrayPtr;   
int main()   
{   
 IntArrayPtr *m = new IntArrayPtr[3];   
        for(int i = 0; i < 3; i++)   
                m[i] = new int[4];   
        for(int i = 0; i < 3; i++)   
                for(int j = 0 ; j < 4; j++)   
                        m[i][j] = i * j;   
        for(int i = 0; i < 3; i++)   
        {   
                for(int j = 0; j < 4; j++)   
                        cout << m[i][j]<<" ";   
                cout<<endl;   
        }   
        for(int i = 0; i < 3; i++)   
                delete []m[i];   
        delete []m;   
       return 0;   
} 

typedef int* IntArrayPtr;
IntArrayPtr *m = new IntArrayPtr[3];
m[i] = new int[4];

删除多维数组：
delete []m[i];
delete []m;


typedef int* IntArrayPtr;
int main()
{
 IntArrayPtr *m = new IntArrayPtr[3];
        for(int i = 0; i < 3; i++)
                m[i] = new int[4];
        for(int i = 0; i < 3; i++)
                for(int j = 0 ; j < 4; j++)
                        m[i][j] = i * j;
        for(int i = 0; i < 3; i++)
        {
                for(int j = 0; j < 4; j++)
                        cout << m[i][j]<<" ";
                cout<<endl;
        }
        for(int i = 0; i < 3; i++)
                delete []m[i];
        delete []m;
       return 0;
} 

10.struct

  
struct{};   
千万别忘了加‘；’   
  
结枸体用作参数是否是引用传递或者是传值调用 


  
11.类中成员默认为private


12.假如构造函数没有参数，就不要在对象声明中包括圆括号。

13.匿名对象：是指一个尚未由任何变量命名的对象再次调用构造函数

14.不能重载的操作符：

  
.          //成员访问运算符   
.*        //成员指针访问运算符   
::        //域运算符   
sizeof  //长度运算符   
?:       //条件运算符 

.          //成员访问运算符
.*        //成员指针访问运算符
::        //域运算符
sizeof  //长度运算符
?:       //条件运算符  
15.头文件的编译技巧

  
＃ifndef YOURHEADER_H   
#define YOURheADER_H   
  
.....   
#endif//防止重定义多次包含 

＃ifndef YOURHEADER_H
#define YOURheADER_H

.....
#endif//防止重定义多次包含  

16.构造两次，析构四次的问题。

    代码如下：

  
#include <iostream>   
#define NDEBUG   
#include <cassert>   
#include <iomanip>   
using namespace std;   
  
double mp(int a, int b)   
{   
        cout<< "this is from int mp." << endl;   
        return a + b;   
}   
  
double mp(double a, double b)   
{   
        cout<< "this is from double mp." << endl;   
        return a + b;   
}   
  
class Money   
{   
        private:   
        double i;   
        public:   
        Money(double t){   
                this->i = t;   
                cout<< "constructor" << t <<endl;   
        };   
        Money(){   
                cout<< "default constructor" <<endl;   
        }   
        friend Money operator + ( Money& a,  Money& b);   
        double get()   
        {   
                return this->i;   
        }   
        friend ostream& operator << (ostream& outs, Money b);   
        friend istream& operator >> (istream& ins, Money& b);   
        ~Money()   
        {   
                cout<< "destructor" << this->i <<endl;   
        }   
  
};   
 Money operator + (Money& a, Money& b)   
{   
        return Money(a.i + b.i);   
}   
ostream& operator << (ostream& outs, Money b)   
{   
                outs<<b.i<< "overloadding cout" <<endl;   
                return outs;   
}   
  
istream& operator >> (istream& ins, Money& b)   
{   
        int t;   
        ins>>t;   
        b.i = t;   
        return ins;   
}   
int main()   
{   
        cout<<"c++ is ok now!"<<endl;   
        Money a, b;   
        cin>>a>>b;   
        cout<<a<<b;   
        //Money b = a + 3.0;   
        //a + 3;   
//      cout<<"dd "<< b.get()<<endl;   
  
        return 0;   
                                                                                                               ｝}