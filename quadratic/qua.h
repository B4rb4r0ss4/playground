#include <iostream>
#include <string>
#include <climits>
#include <cmath>
using namespace std;
class Equation {
    private:
        long double a, b, c, x1 = INT_MAX, x2 = INT_MAX, delta, p = INT_MAX, q;
        bool is = true;
        string getNormalizedVal(long double ele) {
            std::string val = "";
            if(ele>=0) val+="+";
            if(ele == INT_MAX) return "Brak Rozwiązania - delta mniejsza od zera";
            if(ele == floor(ele)) 
                val += std::to_string((int)ele);
            else {
                val += std::to_string(ele);
                val = val.substr(0, val.find('.')+3);
            }
            return val;
        };
        string getX(long double xe) {
            std::string val = "";
            xe*=-1;
            if(xe > 0) {
                return (getNormalizedVal(xe));
            } else return getNormalizedVal(xe);

        };
        long double equ(long double x) {
            return a*(x*x) + b*x + c;
        };
    public: 
        void read() {
            cin>>a>>b>>c;
            delta = (b*b) - (4*a*c);
            if(delta >= 0) {
                x1 = (-b-sqrt(delta)) / (2*a);
                x2 = (-b+sqrt(delta)) / (2*a);
            }
            p = (-b)/(2*a);
            q = (-delta)/(4*a);
            if(delta<=0) is = false;
        }; 
        void getVal(long double val) {
            cout<<getNormalizedVal(equ(val))<<'\n';
        };
        void getVertex() {
            cout<<"Wierzchołek funkcji: ("<<getNormalizedVal(p)<<", "<<getNormalizedVal(q)<<")\n";
        }; 
        void getX() {
            cout<<"x1: "<<getNormalizedVal(x1)<<'\n';
            cout<<"x2: "<<getNormalizedVal(x2)<<'\n';
        };
        void formula() {
            if(is)
            cout<<"Wzór iloczynowy funkcji: "<<getNormalizedVal(a)<<"*(x"<<getX(x1)<<")*(x"<<getX(x2)<<")\n";
          else 
                cout<<"Brak wzoru iloczynowego, delta mniejsza od zera\n";
        };
        void formula2() {
            cout<<"Wzór kanoniczny funkcji: "<<getNormalizedVal(a)<<"*(x"<<getX(p)<<")^2"<<getNormalizedVal(q)<<'\n';
          
        };
};
