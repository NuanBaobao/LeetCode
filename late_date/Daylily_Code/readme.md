## 内置函数inline详解

### 1.使用场景

- 函数是频繁调用,用来压缩时间开销

- 缺点：
   - 压缩了时间但是增加了目标程序的长度,适合将规模很小(5个语句一下)并且频繁使用的函数(如采集数据的函数)声明为内置函数
   - 内置函数中不能包括复杂的控制语句,如循环语句何switch语句

### 2.使用方法

- 可在函数声明和定义时在函数首行左端加关键字**inline**
  ```c++
  // 函数声明
  inline void add_edge(int u, int v, int w); // 内置函数inline,频繁使用添加边的信息

  int main(void)
  {
      return 0;
  }

  // 添加边的信息
  void add_edge(int u, int v, int w){Matrix_Graph[u][v] = w;
  }
  ```