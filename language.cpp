#include "language.h"
#include <cstring>
#include <iostream>
using namespace std;

//лабораторная 5

//конструктор без параметров
language::language() {
    name = new char [strlen("Неизвестный")+1];
    strcpy(name, "Неизвестный");
    wordsAmount = 0;
    complexity = 1;
    nativeAmount = 0;
}

//конструктор с параметрами
language::language(const char* nameValue, int wordsAmountValue, int complexityValue, long int nativeAmountValue) {
    if (complexityValue >= 1 && complexityValue <= 5){
        name = new char [strlen(nameValue)+1];
        strcpy(name, nameValue);
        wordsAmount = wordsAmountValue;
        complexity = complexityValue;
        nativeAmount = nativeAmountValue;
    }
    else {
        cout<<"Некорректное значение поля сложность изучения"<<endl;
        exit(EXIT_FAILURE);
    }
}

//деструктор
language::~language(){
    delete[] name;
}

//конструктор копирования
language::language(const language &other){
    this->name = new char [strlen(other.name)+1];
    strcpy(this->name, other.name);
    this->wordsAmount = other.wordsAmount;
    this->complexity = other.complexity;
    this->nativeAmount = other.nativeAmount;
}

//получение наименования языка
const char* language::getName(){
    return name;
}
//получение количества слов в языке
int language::getWordsAmount() const {
    return wordsAmount;
}
//получение сложности изучения языка от 1 (очень легкий) до 5 (очень тяжелый)
int language::getComplexity() const {
    return complexity;
}
//получение количества носителей языка
long int language::getNativeAmount() const {
    return nativeAmount;
}

//редактирование поля name
void language::setName(const char* nameValue){
    strcpy(name, nameValue);
}
//редактирование поля wordsAmount
void language::setWordsAmount(int wordsAmountValue){
    wordsAmount = wordsAmountValue;
}
//редактирование поля complexity
void language::setComplexity(int complexityValue){
    if (complexityValue >= 1 && complexityValue <= 5){
        complexity = complexityValue;
    }
    else {
        cout<<"Некорректное значение поля сложность изучения"<<endl;
        exit(EXIT_FAILURE);
    }
}
//редактирование поля nativeAmount
void language::setNativeAmount (long int nativeAmountValue){
    nativeAmount = nativeAmountValue;
}

//вывод на экран наименования языка
void language::printName() const {
    cout<<name<<" язык"<<endl;
}
//вывод на экран количества слов
void language::printWordsAmount() const {
    cout<<"Количество слов: "<<wordsAmount<<endl;
}
//вывод на экран сложности изучения языка от 1 (очень легкий) до 5 (очень тяжелый)
void language::printComplexity() const {
    cout<<"Сложность изучения: "<<complexity<<" из 5"<<endl;
}
//вывод на экран количества носителей
void language::printNativeAmount() const {
    cout<<"Количество носителей: "<<nativeAmount<<" человек"<<endl;
}

//вывод на экран полной информации о языке
void language::printAll() const {
    cout<<name<<" язык"<<endl;
    cout<<"Количество слов: "<<wordsAmount<<endl;
    cout<<"Сложность изучения: "<<complexity<<" из 5"<<endl;
    cout<<"Количество носителей: "<<nativeAmount<<" человек"<<endl;
}

//лабораторная 6

//функция вывода на экран массива строк
void language::printStrArr(const char** arr, int size){
    for (int i = 0; i < size; i++){
        cout<<arr[i]<<endl;
    }
}

//список мертвых языков, отсортированный по возрастанию количества слов
const char** language::deadLanguagesList(language *languages, int n) {
    int size = 0;
    for (int i = 0; i < n; i++){
        if (languages[i].getNativeAmount() == 0){
            size++;
        }
    }

    const char** names = new const char* [size];
    int* wordAmounts = new int [size];
    int k = 0;

    for (int i = 0; i < n; i++){
        if (languages[i].getNativeAmount() == 0){
            names[k] = languages[i].getName();
            wordAmounts[k] = languages[i].getWordsAmount();
            k++;
        }
    }

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size-1; j++){
            if (wordAmounts[j] > wordAmounts[j+1]){
                const char* tmpNames = names[j];
                int tmpWordAmounts = wordAmounts[j];
                names[j] = names[j+1];
                wordAmounts[j] = wordAmounts[j+1];
                names[j+1] = tmpNames;
                wordAmounts[j+1] = tmpWordAmounts;
            }
        }
    }
    printStrArr(names, size);
    delete [] wordAmounts;
    return names;
}

//среднее количество носителей среди всех языков
long int language::averageNativeAmount(language* languages, int n){
    long int sum = 0;
    for (int i = 0; i < n; i++){
        sum += languages[i].getNativeAmount();
    }
    return sum / n;
}

//среднее количество слов среди языков заданной сложности изучения N
long int language::averageWordsAmountAmongGivenComplexity(language* languages, int n, int N){
    long int sum = 0;
    int num = 0;
    for (int i = 0; i < n; i++){
        if (languages[i].getComplexity() == N){
            sum += languages[i].getWordsAmount();
            num++;
        }
    }
    return sum / num;
}























