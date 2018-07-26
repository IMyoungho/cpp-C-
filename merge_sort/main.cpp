#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    int number=0;
    cout << "-------------------MERTGE SORT----------------\n";
    cout << ">> How many numbers do you want to enter? = ";
    cin >> number;
    int temp_number=number;
    int figure[number];
    memset(figure, 0, number);
    cout << "   >> Please enter numbers = ";
    int times = ceil(log(number)/log(2)); // NlogN (under2)
    for(int i=0; i<number; i++){
        cin >> figure[i];
    }

    int temp=0;
    for(int i=0; i<number/2; i+=2){
        if(figure[i+1]<figure[i]){
            temp=figure[i+1];
            figure[i+1]=figure[i];
            figure[i]=temp;
        }
//        else if(i==times/2) --fix
//        {
//            if(figure[i]>figure[i+2])
//            {
//                temp=figure[i+2];
//                figure[i+2]=figure[i];
//                figure[i+2]=temp;
//            }
//        }
    }

    for(int i=0; i<temp_number; i++)
        cout << figure[i] << " "<<endl;
    return 0;
}
