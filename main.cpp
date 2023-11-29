#include <iostream>
#include <cstring>
#include "language.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "ru");

    //лабораторная 5

    cout<<"Создадим объект класса language с помощью конструктора без параметров и выведем информацию о нем на экран:"<<endl;
    language firstLanguage;
    firstLanguage.printAll();

    cout<<endl;

    cout<<"Отредактируем поля этого объекта и выведем на экран с помощью соответствующих функций:"<<endl;
    firstLanguage.setName("Русский");
    firstLanguage.setWordsAmount(500000);
    firstLanguage.setComplexity(4);
    firstLanguage.setNativeAmount(20000000);

    firstLanguage.printName();
    firstLanguage.printWordsAmount();
    firstLanguage.printComplexity();
    firstLanguage.printNativeAmount();

    cout<<endl;

    cout<<"Создадим объект класса language с помощью конструктора с параметрами и выведем информацию о нем на экран:"<<endl;
    language secondLanguage("Английский", 300000, 2, 100000000);
    secondLanguage.printAll();

    cout<<endl;

    //лабораторная 6

    int n;
    cout<<"Введите количество языков:"<<endl;
    cin>>n;

    language languages[n];

    for (int i = 0; i < n; i++){
        cout<<"Введите наименование языка "<<i+1<<"-го языка:"<<endl;
        char* tmp = new char [255];
        cin>>tmp;
        char* nameValue = new char [strlen(tmp)+1];
        strcpy(nameValue, tmp);
        delete[] tmp;
        languages[i].setName(nameValue);
        delete[] nameValue;

        int wordsAmoutValue;
        cout<<"Введите количество слов в "<<i+1<<"-ом языке:"<<endl;
        cin>>wordsAmoutValue;
        languages[i].setWordsAmount(wordsAmoutValue);

        int complexityValue;
        cout<<"Введите сложность "<<i+1<<"-го языка от 1 (очень легкий) до 5 (очень тяжелый):"<<endl;
        cin>>complexityValue;
        languages[i].setComplexity(complexityValue);

        long int nativeAmountValue;
        cout<<"Введите количество носителей "<<i+1<<"-го языка"<<endl;
        cin>>nativeAmountValue;
        languages[i].setNativeAmount(nativeAmountValue);

        cout<<endl;
    }

    cout<<"Введены следующие языки:"<<endl;
    for (int i = 0; i < n; i++){
        cout<<"№"<<i+1<<' ';
        languages[i].printAll();
        cout<<endl;
    }


    //№1 список мертвых языков, отсортированный по количеству слов
    cout<<"Список наименований мертвых языков, отсортированный по возрастанию количества слов:"<<endl;
    const char** list = language::deadLanguagesList(languages, n);
    delete[] list;

    cout<<endl;

    //№2 Среднее количество носителей среди всех языков
    cout<<"Среднее количество носителей среди всех языков: "<<language::averageNativeAmount(languages, n)<<endl;

    cout<<endl;

    //№3 среднее количество слов среди языков сложности N
    int N;
    cout<<"Введите сложность изучения языка N от 1 (очень легкий) до 5 (очень тяжелый):"<<endl;
    cin>>N;
    if (N >= 1 && N <= 5){
        cout<<"Среднее количество слов среди языков сложности "<<N<<": "<<language::averageWordsAmountAmongGivenComplexity(languages, n, N)<<endl;
    }
    else {
        cout<<"Некорректный ввод значения сложности языка"<<endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}
