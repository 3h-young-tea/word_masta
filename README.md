#	word_masta

依赖 [`unda::word`](https://github.com/3h-young-tea/purple) 所以使用了相同的 agplv3.

请把要背的单词以

```txt
skateboard 滑板
sweat_rag 头巾
mic 麦克风
freestyle 自由式
```

的格式放在 `./sql/need.md` 里就能使用了.

注意: `sweat_rag` 中间的空格用下划线代替了, 否则会出问题.

##	编译方法

```txt
g++-16 -o main -x main.cpp -std=c++26 -O2 -fcontract-evaluation-semantic=quick_enforce
```
