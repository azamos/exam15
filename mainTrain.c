#include "exam.h"
int count1 = 0;

void fx1(){
    count1++;
}

int main()
{
    //Q1
    const char* strings1[3] = { "ab","cfd","rgf"};

    char* answer1 = createLongString(strings1, 3);
   
    if ((answer1 == NULL) ||(strcmp(answer1, "ab cfd rgf")))
        printf("createLongString function is wrong for for train1_1 (-8)\n");

    const char* strings2[3] = { "I","L","U"};

    char* answer2 = createLongString(strings2, 3);
    
    if ((answer2  == NULL) ||(strcmp(answer2, "I L U")))
        printf("createLongString function is wrong for  train1_2 (-8)\n");

    const char* strings3[2] = { "Good", "Luck"};

    char* answer3 = createLongString(strings3, 2);

    if ((answer3 == NULL) ||(strcmp(answer3, "Good Luck")))
        printf("createLongString function is wrong for train1_3 (-9)\n");


    //Q2
   int answer4 = charInString("abcaraf", 'a', 3);

    if(count1 < 3)
        printf("charInStringfunction is not recursive (-8)\n");
    else if (answer4 != 1)
    {
        printf("specialSum function is wrong for train2_1  (-8)\n");
    }

    count1 = 0;
    int answer5 = charInString("aaaaa", 'a', 2);

    if(count1 < 3)
        printf("charInStringfunction is not recursive (-9)\n");
    else if (answer5 != 0)
    {
        printf("charInStringfunction is wrong for train2_2  (-9)\n");
    }
    count1 = 0;
    int answer6 = charInString("aaaaa", 'a', 5);

    if(count1 < 3)
        printf("charInStringfunction is not recursive (-8)\n");
    else if (answer6 != 1)
    {
        printf("specialSum function is wrong for train2_3  (-8)\n");
    }

    //Q3
    Customer* custArr[5];
    Animal* animalsArr[5];
    House house;
    house.customers = NULL;
    house.customersNum = 0;

    custArr[0] = createCustomer(&house, "1", "name", "32455");
    custArr[1] = createCustomer(&house, "11", "Moshe", "11111");
    custArr[2] = createCustomer(&house, "1A", "haim", "222222");
    custArr[3] = createCustomer(&house, "1 88", "shula", "33333");
    custArr[4] = createCustomer(&house, "109090909090", "koko", "99999999");


    if (NULL == custArr[0] || strcmp(custArr[0]->name, "name")!=0)
        printf("createCustomer function is wrong for train3_1 (-3)\n");
    if ( NULL == custArr[2] || custArr[2]->animalsNum != 0)
        printf("createCustomer function is wrong for train3_2 (-3)\n");
    if ( NULL == custArr[4] || custArr[4]->animals != NULL)
        printf("createCustomer function is wrong for train3_3 (-4)\n");

    animalsArr[0] = createAnimal("1", "snowi", 1, "snowi.png", "Great dog");
    animalsArr[1] = createAnimal("11", "buki", 2, "buki.png", "Great dog");
    animalsArr[2] = createAnimal("111", "nush", 4, "nush.png", "Great dog");
    animalsArr[3] = createAnimal("1111", "humi", 1, "humi.png", "Great dog");


    if ( NULL == animalsArr[1] || strcmp(animalsArr[1]->id, "11"))
        printf("createAnimal function is wrong for train3_4  (-3)\n");

    if ( NULL == animalsArr[2] || strcmp(animalsArr[2]->name, "nush"))
        printf("createAnimal function is wrong for train3_5 (-3)\n");

    if ( NULL == animalsArr[3] || strcmp(animalsArr[3]->imageLink, "humi.png"))
        printf("createAnimal function is wrong for train3_6 (-4)\n");


    int rc[6];
    rc[0] = addAnimalToCustomer(&house, custArr[0]->id, animalsArr[0] );
    rc[1] = addAnimalToCustomer(&house, custArr[0]->id, animalsArr[1] );
    rc[2] = addAnimalToCustomer(&house, custArr[2]->id, animalsArr[2] );
    rc[3] = addAnimalToCustomer(&house, custArr[3]->id, animalsArr[3] );
    rc[4] = addAnimalToCustomer(&house, "no such id", animalsArr[3] );

    if (rc[0] != 1 || rc[4] != -1)
        printf("addAnimalToCustomer function is wrong for train3_7 (-3)\n");
    if ( NULL == custArr[0] || NULL == custArr[0]->animals || custArr[0]->animalsNum < 2 || NULL == custArr[0]->animals[1] || NULL == animalsArr[1] ||
        strcmp(custArr[0]->animals[1]->id,animalsArr[1]->id) != 0)
        printf("addAnimalToCustomer function is wrong for train3_8 (-3)\n");
    if ( NULL == custArr[0] || NULL == custArr[0]->animals || custArr[0]->animalsNum < 1 || NULL == custArr[0]->animals[0] || NULL == animalsArr[0] ||
        strcmp(custArr[0]->animals[0]->id,animalsArr[0]->id) != 0)
        printf("addAnimalToCustomer function is wrong for train3_9 (-4)\n");

    Animal** result = NULL;
    int count = -1;

    result = searchAnimalByAge(&house,0,&count);
    if (count != 0 )
        printf("searchAnimalByAge function is wrong for train3_10 (-6)\n");
    free(result);

    result = searchAnimalByAge(&house,0,&count);
    if (result != NULL )
        printf("searchAnimalByAge function is wrong for train3_11 (-6)\n");
    free(result);

    result = searchAnimalByAge(&house,1,&count);
    if (count != 2 )
        printf("searchAnimalByAge function is wrong for train3_12 (-8)\n");
    free(result);

    printf("done");
    return 0;
}

