# DataStructure

【可信软件能力认证培训】基础算法和数据结构
LeetCode题解，151道题完整版：https://github.com/soulmachine/leetcode

Acm Cheat Sheet（手写代码必备手册）：https://github.com/soulmachine/acm-cheat-sheet

动态规划讲解：

https://www.jianshu.com/p/919cd4e268b1

https://blog.csdn.net/sinat_38816924/article/details/82982865

https://m.sohu.com/a/153858619_466939/?pvid=000115_3w_a&strategyid=00014

贪心算法讲解：https://www.jianshu.com/p/b613ae9d77ff

红黑树：https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/03.01.md

B+树的特点

设有6个节点的无向简单图是一个连通图，该图可能的边数是（）
小李负责某产品版本自研代码里片段引用开源的整改
 
设有6个节点的无向简单图是一个连通图，该图可能的边数是

文档说明

（1）部分参考资料来源
第一章
http://3ms.huawei.com/km/blogs/details/2262623

第二章
http://3ms.huawei.com/km/blogs/details/2262647

第三章
http://3ms.huawei.com/km/blogs/details/2262671

第四章
判断、选择、填空：http://3ms.huawei.com/km/blogs/details/2265547
改错：http://3ms.huawei.com/hi/group/2990017/wiki_4377939.html （感谢 1L 夏超的回复）

第五章
http://3ms.huawei.com/km/blogs/details/2265555

第六章
http://3ms.huawei.com/km/blogs/details/2265575

第七章
http://3ms.huawei.com/km/blogs/details/2265577 



（2）特别说明

虽然在做题过程中参考了很多资料，但鉴于本人水平有限，这份文档不代表官方标准答案，
欢迎指出其中的错误和不足。








樊肇楠 00420095
2017年7月6日
 

第一章：预处理、宏定义
1.1	判断
对于频繁调用的函数需要提高性能，频繁调用的小函数可以改成宏定义来提高性能。( )




对
宏替换不占运行时间，只占编译时间；而函数调用则占运行时间（分配单元、保留现场、值传递、返回），所以每次执行都要载入所以执行起来比较慢一些。
1.2	判断
宏替换的意思是在编译预处理阶段，把代码中出现的宏名替换为宏体，这基本上相当于文字编辑过程中的“查找”与“替换”，只不过宏替换是由预处理器在编译之前自动进行的。( )




对
宏是简单的文本替换，在编译预处理时进行。
1.3	判断
宏定义是用宏名来表示一个字符串，在宏展开时又以该字符串取代宏名，这只是一种简单的代换，字符串中可以含任何字符，可以是常数，也可以是表达式，预处理程序对它不作任何检查。如有错误，只能在编译已被宏展开后的源程序时发现。 ( )




对
预处理程序不对宏作检查，错误只能在编译已被宏展开后的源程序时发现。
1.4	判断
宏定义不是说明或语句，在行末不必加分号，如加上分号则连分号也一起置换。( )




对
宏定义不是说明或语句，在行末不必加分号，如加上分号则连分号也一起置换。
1.5	判断
宏名在源程序中若用引号括起来，则预处理程序不对其作宏代换。( )




对
宏名在源程序中若用引号括起来则为字符串，不是宏名关键字，因此预处理程序不会对其作宏替换。
1.6	判断
习惯上宏名用大写字母表示，以便于与变量区别。但也允许用小写字母。( )




对
1.7	判断
宏定义可以带有参数，宏调用时是以实参代换形参。而不是“值传送”。 ( )




对
1.8	单选
请问下面题目中a,b,c输出值为多少？( )
#include <stdio.h>
#define func(A)         A++;\
			          A *= 10;

int main(int argc, char* argv[])
{
	int a = 10;
	int b=20;
	int c=30;

	if(a > 10)
	   func(a);

	if(b >= 20)
	   func(b);

	if(c>30)
	{
     func(c);
	}
	
	printf("a=%d,b=%d,c=%d\r\n",a,b,c);
	return 0;
}

A、10,210,30  
B、100,210,300
C、110,210,310
D、100,210,30 
E、110,200,30




