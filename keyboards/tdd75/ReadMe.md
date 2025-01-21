## 常用指令

```bash
# 编译
qmk compile -kb tdd75 -km default
# 转换 c 文件
qmk json2c tdd75/tdd75_tdd75_tdd75_mine.json
# 转换 json 文件
qmk c2json -km default -kb tdd75
# 格式化 c 文件
qmk format-c tdd75/keymaps/default/keymap.c
```