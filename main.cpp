//Copyright (C) 2024 BlazeSnow
//保留所有权利
//本程序以GNU General Public License v3.0的条款发布
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

using namespace std;

const vector<vector<char>> words_delete = {
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

int compare_extra_words(const vector<char> &temp) {
	for (const auto &i: words_delete) {
		if (i == temp) {
			return 1;
		}
	}
	return 0;
}

int main() {
	system("chcp 65001");
	cout << "Copyright (C) 2024 BlazeSnow.保留所有权利。" << endl;
	cout << "本程序以GNU General Public License v3.0的条款发布。" << endl;
	cout << "当前程序版本号：v1.2.0" << endl;
	cout << "https://github.com/BlazeSnow/Delete-characters-except-English" << endl << endl;
	vector<char> characters;
	vector<vector<char>> words;
	vector<char> answer;
	int choose;
	cout << "需要生成全新txt文件(0)还是处理现有txt文件(1)：" << endl;
	cin >> choose;
	if (choose == 0) {
		fstream file("Delete-characters-except-English.txt", ios::out);
		if (file.is_open()) {
			file.close();
			cout << "已生成全新\"Delete-characters-except-English.txt\"文件" << endl;
			cout << "路径为：" << filesystem::current_path() << endl;
			system("pause");
		} else {
			cout << "ERROR:生成文件失败" << endl;
			system("pause");
		}
	} else if (choose == 1) {
		fstream file("Delete-characters-except-English.txt", ios::in);
		if (file.is_open()) {
			//输入文件内容
			while (true) {
				char temp;
				file >> noskipws >> temp;
				if (('a' <= temp && temp <= 'z') || ('A' <= temp && temp <= 'Z') || temp == '.' || temp == ' ' ||
				    temp == '\n') {
					characters.push_back(temp);
				} else {
					characters.push_back(' ');
				}
				if (file.eof()) {
					break;
				}
			}
			file.close();
			cout << "文件读取完毕" << endl;
			vector<char> tempWords;
			for (auto i: characters) {
				if (i == ' ' || i == '\n' || i == '.') {
					//插入符号
					tempWords.push_back(i);
					//推送字符
					words.push_back(tempWords);
					//清除暂用字符串
					tempWords.clear();
				} else {
					tempWords.push_back(i);
				}
			}
			//删除特殊词
			for (auto &i: words) {
				if (compare_extra_words(i) == 1) {
					i.clear();
				}
			}
			//写入answer
			for (const auto &i: words) {
				for (auto j: i) {
					answer.push_back(j);
				}
			}
			//写入新文件
			fstream file1("ANSWER-Delete-characters-except-English.txt", ios::out);
			for (auto i: answer) {
				file1 << i;
			}
			cout << "处理后内容已写入\"ANSWER-Delete-characters-except-English.txt\"文件" << endl;
			cout << "路径为：" << filesystem::current_path() << endl;
			system("pause");
		} else {
			cout << "ERROR:读取文件失败" << endl;
			system("pause");
		}
	} else {
		cout << "ERROR:输入内容不合法" << endl;
		system("pause");
	}
	return 0;
}