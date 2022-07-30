/*
    В этом задании вам нужно будет освоиться с работой в IDE Microsoft Visual Studio 2022.
    Для этого реализуем несложную программу
    Наша программа должна будет считать два одномерных целочисленных массива из входного файла in.txt 
    и записать их в выходной файл out.txt с небольшими изменениями

    Во входящем файле in.txt на первой строке находится целое неотрицательное число N - количество элементов
    в первом массиве. После этого идут элементы массива, разделённые пробелом - в количестве N. 
    Затем идёт целое неотрицательное число M - количество элементов во втором массиве. 
    После него находятся элементы второго массива, их количество равняется M

    В выходной файл оба массива должны быть записаны в другом порядке - сначала массив M, 
    потом массив N. При этом элементы в массиве M (изначально второй по счёту массив) 
    должны быть сдвинуты на один элемент вправо с переносом последнего элемента на место первого, 
    а элементы в массиве N (изначально первый по счёту массив) должны быть сдвинуты на один элемент 
    влево с переносом первого элемента на место последнего

    Перед каждым массивом в выходном файле должен быть записан его размер
*/
#include <iostream>
#include <fstream>

bool ifProblem(int val) {
    if (val == 0 || val < 0)
    {
        std::cout << "Размер массива не может быть 0 или отрицательным значением!" << std::endl;
        std::cout << "Закройте программу и повторите попытку устранив ошибки" << std::endl;
        return true;
    }
    else return false;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int data;
    std::ifstream fin("in.txt");
    if (fin.is_open())
    {
        fin >> data;
        if (!ifProblem(data))
        {
            int lArr1 = data;
            int* int_ptr = new int[data];
            for (int i = 0; i < data; ++i) {
                int tmp;
                fin >> tmp;
                int_ptr[i] = tmp;
            }
            fin >> data;
            if (!ifProblem(data))
            {
                int lArr2 = data;
                int* int_ptr2 = new int[data];
                for (int k = 0; k < data; ++k) {
                    int temp;
                    fin >> temp;
                    int_ptr2[k] = temp;
                }

                std::ofstream fout("data.txt");
                fout << lArr2 << std::endl;
                fout << int_ptr2[lArr2 - 1] << " ";
                for (int i = 0; i < lArr2 - 1; ++i) {
                    fout << int_ptr2[i] << " ";
                }
                fout << std::endl;

                fout << lArr1 << std::endl;
                for (int k = 1; k < lArr1; ++k) {
                    fout << int_ptr[k] << " ";
                }
                fout << int_ptr[0];

                fout.close();

                delete[] int_ptr;
                delete[] int_ptr2;

            }
        }
    }
    else {
        std::cout << "Не получилось открыть файл" << std::endl;
    }

    return 0;
}
