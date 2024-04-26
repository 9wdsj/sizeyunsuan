#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include<string>
using namespace std;

// 生成随机数
int generateRandomNum(int maxNum) {
    return rand() % maxNum + 1;
}

// 生成运算符
char generateOperator() {
    char operators[] = { '+', '-', '*', '/' };
    int index = rand() % 4;
    return operators[index];
}

// 生成四则运算表达式
string generateExpression(int maxNum, bool hasDecimal, bool hasBracket) {
    string expression = "";
    int num1 = generateRandomNum(maxNum);
    int num2 = generateRandomNum(maxNum);
    char op = generateOperator();

    // 添加第一个数字
    expression += to_string(num1);

    // 添加运算符
    expression += " ";
    expression += op;
    expression += " ";

    // 添加第二个数字
    expression += to_string(num2);

    // 添加括号
    if (hasBracket) {
        expression = "(" + expression + ")";
    }

    // 添加小数
    if (hasDecimal) {
        expression += ".";
        expression += to_string(generateRandomNum(99)); // 生成0-99的小数部分
    }

    return expression;
}

int main() {
    // 设置种子
    srand(time(0));

    int numQuestions;
    int maxNum;
    char oper;
    bool hasBracket, hasDecimal;

    // 输入参数
    cout << "请输入题目数量：";
    cin >> numQuestions;
    cout << "请输入最大数值：";
    cin >> maxNum;
    cout << "是否有括号（1代表有，0代表没有）：";
    cin >> hasBracket;
    cout << "是否有小数（1代表有，0代表没有）：";
    cin >> hasDecimal;
    cout << "请选择运算符（+ - * /）：";
    cin >> oper;

    // 打开文件
    ofstream file("exercise.txt");

    // 生成题目并写入文件
    for (int i = 0; i < numQuestions; i++) {
        string expression = generateExpression(maxNum, hasDecimal, hasBracket);
        file << expression << " = " << endl;
    }

    // 关闭文件
    file.close();

    cout << "题目已生成并写入exercise.txt文件。" << endl;

    return 0;
}