选D，宏只是简单的文本替换
1.9	单选
请看如下代码,最后result 是多少 ( )
#define MUL(a,b) (a*b)
{
int a =1,b=2,c=3;
int result = 0;
result= MUL(a+b,c);
}
A、6   
B、7
C、8
D、9




选B
1.10	单选
设有以下宏定义:
#define   N      3
#define 　Y(n)　((N+1)*n) 
则执行语句:z = 2 * (N + Y(5 + 1));后,z的值为( )
A、 出错        B、 42           C、 48            D、54




选C
1.11	单选
以下叙述中正确的是 ( )
A、预处理命令行必须位于源文件的开头 B、在源文件的一行上可以有多条预处理命令
C、宏名必须用大写字母表示           D、宏替换不占用程序的运行时间




选D
1.12	单选
#define  A  3.897678
#include  <stdio.h>
main(  )
{ 
printf(“A=%f ”,A);
}
程序运行结果为( )
A、 3.897678=3.897678     B、3.897678=A    C、 A=3.897678   D、无结果




选C 
1.13	单选
以下程序的输出结果是( )
#define M(x,y,z) x*y+z
main()
{ int a=1,b=2, c=3;
printf(“%d\n”, M(a+b,b+c, c+a));
}
A、 19		 B、 17 		C、 15 		D、 12




选D
1.14	单选
有以下程序
#define N 5
#define M1 N*3
#define M2 N*2
main()
{ int i;
i=M1+M2; printf(“%d\n”,i);
}
程序编译后运行的输出结果是( )
A、10  	  B、 20   	 C、 25   	 D、30





选C
1.15	单选
有如下程序
#define N 2
#define M N+1
#define NUM 2*M+1
#main()
{ int i;
for(i=1;i<=NUM;i++)printf(“%d\n”,i);
}
该程序中的for循环执行的次数是( )
A、5		 B、6 		C、7 		D、8




选B，NUM=6
1.16	单选
有宏定义：#define  LI(a,b)  a*b
          #define  LJ(a,b)  (a)*(b)
在后面的程序中有宏引用：x=LI(3+2,5+8);
                  y=LJ(3+2,5+8);
则x、y的值是( )
A、x=65,y=65    B、x=21,y=65    C、x=65,y=21    D、x=21,y=21




选B
1.17	单选
有以下程序
# define f(x) (x*x)
main()
{ int i1, i2;
i1=f(8)/f(4) ; i2=f(4+4)/f(2+2) ;
printf("%d, %d\n",i1,i2);
}
程序运行后的输出结果是( )
A、64, 28 		B、4, 4 		C、4, 3 		D、64, 64




选C
1.18	单选
以下程序的输出结果是( )
#define  MIN(x, y)   (x) < (y) ? (x) : (y)
main()
{   int i , j, k;
    i = 10;  j = 15;
  k = 10 * MIN(i, j);
    printf(“%d\n”, k);
}
A、15  B、100   C、10    D、150




选A
k = 10*(10) < (15) ? (10) : (15)，乘法的优先级高于小于号，即 k= 100<15? 10: 15
1.19	单选
以下程序的输出结果是( )
# include  <stdio.h>
# define  N  2
# define  M  N+2
# define  CUBE(x)  (x*x*x)
main( )
{ int  i=M;   i=CUBE(i);  printf(“%d\n”, i);    }
A、17        B、64      C、125       D、53




选B
1.20	多选
关于宏定义下列说法正确的是( )
A、	使用宏定义可提高源程序的可维护性；
B、	使用宏定义可提高源程序的可移值性；
C、	使用宏定义可减少源程序中重复书写字符串的工作量；
D、	以上都正确。




