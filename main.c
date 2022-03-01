#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "car.h"

int main()
{
    int type, found, choice;
    User *user;
    welcomeScreen();
    addAdmin();

    do
    {
        userOptions();
        scanf("%d", &type);
        found = 0;
        if (type == 1)
        {
            do
            {
                user = getInput();
                if (user != NULL)
                {
                    found = checkUserExist(*user, "admin");
                }
                else
                {
                    exitCode();
                }
            } while (found == 0);

            if (found == -1)
            {
                exitCode();
            }
            if (found == 1)
            {
                gotoxy(1, 20);
                textcolor(WHITE);
                printf("Press any key to continue");
                _getch();
                while (1)
                {
                    int x;
                    clrscr();
                    choice = adminMenu();
                    if (choice == 7)
                        break;
                    switch (choice)
                    {
                    case 1:
                        clrscr();
                        x = addEmployee();
                        if (x == -1)
                        {
                            textcolor(WHITE);
                            printf("\n Press any key to go back to main menu");
                            getch();
                        }
                        break;
                    case 2:
                        clrscr();
                        x = addCarDetails();
                        if (x == -1)
                        {
                            textcolor(WHITE);
                            printf("\n Press any key to go back to main menu");
                            getch();
                        }
                        break;
                    case 3:
                        clrscr();
                        viewEmployee();
                        break;
                    case 4:
                        clrscr();
                        showCarDetails();
                        break;
                    case 5:
                        clrscr();
                        int result = deleteEmp();
                        gotoxy(25, 16);
                        if (result == -1)
                        {
                            break;
                        }
                        if (result == 0)
                        {
                            textcolor(LIGHTRED);
                            printf("Sorry! No record of the given employee found");
                        }
                        else if (result == 1)
                        {
                            textcolor(LIGHTGREEN);
                            printf("Record deleted successfully");
                        }
                        else if (result == 2)
                        {
                            textcolor(LIGHTRED);
                            printf("Error in deletion");
                        }
                        textcolor(WHITE);
                        printf("\n Press any key to go back to main menu");
                        getch();
                        break;
                    case 6:
                        clrscr();
                        result = deleteCarModel();
                        gotoxy(25, 16);
                        if (result == -1)
                        {
                            break;
                        }
                        if (result == 0)
                        {
                            textcolor(LIGHTRED);
                            printf("Sorry! No record of the given car found");
                        }
                        else if (result == 1)
                        {
                            textcolor(LIGHTGREEN);
                            printf("Record deleted successfully");
                        }
                        else if (result == 2)
                        {
                            textcolor(LIGHTRED);
                            printf("Error in deletion");
                        }
                        textcolor(WHITE);
                        printf("\n Press any key to go back to main menu");
                        getch();
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        else if (type == 2)
        {
            do
            {
                user = getInput();
                if (user != NULL)
                {
                    found = checkUserExist(*user, "emp");
                }
                else
                {
                    exitCode();
                }
            } while (found == 0);

            if (found == -1)
            {
                exitCode();
            }
            if (found == 1)
            {
                gotoxy(1, 20);
                textcolor(WHITE);
                printf("Press any key to continue");
                _getch();
                while (1)
                {
                    clrscr();
                    choice = empMenu();
                    if (choice == 6)
                        break;
                    switch (choice)
                    {
                    case 1:
                        clrscr();
                        int rentresp;
                        rentresp = rentCar();
                        if (rentresp == -2)
                        {
                            gotoxy(35, 9);
                            textcolor(LIGHTRED);
                            printf("Sorry! All cars booked. Try later");
                            getch();
                        }
                        else if (rentresp == 0)
                        {
                            gotoxy(27, 18);
                            textcolor(LIGHTRED);
                            printf("You did not choose any car");
                            getch();
                        }

                        break;
                    case 2:
                        clrscr();
                        bookedCarDetails();
                        break;
                    case 3:
                        clrscr();
                        availCarDetails();
                        break;
                    case 4:
                        clrscr();
                        showCarDetails();
                        break;
                    case 5:
                        clrscr();
                        int result=returnCar();
                        gotoxy(25, 16);
                        if (result == -1)
                        {
                            break;
                        }
                        if (result == 0)
                        {
                            textcolor(LIGHTRED);
                            printf("Sorry! No record of the given car found");
                        }
                        else if (result == 1)
                        {
                            textcolor(LIGHTGREEN);
                            printf("Record deleted successfully");
                        }
                        else if (result == 2)
                        {
                            textcolor(LIGHTRED);
                            printf("Error in deletion");
                        }
                        textcolor(WHITE);
                        printf("\n Press any key to go back to main menu");
                        getch();
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        else if (type == 3)
        {
            exitCode();
        }
        else
        {
            textcolor(RED);
            gotoxy(33, 20);
            printf("Invalid Type!");
            getch();
            gotoxy(30, 20);
            printf("\t\t\t");
            gotoxy(50, 16);
            printf("\t\t\t");
            gotoxy(50, 16);
            textcolor(WHITE);
        }
    } while (1);
    return 0;
}
