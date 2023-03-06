#include <bits/stdc++.h>
using namespace std;

int randi(int a, int b) {
    return a+rand()%(b-a+1);
}
vector<long long> res;

int main(int argv,char *argc[]) {
    srand(atoi(argc[1]));
    int tes = 1e8;

    long long pierw = 2;
    long long mini = 1e9;
    long long maxi = 2;
    while(tes-->0) {
        int wygrana = 1;
        pierw = 2;
        while(wygrana) {
            int zdarzenie = randi(1, 2);
            if(zdarzenie == 1) {
                pierw*=2;
            } else break;
        }
        res.push_back(pierw);
        mini = min(mini, pierw);
        maxi = max(maxi, pierw);
    }
    long long suma = 0;
    for(auto i: res) {
         suma+=i;
    }
    cout<<"Średnia eksperymentu: "<<suma/res.size()<<'\n';
    cout<<"Największa wygrana: "<<maxi<<'\n';
    cout<<"Najmniejsza wygrana: "<<mini;

}