选ABCD
首先ABC都是对的，https://wenku.baidu.com/view/2b1f9c57bceb19e8b9f6ba9e.html （第七页）
然后这是多选题… 知识点理解了就好
1.21	多选
下列关于带参宏定义与函数的区别说法正确的是( )
A、	函数调用时，要求出实参表达式的值，而宏定义是简单的字符替换；
B、	对于函数中的形参、实参都要定义类型，而宏不存在类型问题；
C、	调用函数只能得到一个返回值，而用宏可以设法得到几个结果；
D、	使用有参函数，无论调用多少次都不会使目标程序变长，但每次调用都要占用系统时间进行调用现场保护和现场恢复；而使用有参宏，则不占运行时间，但每运行一次，都会使目标程序增大一次。




选ABCD

对于C选项，这句话出自谭浩强的书，第二三版中有如下的例子
#include <stdio.h>
#define PI 3.1415926
#define CIRCLE(R,L,S,V) L=2*PI*R;S=PI*R*R;V=4.0/3.0*PI*R*R*R
void main()
{
float r,l,s,v;
    scanf("%f",&r);
CIRCLE(r,l,s,v);      
printf("r=%6.2f,l=%6.2f,s=%6.2f,v=%6.2f\n",r,l,s,v);
}
对于D选项
函数调用则占运行时间（分配单元、保留现场、值传递、返回）；使用宏次数多时，宏展开后源程序长，因为每展开一次都使程序增长
1.22	多选
下列说法正确的是( )
A、	在宏定义#define  A  3.897678中，宏名A代替一个字符串；
B、	C语言的编译系统对宏命令的处理在对源程序中其它语句正式编译之前进行的；
C、	在文件包含预处理语句的中，被包含文件名用“< >”括起时，寻找被包含文件的方式是在包含文件目录中去查找(包含目录是由用户在设置环境时设置的)，而不在源文件目录去查找；被包含文件名用“”括起时，则表示首先在当前的源文件目录中查找，若未找到才到包含目录中去查找。用户编程时可根据自己文件所在的目录来选择某一种命令形式。
D、	文件包含允许嵌套，即在一个被包含的文件中又可以包含另一个文件。




选ABCD
对于A选项， 网上的例子是#define PI 3.1415926，可以自己Baidu下，网上的讨论很多
《C程序设计（第三版）》,里面对宏的具体定义是：#define 标识符 字符串
理解的关键是：预处理只处理文本，只做文本替换。
1.23	填空
#define  TEST_1  0
#define  TEST_2  1
#define  TEST_3  0

void TestPro()
{
    int a = 0 ; 

#ifdef TEST_1
    a += 1 ;
#endif

#if (TEST_2)
    a += 3 ;
#endif

#ifndef TEST_3
    a += 6;
#else
    a += 5 ;
#endif

    printf("%d\r\n", a) ;
    
    return ;
}
输出结果为_____




结果为： 9
1.24	填空
#define OK 100
main()
{
  printf("OK");
}
输出结果为_____




结果为： OK
1.25	填空
以下程序输出结果是_____
    # include〈stdio.h〉
    # define  MAX(x，y)  (x)>(y)?(x):(y)
    main（）
    {
int i，z，k；
    z=15；
    i=z-5；
    k=10*（MAX（i，z））；
printf（“%d\n”，k）；
}




结果为： 150
1.26	填空

以下程序输出结果是_____
    # include〈stdio.h〉
    # define  ADD(y)  3.54+y
# define  PR(a)   printf(“%d”,(int)(a))
# define  PR1(a)  PR(a);putchar(‘\n’)
main（）
    {int i=4；
     PR1(ADD(5)*i)；
}




输出为: 23
double/float强制类型转换为int时直接向下取整
1.27	填空
设有如下宏定义：
#define MYSWAP(z,x,y) {z=x;x=y;y=z;}以下程序段通过宏调用实现变量a、b内容交换,请填空。float a=5,b=16,c; _____;




MAXSWAP(z,a,b) 或 MAXSWAP(z,b,a)
1.28	填空
下列程序的输出结果是_____
#define N 10
#define s(x) x*x
#define f(x) (x*x)
main()
{ int i1,i2;i1=1000/s(N);i2=1000/f(N);printf(“%d  %d\n”,i1,i2);}




