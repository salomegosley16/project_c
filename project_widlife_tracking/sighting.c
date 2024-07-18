#include <stdio.h>    /*printf() scanf()*/
#include <stdlib.h>   /*mallo() realloc() free()*/
#include "sighting.h" /*sighting.h header*/
#include <assert.h>   /*assert()*/

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

void FreeSightingList(sighting_list_t *list)
{
    if (list->sightings)
    {
        free(list->sightings);
    }

    free(list);
}
