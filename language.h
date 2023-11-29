#include <iostream>

using namespace std;

#ifndef CPP_LAB_5_6_NEW_LANGUAGE_H
#define CPP_LAB_5_6_NEW_LANGUAGE_H

class language {

private:
    char* name;
    int wordsAmount;
    int complexity;
    long int nativeAmount;

public:
    //конструктор без параметров
    language();
    //конструктор с параметрами
    language(const char* nameValue, int wordsAmountValue, int complexityValue, long int nativeAmountValue);
    //деструктор
    ~language();
    //конструктор копирования
    language(const language &other);

    //получение значений каждого поля
    const char* getName();
    int getWordsAmount() const;
    int getComplexity() const;
    long int getNativeAmount() const;

    //редактирование значений каждого поля
    void setName(const char* nameValue);
    void setWordsAmount(int wordsAmountValue);
    void setComplexity(int complexityValue);
    void setNativeAmount(long int nativeAmountValue);

    //вывод на экран значений каждого поля
    void printName() const;
    void printWordsAmount() const;
    void printComplexity() const;
    void printNativeAmount() const;
    //вывод на экран полной информации о языке
    void printAll() const;

    static void printStrArr(const char** arr, int size);
    //список мертвых языков, отсортированный по возрастанию количества слов
    static const char** deadLanguagesList(language* languages, int n);

    //среднее количество носителей среди всех языков
    static long int averageNativeAmount(language* languages, int n);

    //среднее количество слов среди языков заданной сложности изучения N
    static long int averageWordsAmountAmongGivenComplexity(language* languages, int n, int N);

};

#endif //CPP_LAB_5_6_NEW_LANGUAGE_H