结果为： 1000,10
1.29	填空
以下程序输出结果是_____
   main( )
   {
int  b=5;
#define  b  2
#define  f(x)  b*(x)
int  y=3;
printf(“%d  ”,f(y+1));
#undef  b
printf(“%d  ”,f(y+1));
#define  b  3
printf(“%d\n”,f(y+1));
}




结果为：8 20 12
1.30	填空
以下程序的输出结果为_____
#define CIR(r) r*r 
void main()
{
    int a = 1;
    int b = 2;
    int t;
    t = CIR(a + b);
    printf("%d\n", t);
    return;
}




结果为: 5
1.31	填空
下列程序的输出结果是_____
#define MAX(a,b) a>b
#define EQU(a,b) a==b
#define MIN(a,b) a<b
main()
{  int a=5,b=6; 
if(MAX(a,b)) printf(“MAX\n”); 
if(EQU(a,b)) printf(“EQU\n”);
   if(MIN(a,b)) printf(“MIN\n”);
}




结果为： MIN
第二章：数据类型、数据结构
1.1	判断
switch(c)中的c的数据类型可以是char、long、float、unsigned、bool。( )




错
switch()中必须为整型或可以转换为整型的表达式，在C++中 
  1. char、short、int、long、bool 基本类型都可以用于switch语句。 
  2. float、double都不能用于switch语句。 
  3. enum类型，即枚举类型可以用于switch语句。 
  4. 所有类型的对象都不能用于switch语句。 
  5. 字符串也不能用于switch语句
1.2	判断
除非特别指定，首个枚举常量的值总是0，后一个枚举常量的值总是比前一个大1。( )




对
1.3	判断
C语言中枚举类型与“int”类型是相容的。( )




对
1.4	判断
静态(static)类别变量的生存期贯穿于整个程序的运行期间。( )




对
1.5	判断
在C程序中，判逻辑值时，用“非0”表示逻辑值“真”， 又用“0”表示逻辑值“假”。 在求逻辑值时，用“1”表示逻辑表达式值为“真”， 又用“0”表示逻辑表达式值为“假”。 ( )




对
1.6	判断
结构体类型数据在内存中占据空间等于各个成员所占据的内存空间之和。( )




错
要考虑字节对齐
1.7	判断
联合体类型数据的各个成员占据内存空间的起点相同，并且只能对联合体类型变量的的一个成员初始化。( )




对
1.8	判断
堆栈在数据中的存储原则是后进先出，队列在数据中的存储原则是先进先出。( )




对
1.9	判断
线性链表中各个链结点之间的地址一定要连续。( )




错
1.10	判断
若频繁地对一个线性表进行插入和删除操作，该线性表采用顺序存储结构更合适。( )




错
1.11	单选
有一个char *类型的指针，恰好指向了一个int，想让这个指针跳过int指向下一个char，下面的代码可以达到这个目的吗？( )
1）((int *)p)++;
2）p += sizeof(int)；
A、只有1)可以；
B、只有2)可以；
C、都可以；
D、都不可以




选B
表达式整体++是不行的，若int *p2=(int)p;   p2++;  就可以。
在VS2015环境下，((int *)p)++; 会报错：error C2105: “++”需要左值
1.12	单选
C语言中运算对象必须是整型的运算符是( )
A、%=           B、/           C、=              D、<=




选A
1.13	单选
如下描述不正确的是( )
A、无符号数和有符号数在取值范围上是存在差异的，容易引起溢出，若非特殊需要，不要进行有符号数和无符号数的强制类型转换，以免产生不必要的麻烦；
B、无符号数的不同变量类型之间，若非特殊需要，也不要进行强制类型转换，容易引起溢出，以免产生不必要的麻烦；
C、 对于无符号数或者有符号数的输入输出语句中，一般无需考虑数据结构的取值范围问题，输入输出描述符与数据类型不对应一般不会带来溢出类问题，可能只影响到输入结果或者显示结果；
D、 在不同类型数据的混合运算中，由系统自动实现转换，由少字节类型向多字节类型转换。不同类型的变量相互赋值时也由系统自动进行转换，把赋值号右边的类型转换为左边的类型。




