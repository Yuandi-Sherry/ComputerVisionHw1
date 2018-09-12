# 计算机视觉第一次作业实验报告

## 实验环境

Windows10+minGW32

**运行命令：**mingw32-make (options)

**options:**

1. question1 - 编译运行对应第一个问题的代码
2. question2~5 - 同1，以此类推
3. test - 编译运行测试代码

## 实验内容

1. 读入`1.bmp`文件，并用 文件，并用`CImg. display()`显示 。

2. 把 `1.bmp`文件的白色区域变成红色，黑色区域变成绿色。
3. 在图上绘制一个圆形区域，圆心坐标(50,50)，半径为 30，填充颜色为蓝色。
4. 在图上绘制一个圆形区域，圆心坐标 (50,50)，半径为3，填充颜色为黄色。
5. 在图上绘制一条长为 100 的直线 段，起点坐标为 起点坐标为 (0, 0)，方向角为 35 度，直线的颜色为蓝色。
6. 把上面的操作结果保存为`2. bmp`。

## 实验结果

### Step1

![1536744819719](C:\Users\Sherry\AppData\Roaming\Typora\typora-user-images\1536744819719.png)

### Step2

![1536744840466](C:\Users\Sherry\AppData\Roaming\Typora\typora-user-images\1536744840466.png)

### Step3

#### 不调用Library实现

![1536744908186](C:\Users\Sherry\AppData\Roaming\Typora\typora-user-images\1536744908186.png)

#### 调用Library实现

![1536744963412](C:\Users\Sherry\AppData\Roaming\Typora\typora-user-images\1536744963412.png)

### Step4

#### 不调用Library实现

![1536745028531](C:\Users\Sherry\AppData\Roaming\Typora\typora-user-images\1536745028531.png)

#### 调用Library实现

![1536745065598](C:\Users\Sherry\AppData\Roaming\Typora\typora-user-images\1536745065598.png)

### Step5

#### 不调用Library实现

![1536745088069](C:\Users\Sherry\AppData\Roaming\Typora\typora-user-images\1536745088069.png)

#### 调用Library实现

![1536745187338](C:\Users\Sherry\AppData\Roaming\Typora\typora-user-images\1536745187338.png)

### Step6

`2.bmp`

![1536745612028](C:\Users\Sherry\AppData\Roaming\Typora\typora-user-images\1536745612028.png)

## 测试数据以及分析

测试代码`test.cpp`中我采用了遍历手工和调用库两种方式实现的画圆和画直线生成的图片进行相关像素的比对和计数。与调用库函数生成的图片不一致的像素个数越多越说明手工实现的算法存在问题。

测试结果如下：

![1536745997169](C:\Users\Sherry\AppData\Roaming\Typora\typora-user-images\1536745997169.png)

### 第三步、第四步调用CImg函数与手动实现的比较

两个画圆的步骤我采用了相同的代码：

```cpp
if((i-x)*(i-x)+(j-y)*(j-y) <= R*R) 
```

​	其中(x,y)为圆心坐标，R为圆半径。

​	发现随着圆半径的增加与库函数结果的不同的像素点数目增多，但相比于采样面积，越大的圆形像素点错误的占比实则越低。

-----

​	为提高圆的质量，查阅资料了解了计算机图形学的中点圆做法，总体思路大约为从圆正上方一点向x,y轴增加的方向填充出一个圆心角为45°的扇形，之后采用三重对称（关于水平方向、竖直方向以及斜45°方向）对其进行轴对称操作。

​	但却发现，结果与CImg的库函数中所实现的圆去之甚远。

![1536760048464](C:\Users\Sherry\AppData\Roaming\Typora\typora-user-images\1536760048464.png)

​	中点圆算法在Solution中使用`MPCircle`实现了，并在`Question3Manual`和`Question4Manual`中对中点圆方法的调用写在了注释中。

### 第五步调用CImg函数与手动实现的比较

​	直线的实现调节了很多次参数，第一次直接用两直角边比和tan做等值比较，导致了直线只有间断的点；将填充范围的判断从等值变为了±0.1的范围后，又会画出一个扇形。考虑到坐标值越大、其比值会与tan35°越接近，因而采用了上下浮动范围和坐标大小成反比的估计方式。略微调节了参数得到如下填充标准：

```cpp
if((double)j/i < tan(35.0/180.0*pi)+0.5/i
   && (double)j/i > tan(35.0/180.0*pi)-0.5/i 
   && i*i+j*j <= 10000) 
```