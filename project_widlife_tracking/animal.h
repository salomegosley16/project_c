/***************************
Dev: Salome Gosley
****************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include "sighting.h" /*sighting.h header */

#define MAX_NAME_LENGTH 50
#define MAX_SPECIES_LENGTH 50
#define MAX_LOCATION_LENGTH 50

typedef struct
{
    int id;
    int age;
    char name[MAX_NAME_LENGTH];
    char species[MAX_SPECIES_LENGTH];
    char location[MAX_LOCATION_LENGTH];
} animal_t;

/*manage list of animals*/
typedef struct
{
    animal_t *animals; /*a pointer to an array of animal_t structures*/
    int count;         /*num of animals currently in the list*/
} animal_list_t;

/*Initializes and returns an empty 'animal_list_t' struct*/
animal_list_t *InitAnimalList();

/*Add a new animal to the animal list provided*/
void *AddAnimal(animal_list_t *list);

/*Finds an animal in the animal list by its id and returnds its index*/
int FindAnimalByID(animal_list_t *list, int id);

/*Updates the details of an existing animal in the animal list*/
void UpdateAnimal(animal_list_t *list);

/*Display the details of a specific animal, including associated sightings*/
void ViewAnimalDetails(animal_list_t *animal_list, sighting_list_t *sighting_list);

/*Deletes an animal from the animal list by its id*/
void DeleteAnimal(animal_list_t *list, int id);

/*Frees the memory allocated for the animal list structure and its contents*/
void FreeAnimalList(animal_list_t *list);

#endif