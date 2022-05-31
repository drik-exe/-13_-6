//Разработайте программу методом пошаговой детализации.Программа должна содержать три функции - ввод одномерного массива из вещественных чисел из текстового файла, 
//сортировка массива методом пузырька в порядке убывания элементов, вывод массива в конец исходного текстового файла.
//Массив и его размерность должны передаваться в каждую из функций в качестве параметров.Продемонстрировать процесс данной сортировки на примере.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void ReadArray(int(&arr)[10], int& size1, fstream &file) {
    if (!file.is_open()) {
        cout << "Ошибка открытия файла" << endl;
    }
    else {
        cout << "Файл открыт" << endl;
        while (!file.eof())
        {
            file >> arr[size1];
            size1++;
        }
    }
}


void Sort(int(&arr)[10], int size1) {

    int temp;

    for (size_t i = 0; i < size1 - 1; i++)
    {
        for (size_t j = 0; j < size1  - i - 1; j++)
        {
            if (arr[j] < arr[j + 1]) {
                
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

    }

}


void AddArr(int(&arr)[10], int size1, fstream& file) {
    for (size_t i = 0; i < size1; i++)
    {
        if (i == 0) {
            file << endl << arr[i] << ' ';
        }
        else if (i == size1 - 1) {
            file << arr[i];
        }
        else {
            file << arr[i] << ' ';
        }
    }
}

int main()
{
    
    setlocale(0, "");
    int arr[10];
    int size1 = 0;

    fstream file("Array.txt", ios::in);

    ReadArray(arr, size1, file);
    
    file.close();

    Sort(arr, size1);

    file.open("Array.txt", ios::app);

    AddArr(arr, size1, file);

    file.close();



    return 0;

}


