Consider a pointer to void, named ptr, which has been set to point to a floating point variable g. Which choice is a valid way to dereference ptr to assign its pointed value to a float variable f later in the program?

    float g;
    void *ptr=&g;

```
A. float f=(float *)ptr;
B. float f=(float)*ptr;
C. float f=*(float)ptr;
D. float f=*(float *)ptr;
```
就是问如何取得指针指向变量的值
- dereference：间接引用
- assign: 赋值

计算优先级从右向左，以C选项为例，先执行(float)，再执行*

答案：B

---

What's the meaning of the three sections specified between parentheses in a for loop, separated by semicolons?
```
A. The first is the iterating variable name,the second is the starting value for the iterating variable, and the third is the stop value(the last value plus one).
B. The first is the initialization block, the second is the condition to iterate, and the third is the increment block.
C. The first is the iterating variable, the second is the container in which it should operate, and the third is an exit condition to abort at any time.
D. The first is the iterating variable name, the second is the number of times to iterate and the third is the desired increment or decrement(specified with a signed integer).
```
问用分号分隔的for循环中括号之间指定的三个部分的含义是什么？
a. 第一个是迭代变量名，第二个是迭代变量的起始值，第三个是停止值（最后一个值加一个）。
b. 第一个是初始化块，第二个是迭代的条件，第三个是增量块。
C. 第一个是迭代变量，第二个是它应该操作的容器，第三个是随时中止的退出条件。
D. 第一个是迭代变量名，第二个是迭代的次数，第三个是所需的增量或递减（用有符号整数指定）。
- iterating：迭代
- parentheses：括号
- semicolons：分号
- desired：希望

答案：B

----

What is the name for calling a function inside the same function?

A. inner call
B. recursion
C. subfunction
D. infinite loop

- recursion: 递归
- infinite: 无限

答案：A

---

Consider a class named ComplexNumber. Which code will result in an equivalent object?

ComplexNumber(float real, float im)
: real_part(real),
 im_part(im){}

- ComplexNumber(float real, float im) {
    this->real_part = real;
    this->im_part = im;
}
- ComplexNumber(float real, float im) {
    this->real = real_part;
    this->im = im_part;
}

考察构造函数初始化变量的方法，参考《C++编程思想》第1卷P255
- equivalent：相等、对等、相当

答案：A

