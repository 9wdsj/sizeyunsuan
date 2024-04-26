#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include<string>
using namespace std;

// ���������
int generateRandomNum(int maxNum) {
    return rand() % maxNum + 1;
}

// ���������
char generateOperator() {
    char operators[] = { '+', '-', '*', '/' };
    int index = rand() % 4;
    return operators[index];
}

// ��������������ʽ
string generateExpression(int maxNum, bool hasDecimal, bool hasBracket) {
    string expression = "";
    int num1 = generateRandomNum(maxNum);
    int num2 = generateRandomNum(maxNum);
    char op = generateOperator();

    // ��ӵ�һ������
    expression += to_string(num1);

    // ��������
    expression += " ";
    expression += op;
    expression += " ";

    // ��ӵڶ�������
    expression += to_string(num2);

    // �������
    if (hasBracket) {
        expression = "(" + expression + ")";
    }

    // ���С��
    if (hasDecimal) {
        expression += ".";
        expression += to_string(generateRandomNum(99)); // ����0-99��С������
    }

    return expression;
}

int main() {
    // ��������
    srand(time(0));

    int numQuestions;
    int maxNum;
    char oper;
    bool hasBracket, hasDecimal;

    // �������
    cout << "��������Ŀ������";
    cin >> numQuestions;
    cout << "�����������ֵ��";
    cin >> maxNum;
    cout << "�Ƿ������ţ�1�����У�0����û�У���";
    cin >> hasBracket;
    cout << "�Ƿ���С����1�����У�0����û�У���";
    cin >> hasDecimal;
    cout << "��ѡ���������+ - * /����";
    cin >> oper;

    // ���ļ�
    ofstream file("exercise.txt");

    // ������Ŀ��д���ļ�
    for (int i = 0; i < numQuestions; i++) {
        string expression = generateExpression(maxNum, hasDecimal, hasBracket);
        file << expression << " = " << endl;
    }

    // �ر��ļ�
    file.close();

    cout << "��Ŀ�����ɲ�д��exercise.txt�ļ���" << endl;

    return 0;
}