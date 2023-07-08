#ifndef EXAM_H
#define EXAM_H

#define _CRT_SECURE_NO_WARNINGS

//#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void fx1();

struct Customer;
typedef struct
{
    char id[20];
    char name[20];
    int age;
    char* imageLink;
    char* description;
}Animal;

struct Customer
{
    char id[20];
    char name[20];
    char phoneNumber[20];
    Animal** animals;
    int animalsNum;
};

typedef struct Customer Customer;

typedef struct
{
    Customer** customers;
    int customersNum;
}House;

/* Q1 */
char* createLongString(const char* arr[], int size);
/* Q2 */
int charInString(const char* str, char ch, int n);

/* Q3 */
Customer* createCustomer(House* house, const char* id, const char* name, const char* phone);

Animal* createAnimal(const char* id, const char* name, int age, const char* imageLink, const char* description);

int addAnimalToCustomer(House* house, const char* customerId, Animal* animal);

Animal** searchAnimalByAge(House* house, int age, int* count);

#endif
