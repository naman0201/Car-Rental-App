#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "conio2.h"
#include "car.h"

void welcomeScreen()
{
    gotoxy(25, 10);
    textcolor(YELLOW);
    printf("WELCOME TO CAR RENTAL SYSTEM");
    gotoxy(20, 13);
    textcolor(LIGHTGREEN);
    printf("* RENT A CAR AND GO WHEREVER YOU NEED *");
    textcolor(YELLOW);
}

void addAdmin()
{

    User admins[2] = {
        {"naman", "naman123", "Naman Tiwari"},
        {"sanjay", "sanjay123", "Sanjay Verma"},
    };
    FILE *fp = fopen("h:\\Online C Project 2\\Car Rental App Files\\alladmins.bin", "rb");
    if (fp == NULL)
    {
        fp = fopen("h:\\Online C Project 2\\Car Rental App Files\\alladmins.bin", "wb");
        fwrite(admins, 2 * sizeof(User), 1, fp);
    }
    getch();
    fclose(fp);
}

void userOptions()
{
    int i;
    clrscr();
    textcolor(GREEN);
    gotoxy(32, 2);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1, 8);
    textcolor(YELLOW);
    for (i = 0; i < 80; i++)
    {
        printf("*");
    }
    gotoxy(1, 19);
    for (i = 0; i < 80; i++)
    {
        printf("*");
    }
    textcolor(BLUE);
    gotoxy(32, 10);
    printf("1. Admin");
    gotoxy(32, 12);
    printf("2. Employee");
    gotoxy(32, 14);
    textcolor(RED);
    printf("3. Quit");
    gotoxy(32, 16);
    textcolor(WHITE);
    printf("Select Your role: ");
}
void exitCode()
{
    clrscr();
    textcolor(GREEN);
    gotoxy(30, 12);
    printf("Thank You for using the app");
    textcolor(WHITE);
    getch();
    exit(0);
}
User *getInput()
{
    int i;
    clrscr();
    textcolor(GREEN);
    gotoxy(32, 2);
    printf("CAR RENTAL SYSTEM\n");
    textcolor(YELLOW);
    for (i = 1; i <= 80; i++)
        printf("%c", 247);
    gotoxy(32, 7);
    textcolor(LIGHTBLUE);
    printf("*LOGIN PANEL*\n");
    gotoxy(1, 9);
    textcolor(CYAN);
    for (i = 1; i <= 80; i++)
        printf("%c", 247);
    gotoxy(1, 19);
    for (i = 1; i <= 80; i++)
        printf("%c", 247);
    gotoxy(65, 10);
    textcolor(RED);
    printf("Press 0 to exit");
    textcolor(LIGHTCYAN);
    gotoxy(27, 13);
    printf("Enter UserID:- ");
    textcolor(WHITE);
    static User user;
    fflush(stdin);
    fgets(user.userid, 20, stdin);
    char *pos;
    pos = strchr(user.userid, '\n');
    if (pos != NULL)
        *pos = '\0';
    if (strcmp(user.userid, "0") == 0)
    {
        textcolor(LIGHTRED);
        gotoxy(30, 21);
        printf("Login Cancelled!");
        getch();
        return NULL;
    }
    textcolor(LIGHTCYAN);
    gotoxy(27, 15);
    printf("Enter Password:- ");
    fflush(stdin);
    i = 0;
    char ch;
    textcolor(WHITE);
    while (1)
    {
        ch = getch();
        if (ch == 13)
            break;
        if (ch == 8)
        {
            if (i == 0)
                continue;
            printf("\b \b");
            i--;
            continue;
        }
        printf("%c", ch);
        delay(100);
        printf("\b*");
        user.pwd[i] = ch;
        i++;
    }
    user.pwd[i] = '\0';
    if (strcmp(user.pwd, "0") == 0)
    {
        textcolor(LIGHTRED);
        gotoxy(30, 21);
        printf("Login Cancelled!");
        getch();
        return NULL;
    }
    return &user;
}

