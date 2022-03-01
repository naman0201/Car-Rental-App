#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include <time.h>

struct User
{
    char userid[20];
    char pwd[20];
    char name[20];
};
typedef struct User User;

struct Car
{
    int car_id;
    char car_name[50];
    int capacity;
    int total_count;
    int car_count;
    int price;
};
typedef struct Car Car;

struct Customer_Car_Details
{
    int car_id;
    char cust_name[30];
    char pick[30];
    char drop[30];
    struct tm sd;
    struct tm ed;
};
typedef struct Customer_Car_Details Customer_Car_Details;

void welcomeScreen();
void userOptions();
void addAdmin();
void exitCode();
User *getInput();
int checkUserExist(User, char *);
int adminMenu();
int addEmployee();
void viewEmployee();
int addCarDetails();
void showCarDetails();
int deleteEmp();
int deleteCarModel();
int selectCarModel();
int rentCar();
int isValidDate(struct tm);
void updateCarCount(int );
void bookedCarDetails();
char * getCarName(int);
int empMenu();
void shiftCarDetails();
void availCarDetails();
int returnCar();
#endif // CAR_H_INCLUDED
