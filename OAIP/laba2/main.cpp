// Написать программу обработки файла данных, состоящих из структур, 
// в которой реализованы следующие функции: стандартная обработка файла 
// (со-здание, просмотр, добавление); линейный поиск в файле; сортировка массива 
// (файла) методами прямого выбора и QuickSort; двоичный поиск в отсортиро-ванном массиве.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <io.h>
#include <string.h>
using namespace std;

struct Person
{
    char FIO[255];
    double sball;
    int group, fizika, math, inf;
};

int Create(FILE* file, int);
int Read(FILE* file, int);
int Add(FILE* file, int);
int Edit(FILE* file, int);
int Delete(FILE* file, int);
int LinPoisk(FILE* file, int);
int PryamVibor(FILE* file, int);
int QuickSort(FILE* file, int);
int BinarPoisk(FILE* file, int);
double Individual(FILE* file, int);

int QuickSort(FILE* file, int size)
{
    file = fopen("input.txt", "r+b");
//     i = 0; j = n – 1; x = a[(L + R)/2].key;
// while (i <= j) {
// while (a[i].key < x) i++;
// while (a[j].key > x) j--;
// if (i <= j) {
// r = a[i]; // Переставляем элементы
// a[i] = a[j];
// a[j] = r;
// i++; j--;
// }
// }
    Person student;
    
    fclose(file);
}
int LinPoisk(FILE* file, int size)
{
    file = fopen("input.txt", "rb");
    Person student;

    int vib;
    cout << "Vvedite po chem iskat (1 - Familiya, 2 - gruppa): ";
    cin >> vib;
    switch(vib)
    {
        case 1:
        {
        char fio2[255] = "";
        cin >> fio2;
        while (fread(&student, size, 1, file))
        {
            if (strcmp(student.FIO, fio2)==0)
            {
                cout << "Name: " << student.FIO << endl
                << "Number of group: " << student.group << endl
                << "Mark for fiz: " << student.fizika << endl
                << "Mark for math: " << student.math << endl
                << "Mark for inf: " << student.inf << endl
                << "Sball: " << student.sball << endl;
            }
        }
        break;
        }
        case 2:
        {
        int group2;
        cin >> group2;
        while(fread(&student, size, 1, file))
        {
             if (student.group == group2)
            {
                cout << "Name: " << student.FIO << endl
                << "Number of group: " << student.group << endl
                << "Mark for fiz: " << student.fizika << endl
                << "Mark for math: " << student.math << endl
                << "Mark for inf: " << student.inf << endl
                << "Sball: " << student.sball << endl;
            }
        }
        break;
        }
    }
    fclose(file);

}

int Create(FILE* file, int size)
{
    file = fopen("input.txt", "wb");
    if (file == 0)
    {
        cout << "Error of create";
        return(0);
    }
    fclose(file);
}

int Read(FILE* file, int size)
{
    file = fopen("input.txt", "rb");
    if (file != 0)
    {
        Person student;
        bool check = 0;
        while (fread(&student, size, 1, file))
        {
            cout << "Name: " << student.FIO << endl
                << "Number of group: " << student.group << endl
                << "Mark for fiz: " << student.fizika << endl
                << "Mark for math: " << student.math << endl
                << "Mark for inf: " << student.inf << endl
                << "Sball: " << student.sball << endl;
            check = 1;
        }
        if (check == 0)
        {
            cout << "Empty file";
        }
    }
    fclose(file);
    return(1);
}

int Add(FILE* file, int size)
{
    file = fopen("input.txt", "ab");
    if (file != 0)
    {
        Person student;
        cout << "Enter name: " << endl;
        cin >> student.FIO;
        cout << "Enter number of group: " << endl;
        cin >> student.group;
        cout << "Enter mark for fiz: " << endl;
        cin >> student.fizika;
        cout << "Enter mark for math: " << endl;
        cin >> student.math;
        cout << "Enter mark for inf: " << endl;
        cin >> student.inf;
        student.sball = (student.fizika + student.math + student.inf) / 3.; 
        cout << "Sball: " << student.sball << endl;
        fwrite(&student, size, 1, file);
        fclose(file);
        return(1);
    }
    else
    {
        cout << "Open error";
        return(0);
    }
}

int Edit(FILE* file, int size)
{
    file = fopen("input.txt", "r+b");
    int check = 1;
    int id = 0;
    if (file != 0)
    {
        Person student;
        char fio2[255] = "";
        cout << "Enter name for edit" << endl;
        cin >> fio2;
        while (fread(&student, size, 1, file))
        {
            if (strcmp(student.FIO, fio2)==0)
            {
                break;
            }
            id++;
        }
        while (check)
        {
            cout << "1. Edit name" << endl
                << "2. Edit number of group" << endl
                << "3. Edit mark" << endl
                << "4. Exit" << endl;

            cin >> check;

            switch (check)
            {
            case 1:
                cout << "Enter new name" << endl;
                cin >> student.FIO;
                break;

            case 2:
                cout << "Enter new number of group" << endl;
                cin >> student.group;
                break;

            case 3:
                cout << "Enter new mark for math" << endl;
                cin >> student.math;
                cout << "Enter new mark for fiz" << endl;
                cin >> student.fizika;
                cout << "Enter new mark for inf" << endl;
                cin >> student.inf;
                
                student.sball = (student.math + student.fizika + student.inf) / 3.;

                cout << "new sred mark: " << student.sball << endl;

                break;

            default:
                check = 0;
            }
        }
        fseek(file, size * id, SEEK_SET);
        fwrite(&student, size, 1, file);
        fclose(file);
        return(1);
            
    }
    else
    {
        cout << "Open error";
        return(0);
    }
    fclose(file);
}

