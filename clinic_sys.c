#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "proccess3.c"

void main(void)
{
    retrieveDrData();
    // showDrData();
    retrievePatientsData();
    // showPatientsData();
    // exit(0);

    char option;
    bool cheack = false;
    while (true)
    {

        printf("##############################################################################\n");
        system("cls"); // to clear window
        printf("##############################################################################\n");
        printf("##################### SmartCare Clinic  Management System ####################\n");
        printf("##############################################################################\n");
        printf("##################### Welcome... We are here to serve You ####################\n");
        printf("##############################################################################\n");
        printf("######## 1 - Sign in:      ###################################################\n");
        printf("######## 2 - Sign up:      ###################################################\n");
        printf("######## 3 - exit program: ###################################################\n");
        printf("##############################################################################\n>>> ");
        while (true)
        {
            scanf(" %c", &option);
            clear_buffer();
            // printf("%d", option);

            system("cls"); // to clear window

            switch (option)
            {
            case '1':

                sign_in();
                cheack = true;
                break;

            case '2':
                sign_up();
                cheack = true;
                break;
            
            case '3':
                exit(0);
                break;

            default:
                printf("Wrong input!\nTry again: ");
                break;
            }
            if (cheack == true)
                break;
        }

        while (true)
        {
            greeting();
            scanf(" %c", &option);
            clear_buffer();
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