int checkUserExist(User user, char *usertype)
{
    int found = 0;
    User local_user;
    FILE *fp;
    if (strlen(user.userid) == 0 || strlen(user.pwd) == 0)
    {
        gotoxy(23, 21);
        textcolor(LIGHTRED);
        printf("Both Fields are mandatory. Try Again!");
        getch();
        gotoxy(23, 21);
        printf("\t\t\t\t");
        return 0;
    }
    if (strcmp(usertype, "admin") == 0)
    {
        fp = fopen("../Car Rental App Files/alladmins.bin", "rb");
    }
    else
    {
        fp = fopen("../Car Rental App Files/emp.bin", "rb");
    }
    if (fp == NULL)
    {
        gotoxy(23, 21);
        textcolor(LIGHTRED);
        printf("Sorry! cannot open the file.");
        getch();
        gotoxy(23, 21);
        printf("\t\t\t\t");
        return -1;
    }
    while (fread(&local_user, sizeof(local_user), 1, fp) == 1)
    {
        if (strcmp(local_user.userid, user.userid) == 0 && strcmp(local_user.pwd, user.pwd) == 0)
        {
            found = 1;
            break;
        }
    }
    if (!found)
    {
        gotoxy(23, 21);
        textcolor(LIGHTRED);
        printf("Invalid userid/password. Try again");
        getch();
        gotoxy(23, 21);
        printf("\t\t\t\t\t\t\t");
    }
    else
    {
        gotoxy(28, 21);
        textcolor(GREEN);
        printf("Login successful!");
        getch();
        gotoxy(28, 21);
        printf("\t\t\t\t\t\t\t");
    }
    fclose(fp);
    return found;
}

int adminMenu()
{
    int i, choice;
    textcolor(LIGHTGREEN);
    gotoxy(32, 2);
    printf("CAR RENTAL SYSTEM");
    gotoxy(35, 6);
    textcolor(LIGHTBLUE);
    printf("ADMIN MENU\n");
    textcolor(YELLOW);
    for (i = 1; i <= 80; i++)
    {
        printf("*");
    }

    textcolor(BLUE);
    gotoxy(32, 9);
    printf("1. Add Employee");
    gotoxy(32, 10);
    printf("2. Add Car Details");
    gotoxy(32, 11);
    printf("3. Show Employee");
    gotoxy(32, 12);
    printf("4. Show Car Details");
    gotoxy(32, 13);
    printf("5. Delete Employee");
    gotoxy(32, 14);
    printf("6. Delete Car Details");
    gotoxy(32, 15);
    textcolor(RED);
    printf("7. EXIT");
    gotoxy(32, 17);
    textcolor(WHITE);
    printf("Enter choice: ");
    scanf("%d", &choice);
    return choice;
}

int addEmployee()
{
    char temp[20];
    char choice;
    char *pos;
    int total_rec;
    User u;
    FILE *fp = fopen("h:\\Online C Project 2\\Car Rental App Files\\emp.bin", "ab+");
    fseek(fp, 0, SEEK_END);
    total_rec = ftell(fp) / sizeof(User);
    if (total_rec != 0)
    {
        fseek(fp, -60, SEEK_END);
        fread(temp, sizeof(temp), 1, fp);
        pos = strchr(temp, '-');
        total_rec = atoi(pos + 1);
    }
        total_rec++;
        sprintf(u.userid, "EMP-%d", total_rec);
        fseek(fp, 0, SEEK_END);
    do
    {

        clrscr();
        textcolor(LIGHTGREEN);
        gotoxy(32, 2);
        printf("CAR RENTAL SYSTEM");
        textcolor(YELLOW);
        int i;
        gotoxy(1, 3);
        for (i = 1; i <= 80; i++)
            printf("~");
        textcolor(RED);
        gotoxy(65, 23);
        printf("Press 0 to exit");
        textcolor(LIGHTBLUE);
        gotoxy(25, 5);
        printf("***** ADD EMPLOYEE DETAILS *****");
        gotoxy(2, 8);
        textcolor(LIGHTCYAN);
        printf("Enter Employee Name: ");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.name, 20, stdin);
        char *pos;
        pos = strchr(u.name, '\n');
        if (pos != NULL)
            *pos = '\0';
        if (strcmp(u.name, "0") == 0)
        {
            textcolor(RED);
            gotoxy(25, 20);
            printf("Adding Employee cancelled");
            getch();
            return -1;
        }
        gotoxy(2, 9);
        textcolor(LIGHTCYAN);
        printf("Enter Employee Password: ");
        fflush(stdin);
        textcolor(WHITE);
        fgets(u.pwd, 20, stdin);
        pos = strchr(u.pwd, '\n');
        if (pos != NULL)
            *pos = '\0';
        if (strcmp(u.pwd, "0") == 0)
        {
            textcolor(LIGHTRED);
            gotoxy(25, 20);
            printf("Adding Employee cancelled");
            getch();
            return -1;
        }
        fwrite(&u, sizeof(u), 1, fp);
        gotoxy(30, 15);
        textcolor(GREEN);
        printf("EMPLOYEE ADDED SUCCESSFULY");
        gotoxy(30, 16);
        printf("EMPLOYEE ID is %s", u.userid);
        getch();
        gotoxy(1, 20);
        textcolor(CYAN);
        printf("Do you want to add more employees (Y/N)");
        textcolor(WHITE);
        fflush(stdin);
        scanf("%c", &choice);
        if (choice == 'N')
            break;
        total_rec++;
        sprintf(u.userid, "EMP-%d", total_rec);
    } while (1);
    fclose(fp);
    return 0;
}

