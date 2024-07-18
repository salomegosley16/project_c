#include <stdio.h>    /*file operations*/
#include "animal.h"   /*animal.h header*/
#include "sighting.h" /*sighting.h header*/
#include "file_io.h"  /*file_io.h header*/
#include <assert.h>   /*assert()*/
#include <stdlib.h>   /*malloc()*/

void SaveAnimals(animal_list_t *list)
{
    FILE *file = NULL;

    assert(NULL != list);

    file = fopen("animals.dat", "wb");
    if (NULL == file)
    {
        printf("Error saving animals data.\n");
        return;
    }

    /*writes data from the array pointed to, by ptr to the given stream*/
    fwrite(&list->count, sizeof(int), 1, file);
    fwrite(list->animals, sizeof(animal_t), list->count, file);

    fclose(file);
}

void LoadAnimals(animal_list_t *list)
{
    FILE *file = NULL;

    assert(NULL != list);

    file = fopen("animals.dat", "rb");
    if (NULL == file)
    {
        return;
        printf("Error loading animals data.\n");
    }

    fread(&list->count, sizeof(int), 1, file);
    list->animals = (animal_t *)malloc(list->count * sizeof(animal_t));
    if (NULL == list->animals)
    {
        return;
    }

    fread(list->animals, sizeof(animal_t), list->count, file);
    fclose(file);
}

void SaveSightings(sighting_list_t *list)
{
    FILE *file = NULL;

    assert(NULL != list);

    file = fopen("sightings.dat", "wb");
    if (NULL == file)
    {
        printf("Error saving sighting data.\n");
        return;
    }

    /*writes data from the array pointed to, by ptr to the given stream*/
    fwrite(&list->count, sizeof(int), 1, file);
    fwrite(list->sightings, sizeof(sighting_t), list->count, file);

    fclose(file);
}

void LoadSightings(sighting_list_t *list)
{
    FILE *file = NULL;

    assert(NULL != list);

    file = fopen("sightings.dat", "rb");
    if (NULL == file)
    {
        return;
        printf("Error loading sighting data.\n");
    }

    fread(&list->count, sizeof(int), 1, file);
    list->sightings = (sighting_t *)malloc(list->count * sizeof(sighting_t));
    if (NULL == list->sightings)
    {
        return;
    }

    fread(list->sightings, sizeof(sighting_t), list->count, file);
    fclose(file);
}
