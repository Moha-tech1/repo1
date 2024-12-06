#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

int validate_password_input(char arr[])
{
    /*
     * Function to validate the password user input.
     * Set of valid characters = {Uppercase letters, Lowercase letters, _ , \t}
     * Returns 1 if valid
     * Returns 0 if not valid
     */
    bool valid = true;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        valid = true;
        if ((arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122) || (arr[i] >= 48 && arr[i] <= 57) || arr[i] == '_' || arr[i] == '\t')
        { // Makes sure that the name only contains either a space or lowercase letters or uppercase letters
            continue;
        }
        else
        {
            valid = false; // Name not valid
            break;
        }
    }
    return valid;
}

int validate_input(char arr[])
{
    /*
     * Function to validate the user input.
     * Set of valid characters = {Uppercase letters, Lowercase letters, space, _ }
     * Returns 1 if valid
     * Returns 0 if not valid
     */
    bool valid = true;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        valid = true;
        if ((arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122) || arr[i] == 32 || (arr[i] >= 48 && arr[i] <= 57) || arr[i] == 95)
        { // Makes sure that the name only contains either a space or lowercase letters or uppercase letters
            continue;
        }
        else
        {
            valid = false; // Name not valid
            break;
        }
    }
    return valid;
}

void clear_buffer(void)
{
    while (getchar() != '\n')
        ; // Keep reading until a newline character is encountered
}

#define NumberOfDoctors 10
#define NumberOfPatients 10

typedef struct doctors_data
{
    int id;
    char name[30];
    char Specialty[25];
    char Address[45];
    float Visita;
} doctors;
doctors member[10];

void retrieveDrData(void)
{
    FILE *file;
    file = fopen("doctors.txt", "r");
    if (file == NULL)
    {
        printf("error in openning file!");
        return;
    }
    char header[50];

    fgets(header, 50, file);
    for (int i = 0; i < 30; i++)
    {
        fscanf(file, "%d|%29[^|]|%24[^|]|%42[^|]|%f\n", &member[i].id, member[i].name, member[i].Specialty, member[i].Address, &member[i].Visita);
    }
    fclose(file);
}

void showDrData(void)
{
    for (int i = 0; i < 10; i++)
    {
        printf("ID:%-3dName:%-23sSpecialty:%-20sAddress:%-40sFees:%0.2f$\n", member[i].id, member[i].name, member[i].Specialty, member[i].Address, member[i].Visita);
    }
}

// void appendToDrData(void)
// {
//     FILE *file;
//     file = fopen("doctors.csv", "a");
//     if (file == NULL)
//     {
//         printf("error in openning file!");
//         return;
//     }
//     // fprintf(file,"%d,%29[^,],%24[^,],%39[^,],%d\n",021,"Dr moha","Programming","Alex",500);
//     fprintf(file, "%d,%s,%s,%s,%d\n", 21, "Dr moha", "Programming", "Alex", 500);
//     fclose(file);
// }

//*!###############################################################################################################
//*!                 patints data & function

char currentName[30];
char currentUsername[30];
char currentPass[20];
int currentIndex;

typedef struct patients_data
{
    int id;
    char name[30];
    char username[30];
    char password[20];
} patients;
patients p_member[NumberOfPatients];

void sign_up(void);

int count_file_lines(void)
{
    FILE *file = fopen("patients.txt", "r");

    int lines = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        // Each line ends in \n
        if (ch == '\n')
        {
            lines++;
        }
    }
    fclose(file);
    return lines + 1; // Normally the last line doesn't contain a \n so we account for that by adding 1
}

void updatePatientsData(int x)
{
    FILE *file;
    file = fopen("patients.txt", "w");
    if (file == NULL)
    {
        printf("error in openning file!");
        return;
    }
    char header[30];
    fputs("ID,name,username,password\n", file);

    for (int i = 0; i < x - 1; i++)
    {
        if (i != x - 2)
            fprintf(file, "%d,%s,%s,%s\n", i + 1, p_member[i].name, p_member[i].username, p_member[i].password);
        else
            fprintf(file, "%d,%s,%s,%s", i + 1, p_member[i].name, p_member[i].username, p_member[i].password);
    }
    fclose(file);
}