int addCarDetails()
{
    char choice;
    int total_rec;
    Car c,c2;
    FILE *fp = fopen("h:\\Online C Project 2\\Car Rental App Files\\car.bin", "ab+");
    fseek(fp, 0, SEEK_END);
    total_rec=ftell(fp)/sizeof(Car);
    if (total_rec != 0)
    {
        fseek(fp, -1*sizeof(c2), SEEK_END);
        fread(&c2,sizeof(c2),1,fp);
        total_rec=c2.car_id;
    }

    do
    {
        total_rec++;
        c.car_id = total_rec;
        fseek(fp, 0, SEEK_END);
        clrscr();
        textcolor(LIGHTGREEN);
        gotoxy(32, 2);
        printf("CAR RENTAL SYSTEM");
        textcolor(YELLOW);
        int i;
        gotoxy(1, 3);
        for (i = 1; i <= 80; i++)
            printf("~");
        textcolor(RED);
        gotoxy(65, 23);
        printf("Press 0 to exit");
        textcolor(LIGHTBLUE);
        gotoxy(25, 5);
        printf("***** ADD CAR DETAILS *****");
        textcolor(LIGHTCYAN);
        gotoxy(2, 8);
        printf("Enter Car Model: ");
        fflush(stdin);
        textcolor(WHITE);
        fgets(c.car_name, 50, stdin);
        char *pos;
        pos = strchr(c.car_name, '\n');
        if (pos != NULL)
            *pos = '\0';
        if (strcmp(c.car_name, "0") == 0)
        {
            textcolor(LIGHTRED);
            gotoxy(25, 20);
            printf("Adding Car cancelled");
            getch();
            return -1;
        }
        textcolor(LIGHTCYAN);
        gotoxy(2, 9);
        printf("Enter Car Capacity: ");
        fflush(stdin);
        textcolor(WHITE);
        scanf("%d", &c.capacity);
        if (c.capacity == 0)
        {
            textcolor(LIGHTRED);
            gotoxy(25, 20);
            printf("Adding Car cancelled");
            getch();
            return -1;
        }
        textcolor(LIGHTCYAN);
        gotoxy(2, 10);
        printf("Enter Car Count: ");
        fflush(stdin);
        textcolor(WHITE);
        scanf("%d", &c.car_count);
        c.total_count=c.car_count;
        if (c.car_count == 0)
        {
            textcolor(LIGHTRED);
            gotoxy(25, 20);
            printf("Adding Car cancelled");
            getch();
            return -1;
        }
        textcolor(LIGHTCYAN);
        gotoxy(2, 11);
        printf("Enter Car price for per day: ");
        fflush(stdin);
        textcolor(WHITE);
        scanf("%d", &c.price);
        if (c.price == 0)
        {
            textcolor(LIGHTRED);
            gotoxy(25, 20);
            printf("Adding Car cancelled");
            getch();
            return -1;
        }
        fwrite(&c, sizeof(c), 1, fp);
        gotoxy(30, 15);
        textcolor(GREEN);
        printf("CAR ADDED SUCCESSFULY");
        gotoxy(30, 16);
        printf("CAR ID is %d", c.car_id);
        getch();
        gotoxy(1, 20);
        textcolor(CYAN);
        printf("Do you want to add more cars (Y/N)");
        textcolor(WHITE);
        fflush(stdin);
        scanf("%c", &choice);
        if (choice == 'N')
            break;
    } while (1);
    fclose(fp);
    return 0;
}

