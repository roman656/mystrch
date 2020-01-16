#ifndef MYSTRCH_H_INCLUDED
#define MYSTRCH_H_INCLUDED

/*------------------------------*/
/*      Библиотека наиболее     */
/*  часто используемых функций  */
/*       version: 0.1.0.4       */
/*   Диапазон значений exit():  */
/*        [-17001;-17011]       */
/*------------------------------*/

/*----------Библиотеки----------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*------------------------------*/

/*-----------Структуры----------*/
/*Флаги (8)*/
typedef struct {
    unsigned int f0:1;
    unsigned int f1:1;
    unsigned int f2:1;
    unsigned int f3:1;
    unsigned int f4:1;
    unsigned int f5:1;
    unsigned int f6:1;
    unsigned int f7:1;
}FLAGS;
/*------------------------------*/

/*------------Функции-----------*/
///malloc со страховкой.
///\param size_t memory_size - размер выделяемой памяти (sizeof * number).
///\return Возвращает указатель на выделенный блок памяти. Необходимо приведение типа. В случае ошибки: exit(-17001).
void* malloc_s(size_t memory_size);

///realloc со страховкой.
///\param void* ptr - указатель на текущий блок памяти;
///\param size_t memory_size - размер нового блока памяти (sizeof * number).
///\return Возвращает указатель на новый блок памяти. Необходимо приведение типа. В случае ошибки: exit(-17002).
void* realloc_s(void* ptr, size_t memory_size);

///fclose со страховкой.
///\param FILE* filestream - указатель на файл, который нужно закрыть.
///В случае ошибки: exit(-17003).
void fclose_s(FILE* filestream);

///Считывает символьную строку и записывает ее в динамический массив (считывает до: '\n', '\0', EOF).
///\param FILE* filestream - откуда считывать строку;
///\param int array_increment_step - размер шага увеличения памяти (больше 0!).
///\return Возвращает указатель на новый блок памяти со строкой.
char* read_char_str(FILE* filestream, int array_increment_step);

///Проверка скобок.
///\param char* message - указатель на строку, которую нужно проверить.
///\return 0 - все корректно.
///\return 1 - есть ошибка.
int check_brackets(char* message);

///Сравнение строк в различных режимах. Например: mode = 1 - сравнение вещественных чисел, записанных в строки.
///\param char* p1 - указатель на первую строку;
///\param char* p2 - указатель на вторую строку;
///\param int mode - режим сравнения: 0 - сравнение символьное (strcmp); 1 - сравнение вещественное (double). Неправильные строки: exit(-17004) и (-17005) соответственно; 2 - сравнение целочисленное (long int). Неправильные строки: exit(-17006) и (-17007) соответственно. В случае ошибки mode: exit(-17008).
///\return 1 - первая строка больше второй;
///\return 0 - первая строка равна второй;
///\return -1 - первая строка меньше второй.
int str_compare(char* p1, char* p2, int mode);

///fopen со страховкой.
///\param const char* file_name - строка, с именем файла, который надо открыть;
///\param const char* open_mode - строка, с режимом доступа к файлу.
///\return Указатель на открытый файл.
///В случае ошибки: exit(-17009).
FILE* fopen_s(const char* file_name, const char* open_mode);

///Устанавливает значение всех флагов на 1.
///\param FLAGS* p1 - указатель на флаги.
void flags_set_true(FLAGS* p1);

///Устанавливает значение всех флагов на 0.
///\param FLAGS* p1 - указатель на флаги.
void flags_set_false(FLAGS* p1);

///Считывает массив размером count элементов, каждый из которых имеет размер size байт, из потока fileptr, и сохраняет его в блоке памяти, на который указывает memptr.
///\param void* memptr - указатель на блок памяти, куда будет сохранен массив данных;
///\param int size - размер памяти, занимаемый каждым элементом массива;
///\param int count - количество считываемых элементов;
///\param FILE* fileptr - указатель на файл (поток), откуда будет производиться чтение.
void fread_s(void* memptr, int size, int count, FILE* fileptr);

///Записывает массив memptr размером count элементов, каждый из которых имеет размер size байт, в поток fileptr.
///\param void* memptr - указатель на массив элеменотов, который необходимо записать в fileptr;
///\param int size - размер памяти, занимаемый каждым элементом массива;
///\param int count - количество записываемых элементов;
///\param FILE* fileptr - указатель на файл (поток), куда будет производиться запись.
void fwrite_s(void* memptr, int size, int count, FILE* fileptr);
/*------------------------------*/

#endif
