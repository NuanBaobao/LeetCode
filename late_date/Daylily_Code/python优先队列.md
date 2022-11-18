# Python优先队列

## 1.简单优先队列

```python
from queue import PriorityQueue 

pQueue = PriorityQueue()

# 简单对象
for i in range(-1,5):
    pQueue.put(i)

# 元组对象
pQueue.put((1,4))
pQueue.put((-2,5))

while not pQueue.empty():
    print(pQueue.get())
```



