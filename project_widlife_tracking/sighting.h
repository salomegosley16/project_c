/***************************
Dev: Salome Gosley
****************************/

#ifndef SIGHTING_H
#define SIGHTING_H

#define MAX_DATE_LENGTH 11
#define MAX_TIME_LENGTH 6
#define MAX_LOCATION_LEMGTH 50

typedef struct
{
    int animal_id;
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
    char location[MAX_LOCATION_LEMGTH];
} sighting_t;

typedef struct
{
    sighting_t *sightings;
    int count;
} sighting_list_t;

sighting_list_t *InitSightingList();

void *LogSighting(sighting_list_t *list);

/*Deletes a sighting from the sighting list by its index*/
void DeleteSighting(sighting_list_t *list, int index);

void FreeSightingList(sighting_list_t *list);

#endif