// !-----------------------------------------------------------------------------------------------------------------------------------------
void retrievePatientsData(void)
{
    FILE *file;
    file = fopen("patients.txt", "r");
    if (file == NULL)
    {
        printf("error in openning file!");
        return;
    }
    char header[30];
    fgets(header, 30, file);
    for (int i = 0; i < NumberOfPatients; i++)
    {
        int x;
        if (x = fscanf(file, "%d,%29[^,],%29[^,],%19[^\n]\n", &p_member[i].id, p_member[i].name, p_member[i].username, p_member[i].password) != 4)
        {
            // Print an error message and stop reading if there's an issue
            break;
            printf("Error reading data on line %d\n", i + 1);
            // Exit if fewer than 4 fields are read
        }
    }

    for (int i = 0; i < NumberOfPatients; i++)
    {
        int x;
        if (x == -1)
        {
            break;
        }
        x = fscanf(file, "%d,%29[^,],%29[^,],%19[^\n],\n", &p_member[i].id, p_member[i].name, p_member[i].username, p_member[i].password);
    }

    fclose(file);
    // updatePatientsData();
}
// !-----------------------------------------------------------------------------------------------------------------------------------------

// !-----------------------------------------------------------------------------------------------------------------------------------------
void showPatientsData(void)
{
    for (int i = 0; i < NumberOfPatients; i++)
    {
        printf("ID:%d  Name:%s  username:%s  password:%s\n", p_member[i].id, p_member[i].name, p_member[i].username, p_member[i].password);
    }
}
// !-----------------------------------------------------------------------------------------------------------------------------------------

// !-----------------------------------------------------------------------------------------------------------------------------------------
void sign_in(void)
{
    system("cls"); // to clear window
    char tempUser[30];
    char tempPass[20];
    bool check = false; // (true -> valid) (false -> invalid)
    printf("##############################################################################\n");
    printf("##############################################################################\n");
    printf("################################ Welcome back ################################\n");
    printf("##############################################################################\n");
    printf("##############################################################################\n");

    for (int tries = 4; tries > 0; tries--)
    {
        printf("\n###### Username: ");
        scanf("%29[^\n]", tempUser);
        clear_buffer();

        // إدخال كلمة المرور مع دعم Backspace
        char ch;
        int passLength = 0;
        printf("###### Password: ");
        // clear tempPass
        for (int i = 0; i < 16; i++)
        {
            tempPass[i] = 0;
        }
        while (1)
        {
            ch = getch(); // قراءة حرف واحد

            // إذا ضغط المستخدم Enter
            if (ch == 13)
            {
                break;
            }
            // إذا ضغط المستخدم Backspace
            else if (ch == 8)
            {
                if (passLength > 0)
                {
                    passLength--;    // تقليل طول كلمة المرور
                    printf("\b \b"); // حذف الحرف الأخير من الشاشة
                }
            }
            // إذا كان حرف عادي
            else if (passLength < 29) // قيود الطول
            {
                tempPass[passLength++] = ch; // إضافة الحرف إلى كلمة المرور
                printf("*");                 // طباعة *
            }
        }

        tempPass[passLength] = '\0'; // إنهاء كلمة المرور بسلسلة فارغة

        // التحقق من اسم المستخدم وكلمة المرور
        for (int i = 0; i < NumberOfPatients; i++)
        {
            if (strcmp(tempUser, p_member[i].username) == 0 && strcmp(tempPass, p_member[i].password) == 0)
            {
                check = true;
                printf("\nYou are successfully signed in :)\n");
                strcpy(currentName, p_member[i].name);
                strcpy(currentUsername, p_member[i].username);
                strcpy(currentPass, p_member[i].password);
                currentIndex = i;
                _sleep(4000);
                system("cls"); // to clear window
                break;
            }
        }

        if (check)
            break;
        if (tries == 1)
        {
            char choise;
            printf("\nSadly You cannot sign in for now.\nDo you want to:\n1 - sign up\n2 - exit\n>>>");
            scanf("%c", &choise);
            clear_buffer();
            if (choise == '1')
                sign_up();
            else if (choise == '2')
                exit(0);
            else
                exit(0);
        }

        printf("\nInvalid username or password. You have %d tries left.\n", tries - 1);
    }
}