选C
1.14	单选
-1 在存放在char类型时，他的2 进制是( )
A、	1000 0001    
B、	1111 1111     
C、	0111 1111   
D、	0000 0001




选B，-1是int类型，其编码为0xffffffff，放入char时会截断，还剩0xff
1.15	单选
在C++语言中，有符号字符型（char）的取值范围( )
A、-127 到 128 
B、-128 到 127
C、-128 到 128
D、-127 到 127




选B
1.16	单选
#define DOJOKE "1234" 和 char NOPASS[]="1234"  请问 sizeof( DOJOKE ) 和sizeof( NOPASS )分别是( )
A、	4 ，4    
B、	5 ，4      
C、	4 ，5   
D、	5 ，5





选D
1.17	单选
若有以下定义char s='\092';  则该语句( )
A、使s的值包含一个字符；    B、定义不合法，s的值不确定；
C、使s的值包含4个字符；   D、使s的值包含3个字符




答案A和B不确定，建议选B
\0oo是标志该字符是以八进制定义的。但如果o不是合法的数字（应该在0-7)之间，就会忽略这些数字，只取最后一位数字。
比如\092因为9不在有效范围，所以被忽略。上述定义就等价于char s = '2';
VS2015环境下
char s='\092';
printf("%d %c",s,s);
结果是：50 2

https://www.zybang.com/question/9610b762297776b2a51c6643077647b9.html
虽然实际测试可以运行，网上提出问题的这个人说答案是B
1.18	单选
C语言中最简单的数据类型包括( )
 
A、整型、实型、逻辑型
B、整型、实型、字符型
C、整型、字符型、逻辑型
D、整型、实型、逻辑型、字符型





 


选B，逻辑型是C++中新增的
1.19	单选
以下不能正确定义二维数组的是( )
A：int a[2][2]={{1},{2}};
B：int a[][2]={1,2,3,4};
C：int a[2][2]={{1},2,3};
D：int a[2][]={{1,2},{3,4}};


选D，二维数组必须指定第二维的大小
1.20	单选
以下各选项企图说明一种新的类型名，其中正确的是( )
A：typedef  v1  int;
B：typedef  v2 = int;
C：typedef  int  v3;
D：typedef  v4:  int;



选C
1.21	单选
已知
struct point
{
		int x;
		int y;
};
struct rect
{
		struct point pt1;
		struct point pt2;
};
struct rect rt;
struct rect *rp = &rt;
则下面哪一种引用是不正确的( )
A、rt.pt1.x           B、(*rp).pt1.x
C、rp->pt1.x	      D、 rt->pt1.x




选D
1.22	单选
在while（x）语句中的x与下面条件表达式等价的是( )
A. x!=0   B. x==1   C.  x!=1   D.  x==0




选A
1.23	多选
通常从哪些方面评价算法的质量( )
A、	正确性；B、易读性；C、强壮性；D、高效率




选ABCD
1.24	多选
以下叙述中正确的是( )
A、算法正确的程序最终一定会结束
B、算法正确的程序可以有零个输出
C、算法正确的程序可以有零个输入
D、算法正确的程序对于相同的输入-定有相同的结果




选ACD，算法至少要有一个输出
1.25	多选
C语言中整形常量按进制划分，有以下几种( )
   A. 十六进制常量   B. 十进制常量
   C. 八进制常量     D. 二进制常量




选ABC
C语言标准中针对数值常量，规定了八进制、十进制和十六进制的规则，但是对于常用的二进制则没有规定。
一些编译器厂商，自行扩展了类似0b10001000这样的语法，用来表示二进制数值。
1.26	填空
enum ENUM_A
	{
	      X1,
	      Y1,
	      Z1 = 5,
	      A1,
	      B1
	};
	enum ENUM_A enumA = Y1;
	enum ENUM_A enumB = B1;
	请问 enumA = _____; enumB = _____;





答案为： 1  7
1.27	填空
enum NEW_SERV_ID  
{
    NSID_SERV_NULL = 0,
    ...
    NSID_SERV254 = 254,
    NSID_SERV255 ,    
    NSID_BUTT    
};

