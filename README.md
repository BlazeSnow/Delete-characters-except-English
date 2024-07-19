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

## v1.3.2

2024年7月19日17点23分

- 修复了创建输出文件后指针未及时销毁的问题
- 添加了创建输出文件失败的提示

## v1.3.1

2024年7月19日17点08分

- 程序现在将清空空行
	- 先清空双倍空格
	- 然后删除双倍回车的其中一个

## v1.3.0

2024年7月19日16点57分

- 程序现在将删除括号包括的所有内容（包括括号）
- 程序现在将删除双数个空格
- 优化了删除特殊词的算法
- 优化了删除括号的算法
- 修复了程序开头的版本提示语言错位问题

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
