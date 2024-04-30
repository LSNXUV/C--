#include <iostream>
using namespace std;



int main(){
    int n;
    cin >> n;
    int odd = 0, even = 0;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(temp % 2 == 0)
            even++;
        else
            odd++;
    }
    cout << odd << " " << even << endl;

    system("pause");
    return 0;
}