#### 摘要
这是对横版过关游戏的机制要素讨论，从引擎到素材，游戏机制去讨论怎么做一款游戏。但是这并没有需要的游戏素材，为了阅读和参考方便，会有对应的样例代码。

    关键词：AI,攻击,碰撞,素材,机制,移动,,,
    
游戏的设计往往是众多元素调和的结果，所以从一些简单的问题来认识游戏会更加容易。
这些问题可能不局限于游戏本身，也顺带有一些对GUI的困惑。

    制作游戏怎么才能打开一个窗口来显示内容？
    
    窗口的分辨率是如何调整的？
    
    什么样的数据结构可以承载游戏资源并承担游戏逻辑？
        例：这个数据结构必须能既保存多媒体资源内容又兼顾物理碰撞这样的功能
        答：使用数组来存放画面中所有的元素，这样移动，碰撞的检测就可以基于遍历数组
        
#### 依赖
Windows 10 
VS 2017
EasyX for 2017版本

#### 如何阅读？
这些代码的编写没有遵守特定的编程风格，实际上有一些函数式编程的倾向。如果输入阅读某个部分的特定实现，应该优先查看数据流图或者可能的关系结构图，这样会使阅读的逻辑更加清晰。
整个游戏被以功能分割为不同的几个源文件，分别编译后再重新组合成程序。这里需要注意的是，extern关键字是用来说明该变量是外部声明的，防止重复声明。而如果使用include的方法在多个文件中引入同一个全局变量声明文件，会导致重复声明。


#### 当在讨论游戏Bug时我们在讨论什么?
游戏的编写和编写操作系统不同，当操作系统出现逻辑错误时甚至会导致硬盘格式化等严重错误。 游戏的Bug会导致一些看起来“不合逻辑”的游戏动作发生。例如角色无法正常死亡，或者从不正常的位置移动。

#### 游戏的本质问题
当制作游戏时，需要考虑游戏的**视角**，这是一个抽象概念，即当人物移动时画面是如何展现动态效果的。

#### 代码注释
代码是以阅读的约定写的。并不可以编译。例如头文件的引入是单纯的描述依赖关系的。

全局参数声明了游戏中的各个参数，各个功能则对参数初始化后执行游戏逻辑和渲染。
固定炮塔，没有AI设定。
一击即死，没有生命设定。

#### 写在最后
**这游戏怎么玩？**
移动 WASD  跳下左右 
跳跃 W 
技能 E     时间变慢
冲刺 鼠标右键