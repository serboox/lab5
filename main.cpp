
/*************************************************************
	Практическое занятие №5. 
	"Старые" потоковые функции стандартной библиотеки
	Указатели на функции
	Структуры
*************************************************************/

//#include <tchar.h>
#include <iostream>
//#include <cstdio>
#include "cmath"
#include "other.h"

#define      stop __asm("nop")

BOOK book_global;

struct user {
public:
    user(std::string n, int a) {
        name = n;
        age = a;
    }

    void move() {
        std::cout << name << " is moving" << std::endl;
    }

    void setAge(int a) {
        if (a > 0 && a < 100) age = a;
    }

    std::string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

private:
    std::string name;
    int age;

};

int main() {
    user tom("Tom", 22);
    std::cout << "Name: " << tom.getName() << "\tAge: " << tom.getAge() << std::endl;
    tom.setAge(31);
    std::cout << "Name: " << tom.getName() << "\tAge: " << tom.getAge() << std::endl;

    /*{
        //Тема "Старые" потоковые функции стандартной библиотеки
        //Задание 1. С помощью функции scanf сформирйуте три коэффициента: A,B,C
        unsigned int A = 9, B = 10, C = 11;
        std::printf("Please enter A: ");
        std::scanf("%d", &A);
        std::printf("A=%.1d\n", A);
        std::printf("Please enter B: ");
        std::scanf("%d", &B);
        std::printf("B=%.1d\n", B);
        std::printf("Please enter C: ");
        std::scanf("%d", &C);
        std::printf("C=%.1d\n", C);

        //Задание 2. Выведите (красиво!) таблицу значений y=A*x*x + B*x + C
        //при изменении x в диапазоне -2 до +2 с шагом 0.5

        float x = 0, y = 0;
        int sizeX = (int) log10(std::numeric_limits<float>::max()) + 2;
        int sizeY = (int) log10(std::numeric_limits<float>::max()) + 2;

        std::printf("Max size x: %d\n", sizeX);
        std::printf("Max size y: %d\n", sizeY);

        std::cout << "┌";
        for (int i = 1; i <= sizeX; i++) {
            std::cout << "-";
        }
        std::cout << "┬";
        for (int i = 1; i <= sizeY; i++) {
            std::cout << "-";
        }
        std::cout << "┐\n";

        std::cout << "|";
        for (int i = 2; i <= sizeX / 2; i++) {
            std::cout << " ";
        }
        std::cout << "x";
        for (int i = 1; i <= sizeX / 2; i++) {
            std::cout << " ";
        }
        std::cout << "|";

        for (int i = 1; i <= sizeX / 2; i++) {
            std::cout << " ";
        }
        std::cout << "y";
        for (int i = 2; i <= sizeX / 2; i++) {
            std::cout << " ";
        }
        std::cout << "|\n";

        std::cout << "├-";
        for (int i = 2; i <= sizeX; i++) {
            std::cout << "-";
        }
        std::cout << "┼";
        for (int i = 1; i <= sizeY; i++) {
            std::cout << "-";
        }
        std::cout << "┤\n";

        for (x = -2; x <= 2; x += 0.5) {

            int lenX = 3;
            int paddingLeft = (sizeX / 2) - (lenX / 2);
            int paddingRight = paddingLeft;
            if (x < 0) {
                lenX = (int) log10(abs(x)) + 4;
                paddingLeft = (sizeX / 2) - (lenX / 2);
            } else if (x > 0) {
                lenX = (int) log10(abs(x)) + 3;
            }
            if ((lenX + paddingLeft + paddingRight) > sizeX+1) {
                --paddingRight;
            }

            std::cout << "|";
            for (int i = 2; i <= paddingLeft; i++) {
                std::cout << " ";
            }
            std::printf("%.1f", x);
            for (int i = 1; i <= paddingRight; i++) {
                std::cout << " ";
            }
            std::cout << "|";

            y = A * x * x + B * x + C;
            int lenY = 3;
            if (y < 0) {
                lenY = (int) log10(abs(y)) + 4;
            } else if (y > 0) {
                lenY = (int) log10(abs(y)) + 3;
            }

            paddingLeft = (sizeY / 2) - (lenY / 2);
            paddingRight = paddingLeft;
            if ((lenY + paddingLeft + paddingRight) > sizeY) {
                --paddingRight;
            }

            //std::cout << "L: " << lenY << " ";
            //std::cout << "PL: " << paddingLeft << " ";
            //std::cout << "PR: " << paddingRight << " ";

            for (int i = 1; i <= paddingLeft; i++) {
                std::cout << " ";
            }
            std::printf("%.1f", y);
            for (int i = 1; i <= paddingRight; i++) {
                std::cout << " ";
            }
            std::cout << "|\n";
        }
        std::cout << "└";
        for (int i = 1; i <= sizeX; i++) {
            std::cout << "-";
        }
        std::cout << "┴";
        for (int i = 1; i <= sizeY; i++) {
            std::cout << "-";
        }
        std::cout << "┘\n";

    }*/

///////////////////////////////////////////////////////////////////
    //Тема Указатели на функции

    //Задание 1. Указатель на функцию. "Калькулятор".
    //Напишите функции:
    //1)Sum - принимает два значения double и возвращает сумму
    //этих значений
    //2)Sub- принимает два значения double и возвращает разность
    //этих значений
    //3)Mul - *
    //4)Div - /
    //5)а для возведения в степень можете использовать функцию стандартной библиотеки
    //		- pow(). Подсказка 1: прототип функции находится в <cmath>.
    //		Подсказка 2: стандартная библиотека предоставляет несколько перегруженных
    //		вариантов этой функции, а Вам потребуется сформировать указатель на
    //		double pow(double, double);

    //Предоставьте пользователю	следующую возможность:
    //пока пользователь хочет пользоваться услугами Вашего калькулятора,
    //он может вводить два значения и знак операции
    //а Вы выводите результат. Результат получаете посредством вызова
    //соответствующей Вашей функции по указателю.
    //Предусмотрите возможность ввода непредусмотренного знака операции


    //stop;

    //Задание 2. Указатель на функцию в качестве аргумента.
    //Дана заготовка функции сортировки любых объектов - Sort.
    //Функция принимает следующие параметры:
    //1) указатель на первый сортируемый элемент
    //2) количество сортируемых элементов
    //3) размер элемента в байтах
    //4) указатель на функцию перестановки элементов
    //5) указатель на функцию сравнения элементов

    //2a. Напишите функцию перестановки двух целых значений -
    // SwapInt, которая принимает два void указателя и
    //меняет значения местами

    //Напишите функцию сравнения двух целых значений -
    // CmpInt, которая принимает два void указателя и
    //возвращает int результат сравнения:
    //<0 - первый элемент меньше, чем второй
    //=0 - равны
    //>0 - первый элемент больше, чем второй
/*
	int nAr[]=...	//массив для сортировки

	//Печать исходного массива



	//Вызов сортировки
	int nTotal=...			//количество элементов в массиве 
	Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(int), SwapInt, CmpInt);
	
	//Печать результатов сортировки

	stop
*/
/*
	//Задание 2б. По аналогии с 8а создайте вспомогательные
	//функции - SwapDouble и CmpDouble и вызовите функцию Sort
	//для сортировки массива вещественных значений.
*/
/*
	//Задание 2в*. По аналогии с 8а создайте вспомогательные
	//функции - SwapStr и CmpStr и вызовите функцию Sort 
	//для сортировки массива указателей на строки.
	char s[] = "QWERTY";
	char* arStr[] = {"WWW", "SDF", "ABC", s, ...};

*/

/*
	//Задание 3. Массивы указателей на функцию.
	//Напишите несколько функций вида
	//const char* GetString1();
	//const char* GetString2();
	//		...., каждая из функций возвращает указатель на свою строку
	//(подумайте - какой адрес Вы имеете право возвращать из функции)
	

	//Объявите и проинициализируйте массив указателей на функции
	//GetString1,GetString2...



	//Введите номер функции, которую Вы хотите вызвать:
	int n;



    //Вызовите функцию 



	//Распечатайте результат


*/
//////////////////////////////////////////////////////////////////////////////////////
    {
        //Тема. Структуры С.
        //Задание 1. Объявите структуру BOOK, описывающую книгу
        //(автор, заглавие, год издания, цена, категория…).
        //Подумайте: какого типа могут быть поля структуры.
        //Подсказка: объявление структуры рекомендуется выносить
        //в заголовочный файл.

        // INFO: Объявление структуры находится в файле other.h

        //Задание 2. Создайте разными способами (глобальный, локальный, статический,
        //динамический) экземпляры (объекты) типа BOOK (без инициализации).
        //Определите - сколько памяти отводит компилятор под каждый
        //такой объект. Как инициализируются (или не инициализируются) поля
        //структуры. Подумайте: от чего зависит объем выделяемой памяти?

        std::printf("Task_2________________________________________________\n");

        //При глобальном создании экземпляра структуры
        std::printf("\nGlobal size: %d\n", (int) sizeof(book_global)); //104 bytes

        //При локальном создании экземпляра структуры
        struct {
            std::string authorFirstName; // 24 bytes
            std::string authorLastName; // 24 bytes

            std::string bookTitle; // 24 bytes
            short int bookYear; // 2 bytes
            /* 2 padding byte */
            float bookPrice; // 4 bytes
            BookCategoryEnum bookCategory; // 4 bytes
        } book_local;
        std::printf("Local size: %d\n", (int) sizeof(book_local)); //88 bytes

        //При статическом создании экземпляра структуры
        BOOK static_book;
        std::printf("Static size: %d\n", (int) sizeof(static_book)); //88 bytes

        //При динамическом создании экземпляра структуры
        BOOK *dynamic_book = new(BOOK);
        std::printf("Dynamic size: %d\n", (int) sizeof(*dynamic_book)); //88 bytes
        delete dynamic_book;

        std::printf("\nBook authorFirstName size: %d\n", (int) sizeof(static_book.authorFirstName));
        std::printf("Book authorLastName size: %d\n", (int) sizeof(static_book.authorLastName));
        std::printf("Book bookTitle size: %d\n", (int) sizeof(static_book.bookTitle));
        std::printf("Book bookYear size: %d\n", (int) sizeof(static_book.bookYear));
        std::printf("Book bookPrice size: %d\n", (int) sizeof(static_book.bookPrice));
        std::printf("Book bookCategory size: %d\n\n", (int) sizeof(static_book.bookCategory));

        //Во всех случаях компилятор отводит под структуру 88 байта
        //     1       2       3       4      5       6       7       8
        //+-------+-------+-------+-------+-------+-------+-------+-------+
        //|        authorFirstName
        //+-------+-------+-------+-------+-------+-------+-------+-------+ ... 24
        //|        authorLastName
        //+-------+-------+-------+-------+-------+-------+-------+-------+ ... 24
        //|           bookTitle
        //+-------+-------+-------+-------+-------+-------+-------+-------+ ... 24
        //|    bookYear   | 2 padding byte|
        //+-------+-------+-------+-------+
        //|           bookPrice           |
        //+-------+-------+-------+-------+
        //|          bookCategory         |
        //+-------+-------+-------+-------+

        // Поля структуры инициализируются и заполняются значениями по умолчанию для
        // каждого из используемых типов
        std::printf("Books{\n"
                    "\tauthorFirstName (default):%s\n"
                    "\tauthorLastName (default): %s\n"
                    "\tbookTitle (default): %s\n"
                    "\tbookYear (default): %hu\n"
                    "\tbookPrice (default): %f\n"
                    "\tbookCategory (default): %s\n}\n",
                    static_book.authorFirstName.c_str(), //""
                    static_book.authorLastName.c_str(), //""
                    static_book.bookTitle.c_str(), //""
                    static_book.bookYear, //18641
                    static_book.bookPrice, //0.000000
                    static_book.getBookCategory().c_str()); //""

        // Размер выделяемой памяти под структуру зависит от многих факторов.
        // В основном все выливается в размер базовых типов данных и тем как они будут расположенны в оперативной памяти.
        // Процессор, операционная система и компилятор могут в совокупоности предоставлять различные размеры для (int, char, double), вполоть до того, того что все типы могут быть одного размера.

        // Ссылки на используемые ресурсы
        // http://qaru.site/questions/147/why-isnt-sizeof-for-a-struct-equal-to-the-sum-of-sizeof-of-each-member
        // https://habr.com/post/90580/

        //Задание 3. Заполните поля созданных объектов.
        //Замечание: если для хранения строки используется массив, необходимо
        //предусмотреть "защиту" от выхода за границы массива.

        std::printf("Task_3________________________________________________\n");

        std::printf("Please enter fields \nauthorFirstName (string): ");
        std::getline(std::cin, static_book.authorFirstName);

        std::printf("authorLastName (string): ");
        std::getline(std::cin, static_book.authorLastName);

        std::printf("bookTitle (string): ");
        std::getline(std::cin, static_book.bookTitle);

        std::printf("bookYear (short int): ");
        std::scanf("%hu", &static_book.bookYear);
        std::cin.ignore();

        std::printf("bookPrice (float): ");
        std::scanf("%f", &static_book.bookPrice);
        std::cin.ignore();

        std::printf("bookCategory (strings): ");
        std::string category;
        std::getline(std::cin, category, '\n');
        static_book.bookCategory = static_book.getBookCategory(category);
        std::cout << std::endl;

        //Задание 4. Напишите функцию, выводящую на экран реквизиты книги.
        //Подумайте: как эффективнее передавать экземпляр BOOK в функцию.
        //Для вывода на консоль используйте функцию стандартной библиотеки
        //printf

        std::printf("Task_4________________________________________________\n");
        static_book.print();

        //Задание 5. Напишите функцию для формирования полей структуры.
        //Для ввода используйте функцию стандартной библиотеки scanf
        //Замечание: неплохо заложить в такую функцию возможность проверки
        //корректности введенного значения, например, год издания не может быть
        //меьше, чем... (год появления письменности), категорию ползователь
        //должен выбирать из существующих, цена не может быть отрицательной...

        std::printf("Task_5________________________________________________\n");
        fillBookFields(static_book);
        static_book.print();
    }

    return 0;
}//main

