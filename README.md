# PAT
prepare for pat exam

## [1003 Emergency](https://pintia.cn/problem-sets/994805342720868352/problems/994805523835109376)
这是一个普通的最短路径算法，注意点如下：
* 这是一个无向图，所有注意`g[i][j]`和`g[j][i]`是相同的
* 需要熟练掌握dijkstra最短路径算法
* 路径权重相同时，注意其他权重

## [**1004 Counting Leaves**](https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184)

dfs计算每个节点所在的深度，然后计算每一层众叶子节点的个数即可

## [**1010 Radix**](https://pintia.cn/problem-sets/994805342720868352/problems/994805507225665536)

1. 转换的时候注意使用long long 类型
2. 转换的结果有可能是溢出的
3. 需要使用二分查找，否则会有超时用例

[这个答案](https://www.liuchuo.net/archives/2458)非常清楚，关于转换的方法，我的代码会更清楚




## [1018 Public Bike Management](https://pintia.cn/problem-sets/994805342720868352/problems/994805489282433024)
同样是最短路径算法，但是需要保存所有的最短路径，然后遍历所有路径，选择满足题意要求的
网上给出的算法是先使用最短路径算法构造前驱子图，然后使用dfs来遍历前驱子图，可以参考[这个](https://www.liuchuo.net/archives/2373)
本质是一样的，因为保存所有最短路径的过程就是递归的，就是dfs
真正重要的是理解递归

## [**1036 Boys vs Girls** ](https://pintia.cn/problem-sets/994805342720868352/problems/994805453203030016)

怎么说，就怎么做

## [**1042 Shuffling Machine** ](https://pintia.cn/problem-sets/994805342720868352/problems/994805442671132672)

看柳神答案https://www.liuchuo.net/archives/2019

## [**1046 Shortest Distance**](https://pintia.cn/problem-sets/994805342720868352/problems/994805435700199424)

此题就是怎么说，那就怎么做，使用一个累积数组，如果对每一个查询都直接处理的话，看题目数据量可能会超时



## [**1069 The Black Hole of Numbers**](https://pintia.cn/problem-sets/994805342720868352/problems/994805400954585088)

easy，看柳神答案https://www.liuchuo.net/archives/2468

## [**1074 Reversing Linked List**](https://pintia.cn/problem-sets/994805342720868352/problems/994805394512134144)

这题有点搞笑，输入的节点并不全是有用的，但是单纯看题目并不能发现这个

反转链表也难到我了

## [**1077 Kuchiguse**](https://pintia.cn/problem-sets/994805342720868352/problems/994805390896644096)

没什么难度，看柳神答案https://www.liuchuo.net/archives/2065

可以了解一下std::string, substr, find

## [**1084 Broken Keyboard**](https://pintia.cn/problem-sets/994805342720868352/problems/994805382902300672)

没有难度，看柳神的答案https://www.liuchuo.net/archives/452

## [**1104 Sum of Number Segments**](https://pintia.cn/problem-sets/994805342720868352/problems/994805363914686464)

服气，没过的这个点，查看[这个说明](https://www.liuchuo.net/archives/1921)

PAT网站上已经注明修改，为什么不提示一下呢。

## [**1105 Spiral Matrix**](https://pintia.cn/problem-sets/994805342720868352/problems/994805363117768704)

这道题需要非常注意一下，特别是x,y，行列顺序需要处理正确，我们认为向下是x轴，向右是y轴，这样方便我们访问matrix

[柳神的一个参考答案](https://www.liuchuo.net/archives/2073) 我觉得我的代码非常清楚，比较容易看懂

## [1110 Complete Binary Tree](https://pintia.cn/problem-sets/994805342720868352/problems/994805359372255232)

这道题需要注意一下输入，因为可能是char类型，也可能是int类型

关于int转换为string，string转换为int，可以参考[这个](https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c)，stoi和std::to_string

当然如果临时忘记，也可以自己手动写

网上的[这个参考答案]()https://www.liuchuo.net/archives/2158是有问题的，可能会段错误，想象一个全是右子树形成的线性链表

对于树的题目，需要熟练使用heap数据结构



## [**1113 Integer Set Partition**](https://pintia.cn/problem-sets/994805342720868352/problems/994805357258326016)

怎么说，怎么做



## [**1115 Counting Nodes in a BST**](https://pintia.cn/problem-sets/994805342720868352/problems/994805355987451904)

本题非常简单；

把BST相关内容再看一下，也看一下AVL Tree

## [**1116 Come on! Let's C** ](https://pintia.cn/problem-sets/994805342720868352/problems/994805355358306304)

怎么说，怎么做



## [**1117 Eddington Number**](https://pintia.cn/problem-sets/994805342720868352/problems/994805354762715136)

>  *E* -- that is, the maximum integer *E* such that it is for *E* days that one rides more than *E* miles.

把上面这句话再理解一遍：

1. 在E天中，每天都骑行超过E英里
2. 满足条件1的数字可能有很多，我们需要找出最大的那一个

看一下题目给的示例：

>10
>6 7 6 9 3 10 8 2 7 8

这样看会更加清楚一些:

| day   | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 10   |
| ----- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| miles | 10   | 9    | 8    | 8    | 7    | 7    | 6    | 6    | 3    | 2    |

我们不妨随便取一个天数E，就取E为5吧，那么我们先看一下条件1是否满足：

在5天中，每天骑行都超过5英里的(>=6)，明显1,2,3,4,5这5天能够满足条件；

试探性的，我们不妨再取E=6,我们再看一下条件1是否满足：

在6天中，每天骑行都超过6英里的(>=7)，明显1,2,3,4,5,6满足

再尝试一下，取E=7呢，我们看一下条件1：

在7天中，每天骑行都超过7英里的(>=8)，明显有1,2,3,4这4天，但是只有4天，而不是7天，所以不符合

显然，这是我们可以确认，E应该为6



## [**1120 Friend Numbers**](https://pintia.cn/problem-sets/994805342720868352/problems/994805352925609984)

题目怎么说，就怎么做；

但是感觉题目还是多少有点问题的，`friend num`应该是至少两个数才共享的概念，像实例中的12,其实就是一个数，应该不正确；但是我们不管这个哈，首先把分数得到，然后知道这个可能有问题就行了；

## [**1121 Damn Single**](https://pintia.cn/problem-sets/994805342720868352/problems/994805352359378944)

这里注意一下输出是"%05d"即可

## [**1128 N Queens Puzzle** ](**1128 N Queens Puzzle** )

怎么说，就怎么做

## [**1130 Infix Expression** ](https://pintia.cn/problem-sets/994805342720868352/problems/994805347921805312)

有几个注意点：

* 根节点需要自己找
* 使用中序遍历的时候，注意叶子节点不要加左右括号
* 注意节点只有一个的时候的输出是否正确

考点就是树的中序遍历，当然本质还是递归

## [**1132 Cut Integer**](https://pintia.cn/problem-sets/994805342720868352/problems/994805347145859072)

考点：

* 数位分割
* 将分割后的数位再转换成数字
* 注意除0异常

## [**1138 Postorder Traversal**](https://pintia.cn/problem-sets/994805342720868352/problems/994805345078067200)

根据前序遍历和中序遍历重建二叉树

二叉树相关的基本就是4种遍历方式，当然本质还是递归，凡是和树相关的都是送分题

## [**1141 PAT Ranking of Institutions**](https://pintia.cn/problem-sets/994805342720868352/problems/994805344222429184)

常规题目，多关键字排序，主要就是调用std::sort，注意第三个参数，我的代码中用的匿名函数比较简洁；

凡是这种的都是送分题，务必要看清题目，做对做快

## [**1144 The Missing Number**](https://pintia.cn/problem-sets/994805342720868352/problems/994805343463260160)

怎么说，就怎么做；

将非正数过滤掉，然后对剩下的数字进行排序，接着找出第一个下标和该位置上的元素不相等的下标即可

注意输入可能有重复的数字，也需要过滤掉



## [**1146 Topological Order**](https://pintia.cn/problem-sets/994805342720868352/problems/994805343043829760)

拓扑排序；

一般有两种方法：

* 使用队列进行模拟，每次将入度为0的节点推入队列，并将邻接节点的入度减一，知道所有节点全部入队
* 使用dfs，有一个命题是：在有向无环图中，深度优先搜索该图，得到的逆后序就是该图的一个拓扑排序

## [**1147 Heaps**](https://pintia.cn/problem-sets/994805342720868352/problems/994805342821531648)

堆的使用
