#include <iostream>
#include <vector>
#include <map>
using namespace std;


vector<char> decodificacion(){
    vector<char> pal2;
    vector<char> resultado;
    map<char,unsigned int> palll1;
    map<char,unsigned int> palll2;
    map<char,char> swap;
    string palabra1, palabra2;
    cin >> palabra1;
    cin >> palabra2;
    for (char x : palabra1){
        palll1[x]++;
    }
    for (char y : palabra2){
        pal2.push_back(y);
        palll2[y]++;
    }

    while(palll2.size()>=1){
        int max1 = 0, max2 = 0;
        char x,y;
        for(auto it = palll1.begin();it!=palll1.end();it++){
            if(it->second > max1){
                max1 = it->second;
                x = it->first;
            }
        }
        for(auto it = palll2.begin();it!=palll2.end();it++){
            if(it->second > max2){
                max2 = it->second;
                y = it->first;
            }
        }
        swap[y] = x;
        palll1.erase(x);
        palll2.erase(y);
    }

    for (char x : pal2){
        resultado.push_back(swap[x]);
    }

    return resultado;
};



void imprimir(vector<vector<char>> outputs){
    unsigned int cantidad = outputs.size();
    for (auto x : outputs){
        for (auto y : x){
            cout << y;
        }
        if (cantidad > 1){
            cout << endl << endl;
        }
        cantidad--;
    }
}

int main() {
    int cantidad;
    cin >> cantidad;
    cout << endl;

    vector<vector<char>> outputs;

    while (cantidad >=1){
        outputs.push_back(decodificacion());
        if (cantidad>1){
            cout << endl;
        }
        cantidad--;
    }

    imprimir(outputs);

    return 0;
}