#include <iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        char sex;
        cin>>sex;
        double h;
        cin>>h;
        if(sex == 'F'){
            printf("%.2f",h*1.09);
        }else{
            printf("%.2f",h/1.09);
        }
        cout<<endl;
    }
    
    system("pause");
    return 0;
}