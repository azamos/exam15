#include "exam.h"

Customer* createCustomer(House* house, const char* id, const char* name, const char* phone)
{
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    if(!newCustomer){
        return NULL;
    }
    /*
    *  the Customer fields: id, name and phone, are already allocated,
    *  thus I only need to copy from the paramaters into them.
    */
    strcpy(newCustomer->id,id);

    strcpy(newCustomer->name, name);

    strcpy(newCustomer->phoneNumber, phone);

    newCustomer->animals = NULL;
    newCustomer->animalsNum = 0;

    Customer** updatedCustomerList = (Customer**)realloc(house->customers, sizeof(Customer*) * (house->customersNum + 1));
    if(!updatedCustomerList){
        free(newCustomer);
        return NULL;
    }
    /*
    * if code reaches here, it means re-allocation to size+1
        was succesfull, and I can now access the  house->customersNum cell,
        to populate it with the newly created newCustomer instance.
    */
    updatedCustomerList[house->customersNum] = newCustomer;
    house->customers = updatedCustomerList;
    house->customersNum++;

    return newCustomer;
}

Animal* createAnimal(const char* id, const char* name, int age, const char* imageLink, const char* description)
{
    Animal* newPet = (Animal*)malloc(sizeof(Animal));
    if (!newPet) {
        return NULL;
    }
    /*
    * Animal imageLink and description are of type char*, and NOT
    * of some fixed length, thus I must allocate space for them.
    */
    char* petImage = (char*)malloc(sizeof(char) * (1 + strlen(imageLink)));
    char* petDescr = (char*)malloc(sizeof(char) * (1 + strlen(description)));

    if (!(petImage && petDescr)) {
        free(newPet);
        free(petImage);
        free(petDescr);
        return NULL;
    }

    strcpy(petImage, imageLink);
    strcpy(petDescr, description);

    /*
    * id and name are defined as char[20],
    * meaning that they do not need to be allocated,
    * thus a simple strcpy suffices.
    */
    strcpy(newPet->id, id);
    strcpy(newPet->name, name);
    newPet->imageLink = petImage;
    newPet->description = petDescr;
    
    newPet->age = age;

    return newPet;;
}

int addAnimalToCustomer(House* house, const char* customerId, Animal* animal)
{
    /*
    * go over all customer, until a customer with cust_id == customerId is found.
    * The return statements inside the block will prevent further checks
    * after a customer was found.
    */
    for (int i = 0; i < house->customersNum; i++) {
        if(strcmp(customerId,house->customers[i]->id)==0){
            Customer* owner = house->customers[i];
            Animal** updatedPetsList = 
                (Animal**)realloc(owner->animals,
                    sizeof(Animal*)*(1+owner->animalsNum));
            if (!updatedPetsList) {
                return -1;
            }
            /*
            * beign here -> reallocation to size+1 was successful
            */
            updatedPetsList[owner->animalsNum] = animal;
            owner->animals = updatedPetsList;
            owner->animalsNum++;
            return 1;
        }
    }
    return -1;
}

Animal** searchAnimalByAge(House* house, int age, int* count)
{
    *count = 0;
    Animal** filteredAnimals = NULL;//will be the list of relevant animals
    /*
    * go over all customers in house, with index i
    */
    for (int i = 0; i < house->customersNum; i++) {
        /*
        * for customer[i], go over all his animals, with index j
        */
        for (int j = 0; j < house->customers[i]->animalsNum; j++) {
            /*
            * filter by animals with Animal.age == age
            */
            if (house->customers[i]->animals[j]->age == age) {
                (*count)++;
                filteredAnimals = (Animal**)realloc(filteredAnimals, sizeof(Animal*)*(*count));
                if (filteredAnimals == NULL) {
                    *count = 0;
                    return NULL;
                }
                filteredAnimals[(*count) - 1] = house->customers[i]->animals[j];
            }
        }
    }
    return filteredAnimals;
}