void sign_up(void)
{
    char temp_name[30];
    char temp_username[30];
    char temp_password[20];
    printf("##############################################################################\n");
    printf("################## Kindly... fill the following information ##################\n");
    printf("##############################################################################\n");
    printf("##### Your name: ");

    while (true)
    {

        scanf("%29[^\n]", temp_name);
        clear_buffer();
        // char *pos_name = strpbrk(temp_name, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

        if (validate_input(temp_name) == false)
        {
            // printf("%s", pos);
            printf("Invalid Name!\nTry again: ");
        }
        else
        {
            break;
        }
    }

    printf("\n##### Create Username: ");
    bool check = false;
    while (true)
    {
        check = false;
        scanf("%29[^\n]", temp_username);
        clear_buffer();
        // char *pos_user = strpbrk(temp_username, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
        if (validate_input(temp_username) == false)
        {
            // printf("%s", pos);
            printf("Invalid Username!\nTry again: ");
            continue;
        }
        for (int i = 0; i < NumberOfPatients; i++)
        {
            if (strcmp(temp_username, p_member[i].username) == 0)
                check = true;
        }

        //
        if (check == true)
            printf("This username has been used already :(\ntry again\n##### Create Username: ");
        else
            break;
    }

    // *! Don't let password accept spaces or tabs
    printf("\n##### Create Password:\nMake sure that password should be 8 to 15 characters!\nMake sure that password must not contain spaces\n>>> ");
    while (true)
    {
        scanf("%30[^\n]", temp_password);
        clear_buffer();
        // char *pos_pass = strpbrk(temp_password, " \t");
        if (strlen(temp_password) < 8 || strlen(temp_password) > 15)
        {
            printf("Invalid Password :(\nTry again: ");
        }
        //

        else if (validate_password_input(temp_password) == false)
        {
            // printf("%s", pos);
            printf("The password can't contain space or tab or any special characters(except _)!\nTry again: ");
        }
        //
        else
            break;
    }
    FILE *file;
    file = fopen("patients.txt", "a");
    if (file == NULL)
    {
        printf("error in openning file!");
        return;
    }
    fprintf(file, "\n%d,%s,%s,%s", count_file_lines(), temp_name, temp_username, temp_password);
    fclose(file);

    system("cls"); // to clear window
    // greeting
    printf("Welcome, %s!\n", temp_name);
    printf("Thank you for signing up at the Clinic.\n");
    printf("Your account has been successfully created!\n");
    printf("You can now log in with your username: %s\n", temp_username);
    printf("We look forward to serving you!\n");

    char choose[10];

    printf("Do you want to continue or exit?\n>>> ");
    gets(choose);
    if (strcmp(choose, "exit") == 0)
    {
        printf("Bye Bye...");
        exit(0);
    }
    else
    {
        retrievePatientsData();
        // showPatientsData();
        sign_in();
    }
}

void greeting(void)
{
    printf("##############################################################################\n");
    printf("###################### Welcome >>> %-20s ######################\n", p_member[currentIndex].name);
    printf("########################## What do you think today ###########################\n");
    printf("##############################################################################\n");
    printf("###### 1 - Show Profile        ###############################################\n");
    printf("###### 2 - Manage account      ###############################################\n");
    printf("###### 3 - Search for a doctor ###############################################\n");
    printf("###### 4 - Sign out            ###############################################\n");
    printf("##############################################################################\n##### >>> ");
}

