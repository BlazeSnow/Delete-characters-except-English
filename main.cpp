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
		//删除省略号
		{'.', '.', '.'},
		{'.', '.', '.', '.', '.', '.'},
};

static vector<char> characters;

void compare_extra_words() {
	for (auto i = characters.begin(); i != characters.end(); i++) {
		int count = 0;
		for (const auto &words: words_delete) {
			auto it = i;
			for (auto j: words) {
				if (*it == j) {
					++it;
					++count;
				}
			}
			if (count == words.size()) {
				characters.erase(i, it);
			}
			count = 0;
		}
	}
}

void compare_delete_parenthesis() {
	for (auto i = characters.begin(); i != characters.end(); i++) {
		if (*i == '(') {
			for (auto it = i; it != characters.end(); it++) {
				if (*it == ')') {
					characters.erase(i, it + 1);
					break;
				}
			}
		}
	}
}

int main() {
	system("chcp 65001");
	cout << "Copyright (C) 2024 BlazeSnow.保留所有权利。" << endl;
	cout << "本程序以GNU General Public License v3.0的条款发布。" << endl;
	cout << "当前程序版本号：v1.3.0" << endl;
	cout << "https://github.com/BlazeSnow/Delete-characters-except-English" << endl << endl;
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
				if (('a' <= temp && temp <= 'z') || ('A' <= temp && temp <= 'Z') || temp == '.'
				    || temp == ' ' || temp == '\n' || temp == '(' || temp == ')') {
					//正常收集
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
			//删除特殊词
			compare_extra_words();
			compare_delete_parenthesis();
			//写入answer
			for (const auto &i: characters) {
				answer.push_back(i);
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