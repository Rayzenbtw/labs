#include <stdio.h>
#include <conio.h>

int main(){
struct S1
{
    char c[4];
    char *str;
} s1 = { "abc", "def" };// первая структура абц будет в переменной с, деф будет в стр(указатель на строку)
struct S2
{
    char *cp;// указатель на строку гхи,
    struct S1 msg;//мсг структура с словами
} s2 = { "ghi", { "jkl", "mno" } };
printf("ex1: %c %c\n", s1.c[0], *s1.str);// выведем сначала 1 элемент с (а) потом выведем д(первый елемент стр)
printf("ex2: %s %s\n", s1.c, s1.str);//выведет сразу всё
printf("ex3: %s %s\n", s2.cp, s2.msg.str);//гхи мно
printf("ex4: %s %s\n", ++s1.str, ++s2.msg.str);//еф но
return 0;
}