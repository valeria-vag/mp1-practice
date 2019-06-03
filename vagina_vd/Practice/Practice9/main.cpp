#include "ToDoList.h"
#include "Task.h"
#include "Date.h"
#include "Time.h"
#include "conio.h"
using namespace std;

int main()
{
    ToDoList List;
    Date YourDate;

    try
    {
        List.read("Plans.txt");
        cin >> YourDate;
        List.print(YourDate);
    }
    catch (Exception_date& e)
    {
        cerr << e.what() << endl;
    }
    catch (Exception_free& e)
    {
        cerr << e.what() << endl;
    }
    catch (Exception_task& e)
    {
        cerr << e.what() << endl;
    }
}