unsigned char GetNsid(char nsid)
{
    return (nsid);
}
GetNsid(NSID_SERV_NULL) = _____;
GetNsid(NSID_SERV255) = _____;
GetNsid(NSID_BUTT) =_____.





答案为： 0  255  0
enum类型的变量大小为4Byte，所以NSID_BUTT = 256 = 0x100，NSID_BUTT转换为unsigned char时会发生截断，结果为0x00（即0）
1.28	填空
ULONG ATM_UNI_GetParaULONGValByOID(UCHAR *Type );
{
    *Type=0x12;
}
ULONG ATM_UNI_MAPIPTable_DeleteHandler (VOID* pMsgRcv, VOID** ppMsgSnd)
{  
    ULONG ulType=0x456789ab;
    ulErrCode = ATM_UNI_GetParaULONGValByOID(&ulType );
    printf(”%x”,ulType);
}
在小端字节序下打印输出的值是多少？_____
在大端字节序下打印输出的值是多少？_____





答案： 0x45678912	0x126789ab

小端口诀: 高高低低 -> 高字节在高地址, 低字节在低地址
大端口诀: 高低低高 -> 高字节在低地址, 低字节在高地址

long test = 0x313233334;
小端机器:
低地址 -->　高地址
00000010: 34 33 32 31         -> 4321
大端机器:
低地址 -->　高地址
00000010: 31 32 33 34         -> 4321
1.29	填空
若有以下整型的a数组，数组元素和它们得值如下所示:
   数组元素:  a[0] a[1] a[2] a[3] a[4] a[5] a[6] a[7] a[8] a[9]
   元素的值:  9    4    12   8    2    10   7    5    1    3
    (1)请写出对该数组的说明，并赋以上初值。
       _____
    (2)该数组的最小下标值为___,最大下标值为___。
    (3)写出下面各式的值:
         a[a[9]]的值为___
         a[a[4]+a[8]]的值为___





答案：	（1）int a[10] = {9,4,12,8,2,10,7,5,1,3};
		（2）0   9
		（3）8   8
1.30	填空
已知有以下的说明，
int a[]={8,1,2,5,0,4,7,6,3,9};
那么a[*(a+a[3])]的值为_____




答案：0
1.31	填空
75的十六进制写法为___,八进制写法为___。
    0x75的八进制写法为___,十进制写法为___。
    075的十进制写法为___,十六进制写法为___。




答案：	0x4B	0113
			0165	117
			61		0x3D
1.32	填空
C语言中，字符型数据在内存中以_____码形式存放。




答案：ASCII
1.33	填空
已知：a＝1，b=2，表达式a>b?a:b+1的值是_____




答案：3
优先级： 单目运算符 > 双目运算符 > 三目运算符，所以 “+” 优先级高于“？：”
1.55	找错
以下函数用来对指定的字符串计算32位CRC，请指出其中的3个错误（忽略具体算法本身的正确性）:
VOS_INT32 TRC_GetCrc32( VOS_INT8 * pBuff, VOS_INT32 ulLen)
{
    /* 此处为计算CRC 值的固定算法 */
    VOS_UINT32 uiCRC = VOS_NULL ^ 0xffffffffL;
    do 
    {
        uiCRC = (trc_crc32_table[((int)uiCRC ^ (*pBuff++)) & 0xff]) ^ (uiCRC >> 8);
    } 
    while (ulLen--);
    return (uiCRC ^ 0xffffffffL);
}




（1）	入参没有检查有效性
其它的地方真看不出来 T^T
1.49	填空
以下程序执行的结果是_____ 
#include <stdio.h> 
main()
{ 
	int i,j,row=0,col=0,m; 
	int a[3][3]={1,-2,0,4,-5,6,2,4}; 
	m=a[0][0]; 
	for(i=0;i<3;i++) 
		for(j=0;j<3;j++) 
			if(a[i][j]<m) 
			{
				m=a[i][j]; 
				row=i; 
				col=j;		
			} 
			printf("(%d,%d)= %d\n",row,col,m); 
} 




答案是：（1,1）=-5

