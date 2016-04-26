#include<iostream>
using namespace std;

const int numberMonkeys = 3;                            // 1 row per monkey ie. 3 rows
const int numberDays = 7;                               // 1 column per day ie. 7 days

void averageFood(int array[][numberDays], int);

double getAverage(int array[][numberDays], int);
int getRowSum(int array[][numberDays], int);
double getAverage(int array[][numberDays], int);
int leastFood(int, int, int);
int mostFood(int, int, int);

int main()
{
    int monkeys[numberMonkeys][numberDays];
    int monkey1 = 0, monkey2 = 1, monkey3 = 2, monkey1Total, monkey2Total, monkey3Total, largest, smallest;
    averageFood(monkeys,numberMonkeys);
    monkey1Total = getRowSum(monkeys, monkey1);
    monkey2Total = getRowSum(monkeys, monkey2);
    monkey3Total = getRowSum(monkeys, monkey3);
    smallest = leastFood(monkey1Total, monkey2Total, monkey3Total);
    largest = mostFood(monkey1Total, monkey2Total, monkey3Total);
    cout << "The average daily food consumed by all 3 monkeys was " << getAverage(monkeys, numberMonkeys)/3 << "." << endl;
    cout << "The smallest amount of food eaten by one monkey in a week was: " << smallest << "."<<endl;
    cout << "The largest amount of food eaten by one monkey in a week was: " << largest << "."<<endl;

}
void averageFood(int monkeys[][numberDays],int numberMonkeys)
{
    for (int rows = 0; rows < numberMonkeys; rows++)
    {
        cout << "Monkey " << (rows + 1) << endl;
        for (int cols = 0; cols < numberDays; cols++)
        {
            cout << " Day " << (cols + 1) << ": ";
            cin >> monkeys[rows][cols];
            while (monkeys[rows][cols] < 0){
                cout << "Stop trying to starve the monkeys, try again: ";
                cin >> monkeys[rows][cols];}}
        cout << endl;}}
int getRowSum(int monkeys[][numberDays], int monkeyNum)
{
    int total = 0;

    for (int cols = 0; cols < numberDays;cols++)
        total += monkeys[monkeyNum][cols];

    return total;
}
double getAverage(int monkeys[][numberDays], int numberMonkeys)
{
    double total = 0;

    for (int cols = 0; cols < numberDays; cols++){
        for (int rows = 0; rows < numberMonkeys; rows++)
            total += monkeys[rows][cols];}
    return (total/(numberDays));
}

int mostFood(int monkey1, int monkey2, int monkey3){
    int array[3]{monkey1, monkey2, monkey3};
    int max = array[0];
    for (int count = 0; count < 3; count++)
    {
        if (array[count] > max)
        {
            max = array[count];
        }}
    return max;
}

int leastFood(int monkey1, int monkey2, int monkey3)
{
    int array[3]{monkey1, monkey2, monkey3};
    int min = array[0];

    for (int count = 0; count < 3; count++)
    {
        if (array[count] < min)
        {
            min = array[count];
        }
    }
    return min;
}