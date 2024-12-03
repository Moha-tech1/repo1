#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "proccess2.c"

void main(void)
{
    retrieveDrData();
    // showDrData();
    retrievePatientsData();
    // showPatientsData();

    char option;
    while (true)
    {
        printf("###########################################################################\n");
        system("cls"); // to clear window
        printf("###########################################################################\n");
        printf("################### Welcome... We are here to serve You ###################\n");
        printf("###########################################################################\n");
        printf("####### 1-Sign in:\n");
        printf("####### 2-Sign up:\n>>>");
        scanf(" %c", &option);
        // printf("%d", option);

        //*? clear the \n that results from scanf()
        getchar(); // printf("%d",getchar());

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

        printf("####################### Welcome < %s >... #######################");
        printf("#################### What do you think today ####################");
        printf("##### 1 - Show Profile ##########################################");
        printf("##### 2 - Manage account ########################################");
        printf("##### 3 - Search for a doctor ###################################");
        printf("##### 4 - Book an appointment ###################################\n##### >>>");
        scanf(" %c", &option);
        getchar();
        switch (option)
        {
        case '1':
            // showProfile();
            break;
        case '2':
            /* code */
            break;
        case '3':
            /* code */
            break;
        case '4':
            /* code */
            break;

        default:
            break;
        }
    }
}