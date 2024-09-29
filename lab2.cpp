#include <iostream>
#include <cmath>

using namespace std;

int factor(int o){
    int f=1;
    if (o % 2==0){
        for(double i=2; i<=o; i += 2){
            f*=i;
        }
    }
    if (o % 2==1){
        for(double i=1; i<=o; i += 2){
            f*=i;
        }
    }
    return f;
}


double Tx(double x){
    double s1, s2 = 0.;
    for (int k = 0; k <= 10; k++){
        s1 += ( pow(x, 2*k + 1) / factor(2*k+1));
        s2 += ( pow(x, 2*k) / factor(2*k));
    }
    return s1 / s2;
}

double func( double y){
    double a = (7 * Tx(0.25) + 2 * Tx(1 + y));
    double b = (6 - Tx(pow(y,2) - 1));
    double c = a/b;
    return c;
}

int main(){
    double n;
    cout << "y=";
    cin>>n;
    cout<<func(n);
    
    return 0;
}