#include <stdio.h>  /*printf()*/
#include "report.h" /*report.h header*/
#include <assert.h> /*assert()*/

void GenerateReports(animal_list_t *animal_list, sighting_list_t *sighting_list)
{
    int i = 0;
    int j = 0;
    int sighting_count = 0;

    assert(NULL != animal_list);
    assert(NULL != sighting_list);

    printf("\nTotal number of animals: %d\n", animal_list->count);
    printf("\nTotal number of sightings: %d\n\n", sighting_list->count);

    for (i = 0; i < animal_list->count; ++i)
    {
        sighting_count = 0;
        printf("Animal ID: %d, Species: %s\n", animal_list->animals[i].id, animal_list->animals[i].species);

        for (j = 0; j < sighting_list->count; ++j)
        {
            if (sighting_list->sightings[j].animal_id == animal_list->animals[i].id)
            {
                printf("  Sighting Indes: %d, Date: %s, Time: %s, Location: %s\n", j, sighting_list->sightings[j].date, sighting_list->sightings[j].time, sighting_list->sightings[j].location);
                ++sighting_count;
            }
        }

        printf("Total Sightings for Animal ID %d: %d\n\n", animal_list->animals[i].id, sighting_count);
    }
}