int Delete(FILE* file, int size)
{
    file = fopen("input.txt", "r+b");
    if (file != 0)
    {
        int id = 0, count = _filelength(_fileno(file)) / size;
        char fio2[255] = "";

        Person student;

        cout << "Enter name for delete: " << endl;
        cin >> fio2;

        while (fread(&student, size, 1, file))
        {
            if (strcmp(student.FIO, fio2) == 0)
            {
                break;
            }
            id++;
        }
        while (fread(&student, size, 1, file))
        {
            fseek(file, id * size, SEEK_SET);
            fwrite(&student, size, 1, file);
            fseek(file, size, SEEK_CUR);
        }
        int newsize = _chsize(_fileno(file), size * (count - 1));

        fclose(file);
        return(1);
    }
    else
    {
        cout << "Open error";
        return(0);
    }

}

int PryamVibor(FILE* file, int size)
{
    file = fopen("input.txt", "r+b");
    if (file != 0)
    {
        int check = 0, count = _filelength(_fileno(file)) / size, id = 0;
        Person* student_array = new Person[size];
        Person student;
        
        cout << "Sort for: " << endl
            << "1. Name" << endl
            << "2. Number of group" << endl
            << "3. Sball" << endl;
        cin >> check;
        fread(student_array, size, count, file);
        fclose(file);

        switch (check)
        {
        case 1:
            cout << "Sort for name" << endl;
            for (int i = 0; i < count; i++)
            {
                for (int j = i + 1; j < count; j++)
                {
                    if (strcmp(student_array[i].FIO, student_array[j].FIO) > 0)
                    {
                        Person temp = student_array[j];
                        student_array[j] = student_array[i];
                        student_array[i] = temp;
                    }
                }
            }
            break;

        case 2:
            cout << "Sort for group" << endl;
            for (int i = 0; i < count; i++)
            {
                for (int j = i + 1; j < count; j++)
                {
                    if (student_array[i].group > student_array[j].group)
                    {
                        Person temp = student_array[j];
                        student_array[j] = student_array[i];
                        student_array[i] = temp;
                    }
                }
            }
            break;

        case 3:
            cout << "Sort for sredball" << endl;
            for (int i = 0; i < count; i++)
            {
                for (int j = i + 1; j < count; j++)
                {
                    if (student_array[i].sball > student_array[j].sball)
                    {
                        Person temp = student_array[j];
                        student_array[j] = student_array[i];
                        student_array[i] = temp;
                    }
                }
            }
            break;

        default:
            cout << "Selected wrong sort" << endl;
        }

        file = fopen("input.txt", "wb");
        if (file != 0)
        {
            fwrite(student_array, size, count, file);
            fclose(file);
            return(1);
        }
        else
        {
            cout << "File error";
            return(0);
        }
    }
    else
    {
        cout << "Open error";
        return(0);
    }
}

double Individual(FILE* file, int size)
{
    file = fopen("input.txt", "rb");
    if (file != 0)
    {
        double sredny;
        double summasred = 0;
        int count = _filelength(_fileno(file)) / size;
        Person* student_array = new Person[size];
        fread(student_array, size, count, file);
        fclose(file);
        for (int i = 0; i < count; i++)
        {
            summasred += student_array[i].sball;
        }
        sredny = summasred / count;
        cout << "Общий средний балл: " << sredny << endl
            << "Список со средним баллом выше среднего: " << endl;
        for (int i = 0; i < count; i++)
        {
            if (student_array[i].sball > sredny)
            {
                cout << student_array[i].FIO << endl;
            }
        }
        fclose(file);
        return(sredny);
    }
    else
    {
        cout << "Error";
        return(0);
    }
    
}

int main()
{
    setlocale(LC_ALL, "rus");
    int size = sizeof(Person);
    FILE* file = 0;
    int check;
    do
    {
        cout << "Main menu\n" << "1. Create\n" << "2. Read\n" << "3. Add\n" << "4. Edit\n" << "5. Delete\n" << "6. PryamVibor\n" << "7. Ind\n" << "8. LinPoisk\n" << "9. Exit\n";
        cin >> check;
        switch (check)
        {
        case 1:
            cout << "You choose create" << endl;
            Create(file, size);
            break;
        case 2:
            cout << "You choose read" << endl << endl;
            Read(file, size);
            break;
        case 3:
            cout << "You choose add" << endl;
            Add(file, size);
            break;
        case 4:
            cout << "You choose edit" << endl;
            Edit(file, size);
            break;
        case 5:
            cout << "You choose delete" << endl;
            Delete(file, size);
            break;
        case 6:
            cout << "You choose PryamVibor" << endl;
            PryamVibor(file, size);
            Read(file, size);
            break;
        case 7:
            cout << "You choose Ind" << endl;
            Individual(file, size);
            break;
        case 8:
            cout << "You choose LinPoisk" << endl;
            LinPoisk(file, size);
        }
    }
    while (check != 9);
}
