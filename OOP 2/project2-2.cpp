#include <iostream>
#include <vector>
using namespace std;

class Queue
{
private:
    vector<int> listOfElements;
    int size;

public:
    Queue(): size(0){};

    Queue(int someSize)
    {
        int size = someSize;
        int newElement;
        
        cout << "#############################################################################################" << endl;
        cout << "\tYou need to input " << size << " elements into Queue:" << endl;
        cout << "#############################################################################################" << endl;

        for(int i = 0; i < size; i++)
        {
            cin >> newElement;
            listOfElements.push_back(newElement);
        }
    }

    void addElemToQue()
    {
        int newElement;

        cout << "--------------------------------------------------------------------------------------------" << endl;
        cout << "\tInput new element that you want to insert:\t";
        cin >> newElement;
        cout << "--------------------------------------------------------------------------------------------" << endl;

        listOfElements.push_back(newElement);
        size++;
    }

    void addElemToQue(int newElement)
    {
        listOfElements.push_back(newElement);
        size++;
    }

    void isFull()
    {
        if(size >= 20)
        {
            cout << "///////////////////////////////////////////////////////////////////////////////////////" << endl;
            cout << "\tThis queue is full." << endl;
            cout << "///////////////////////////////////////////////////////////////////////////////////////" << endl;
        }
        else if (size > 0)
        {
            cout << "//////////////////////////////////////////////////////////////////////////////////////" << endl;
            cout << "\tThis queue has some elements, but it's not full." << endl;
            cout << "//////////////////////////////////////////////////////////////////////////////////////" << endl;
        }
        else
        {
            cout << "/////////////////////////////////////////////////////////////////////////////////////" << endl;
            cout << "\tThis queue is empty." << endl;
            cout << "/////////////////////////////////////////////////////////////////////////////////////" << endl;
        }
    }

    int getElement(int indexOfElementInQue)
    {
        return listOfElements.at(indexOfElementInQue);
    }

    void showQue()
    {
        cout << "/////////////////////////////////////////////////////////////////////////////////////////\n\t";

        for(vector<int>::size_type i = 0; i != listOfElements.size(); i++)
        {
            cout << " " << listOfElements[i];
        }
        cout << "\n\t That's all folks!" << endl;
        cout << "////////////////////////////////////////////////////////////////////////////////////////" << endl;
    }
};

int main()
{
    Queue first, second(5);

    second.showQue();
    
    second.addElemToQue(12);
    second.addElemToQue();

    second.isFull();
    first.isFull();

    cout << "\tElement number 4 from second Queue is " << second.getElement(4) << endl;
}