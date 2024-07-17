//Copyright (C) 2024 BlazeSnow
//保留所有权利
//本程序以GNU General Public License v3.0的条款发布
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

using namespace std;

int compare_extra_words(const vector<char> &temp) {
	const vector<char> words_n = {'n', '.'};
	const vector<char> words_pron = {'p', 'r', 'o', 'n', '.'};
	const vector<char> words_art = {'a', 'r', 't', '.'};
	const vector<char> words_num = {'n', 'u', 'm', '.'};
	const vector<char> words_adj = {'a', 'd', 'j', '.'};
	const vector<char> words_adv = {'a', 'd', 'v', '.'};
	const vector<char> words_v = {'v', '.'};
	const vector<char> words_conj = {'c', 'o', 'n', 'j', '.'};
	const vector<char> words_prep = {'p', 'r', 'e', 'p', '.'};
	const vector<char> words_int = {'i', 'n', 't', '.'};
	if (temp == words_n || temp == words_pron || temp == words_art || temp == words_num || temp == words_adj ||
	    temp == words_adv || temp == words_v || temp == words_conj || temp == words_prep || temp == words_int) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	system("chcp 65001");
	cout << "Copyright (C) 2024 BlazeSnow.保留所有权利。" << endl;
	cout << "本程序以GNU General Public License v3.0的条款发布。" << endl;
	cout << "https://github.com/BlazeSnow/Delete-characters-except-English" << endl << endl;
	cout << "当前程序版本号：v1.1.0" << endl;
	vector<char> characters;
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
		}
	} else if (choose == 1) {
		fstream file("Delete-characters-except-English.txt", ios::in);
		if (file.is_open()) {
			//输入文件内容
			while (true) {
				char temp;
				file >> noskipws >> temp;
				if (('a' <= temp && temp <= 'z') || ('A' <= temp && temp <= 'Z') || temp == '.' || temp == ' ' ||
				    temp == ',' || temp == '\n' || temp == '(' || temp == ')') {
					characters.push_back(temp);
				}
				if (file.eof()) {
					break;
				}
			}
			file.close();
			cout << "文件读取完毕" << endl;
			vector<char> tempWords;
			for (auto i: characters) {
				if (i == ' ' || i == '\n' || i == ',' || i == '(' || i == ')') {
					for (auto j: tempWords) {
						answer.push_back(j);
					}
					answer.push_back(i);
					tempWords.clear();
				} else {
					tempWords.push_back(i);
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