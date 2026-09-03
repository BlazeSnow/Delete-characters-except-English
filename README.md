# 背单词删中文

1. 本程序将含有英文单词与中文解释的txt文件转化为仅含英文单词的txt文件
2. 第一次使用请生成新文件"DCEE.txt"，将需处理内容复制进文件后处理
3. 程序的输出文件为"ANSWER-DCEE.txt"
4. 程序将删除英文括号及括号内内容
5. 程序将删除表示单词类型的缩写

|       |         Full          |    Short    |       |         Full          |   Short    |
| :---: | :-------------------: | :---------: | :---: | :-------------------: | :--------: |
|   1   |         Noun          |     n.      |   2   |        Pronoun        |   pron.    |
|   3   |        Article        |    art.     |   4   |        Numeral        |    num.    |
|   5   |       Adjective       |    adj.     |   6   |        Adverb         |    adv.    |
|   7   |         Verb          |     v.      |   8   |      Conjunction      |   conj.    |
|   9   |      Preposition      |    prep.    |  10   |     Interjection      |    int.    |
|  11   |     Abbreviation      |    abbr.    |  12   |    Transitive Verb    |    vt.     |
|  13   |   Intransitive Verb   |     vi.     |  14   |      Determiner       |    det.    |
|  15   |      Quantifier       |   quant.    |  16   |    Auxiliary Verb     |    aux.    |
|  17   |      Modal Verb       |   modal.    |  18   |        Gerund         |    ger.    |
|  19   |      Infinitive       |    inf.     |  20   |      Participle       |   part.    |
|  21   |   Reflexive Pronoun   | refl. pron. |  22   | Demonstrative Pronoun | dem. pron. |
|  23   |  Possessive Pronoun   | poss. pron. |  24   |   Relative Pronoun    | rel. pron. |
|  25   | Interrogative Pronoun | int. pron.  |  26   |      Proper Noun      |  prop. n.  |
|  27   |    Collective Noun    |  coll. n.   |  28   |     Abstract Noun     |  abs. n.   |
|  29   |     Concrete Noun     |  conc. n.   |       |                       |            |

## 如何下载？

前往 [GitHub Release](https://github.com/BlazeSnow/Delete-characters-except-English/releases/latest) 下载对应系统的可执行文件。

文件命名格式为 `Delete-characters-except-English-<版本>-<系统>-<架构>`，各平台对应关系如下：

| 文件名后缀           | 适用平台               |
| -------------------- | ---------------------- |
| `-windows-x64.exe`   | Windows x64            |
| `-windows-arm64.exe` | Windows ARM64          |
| `-linux-x64`         | Linux x64              |
| `-linux-arm64`       | Linux ARM64            |
| `-macos-x64`         | macOS（Intel）         |
| `-macos-arm64`       | macOS（Apple Silicon） |

## Linux / macOS 额外处理

```sh
sudo chmod +x <可执行文件>
```

## 更新日志

见 [CHANGELOG.md](./CHANGELOG.md)

## 许可证

[MIT](./LICENSE)
