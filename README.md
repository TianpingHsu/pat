# PAT
prepare for pat exam

## [1003 Emergency](https://pintia.cn/problem-sets/994805342720868352/problems/994805523835109376)
这是一个普通的最短路径算法，注意点如下：
* 这是一个无向图，所有注意`g[i][j]`和`g[j][i]`是相同的
* 需要熟练掌握dijkstra最短路径算法
* 路径权重相同时，注意其他权重


## [1018 Public Bike Management](https://pintia.cn/problem-sets/994805342720868352/problems/994805489282433024)
同样是最短路径算法，但是需要保存所有的最短路径，然后遍历所有路径，选择满足题意要求的
网上给出的算法是先使用最短路径算法构造前驱子图，然后使用dfs来遍历前驱子图，可以参考[这个](https://www.liuchuo.net/archives/2373)
本质是一样的，因为保存所有最短路径的过程就是递归的，就是dfs
真正重要的是理解递归