void viewEmployee()
{
    FILE *fp = fopen("h:\\Online C Project 2\\Car Rental App Files\\emp.bin", "rb");
    User ur;
    int i;
    textcolor(LIGHTGREEN);
    gotoxy(32, 2);
    printf("CAR RENTAL SYSTEM\n");
    textcolor(YELLOW);
    for (i = 1; i <= 80; i++)
        printf("%c", 247);
    textcolor(LIGHTBLUE);
    gotoxy(31, 5);
    printf("* EMPLOYEE DETAILS *");
    gotoxy(1, 7);
    textcolor(CYAN);
    for (i = 0; i < 80; i++)
        printf("%c", 247);
    if (fp == NULL)
    {
        gotoxy(31, 9);
        textcolor(LIGHTRED);
        printf("Sorry!NO EMPLOYEES ADDED YET!");
        getch();
        return;
    }
    gotoxy(1, 8);
    textcolor(WHITE);
    printf("EMPLOYEE ID\t\t\tNAME\t\t\tPASSWORD");
    gotoxy(1, 9);
    textcolor(CYAN);
    for (i = 0; i < 80; i++)
        printf("%c", 247);
    int row = 11;
    textcolor(LIGHTCYAN);
    while (fread(&ur, sizeof(ur), 1, fp) == 1)
    {
        gotoxy(2, row);
        printf("%s", ur.userid);
        gotoxy(33, row);
        printf("%s", ur.name);
        gotoxy(57, row);
        printf("%s", ur.pwd);
        row++;
    }
    fclose(fp);
    getch();
}
void showCarDetails()
{
    FILE *fp = fopen("h:\\Online C Project 2\\Car Rental App Files\\car.bin", "rb");
    Car c;
    int i;
    textcolor(LIGHTGREEN);
    gotoxy(32, 2);
    printf("CAR RENTAL SYSTEM\n");
    textcolor(YELLOW);
    for (i = 1; i <= 80; i++)
        printf("%c", 247);
    textcolor(LIGHTBLUE);
    gotoxy(31, 5);
    printf("* CAR DETAILS *");
    gotoxy(1, 7);
    textcolor(CYAN);
    for (i = 0; i < 80; i++)
        printf("%c", 247);
    if (fp == NULL)
    {
        gotoxy(31, 9);
        textcolor(LIGHTRED);
        printf("Sorry! NO CARS ADDED YET!");
        getch();
        return;
    }
    gotoxy(1, 8);
    textcolor(WHITE);
    printf("CAR ID   CAR MODEL\tCAR CAPACITY\tCAR COUNT\tCAR PRICE PER DAY");
    gotoxy(1, 9);
    textcolor(CYAN);
    for (i = 0; i < 80; i++)
        printf("%c", 247);
    int row = 11;
    textcolor(LIGHTCYAN);
    while (fread(&c, sizeof(c), 1, fp) == 1)
    {
        gotoxy(3, row);
        printf("%d", c.car_id);
        gotoxy(10, row);
        printf("%s", c.car_name);
        gotoxy(30, row);
        printf("%d", c.capacity);
        gotoxy(44, row);
        printf("%d", c.total_count);
        gotoxy(64, row);
        printf("%d", c.price);
        row++;
    }
    fclose(fp);
    getch();
}

int deleteEmp()
{
    FILE *fp1 = fopen("h:\\Online C Project 2\\Car Rental App Files\\emp.bin", "rb");
    char empid[10];
    int i, result;
    textcolor(RED);
    gotoxy(65, 23);
    printf("Press 0 to exit");
    textcolor(GREEN);
    gotoxy(32, 2);
    printf("CAR RENTAL SYSTEM\n");
    textcolor(YELLOW);
    for (i = 1; i < 80; i++)
        printf("%c", 247);
    gotoxy(1, 8);
    textcolor(CYAN);
    for (i = 1; i < 80; i++)
        printf("%c", 247);
    gotoxy(1, 14);
    for (i = 1; i < 80; i++)
        printf("%c", 247);
    gotoxy(30, 6);
    textcolor(LIGHTBLUE);
    printf("* Delete Employee Record *");
    if (fp1 == NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(32, 17);
        printf("NO EMPLOYEES ADDED YET!");
        return -1;
    }
    FILE *fp2 = fopen("h:\\Online C Project 2\\Car Rental App Files\\temp.bin", "wb");
    if (fp2 == NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(32, 17);
        printf("SORRY CANNOT CREATE TEMP FILE");
        return -1;
    }
    gotoxy(8, 11);
    textcolor(LIGHTCYAN);
    printf("Enter employee ID to delete the record:");
    textcolor(WHITE);
    scanf("%s", empid);
    if (strcmp(empid, "0") == 0)
    {
        textcolor(LIGHTRED);
        gotoxy(25, 20);
        printf("Deleting Employee Cancelled");
        getch();
        return -1;
    }
    User u;
    int found = 0;
    while (fread(&u, sizeof(u), 1, fp1) == 1)
    {
        if (strcmp(u.userid, empid) != 0)
            fwrite(&u, sizeof(u), 1, fp2);
        else
            found = 1;
    }
    fclose(fp1);
    fclose(fp2);
    if (found == 0)
        remove("h:\\Online C Project 2\\Car Rental App Files\\temp.bin");
    else
    {
        result = remove("h:\\Online C Project 2\\Car Rental App Files\\emp.bin");
        if (result != 0)
            return 2;
        result = rename("h:\\Online C Project 2\\Car Rental App Files\\temp.bin", "h:\\Online C Project 2\\Car Rental App Files\\emp.bin");
        if (result != 0)
            return 2;
    }
    return found;
}

