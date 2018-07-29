#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int number=0;
    cout << "-------------------BUBBLE SORT----------------\n";
    cout << ">> How many numbers do you want to enter? = ";
    cin >> number;
    int temp_number=number;
    int figure[number];
    memset(figure, 0, number);
    cout << "   >> Please enter numbers = ";
    
    int temp{0};
    for(int i=0; i<temp_number; i++){
            if(i==temp_number-1){
                temp_number--;
                i=0;
            }
            if(figure[i+1]-figure[i] < 0){
                temp=figure[i+1];
                figure[i+1]=figure[i];
                figure[i]=temp;
            }
    }
    for(int i=0; i<number; i++)
        cout << figure[i] << " " ;

    return 0;
}
