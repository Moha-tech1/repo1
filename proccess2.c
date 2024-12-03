#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

typedef struct doctors_data
{
    int id;
    char name[30];
    char Specialty[25];
    char Address[40];
    int Visita;
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
    /* records=0
    read=0
    read=fscanf(file, "%d,%29[^,],%24[^,],%39[^,],%d\n", &member[i].id
    , member[i].name, member[i].Specialty, member[i].Address, &member[i].Visita);*/

    fgets(header, 50, file);
    for (int i = 0; i < 30; i++)
    {
        fscanf(file, "%d,%29[^,],%24[^,],%39[^,],%d\n", &member[i].id, member[i].name, member[i].Specialty, member[i].Address, &member[i].Visita);
    }
    fclose(file);
}

void showDrData(void)
{
    for (int i = 0; i < 10; i++)
    {
        printf("ID:%d  Name:%s  Specialty:%s  Address:%s  Fees:%d$\n", member[i].id, member[i].name, member[i].Specialty, member[i].Address, member[i].Visita);
    }
}

void appendToDrData(void)
{
    FILE *file;
    file = fopen("doctors.csv", "a");
    if (file == NULL)
    {
        printf("error in openning file!");
        return;
    }
    // fprintf(file,"%d,%29[^,],%24[^,],%39[^,],%d\n",021,"Dr moha","Programming","Alex",500);
    fprintf(file, "%d,%s,%s,%s,%d\n", 21, "Dr moha", "Programming", "Alex", 500);
    fclose(file);
}

//*!###############################################################################################################
//*!                 patints data & function

#define NumberOfPatients 10

typedef struct patients_data
{
    int id;
    char name[30];
    char username[30];
    char password[20];
} patients;
patients p_member[NumberOfPatients];

// void updatePatientsData(void){
//     FILE *file;
//     file = fopen("patients.txt", "w");
//     if (file == NULL)
//     {
//         printf("error in openning file!");
//         return;
//     }
//     char header[30];
//     fputs("ID,name,username,password\n", file);
//     for (int i = 0; i < NumberOfPatients; i++)
//     {
//         fprintf(file, "%d,%s,%s,%s\n", i, p_member[i].name, p_member[i].username, p_member[i].password);
//     }
//     fclose(file);
// }

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

void showPatientsData(void)
{
    for (int i = 0; i < NumberOfPatients; i++)
    {
        printf("ID:%d  Name:%s  username:%s  password:%s\n", p_member[i].id, p_member[i].name, p_member[i].username, p_member[i].password);
    }
}

void sign_in(void)
{
    system("cls"); // to clear window
    char tempUser[30];
    char tempPass[20];
    bool check = false; // (true -> valid) (false -> invalid)
    printf("###############################################\n");
    printf("###############################################\n");
    printf("############### Welcome back ##################\n");

    for (int tries = 4; tries > 0; tries--)
{
    printf("\n###### Username: ");
    scanf("%29[^\n]", tempUser);
    getchar(); // تنظيف الإدخال المتبقي
    
    // إدخال كلمة المرور مع دعم Backspace
    char ch;
    int passLength = 0;
    printf("###### Password: ");
    
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
                passLength--;          // تقليل طول كلمة المرور
                printf("\b \b");       // حذف الحرف الأخير من الشاشة
            }
        }
        // إذا كان حرف عادي
        else if (passLength < 29) // قيود الطول
        {
            tempPass[passLength++] = ch; // إضافة الحرف إلى كلمة المرور
            printf("*");                // طباعة *
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
            break;
        }
    }

    if (check) 
        break;

    printf("\nInvalid username or password. You have %d tries left.\n", tries - 1);
}
}

void sign_up(void)
{
    char temp_name[30];
    char temp_username[30];
    char temp_password[20];
    printf("##### Kindly... fill the following information #####\n");
    printf("##### Your name: ");
    scanf("%29[^\n]", temp_name);

    getchar();

    printf("##### Create Username: ");
    bool check = false;
    for (int i = 0; i < NumberOfPatients; i++)
    {
        check = false;
        scanf("%29[^\n]", temp_username);
        getchar();
        for (size_t i = 0; i < NumberOfPatients; i++)
        {
            if (strcmp(temp_username, p_member[i].username) == 0)
                check = true;
        }
        if (check == true)
            printf("This username has been used already :(\ntry again\n##### Create Username: ");
        else
            break;
    }

    printf("##### Create Password:\nMake sure that password sould be 8 to 15 characters!\nMake sure that password must not contain spaces\n>>> ");
    for (int i = 0; i < NumberOfPatients; i++)
    {
        scanf("%15[^\n]", temp_password);
        getchar();
        if (strlen(temp_password) < 8 || strlen(temp_password) > 15)
        {
            printf("Invalid Password :(\nTry again: ");
        }
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
    fprintf(file, "\n%d,%s,%s,%s", 0, temp_name, temp_username, temp_password);
    fclose(file);

    system("cls"); // to clear window
    // greeting
    printf("\nWelcome, %s!\n", temp_name);
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
    else{
        retrievePatientsData();
        showPatientsData();
        sign_in();
    }
}

// FILE *file;
// file = fopen("patients.txt", "a");
// if (file == NULL)
// {
//     printf("error in openning file!");
//     return;
// }
// fprintf(file, "\n%d,%s,%s,%s", 1, temp_name, temp_username, temp_password);
// fclose(file);