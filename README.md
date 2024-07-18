# 写在最前

1. 本程序用于删除除了英文和空格的字符
2. 第一次使用请生成新文件，将需处理内容复制进新文件后处理文件
3. 程序将删除表示单词类型的缩写

```c++
{
		//英语单词类型常用缩写
		{'n', '.'},
		{'p', 'r', 'o', 'n', '.'},
		{'a', 'r', 't', '.'},
		{'n', 'u', 'm', '.'},
		{'a', 'd', 'j', '.'},
		{'a', 'd', 'v', '.'},
		{'v', '.'},
		{'c', 'o', 'n', 'j', '.'},
		{'p', 'r', 'e', 'p', '.'},
		{'i', 'n', 't', '.'},
		//自定义
		{'a', 'b', 'b', 'r', '.'},
		{'v', 't', '.'},
		{'v', 'i', '.'},
};
```

# 更新日志

## v1.2.0

2024年7月18日17点11分

- 程序现在不再对括号进行处理
- 程序现在把要删除的其他字符编写为空格
- 现在将删除表示单词类型的缩写

## v1.1.0

2024年7月17日21点25分

- 程序现在将对括号进行处理
- 现在将保留```.```、```()```

## v1.0.1

2024年7月17日18点08分

- 读取文件时现在将保留回车

## v1.0.0

2024年7月17日18点01分

- 发布了第一个release
