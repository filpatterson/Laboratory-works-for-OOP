#include <iostream>
#include <string.h>
using namespace std;

struct dimensions
{
    float width;
    float height;
};

struct resolution
{
    int width;
    int height;
};

class Monitor
{
private:
    string color;
    dimensions Dimens;
    resolution Resol;

public:
    Monitor(string someColor, dimensions someDimens, resolution someResol): color(someColor), Dimens(someDimens), Resol(someResol){};

    Monitor()
    {
        cout << "----------------------------------------------------------" << endl;
        
        cout << "Input color of monitor:\t";
        cin >> color;
        
        cout << "Input dimensions of monitor (width and height):\n";
        cin >> Dimens.width;
        cin >> Dimens.height;
        
        cout << "Input resolution of monitor (width and height):\n";
        cin >> Resol.width;
        cin >> Resol.height;

        cout << "//////////////////////////////////////////////////////\n";
    }

    void update()
    {
        cout << "----------------------------------------------------------" << endl;

        cout << "Input new color of monitor:\t";
        cin >> color;
        
        cout << "Input new dimensions of monitor (width and height):\n";
        cin >> Dimens.width;
        cin >> Dimens.height;
        
        cout << "Input new resolution of monitor (width and height):\n";
        cin >> Resol.width;
        cin >> Resol.height;

        cout << "///////////////////////////////////////////////////////\n";
    }

    void comparison(const Monitor *anotherMonitor)
    {
        if(Dimens.width * Dimens.height < anotherMonitor->Dimens.width * anotherMonitor->Dimens.height)
            cout << "Monitor " << color << " is smaller than " << anotherMonitor->color << " one" << endl;
        if(Dimens.width * Dimens.height == anotherMonitor->Dimens.width * anotherMonitor->Dimens.height)
            cout << "Monitor " << color << " is equal to " << anotherMonitor->color << " one" << endl;
        if(Dimens.width * Dimens.height > anotherMonitor->Dimens.width * anotherMonitor->Dimens.height)
            cout << "Monitor " << color << " is bigger than " << anotherMonitor->color << " one" << endl;
    }

    void showMonitor()
    {
        cout << "-------------------------------------" << endl;

        cout << "\tColor of the monitor is " << color << endl;
        cout << "\tDimensions of the monitor are " << Dimens.width << " * " << Dimens.height << endl;
        cout << "\tResolution of the monitor are " << Resol.width << " * " << Resol.height << endl;
        
        cout << "///////////////////////////////////////\n";
    }

};

int main()
{
    Monitor first, second, third;
    dimensions someDimens;
    resolution someResol;

    cout << "Input value for some random dimension(width and height):\t";
    cin >> someDimens.width;
    cin >> someDimens.height;

    cout << "Input value for some random resolution(width and height):\t";
    cin >> someResol.width;
    cin >> someResol.height;

    Monitor fourth("Red", someDimens, someResol);

    first.showMonitor();
    second.showMonitor();
    third.showMonitor();
    fourth.showMonitor();

    first.comparison(&second);
}