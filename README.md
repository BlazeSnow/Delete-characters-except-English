# 写在最前

1. 本程序用于删除除了英文和空格的字符
2. 第一次使用请生成新文件，将需处理内容复制进新文件后处理文件
3. 程序将删除英文括号及括号内内容
4. 程序将删除表示单词类型的缩写

|    |         Full          |    Short    |    |         Full          |   Short    |
|:--:|:---------------------:|:-----------:|:--:|:---------------------:|:----------:|
| 1  |         Noun          |     n.      | 2  |        Pronoun        |   pron.    |
| 3  |        Article        |    art.     | 4  |        Numeral        |    num.    |
| 5  |       Adjective       |    adj.     | 6  |        Adverb         |    adv.    |
| 7  |         Verb          |     v.      | 8  |      Conjunction      |   conj.    |
| 9  |      Preposition      |    prep.    | 10 |     Interjection      |    int.    |
| 11 |     Abbreviation      |    abbr.    | 12 |    Transitive Verb    |    vt.     |
| 13 |   Intransitive Verb   |     vi.     | 14 |      Determiner       |    det.    |
| 15 |      Quantifier       |   quant.    | 16 |    Auxiliary Verb     |    aux.    |
| 17 |      Modal Verb       |   modal.    | 18 |        Gerund         |    ger.    |
| 19 |      Infinitive       |    inf.     | 20 |      Participle       |   part.    |
| 21 |   Reflexive Pronoun   | refl. pron. | 22 | Demonstrative Pronoun | dem. pron. |
| 23 |  Possessive Pronoun   | poss. pron. | 24 |   Relative Pronoun    | rel. pron. |
| 25 | Interrogative Pronoun | int. pron.  | 26 |      Proper Noun      |  prop. n.  |
| 27 |    Collective Noun    |  coll. n.   | 28 |     Abstract Noun     |  abs. n.   |
| 29 |     Concrete Noun     |  conc. n.   |    |                       |            |

# 更新日志

## v1.3.3

2024年7月19日20点58分

- 扩充了英语词性缩写，从13种增加到29种

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
