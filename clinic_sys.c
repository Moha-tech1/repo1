// *! if the user press any key (not (1 or 2)) the program should loop again

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "process2.c"

// Comment from kimoooooooooooooooo
void main(void)
{
    retrieveDrData();
    // showDrData();
    retrievePatientsData();
    // showPatientsData();

    char option;
    while (true)
    {
        printf("##############################################################################\n");
        system("cls"); // to clear window
        printf("##############################################################################\n");
        printf("##################### SmartCare Clinic  Management System ####################\n");
        printf("##############################################################################\n");
        printf("##################### Welcome... We are here to serve You ####################\n");
        printf("##############################################################################\n");
        printf("######## 1-Sign in: ##########################################################\n");
        printf("######## 2-Sign up: ##########################################################\n");
        printf("##############################################################################\n>>> ");
        scanf(" %c", &option);
        clear_buffer();
        // printf("%d", option);

        system("cls"); // to clear window

        switch (option)
        {
        case '1':

            sign_in();
            break;

        case '2':
            sign_up();
            break;

        default:
            printf("Wrong input\nTry again later :(");
            exit(0);
            break;
        }

        // *! sign_out();
        while (true)
        {
            greeting();
            scanf(" %c", &option);
            getchar();
            switch (option)
            {
            case '1':
                showProfile();
                break;
            case '2':
                manageAccount();
                break;
            case '3':
                searchDoctor();
                break;
            case '4':
                sign_out();
                break;

            default:
                break;
            }
        }
    }
}
