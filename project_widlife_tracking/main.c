#include <stdio.h>    /*printf() scanf()*/
#include "animal.h"   /*animal.h header*/
#include "sighting.h" /*sighting.h header*/
#include "file_io.h"  /*file_io.h header*/
#include "report.h"   /*report.h header*/

void DisplayMenu();

int main()
{
    int choice = 0;

    animal_list_t *animal_list = InitAnimalList();
    sighting_list_t *sighting_list = InitSightingList();

    LoadAnimals(animal_list);
    LoadSightings(sighting_list);

    do
    {
        DisplayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            AddAnimal(animal_list);
            break;
        case 2:
            LogSighting(sighting_list);
            break;
        case 3:
            UpdateAnimal(animal_list);
            break;
        case 4:
            ViewAnimalDetails(animal_list, sighting_list);
            break;
        case 5:
            GenerateReports(animal_list, sighting_list);
            break;
        case 6:
            SaveAnimals(animal_list);
            SaveSightings(sighting_list);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (6 != choice);

    FreeAnimalList(animal_list);
    FreeSightingList(sighting_list);

    return 0;
}

void DisplayMenu()
{
    printf("\nWildlife Tracking System\n");
    printf("1. Add Animal\n");
    printf("2. LogSighting\n");
    printf("3. Update Animal Details\n");
    printf("4. View Animal Details\n");
    printf("5. Generate Reports\n");
    printf("6. Save and Exit\n");
    printf("Enter your choice: ");
}
