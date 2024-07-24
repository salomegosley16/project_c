#include <stdio.h>    /*printf() scanf()*/
#include <stdlib.h>   /*mallo() realloc() free()*/
#include "sighting.h" /*sighting.h header*/
#include <assert.h>   /*assert()*/
#include <string.h>   /*memset*/

sighting_list_t *InitSightingList()
{
    sighting_list_t *list = (sighting_list_t *)malloc(sizeof(sighting_list_t));
    if (NULL == list)
    {
        return NULL;
    }

    list->sightings = NULL;
    list->count = 0;

    return list;
}

void *LogSighting(sighting_list_t *list)
{
    sighting_t *new_sighting = NULL;

    assert(NULL != list);

    ++list->count;
    list->sightings = (sighting_t *)realloc(list->sightings, list->count * sizeof(sighting_t));
    if (NULL == list->sightings)
    {
        return NULL;
    }

    new_sighting = &list->sightings[list->count - 1];
    memset(new_sighting, 0, sizeof(sighting_t)); /*zero out the new animal*/

    printf("Enter animal ID: ");
    scanf("%d", &new_sighting->animal_id);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", new_sighting->date);
    printf("Enter time (HH:MM): ");
    scanf("%s", new_sighting->time);
    printf("Enter location: ");
    scanf("%s", new_sighting->location);

    printf("\nSighting logged successfully.\n");
}

void DeleteSighting(sighting_list_t *list, int index)
{
    int i = 0;
    sighting_t *temp = NULL;

    assert(NULL != list);

    if (index < 0 || index >= list->count)
    {
        printf("Sighting not found.\n");
        return;
    }

    for (i = index; i < list->count - 1; ++i)
    {
        list->sightings[i] = list->sightings[i + 1];
    }

    --list->count;

    if (0 < list->count)
    {
        temp == (sighting_t *)realloc(list->sightings, list->count * sizeof(sighting_t));
        if (NULL == temp)
        {
            printf("Error reallocating memory\n");
            return;
        }

        list->sightings = temp;
    }
    else
    {
        free(list->sightings);
        list->sightings = NULL;
    }

    printf("Sighting deleted successfully\n");
}

void FreeSightingList(sighting_list_t *list)
{
    if (list->sightings)
    {
        free(list->sightings);
        list->sightings = NULL;
    }

    free(list);
}
