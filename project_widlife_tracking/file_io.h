/***************************
Dev: Salome Gosley
****************************/

#ifndef FILE_IO_H
#define FILE_IO_H

#include "animal.h" /*animal.h header*/

/*saves the list of animals to a file*/
void SaveAnimals(animal_list_t *list);

/*loads the list of animals from a file*/
void LoadAnimals(animal_list_t *list);

/*saves the list of sightings to a file*/
void SaveSightings(sighting_list_t *list);

/*loads the list of sightings from a file*/
void LoadSightings(sighting_list_t *list);

#endif