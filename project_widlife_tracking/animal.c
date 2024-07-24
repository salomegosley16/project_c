#include <stdio.h>  /*printf() scanf()*/
#include <stdlib.h> /*malloc() realloc() free()*/
#include "animal.h" /*animal.h header*/
#include <assert.h> /*assert()*/
#include <string.h> /*memset()*/

animal_list_t *InitAnimalList()
{
    animal_list_t *list = (animal_list_t *)malloc(sizeof(animal_list_t));
    if (NULL == list)
    {
        return NULL;
    }

    list->animals = NULL;
    list->count = 0;

    return list;
}

void *AddAnimal(animal_list_t *list)
{
    animal_t *new_animal = NULL;

    assert(NULL != list);

    ++list->count;
    list->animals = (animal_t *)realloc(list->animals, list->count * sizeof(animal_t));
    if (NULL == list->animals)
    {
        return NULL;
    }

    /*pointer to the last element in the animals array*/
    new_animal = &list->animals[list->count - 1];
    memset(new_animal, 0, sizeof(animal_t)); /*zero out the new animal*/
    new_animal->id = list->count;

    printf("\nEnter name: ");
    scanf("%s", new_animal->name);
    printf("Enter estimated age (in years, if unknown approximate): ");
    scanf("%d", &new_animal->age);
    printf("Enter species: ");
    scanf("%s", new_animal->species);
    printf("Enter location between: Savannah, Waterhole, Forest, Grassland, Mountain:");
    scanf("%s", new_animal->location);

    printf("\nAnimal added successfully. ID is %d.\n", new_animal->id);
}

int FindAnimalByID(animal_list_t *list, int id)
{
    int i = 0;

    assert(NULL != list);

    for (i = 0; i < list->count; ++i)
    {
        if (list->animals[i].id == id)
        {
            return i;
        }
    }
    return -1; /*not found*/
}

void UpdateAnimal(animal_list_t *list)
{
    int id = 0;
    int index = 0;
    animal_t *animal = NULL;

    assert(NULL != list);

    printf("\nEnter the ID of the animal to update: ");
    scanf("%d", &id);

    index = FindAnimalByID(list, id);
    if (-1 == index)
    {
        printf("Animal not found.\n");
        return;
    }

    animal = &list->animals[index];
    printf("Enter new name: ");
    scanf("%s", animal->name);
    printf("Enter new estimated age (in years, if unknown approximate): ");
    scanf("%d", &animal->age);
    printf("Enter new species: ");
    scanf("%s", animal->species);
    printf("Enter new location between: Savannah, Waterhole, Forest, Grassland, Mountain");
    scanf("%s", animal->location);

    printf("\nAnimal updated successfully.\n");
}

void ViewAnimalDetails(animal_list_t *animal_list, sighting_list_t *sighting_list)
{
    int id = 0;
    int index = 0;
    int i = 0;
    animal_t *animal = NULL;

    assert(NULL != animal_list);
    assert(NULL != sighting_list);

    printf("\nEnter the ID of the animal to view: ");
    scanf("%d", &id);

    index = FindAnimalByID(animal_list, id);
    if (-1 == index)
    {
        printf("Animal not found.\n");
        return;
    }

    animal = &animal_list->animals[index];
    printf("\nID: %d\n", animal->id);
    printf("Name: %s\n", animal->name);
    printf("Species: %s\n", animal->species);
    printf("ID: %d\n", animal->id);
    printf("Age: %d\n", animal->age);
    printf("Location: %s\n", animal->location);

    printf("Sightings:\n");
    for (i = 0; i < sighting_list->count; ++i)
    {
        if (sighting_list->sightings[i].animal_id == id)
        {
            printf("Date: %s, Time: %s, Location: %s\n", sighting_list->sightings[i].date, sighting_list->sightings[i].time, sighting_list->sightings[i].location);
        }
    }
}

void DeleteAnimal(animal_list_t *list, int id)
{
    int idx = 0;
    int i = 0;
    animal_t *temp = NULL;

    assert(NULL != list);

    idx = FindAnimalByID(list, id);
    if (-1 == idx)
    {
        printf("Animal not found.\n");
        return;
    }

    for (i = idx; i < list->count - 1; ++i)
    {
        list->animals[i] = list->animals[i + 1];
    }

    --list->count;

    if (0 < list->count)
    {
        temp = (animal_t *)realloc(list->animals, list->count * sizeof(animal_t));
        if (NULL == temp)
        {
            printf("Error reallocating memory\n");
            return;
        }
        /*Assign temp to list->animals only if realloc is successful*/
        list->animals = temp;
    }
    else
    {
        free(list->animals);
        list->animals = NULL;
    }

    printf("Animal deleted successfully\n");
}

void FreeAnimalList(animal_list_t *list)
{
    if (list->animals)
    {
        free(list->animals);
        list->animals = NULL;
    }

    free(list);
}
