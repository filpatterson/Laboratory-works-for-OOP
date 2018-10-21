#include <iostream>
using namespace std;

class Box
{
private:
    double height, width, length;

public:
    Box()
    {
        height = width = length = 1;
    };

    Box(double someHeight, double someWidth, double someLength): height(someHeight), width(someWidth), length(someLength){};

    Box(int commonValue)
    {
        height = width = length = commonValue;
    };

    double areaOfBox()  //calculate area of the box
    {
        return length * width * 2 + length * height * 2 + width * height * 2;
    };

    double volumeOfBox()    //calculate volume of the box
    {
        return length * width * height;
    };

    void showBox()  //show all values of box
    {
        cout << "--------------------------------" << endl;
        cout << "\tLength = " << length << "; Width = " << width << "; Height = " << height << endl;
        cout << "//////////////////////////////////" << endl;
    }
};

int main()
{
    Box first(1.2, 2.2, 3.3), second, third(3);
    //three different methods of initializing boxes

    first.showBox();
    second.showBox();
    third.showBox();
    //show all boxes

    cout << "Areas of those boxes:" << endl;
    cout << "\tArea of the first box = " << first.areaOfBox() << endl;
    cout << "\tArea of the second box = " << second.areaOfBox() << endl;
    cout << "\tArea of the third box= " << third.areaOfBox() << endl;
    //show areas of those boxes

    cout << "Volumes of those boxes:" << endl;
    cout << "\tVolume of the first box = " << first.volumeOfBox() << endl;
    cout << "\tVolume of the second box = " << second.volumeOfBox() << endl;
    cout << "\tVolume of the third box = " << third.volumeOfBox() << endl;
    //volumes of those boxes
}