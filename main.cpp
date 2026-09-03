#include <cstdio>
#include <filesystem>
#include <fstream>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void enterToContinue() {
    printf("按回车键继续...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    getchar();
}

const filesystem::path CurrentPath = filesystem::current_path();
const string CurrentPathString = CurrentPath.string();

const vector<vector<char> > words_delete = {
    // 英语单词类型常用缩写
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
    {'a', 'b', 'b', 'r', '.'},
    {'v', 't', '.'},
    {'v', 'i', '.'},
    {'d', 'e', 't', '.'},
    {'q', 'u', 'a', 'n', 't', '.'},
    {'a', 'u', 'x', '.'},
    {'m', 'o', 'd', 'a', 'l', '.'},
    {'g', 'e', 'r', '.'},
    {'i', 'n', 'f', '.'},
    {'p', 'a', 'r', 't', '.'},
    {'r', 'e', 'f', 'l', '.'},
    {'d', 'e', 'm', '.'},
    {'p', 'o', 's', 's', '.'},
    {'r', 'e', 'l', '.'},
    {'c', 'o', 'l', 'l', '.'},
    {'a', 'b', 's', '.'},
    {'c', 'o', 'n', 'c', '.'},
};

static vector<char> characters;

// 删除特殊词
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

// 删除括号及其内容
void delete_parenthesis() {
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

// 删除double空格
void delete_blank() {
    for (auto i = characters.begin(); i != characters.end();) {
        if (*i == ' ' && *(i + 1) == ' ') {
            characters.erase(i);
        } else {
            i++;
        }
    }
}

// 删除.
void delete_dot() {
    for (auto i = characters.begin(); i != characters.end();) {
        if (*i == '.') {
            characters.erase(i);
        } else {
            i++;
        }
    }
}

// 删除空格+回车＆回车+回车＆回车+空格
void delete_blank_n() {
    // （空格+回车）
    for (auto i = characters.begin(); i != characters.end();) {
        if (*i == ' ' && *(i + 1) == '\n') {
            characters.erase(i, i + 1);
        } else {
            i++;
        }
    }
    // （回车）+回车
    for (auto i = characters.begin(); i != characters.end();) {
        if (*i == '\n' && *(i + 1) == '\n') {
            characters.erase(i);
        } else {
            i++;
        }
    }
    // 回车+（空格）
    for (auto i = characters.begin(); i != characters.end();) {
        if (*i == '\n' && *(i + 1) == ' ') {
            characters.erase(i + 1);
        } else {
            i++;
        }
    }
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    clearConsole();
    printf("Copyright (C) 2024-2026 BlazeSnow.\n");
    printf("https://github.com/BlazeSnow/Delete-characters-except-English\n\n");
    vector<char> answer;
    int choose;
    printf("需要生成全新txt文件(0)还是处理现有txt文件(1)：\n");
    scanf("%d", &choose);
    if (choose == 0) {
        fstream file("DCEE.txt", ios::out);
        if (file.is_open()) {
            file.close();
            printf("已生成全新\"DCEE.txt\"文件\n");
            printf("目录为：%s\n", CurrentPathString.c_str());
            enterToContinue();
        } else {
            fprintf(stderr, "错误：\"DCEE.txt\"文件生成失败，请重试\n");
            fprintf(stderr, "目录为：%s\n", CurrentPathString.c_str());
            enterToContinue();
        }
    } else if (choose == 1) {
        fstream file("DCEE.txt", ios::in);
        if (file.is_open()) {
            // 输入文件内容
            while (true) {
                char temp;
                file >> noskipws >> temp;
                if (('a' <= temp && temp <= 'z') || ('A' <= temp && temp <= 'Z') || temp == '.' || temp == ' ' ||
                    temp == '\n' || temp == '(' || temp == ')') {
                    // 正常收集
                    characters.push_back(temp);
                } else {
                    characters.push_back(' ');
                }
                if (file.eof()) {
                    break;
                }
            }
            file.close();
            printf("文件读取完毕\n");
            // 删除特殊词
            compare_extra_words();
            delete_parenthesis();
            delete_dot();
            delete_blank();
            delete_blank_n();
            // 写入answer
            for (const auto &i: characters) {
                answer.push_back(i);
            }
            // 写入新文件
            fstream file1("ANSWER-DCEE.txt", ios::out);
            if (file1.is_open()) {
                for (auto i: answer) {
                    file1 << i;
                }
                printf("处理后内容已写入\"ANSWER-DCEE.txt\"文件\n");
                printf("目录为：%s\n", CurrentPathString.c_str());
                file1.close();
                enterToContinue();
            } else {
                fprintf(stderr, "ERROR:创建输出文件失败\n");
                enterToContinue();
            }
        } else {
            fprintf(stderr, "ERROR:读取文件失败\n");
            enterToContinue();
        }
    } else {
        fprintf(stderr, "ERROR:输入内容不合法\n");
        enterToContinue();
    }
    return 0;
}
