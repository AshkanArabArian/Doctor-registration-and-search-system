#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;


class hava {
private :
    string id;
    int vaz;
    int bandm;
public :
    
    void chVaz(int vaziat){
        vaz = vaziat;
    }
    void setId(string inputid){
        id = inputid;
    }
    void setBand(int band){
        bandm = band;
    }
    int getVaz(){
        return vaz;
    }
    int getBand(){
        return bandm;
    }
    string getId(){
        return id;
    }

};


class band {
private :
    string havamid; 
    int number;

public :

    void setHavam(string id){
        havamid = id;
    }
    void setNum(int num){
        number = num;
    }
    string getHavam(){
        return havamid;
    }
    int getNum(){
        return number;
    }

};

vector <band> bands;
vector <hava> havas;


int main(){

    int n, k, q, t;
    cin >> n >> k;
    for (t = 0; t < n; t++){
        string id;
        cin >> id;
        hava hh;
        hh.setId(id);
        hh.chVaz(1);
        havas.push_back(hh);
    }

    for (t = 0; t < k; t++){
        band bb;
        bb.setNum(t + 1);
        bb.setHavam("1");
        bands.push_back(bb);
    }

    cin >> q;

    for (t = 0; t < q; t++){
        string d;
        cin >> d;

        if (d == "TAKE-OFF"){
            string id;
            cin >> id;
            int i = 0;
            for (hava &hh : havas){
                if (hh.getId() == id){
                    i = 1;
                    if (hh.getVaz() == 1){
                        int i = 0;
                        for (band &bb : bands){
                            if (bb.getHavam() == "1"){
                                i = 1;
                                hh.chVaz(2);
                                bb.setHavam(hh.getId());
                                break;
                            }
                        }
                        if (i == 0){
                            cout << "NO FREE BOUND\n";
                        }
                    }
                    else if (hh.getVaz() == 2){
                        cout << "YOU ARE TAKING OFF\n";
                    }
                    else if (hh.getVaz() == 3){
                        cout << "YOU ARE LANDING NOW\n";
                    }
                    else if (hh.getVaz() == 4){
                        cout << "YOU ARE NOT HERE\n";
                    }
                }
            }
            if(i == 0){
                cout << "YOU ARE NOT HERE\n";
            }
        }
        else if (d == "LANDING"){
            string id;
            cin >> id;
            int i = 0;
            for (hava &hh : havas){
                if (hh.getId() == id){
                    if (hh.getVaz() == 1){
                        cout << "YOU ARE HERE\n";
                    }
                    else if (hh.getVaz() == 2){
                        cout << "YOU ARE TAKING OFF\n";
                    }
                    else if (hh.getVaz() == 3){
                        cout << "YOU ARE LANDING NOW\n";
                    }
                    else if (hh.getVaz() == 4){
                        int j = 0;
                        for (int i = k - 1; i >= 0; i--){
                            if (bands[i].getHavam() == "1"){
                                j = 1;
                                hh.chVaz(3);
                                bands[i].setHavam(hh.getId());
                                break;
                            }
                        }
                        if (j == 0){
                            cout << "NO FREE BOUND\n";
                        }
                    }
                    i = 1;
                }
            }
            if (i == 0){
                int j = 0;
                hava hh;
                hh.setId(id);              
                for (int i = k - 1; i >= 0; i--){
                    if (bands[i].getHavam() == "1"){
                        j = 1;
                        hh.chVaz(3);
                        bands[i].setHavam(hh.getId());
                        break;
                    }
                }
                if (j == 0){
                    hh.chVaz(4);
                    cout << "NO FREE BOUND\n";
                }
                havas.push_back(hh);
            }
        }
        else if (d == "PLANE-STATUS"){
            string id;
            cin >> id;
            int i = 0;
            for (hava &hh : havas){
                if (hh.getId() == id){
                    i = 1;
                    cout << hh.getVaz() << endl;
                }
            }
            if (i == 0){
                cout << "4\n";
            }
        }
        else if (d == "BAND-STATUS"){
            int num;
            cin >> num;
            for (band &bb : bands){
                if (bb.getNum() == num){
                    if (bb.getHavam() == "1"){
                        cout << "FREE\n";
                    }
                    else {
                        cout << bb.getHavam() << endl;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}
