#ifndef PERSON
#define PERSON

#include <iostream>
#include <string>
#include <cctype>
//专门处理字符串的头文件
using std::string;

struct person {
    std::string bookName;//原来字符串是这样定义的
    int age;
    char name;
    int sex;
};

using std::cout;
using std::cin;
using std::endl;//不过在header文件中就不要使用using了  因为头文件会被copy到任何地方  spacename后面的name可能会跟变量名产生冲突
//一般都是函数体外定义函数  和 java 一样   可以把struct抽取为head文件 头文件的名称应该类名称保持一致 struct person->person.h

//头文件一旦改变了  源文件需要重新编译以获取最新的声明
#endif

//以上的预处理器的变量的配合使用可以避免程序多次重复引入头文件
//什么是pre处理器？－>在编译之前执行的一段程序  #include就是一个预处理功能  预处理器在遇到#include时候会用指定的头文件来代替
//预处理变量
int main() {
    person p1, p2;
    string name = "aadon";

    p1.bookName = "Love And War";//24
    p1.name = 'Z';//2
    p1.age = 18;//8
    p1.sex = 0;//8
    string duplication(10, 'c');
    auto legth = duplication.size();//一般说来这个string.size()返回的是一个string::size_type类型的  不一定说就是一个int还可能是auto所以说是用auto是最好的选择
//    cout << "my size:" +  << endl;
    printf("my size: %d\n", sizeof(legth));//这里是8  如果强制转化成int的话就是4了
//    int cout = 10;//看到没  这里因为head引入了using导致了cout失效 必须使用完整的 std::cout
    std::cout << "haha" + name + duplication << endl;//提前using明明空间就好了
    //sizeof(struct)的构成 也就是这个sizeof如何计算出来的呢
    std::cout << p1.bookName << sizeof(p1) << sizeof(p1.bookName) << sizeof(p1.age) << sizeof(p1.sex) << sizeof(p1.name)
              << std::endl;
    //所以说在使用string.size()的时候需要小心 有时候在做string.size()和一个数进行比较的时候  如果这个数是一个负数 会自动的转型为一个五福好的int 实际值会变大很多导致意外结果
//    string ddcin, d2;
    string t = "Aaron";
    t = t + "," + "Hello";
//    toupper(t);
//    for (auto c:t) {
//        if (ispunct(c)) {
//            cout << c << endl;
//        } else {
//            cout << c << endl;//参考cctype里面定义的一些对char的操作
//        }
////        cout << toupper(c) << endl;
//    }
    //遍历字符串并且改指定的value
//    for (auto c:t) {
//        if (isupper(c)) { c = '?'; }
//    }
//    cout << t << endl;//可见的是并没有改动t的本身的val 所以需要利用地址值
//    for (auto &c:t) {
//        if (isupper(c)) { c = '?'; }
//    }
//    cout << t << endl;//这里就成功的修改了t里面的val 主要是因为得到的c是每一个char的地址  修改了地址指向的val
    for (char c:t) {
        printf("%c\n", c);
        if (isupper(c)) { c = '?'; }
    }
    cout << t << endl;

//    for (char c:t) {
//        printf("%c\n", c);
//    }
//    cout << t << endl;
    //总结:获取string的size的方式使用auto来接受是比较好的习惯  尤其是在根据string的下表来访问char 可以避免负值index的问题
//    printf("%s\n", t);
//    t = "Hello" + "Aaro " + t;//每一个操作表达式里面都应该包含一个string对象而这个表示中"Hello"和"Aaron"都是字面值没有变量导致编译不通过
//    cin >> ddcin >> d2;
//    cout << ddcin + d2 << endl;//read in two strings and compact them
//    string temp;
//    while (getline(cin,temp)) {
//        cout << temp << endl;
//    }
//    std::cout << "Hello, Aaron!" << std::endl;
//    unsigned a = 123;
//    for (unsigned int u = 10; u >= 0; u--) {
//        std::cout << u << std::endl;
//    }//为何这里会死循环呢?-> u 永远都是大于0的到0了后直接编程了2^32 然后再不断的减到0接着继续死循环

//    int ss = -32;
//    unsigned int sss = ss;//注意: 带符号的转化成无符号的int
//    std::cout << sss << std::endl;
//    unsigned char x = (0x42 + 0xef) % 256;//x->1  也就是前面总和相加溢出 对256求mod
//    unsigned char x = 0x42 + 0xef;//  x->'1'
//    std::cout << x << std::endl;
    //int 默认是 signed 的
//    signed char xxx = 0x7f;//0x00~0x7f 为0~127正数 127＋1 --> －128
//    printf("%d\n", ++xxx);//10000000->符号位1为负 此时即为最小的负数  反而后期开始继续增加的话从-1~-127
    //可见int**_t就是一个对应bits的int值
//    printf("%d\n", sizeof(char *));//10000000->符号位1为负 此时即为最小的负数  反而后期开始继续增加的话从-1~-127
    //不同类型的整型 类型提升的话考虑的是从size.of()小的提升到size.of()大的,而实际中 带符号的整型范围小于不带符号的int
    //所以在此类类型比较的时候 会优先把带符号的signed int提升到 unsigned int来的
//    for (unsigned char i = 0; i < 255; i++) {
////        printf("overflow\n");//加到255的时候再加1又变成了0
//    }
//    signed int a = -127;
//    printf("%d\n", a);
//
//    unsigned int aa = a;
//    printf("%d\n", aa);
//
//    std::string str = "hello aaron";
//    printf("%d\n", str.length());
//    int res = 3.14;
//    printf("%d\n", res);
//
//
//    temp = 1000;
//    int j = temp;
//    printf("%d\n", j);
////    int ha;
////    std::cin >> ha;
////    printf("%d\n", ha);
//    //声明和定义的区别:
//    //声明只是做了规定变量的类型和名称 没有去申请内存
//    //而定义在做了变量的类型和名称的规定的同时还向内存申请了指定的内存空间给变量来存储数据
//    //变量只能定义一次  但是声明可以多次  毕竟一个变量内存空间确定下来的话 再去修改内存空间地址造成内存的浪费以及寻址的麻烦
////    extern int i = 10;//语法存错  使用了extern的话就不要初始化这个变量了 extern a val can't have an initial
////    printf("%d\n", i);
//
//    //复合类型
//    int ref = 10000;
//    int ref2 = ref;
//    int &refVal = ref;//这是在定义一个引用
//    printf("%d\n", refVal);//ref == refVal 可见
//    printf("%d\n", &refVal);//refValue实际用到的是ref的内存地址
//    printf("%d\n", &ref2);//而ref2本身用到的是ref的value而不适ref的内存地址
//    printf("%d\n", &ref);//  &ref == &refVal
//
//    ref = 20000;//改变的只是value 地址是没变动的
////    &refVal = ref2;//不可再次绑定  引用本身不是一个对象  所以引用本身也就不存在引用
//    printf("%d\n", refVal);//ref == refVal 可见
//    printf("%d\n", &refVal);
//    printf("%d\n", &ref);//引用只能绑定在一个对象上去 无法重新绑定到另外一个对象上去?

//    int &refref = 272;//为何&refref只能指向一个变量 而不能初始化一个int值呢?
//    printf("%s\n", "--------");
//
//    int reff = 1024;
//    int &reffVal = reff;
//    printf("%d\n", reffVal);
//    printf("%d\n", reff);
//    reffVal = 1;//这里把reff指向的内存空间地址里面的value改成了1  导致最后打印reff也受影响
//    printf("%d\n", &reffVal);//地址
//    printf("%d\n", reffVal);
//    printf("%d\n", reff);
//    //始终记住  引用类型本身就是copy了一份对象的内存空间地址 而引用类型去掉&符号就是对应内存空间里面的value了
//    double r2 = 0;
//    double &rr2 = r2;
//    rr2 = 3.1415926;
//    printf("%6d\n", r2);
//    printf("%6d\n", &r2);
//    printf("%6d\n", rr2);
//    printf("%6d\n", &rr2);
//
//    int i = 0, &i1 = i;
//    double d = 0, &d2 = d;
//    d2 = 3.1415;
//    d2 = i1;
//    i = d2;
//    i1 = d;
    //以上的赋值编译器都可以通过 只不过会造成数据丢失

//    int aaa, &aaai = aaa;
//    aaa = 10;
//    aaai = 20;
    //都是输出20  因为aaai改变了aaa内存地址指向的内存空间的value
//    std::cout << aaa << "~" << aaai << std::endl;
    //接下来就是了解指针跟引用类型区别在哪儿
    //指针和引用都可以提供间接访问到其他对象的能力
    //引用只能跟变量绑定在一起  一旦绑定  无法再次绑定其他的变量
//    int p = 1024;
//    int *pp = &p;//取出p的内存空间的地址赋给这个指针  指针本身是一个对象 而引用类型却不是一个对象 他只是一个对象 的alias 别名
//    int &refp = p;
//    *pp = 102;//在定下了指针对象指向的对象后去修改*pp指向的 value  实际上就是去修改了被指向的对象的value
//    printf("%d\n", refp);
//    printf("%d\n", &refp);
//    printf("%d\n", pp);//内存空间地址
//    printf("%d\n", *pp);//*pp就是取对应的地址下的value
//    p = 2048;
//    printf("%d\n", refp);
//    printf("%d\n", &refp);
//    printf("%d\n", pp);//内存空间地址
//    printf("%d\n", *pp);

//    printf("%6s\n", "-------");
//    int val = 42;
//    int *valp = &val;//取了地址
//    int &valref = val;
//    printf("%d\n", *valp);
//    //指针的本身就是一个指向内存空间地址的一个对象 通过*来取出内存地址里面的val
//    printf("%d\n", &valref);
//    printf("%d\n", valref);//引用的本身其实就是一个val 的别名  就像是int a 中的a一样,一个变量的别名,可以通过直接访问ref来获取到val
//    // 反而加上&就是取出了这val的内存空间地址值
//    int &valref2 = *valp;//*valp是取出指针对象指向的内存地址的val
//    printf("%d\n", valref2);
//    printf("%d\n", &valref2);
//    printf("%d\n", valp);
//    printf("%d\n", &*valp);//&(*valp)  &(42)
//    printf("%6s\n", "-------");
//
//    int ha = 4;
//    int *pss = &ha;
//    int &rref = ha;
//
//    printf("%d\n", ha);
//    printf("%d\n", rref);
//    printf("%d\n", *&rref);
//    printf("%d\n", pss);
//    printf("%d\n", *pss);
//    printf("%d\n", &*pss);
//    *pss = *pss * *pss;
//    printf("%d\n", *pss);
//    printf("%d\n", pss);//只是修改了val
////    int *temp = 1;//这样就不可以了
//    int *temp = 0;//这样就不可以了
//    printf("%d\n", temp);
//    printf("%d\n", *temp);//此处定义的是一个null指针  所以通过*来取汁取出来的是一个null
//    if (pss) {
//        printf("%10d\n", "if (pss) pass");
////        std::cout << "" << std::endl;
//    }
//    if (!*pss) {
//        printf("%s\n", "if (*pss) pass");
//    }

    //引用可能不占据内存  但是指针一定会占据内存
    //在访问指向的对象的值的时候,指针可是需要带上*来取val而引用却不需要带上&就可以访问到

//    printf("%d\n", &*(&valref));//&(*valp)  &(42)  *是一个解引用符

//    printf("%6s\n", "~~~~~~");
    //常量指针和普通指针的区别在于普通指针可以访问到所指向的val并修改它 但是常量指针只能访问到 却不可以修改val
    //常量指针的所指向的对象如果是一个const的话就不可以改动了
    //因此说 指针本身是不是常量和指针指向的对象是不是常量 这两个是独立的问题
//    int g = 21;
//    int *const ggp = &g;//这个是说ggp本身就是一个常量
//    int gg = 22;
//    const int *gp = &gg;//是说gp指向的对象gg是一个常量  这个gp的地址值都可以改变
//    int *ggpp = &gg;//类型不对

//    printf("%d\n", gp);
//    printf("%d\n", *ggp);
//    gg = 33;
//    printf("%d\n", *gp);
//    g = 23;
//    int gggg = 1023;
//    gp = &gggg;

//    printf("%d\n", *gp);//可见常量指针所指向的val对象如果是一个普通的对象  还是可以修改的
//    printf("%d\n", *ggp);
//    printf("%d\n", gp);

//    typedef char *pstring;
//    const pstring c = 0;//==>const *char c = 0;
    //const int *const pointer = 0;//这个pointer即是顶层const也是底层const
    //并非一个常量表达式
//    constexpr 可以用与检测一个表达式是否是一个合格的常量表达式
    //const int sz = get_size();//这个sz实际上不是一个常量 因为常量的含义是要在编译期就获取到了value而get_size()的返回值是在runtime才有的  所以互相矛盾了


    //总结: 基本类型溢出问题: 了解每个类型的上下限,在扩增value的时候注意是否会溢出
    //其次  注意 unsigned int类型数据到0了后如果再继续减下去导致回到2^32－1了 尤其在循环中  容易导致死循环
    //最后 关于基础类型数据进行数位操作的时候  类型的提升问题也需要考虑  规律就是范围小的往范围大的提升  也就是 signed -> unsigned
    //也就是会出现莫名其妙的if出现假的条件  所以给人的警示就是在整型溢出前一定要做检查
//    typedef int alias;
//    alias same = 10;
//    std::cout << same << std::endl;
//    int aaaa = 1;
////    decltype((aaaa)) xs = aaaa;
//    using Persion = person;//decltype(var) decltype((var))  var 为一个正数的时候  后者得到的永远都是一个引用 而引用的定义必须要初始化
//    Persion persion = persion.__construct();
//    std::cout << persion.age + "~" + persion.name << std::endl;

    int tr;
    string *pa, arr[] = {"he", "ha", "xi", "ga", "hou"};
    pa = arr;
    for (int tr = 0; tr < 5; ++tr) {
        printf("%d\n", pa);
        pa++;//此时的pa指针代表的就是一个int数组//如果修改成为了一个string对象的话  那么pa++递增的值就是string所占据的长度了
    }

//    const string *pas = arr;
    int te = 10, he = 100;
    int const *tep = &te;
    tep = &he;//通过
    int *const tepp = &te;//这个常量指针表明tepp的内存地址已经固定了
//    *tep = 5;//添加了const后导致指针不可以修改指向的变量的val
    printf("%d\n", &te);
    printf("%d\n", tep);
    printf("%d\n", tepp);
    printf("%10s\n", "~~~~~~~~~~~~~");
    int ttee = 101;

    //总结:  const int *a1 <--> int *const a2的区别
    //const修饰的是整个*a1 所以说*a1是一个常量  也就是说*a1的值是一个定值 所以如果想再次通过*a1来修改val的话无法编译通过,
    // 但是a1本身又是一个变量,也就是说它的内存地址是可以改变的，所以一旦内存地址改变*a1的值也跟着改变 需要绕着来改变value
    //而用*const来修饰a2的话 a2的内存地址给定为了常量 也就是无法修改任何属性了  很适合用来作为数组的首位指针.
    tep = &ttee;
//    tepp = &ttee;
    printf("%d\n", &te);
    printf("%d\n", tep);
    printf("%d\n", tepp);

    const int a = 1000;
    const int *addr = &a;//*addr修饰的是常量

    printf("%d\n", addr);
    printf("%d\n", *addr);

    addr = &te;
    printf("%d\n", addr);
    printf("%d\n", *addr);

    string s("Hello,World");
    for (char c:s) {
        cout << c << endl;
    }

    for (auto &c:s) {
//        cout << c = 'a') << endl;
        c = 'a';//因为访问的是每一个char的地址值 所以会影响到string的val
    }
    cout << s << endl;
    return 0;
}