# Лабораторная работа №4

*Вариант 23*
| Фигура №1  |  Фигура №2 |  Фигура №3  |
|   :---:    |   :---:    |   :---:     |
| 8-угольник | 6-угольник | Треугольник |

Разработать шаблоны классов согласно варианту задания. Параметром шаблона должен
являться скалярный тип данных задающий тип данных для оси координат.Классы должны наследоваться от базового
класса Figure. Фигуры являются фигурами вращения. 

Все классы должны поддерживать набор общих методов:

1. Вычисление геометрического центра фигуры вращения;
2. Вывод в стандартный поток вывода std::cout координат вершин фигуры через
перегрузку оператора << для std::ostream;
3. Чтение из стандартного потока данных фигур через перегрузку оператора >> для
std::istream
4. Вычисление площади фигуры через перегрузку оператора приведения к типу double;

Создать программу, которая позволяет:

• Запрещается использовать сырые указатели
• Вводить из стандартного ввода std::cin фигуры, согласно варианту задания.
• Сохранять созданные фигуры в динамический массив (переиспользовать от
предыдущей лабораторной работы) умных указатели на фигуру
(std::shared_ptr<Figure[]>)
• Динамический массив должен быть сделан в виде шаблона (параметр шаблона – класс
для хранения в массиве template <class T> Array {…})
• Фигуры должны иметь переопределенные операции копирования, сравнения и
приведение к типу double (вычисление площади)
• Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для
каждой фигуры в массиве геометрический центр, координаты вершин и площадь.
• Необходимо уметь вычислять общую площадь фигур в массиве.
• Удалять из массива фигуру по индексу;