int deleteCarModel()
{
    FILE *fp1 = fopen("h:\\Online C Project 2\\Car Rental App Files\\car.bin", "rb");
    int carid;
    int i, result;
    textcolor(RED);
    gotoxy(65, 23);
    printf("Press 0 to exit");
    textcolor(GREEN);
    gotoxy(32, 2);
    printf("CAR RENTAL SYSTEM\n");
    textcolor(YELLOW);
    for (i = 1; i < 80; i++)
        printf("%c", 247);
    gotoxy(1, 8);
    textcolor(CYAN);
    for (i = 1; i < 80; i++)
        printf("%c", 247);
    gotoxy(1, 14);
    for (i = 1; i < 80; i++)
        printf("%c", 247);
    gotoxy(30, 6);
    textcolor(LIGHTBLUE);
    printf("* Delete Car Record *");
    if (fp1 == NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(32, 17);
        printf("NO CAR ADDED YET!");
        return -1;
    }
    FILE *fp2 = fopen("h:\\Online C Project 2\\Car Rental App Files\\temp.bin", "wb");
    if (fp2 == NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(32, 17);
        printf("SORRY CANNOT CREATE TEMP FILE");
        return -1;
    }
    gotoxy(8, 11);
    textcolor(LIGHTCYAN);
    printf("Enter CAR ID to delete the record:");
    textcolor(WHITE);
    scanf("%d", &carid);
    if (carid == 0)
    {
        textcolor(LIGHTRED);
        gotoxy(25, 20);
        printf("Deleting CAR Cancelled");
        getch();
        return -1;
    }
    Car c;
    int found = 0;
    while (fread(&c, sizeof(c), 1, fp1) == 1)
    {
        if (c.car_id != carid)
            fwrite(&c, sizeof(c), 1, fp2);
        else
            found = 1;
    }
    fclose(fp1);
    fclose(fp2);
    if (found == 0)
        remove("h:\\Online C Project 2\\Car Rental App Files\\temp.bin");
    else
    {
        result = remove("h:\\Online C Project 2\\Car Rental App Files\\car.bin");
        if (result != 0)
            return 2;
        result = rename("h:\\Online C Project 2\\Car Rental App Files\\temp.bin", "h:\\Online C Project 2\\Car Rental App Files\\car.bin");
        if (result != 0)
            return 2;
    }
    return found;
}

int empMenu()
{
    int i, choice;
    textcolor(LIGHTGREEN);
    gotoxy(32, 2);
    printf("CAR RENTAL SYSTEM");
    gotoxy(35, 6);
    textcolor(LIGHTBLUE);
    printf("Employee MENU\n");
    textcolor(YELLOW);
    for (i = 1; i <= 80; i++)
    {
        printf("*");
    }

    textcolor(BLUE);
    gotoxy(32, 9);
    printf("1. Rent A Car");
    gotoxy(32, 10);
    printf("2. Booking Details");
    gotoxy(32, 11);
    printf("3. Available Car Details");
    gotoxy(32, 12);
    printf("4. Show All Car Details");
    gotoxy(32, 13);
    printf("5. Return Car");
    gotoxy(32,14);
    textcolor(RED);
    printf("6. EXIT");
    gotoxy(32, 17);
    textcolor(WHITE);
    printf("Enter choice: ");
    scanf("%d", &choice);
    return choice;
}

