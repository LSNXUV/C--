#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main(){
    set<int> s = {1, 2, 3, 4, 5};
    set<int> s2 = {3, 4, 5, 6, 7};
    set<int> symmetricSet,intersection,unionSet,differenceSet;
    set_intersection(s.begin(), s.end(), s2.begin(), s2.end(), inserter(intersection, intersection.begin()));
    set_union(s.begin(), s.end(), s2.begin(), s2.end(), inserter(unionSet, unionSet.begin()));
    set_difference(s.begin(), s.end(), s2.begin(), s2.end(), inserter(differenceSet, differenceSet.begin()));
    set_symmetric_difference(s.begin(), s.end(), s2.begin(), s2.end(), inserter(symmetricSet, symmetricSet.begin()));

    cout << "Intersection: ";
    for(auto i : intersection){
        cout << i << " ";
    }
    cout << endl;
    cout << "Union: ";
    for(auto i : unionSet){
        cout << i << " ";
    }
    cout << endl;
    cout << "Difference: ";
    for(auto i : differenceSet){
        cout << i << " ";
    }
    cout << endl;
    cout << "Symmetric Difference: ";
    for(auto i : symmetricSet){
        cout << i << " ";
    }
    system("pause");
    return 0;
}