void showProfile(void)
{
    system("cls");
    printf("#########################################################\n");
    printf("############### This is Your private Info ###############\n");
    printf("#########################################################\n");
    printf("########## Name: %s \n", p_member[currentIndex].name);
    printf("########## Username: %s \n", p_member[currentIndex].username);
    printf("########## Password: %s \n", p_member[currentIndex].password);
    printf("#########################################################\n");
    printf(">Be careful! You can't share your information with anyone\n");
    printf("#########################################################\n");
    printf("Press (any key) to get back to home page...\n");
    /*getchar();*/getch();
    system("cls");
}

void manageAccount(void)
{
    system("cls");
    while (true)
    {
        // *! Delete my account
        printf("##############################################################################\n");
        printf("########################## What do you want to do? ###########################\n");
        printf("##############################################################################\n");
        printf("######## 1 - Edit Name #######################################################\n");
        printf("######## 2 - Edit Username ###################################################\n");
        printf("######## 3 - Change Password #################################################\n");
        printf("######## 4 - Delete my Account ###############################################\n");
        printf("##############################################################################\n");
        printf("##### >>> ");
        char option;
        option = getchar();
        clear_buffer();

        /* edit name */
        if (option == '1')
        {
            char tempName[30];

            printf("\nWrite the new name: ");

            while (true)
            {
                scanf("%29[^\n]", tempName);
                clear_buffer(); // تنظيف الإدخال المتبقي

                if (validate_input(tempName) == false)
                {
                    // printf("%s", pos);
                    printf("Invalid Name!\nTry again: ");
                    continue;
                }
                else
                    break;
            }

            strcpy(p_member[currentIndex].name, tempName);
            printf("Done :)\n");

            int x = count_file_lines();
            updatePatientsData(x);
            retrievePatientsData();

            _sleep(4000);
            system("cls"); // to clear window
            break;
        }

        /* edit username */
        else if (option == '2')
        {
            char tempUsername[30];

            printf("\nWrite the new username: ");
            while (true)
            {
                scanf("%29[^\n]", tempUsername);
                clear_buffer(); // تنظيف الإدخال المتبقي
                // char *pos_name = strpbrk(tempUsername, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
                if (validate_input(tempUsername) == false)
                {
                    // printf("%s", pos);
                    printf("Invalid Userame!\nTry again: ");
                    continue;
                }
                else
                    break;
            }
            strcpy(p_member[currentIndex].username, tempUsername);
            printf("Done :)\n");

            int x = count_file_lines();
            updatePatientsData(x);
            retrievePatientsData();

            _sleep(4000);
            system("cls"); // to clear window
            break;
        }
        /* edit password */
        else if (option == '3')
        {
            // *! add the two restriction
            char tempPass[30];
            
            printf("\nAssign a new Password: ");
            // scanf("%29[^\n]", tempPass);
            // getchar(); // تنظيف الإدخال المتبقي
            while (true)
            {
                scanf("%30[^\n]", tempPass);
                clear_buffer();
                // char *pos_pass = strpbrk(tempPass, " \t");
                if (strlen(tempPass) < 8 || strlen(tempPass) > 15)
                {
                    printf("Invalid Password :(\nTry again: ");
                }
                //

                else if (validate_password_input(tempPass) == false)
                {
                    // printf("%s", pos);
                    printf("The password can't contain space or tab or any special characters(except _)!\nTry again: ");
                }
                //
                else
                    break;
            }

            strcpy(p_member[currentIndex].password, tempPass);
            printf("Done :)\n");

            int x = count_file_lines();
            updatePatientsData(x);
            retrievePatientsData();

            _sleep(4000);
            system("cls"); // to clear window
            break;
            break;
        }
        else if (option == '4')
        {
            int x = count_file_lines();
            FILE *file;
            file = fopen("patients.txt", "w");
            if (file == NULL)
            {
                printf("error in openning file!");
                return;
            }
            char header[30];
            fputs("ID,name,username,password\n", file);

            if (currentIndex == x - 2)
            {
                for (int i = 0; i < x - 2; i++)
                {
                    if (i != x - 3)
                        fprintf(file, "%d,%s,%s,%s\n", i + 1, p_member[i].name, p_member[i].username, p_member[i].password);
                    else
                        fprintf(file, "%d,%s,%s,%s", i + 1, p_member[i].name, p_member[i].username, p_member[i].password);
                }
            }
            else
            {
                for (int i = 0; i < x - 1; i++)
                {
                    if (i == currentIndex)
                        continue;
                    else if (i != x - 2)
                        fprintf(file, "%d,%s,%s,%s\n", i + 1, p_member[i].name, p_member[i].username, p_member[i].password);
                    else
                        fprintf(file, "%d,%s,%s,%s", i + 1, p_member[i].name, p_member[i].username, p_member[i].password);
                }
            }
            fclose(file);
            printf("\nYour account have been deleted.");
            _sleep(4000);
            exit(0);
            break;
        }
        else
        {
            printf("\nInvalid choise\nTry again\n");
        }
    }
}