int selectCarModel()
{
    FILE *fp = fopen("../Car Rental App Files/car.bin", "rb");
    int flag;
    int choice, rowno = 9;
    Car C;
    gotoxy(34, rowno);
    int carcount = 0;
    while (fread(&C, sizeof(C), 1, fp) == 1)
    {
        if (C.car_count > 0)
        {
            printf("%d .  %s", C.car_id, C.car_name);
            gotoxy(34, ++rowno);
            ++carcount;
        }
    }
    if (carcount == 0)
    {
        fclose(fp);
        return -2;
    }

    gotoxy(34, rowno + 2);
    printf("Enter your choice(0 to quit):");
    while (1)
    {
        flag = 0;
        scanf("%d", &choice);
        if (choice == 0)
        {
            fclose(fp);
            return 0;
        }
        rewind(fp);
        while (fread(&C, sizeof(C), 1, fp) == 1)
        {
            if (C.car_id == choice && C.car_count > 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            fclose(fp);
            return C.car_id;
        }
        gotoxy(37, rowno + 4);
        textcolor(LIGHTRED);
        printf("Wrong Input");
        getch();
        gotoxy(35, rowno + 4);
        printf("\t\t\t");
        gotoxy(52, rowno + 2);
        printf("\t\t\\t");
        gotoxy(52, rowno + 2);
        textcolor(WHITE);
    }
}

int isValidDate(struct tm dt)
{
    if (dt.tm_year >= 2021 && dt.tm_year <= 2022)
    {
        if (dt.tm_mon >= 1 && dt.tm_mon <= 12)
        {
            if ((dt.tm_mday >= 1 && dt.tm_mday <= 31) && (dt.tm_mon == 1 || dt.tm_mon == 3 || dt.tm_mon == 5 || dt.tm_mon == 7 || dt.tm_mon == 8 || dt.tm_mon == 10 || dt.tm_mon == 12))
                return 1;
            else if ((dt.tm_mday >= 1 && dt.tm_mday <= 30) && (dt.tm_mon == 4 || dt.tm_mon == 6 || dt.tm_mon == 9 || dt.tm_mon == 11))
                return 1;
            else if ((dt.tm_mday >= 1 && dt.tm_mday <= 28) && (dt.tm_mon == 2))
                return 1;
            else if (dt.tm_mday == 29 && dt.tm_mon == 2 && (dt.tm_year % 400 == 0 || (dt.tm_year % 4 == 0 && dt.tm_year % 100 != 0)))
                return 1;
            else
                return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

void updateCarCount(int c)
{

    FILE *fp = fopen("../Car Rental App Files/car.bin", "rb+");
    Car C;
    while (fread(&C, sizeof(Car), 1, fp) == 1)
    {

        if (C.car_id == c)
        {
            fseek(fp, -8, SEEK_CUR);
            int cc_new = C.car_count - 1;
            fwrite(&cc_new, sizeof(cc_new), 1, fp);
            fseek(fp, -4, SEEK_CUR);
            _getch();
        }
    }
    fclose(fp);
}

void bookedCarDetails()
{
    clrscr();
    FILE *fp = fopen("../Car Rental App Files/customer.bin", "rb");
    Customer_Car_Details CC;
    int i;
    textcolor(YELLOW);
    gotoxy(32, 1);
    printf("CAR RENTAL SYSTEM\n");
    for (i = 1; i <= 80; i++)
        printf("%c", 247);
    gotoxy(31, 5);
    textcolor(YELLOW);
    printf("* BOOKED CAR DETAILS *");
    gotoxy(1, 7);
    textcolor(LIGHTGREEN);
    for (i = 1; i < 80; i++)
        printf("%c", 247);
    gotoxy(1, 8);
    printf("Model\t    Cust Name\t  Pick Up\t   Drop\t\t S_Date\t     E_Date");
    gotoxy(1, 9);
    textcolor(LIGHTGREEN);
    for (i = 1; i < 80; i++)
        printf("%c", 247);
    int x = 10;
    textcolor(YELLOW);

    while (fread(&CC, sizeof(Customer_Car_Details), 1, fp) == 1)
    {
        gotoxy(1, x);
        printf("%s", getCarName(CC.car_id));
        gotoxy(13, x);
        printf("%s", CC.cust_name);
        gotoxy(27, x);
        printf("%s", CC.pick);
        gotoxy(44, x);
        printf("%s", CC.drop);
        gotoxy(58, x);
        printf("%d-%d-%d", CC.sd.tm_mday, CC.sd.tm_mon, CC.sd.tm_year);
        gotoxy(70, x);
        printf("%d-%d-%d", CC.ed.tm_mday, CC.ed.tm_mon, CC.ed.tm_year);
        x++;
    }
    fclose(fp);
    _getch();
}
char *getCarName(int car_id)
{
    FILE *fp = fopen("../Car Rental App Files/car.bin", "rb");
    static Car C;
    while (fread(&C, sizeof(C), 1, fp) == 1)
    {
        if (C.car_id == car_id)
        {
            break;
        }
    }
    fclose(fp);
    return C.car_name;
}

int rentCar()
{
    Customer_Car_Details CC;
    int c, i;
    textcolor(LIGHTRED);
    gotoxy(32, 2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);

    gotoxy(35, 6);
    printf("EMPLOYEE MENU\n");
    for (i = 0; i < 80; i++)
    {
        printf("*");
    }

    textcolor(YELLOW);
    gotoxy(32, 8);
    c = selectCarModel();
    if (c == 0 || c == -2)
        return c;
    CC.car_id = c;
    clrscr();
    textcolor(LIGHTRED);
    gotoxy(32, 2);
    printf("CAR RENTAL SYSTEM");
    textcolor(LIGHTGREEN);

    gotoxy(35, 6);
    printf("EMPLOYEE MENU\n");
    for (i = 0; i < 80; i++)
    {
        printf("*");
    }
    gotoxy(1, 17);
    for (i = 0; i < 80; i++)
    {
        printf("*");
    }
    textcolor(YELLOW);
    gotoxy(27, 9);

    printf("Enter Customer Name:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.cust_name, 30, stdin);
    char *pos;
    pos = strchr(CC.cust_name, '\n');
    *pos = '\0';
    gotoxy(27, 10);
    textcolor(YELLOW);
    printf("Enter Pickup Point:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.pick, 30, stdin);
    pos = strchr(CC.pick, '\n');
    *pos = '\0';
    gotoxy(27, 11);
    textcolor(YELLOW);
    printf("Enter Drop Point:");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.drop, 30, stdin);
    pos = strchr(CC.drop, '\n');
    *pos = '\0';
    gotoxy(27, 12);
    textcolor(YELLOW);
    printf("Enter start date (dd/m/yyyy):");
    textcolor(WHITE);
    do
    {
        scanf("%d/%d/%d", &CC.sd.tm_mday, &CC.sd.tm_mon, &CC.sd.tm_year);
        int datevalid = isValidDate(CC.sd);
        if (datevalid == 0)
        {
            gotoxy(27, 18);
            textcolor(LIGHTRED);
            printf("Wrong Date");
            _getch();
            gotoxy(27, 18);
            printf("\t\t");
            gotoxy(56, 12);
            printf("\t\t\t");
            gotoxy(56, 12);
            textcolor(WHITE);
        }
        else
            break;
    } while (1);
    gotoxy(27, 13);
    textcolor(YELLOW);
    printf("Enter end date (dd/m/yyyy):");
    textcolor(WHITE);

    do
    {
        scanf("%d/%d/%d", &CC.ed.tm_mday, &CC.ed.tm_mon, &CC.ed.tm_year);
        int datevalid = isValidDate(CC.ed);
        if (datevalid == 0)
        {
            gotoxy(27, 18);
            textcolor(LIGHTRED);
            printf("Wrong Date");
            _getch();
            gotoxy(27, 18);
            printf("\t\t");
            gotoxy(54, 13);
            printf("\t\t\t");
            gotoxy(54, 13);
            textcolor(WHITE);
        }
        else
            break;
    } while (1);

    FILE *fp;
    fp = fopen("../Car Rental App Files/customer.bin", "ab");
    if (fp == NULL)
    {
        gotoxy(27, 18);
        textcolor(LIGHTRED);
        printf("Sorry ! File cannot be opened");
        getch();
        gotoxy(27, 18);
        printf("\t\t");
        return -1;
    }
    fwrite(&CC, sizeof(Customer_Car_Details), 1, fp);
    printf("Booking Done:%d", CC.car_id);
    printf("\nPress any key to continue...");
    getch();
    fclose(fp);
    updateCarCount(c);
    bookedCarDetails();
    return 1;
}

void availCarDetails()
{
    FILE *fp = fopen("h:\\Online C Project 2\\Car Rental App Files\\car.bin", "rb");
    Car c;
    int i;
    textcolor(LIGHTGREEN);
    gotoxy(32, 2);
    printf("CAR RENTAL SYSTEM\n");
    textcolor(YELLOW);
    for (i = 1; i <= 80; i++)
        printf("%c", 247);
    textcolor(LIGHTBLUE);
    gotoxy(31, 5);
    printf("* CAR DETAILS *");
    gotoxy(1, 7);
    textcolor(CYAN);
    for (i = 0; i < 80; i++)
        printf("%c", 247);
    if (fp == NULL)
    {
        gotoxy(31, 9);
        textcolor(LIGHTRED);
        printf("Sorry! NO CARS ADDED YET!");
        getch();
        return;
    }
    gotoxy(1, 8);
    textcolor(WHITE);
    printf("CAR ID   CAR MODEL\tCAR CAPACITY\tCAR COUNT\tCAR PRICE PER DAY");
    gotoxy(1, 9);
    textcolor(CYAN);
    for (i = 0; i < 80; i++)
        printf("%c", 247);
    int row = 11;
    textcolor(LIGHTCYAN);
    while (fread(&c, sizeof(c), 1, fp) == 1)
    {
        gotoxy(3, row);
        printf("%d", c.car_id);
        gotoxy(10, row);
        printf("%s", c.car_name);
        gotoxy(30, row);
        printf("%d", c.capacity);
        gotoxy(44, row);
        printf("%d", c.car_count);
        gotoxy(64, row);
        printf("%d", c.price);
        row++;
    }
    fclose(fp);
    getch();
}

int returnCar()
{
    clrscr();
    FILE *fp = fopen("../Car Rental App Files/customer.bin", "rb");
    Customer_Car_Details CC;
    int i,result;
    gotoxy(65, 23);
    printf("Press 0 to exit");
    textcolor(YELLOW);
    gotoxy(32, 1);
    printf("CAR RENTAL SYSTEM\n");
    for (i = 1; i <= 80; i++)
        printf("%c", 247);
    gotoxy(25,5);
    textcolor(WHITE);
    printf("Enter car Id: ");
    gotoxy(31, 7);
    textcolor(YELLOW);
    printf("* BOOKED CAR DETAILS *");
    gotoxy(1, 9);
    textcolor(LIGHTGREEN);
    for (i = 1; i < 80; i++)
        printf("%c", 247);
    gotoxy(1, 10);
    printf("ID  Model    Cust Name\t    Pick Up\t   Drop\t\t S_Date\t     E_Date");
    gotoxy(1, 11);
    textcolor(LIGHTGREEN);
    for (i = 1; i < 80; i++)
        printf("%c", 247);
    int x = 12;
    textcolor(YELLOW);
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        gotoxy(32,17);
        printf("NO BOOKINGS DONE YET");
        return -1;
    }
    while (fread(&CC, sizeof(Customer_Car_Details), 1, fp) == 1)
    {
        gotoxy(1, x);
        printf("%d",CC.car_id);
        gotoxy(4,x);
        printf("%s", getCarName(CC.car_id));
        gotoxy(14, x);
        printf("%s", CC.cust_name);
        gotoxy(30, x);
        printf("%s", CC.pick);
        gotoxy(47, x);
        printf("%s", CC.drop);
        gotoxy(59, x);
        printf("%d-%d-%d", CC.sd.tm_mday, CC.sd.tm_mon, CC.sd.tm_year);
        gotoxy(70, x);
        printf("%d-%d-%d", CC.ed.tm_mday, CC.ed.tm_mon, CC.ed.tm_year);
        x++;
    }
    gotoxy(40,5);
    textcolor(WHITE);
    int carid;
    scanf("%d",&carid);
    FILE *fp2 = fopen("h:\\Online C Project 2\\Car Rental App Files\\temp.bin", "wb");
    if (carid == 0)
    {
        textcolor(LIGHTRED);
        gotoxy(25, 20);
        printf("Returning CAR cancelled");
        getch();
        return -1;
    }
    rewind(fp);
    int found=0;
    while (fread(&CC, sizeof(Customer_Car_Details), 1, fp) == 1)
    {
        if(CC.car_id!=carid)
            fwrite(&CC,sizeof(CC),1,fp2);
        else
            found=1;
    }
    fclose(fp);
    fclose(fp2);
    if(found==0)
        remove("../Car Rental App Files/temp.bin");
    else
    {
        result=remove("../Car Rental App Files/customer.bin");
        if(result!=0)
            return 2;
        result=rename("../Car Rental App Files/temp.bin","../Car Rental App Files/customer.bin");
        if(result!=0)
            return 2;

        FILE *fp3 = fopen("../Car Rental App Files/car.bin", "rb+");
    Car C;
    while (fread(&C, sizeof(Car), 1, fp) == 1)
    {

        if (C.car_id == carid)
        {
            fseek(fp, -8, SEEK_CUR);
            int cc_new = C.car_count + 1;
            fwrite(&cc_new, sizeof(cc_new), 1, fp);
            fseek(fp, -4, SEEK_CUR);
            _getch();
        }
    }
    fclose(fp3);
    }
    return found;
    getch();
}
