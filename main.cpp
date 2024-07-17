//Copyright (C) 2024 BlazeSnow
//保留所有权利
//本程序以GNU General Public License v3.0的条款发布
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

using namespace std;

int main() {
	system("chcp 65001");
	cout << "Copyright (C) 2024 BlazeSnow.保留所有权利。" << endl;
	cout << "本程序以GNU General Public License v3.0的条款发布。" << endl;
	cout << "https://github.com/BlazeSnow/Delete-characters-except-English" << endl << endl;
	cout << "当前程序版本号：v1.0.1" << endl;
	vector<char> characters;
	vector<char> answer;
	int choose;
	cout << "需要生成全新txt文件(0)还是处理现有txt文件(1)：" << endl;
	cin >> choose;
	if (choose == 0) {
		fstream file("Delete-characters-except-English.txt", ios::out);
		file.close();
		cout << "已生成全新\"Delete-characters-except-English.txt\"文件" << endl;
		cout << "路径为：" << filesystem::current_path() << endl;
		system("pause");
	} else if (choose == 1) {
		fstream file("Delete-characters-except-English.txt", ios::in);
		if (file.is_open()) {
			while (true) {
				char temp;
				file >> noskipws >> temp;
				characters.push_back(temp);
				if (file.eof()) {
					break;
				}
			}
			file.close();
			cout << "文件读取完毕" << endl;
			for (auto &i: characters) {
				if (('a' <= i && i <= 'z') || ('A' <= i && i <= 'Z') || i == ' ' || i == '\n') {
					answer.push_back(i);
				}
			}
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