void searchDoctor(void)
{
    system("cls");
    printf("##############################################################################\n");
    printf("################################ We offer you ################################\n");
    printf("##### a variety of doctors with extensive experience and high competence #####\n");
    printf("################# You can search for doctors by their: #######################\n");
    printf("##############################################################################\n");
    printf("##### 1 - specialty              #############################################\n");
    printf("##### 2 - Name                   #############################################\n");
    printf("##### 3 - Show the complete list #############################################\n");
    printf("##############################################################################\n##### >>> ");
    char option;
    option = getchar();
    clear_buffer();

    // searsh by specility
    if (option == '1')
    {
        system("cls");
        
        printf("##############################################################################\n");
        printf("#### You can write the specialty (or any part of specialty) of the doctor ####\n");
        printf("##############################################################################\n");
        printf("\nSearch: ");
        char search[30];
        scanf("%29[^\n]", search);
        clear_buffer(); // تنظيف الإدخال المتبقي
        for (int i = 0; i < NumberOfDoctors; i++)
        {
            if (strstr(member[i].Specialty, search) != NULL)
            {
                printf("ID:%-3dName:%-23sSpecialty:%-24sAddress:%-32sFees:%d$\n", member[i].id, member[i].name, member[i].Specialty, member[i].Address, member[i].Visita);
            }
        }
        printf("Press (any key) to get back to home page...\n");
        /*getchar();*/getch();
        system("cls");
    }

    // searsh by name
    if (option == '2')
    {
        system("cls");

        printf("##############################################################################\n");
        printf("######## You can write the name (or any part of name) of the doctor ##########\n");
        printf("##############################################################################\n");
        printf("\nSearch: ");
        char search[30];
        scanf("%29[^\n]", search);
        clear_buffer(); // تنظيف الإدخال المتبقي
        for (int i = 0; i < NumberOfDoctors; i++)
        {
            if (strstr(member[i].name, search) != NULL)
            {
                printf("ID:%-3dName:%-23sSpecialty:%-24sAddress:%-32sFees:%d$\n", member[i].id, member[i].name, member[i].Specialty, member[i].Address, member[i].Visita);
            }
        }
        printf("Press (any key) to get back to home page...\n");
        /*getchar();*/getch();
        system("cls");
    }

    // Show the complete list
    if (option == '3')
    {
        system("cls");
        printf("##############################################################################\n");
        printf("################### <This is the Full list of the doctors> ###################\n");
        printf("##############################################################################\n");
        showDrData();
        printf("Press (any key) to get back to home page...\n");
        getch();
        system("cls");
    }
}

void sign_out(void)
{
    system("cls");
    printf("##############################################################################\n");
    printf("##################### We are pleased to have served you ######################\n");
    printf("#################### We look forward to your next visit! #####################\n");
    printf("##############################################################################\n");
    exit(0);
}
