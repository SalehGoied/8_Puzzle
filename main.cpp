
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void show (int a[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == 0)
                cout<<" - ";
            else
                cout<<" "<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}
bool check_solvable(int a[3][3])
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
                for (int k = i; k < 3; k++)
                {
                    if (a[i][j] == 0 || a[i][j] == 1)
                        break;
                    for (int l = (k == i ? j+1: 0); l < 3; l++)
                        if (a[k][l] == 0)
                            continue;
                        else if (a[i][j] > a[k][l])
                            count++;
                }
        }
    }
    if (count % 2 == 0)
        return true;
    else
        return false;
}
void random_number(int a[3][3],int &indexi, int &indexj)
{
    bool check[9] = {false};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[i][j] = -1;
        }
    }
    srand(time(0));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x = 0;
            do
            {
                x = rand() % 9;
            }
            while (check[x] == true);
            check[x] = true;
            a[i][j] = x;
            if (a[i][j] == 0)
            {
                indexi = i;
                indexj = j;
            }
        }
    }
    if (!check_solvable(a))
    {
        if (a[0][0] != 0 && a[0][1] != 0)
            swap(a[0][0], a[0][1]);
        else
            swap(a[1][0], a[1][1]);
    }
}
bool check_win(int a[3][3])
{
    int k = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (i == 2&& j == 2)
                break;
            if (a[i][j] != k)
            {
                return false;
            }
            k++;
        }
    return true;
}
void move_element (int a[3][3], int x, int &i0, int &j0)
{
    int ix, jx;
    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 3; j ++)
        {
            if (a[i][j] == x)
            {
                ix = i;
                jx = j;
                break;
            }
        }
    if (x > 8 || x < 0)
    {
        cout<<"number is not valid"<<endl
            <<"enter another number"<<endl;
    }
    else if ((ix == i0-1&& jx == j0)||(ix == i0&& jx == j0-1)||(ix == i0+1&& jx == j0)||(ix == i0&& jx == j0+1))
    {
        a[i0][j0] = x;
        a[ix][jx] = 0;
        j0 = jx;
        i0 = ix;
        show(a);
    }
    else
    {
        cout<<"number is not correct"<<endl
            <<"enter another number"<<endl;
    }
}
void start_game(int a[3][3])
{
    int i0 = 0,j0 = 0;
    random_number(a, i0, j0);
    show(a);
    int x;
    do
    {
        cout<<"your number: ";
        cin>>x;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"you cannot enter character or text"<<endl
                <<"please enter only number"<<endl;
                continue;

        }
        else if (x == -1)
            break;
        move_element(a,x,i0,j0);
        if (check_win(a))
        {
            cout<<"well done! (^_^)"<<endl;
            break;
        }
    }while(x != -1);
}
int main()
{
    int element[3][3]={1, 2, 3, 4, 5, 6, 7, 8,0};
    string name;
    cout<<"8-puzzle"<<endl
        <<"========="<<endl<<endl;
    cout<<"your name: ";
    cin>>name;
    cout<<"hello "<<name<<endl;
    show(element);
    cout<<"your aim make the box in bottom like up"<<endl
        <<"move the number around the space place"<<endl
        <<"if you bored enter -1 to end"<<endl
        <<"Enjoy <o-o>"<<endl;
    start_game(element);
    return 0;
}
