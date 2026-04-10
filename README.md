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

注意: `sweat_rag` 中间的空格用下划线代替了, 用空格则会出问题.

##	编译方法

```txt
g++-16 -o main -x main.cpp -std=c++26 -O2 -fcontract-evaluation-semantic=quick_enforce
```

##	关于复习功能

我个人喜欢完整复习一遍之前背过的单词, 所以没有给 `rev.md` 删除任何东西.

不过如果你写了个新版本能结合遗忘曲线或者直接删除掉复习时能一遍过的单词, 那也非常棒, 开源社区就需要你这样的人才.
