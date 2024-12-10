#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>
using namespace std;

struct city {
    string name;
    int population;

};
void readFile(city Texas[100]);
void incPopulation(city Texas[100], int t);
void displayPopulation(city Texas[100]);
void sortingPopulation(city Texas[100]);
void writingFile(city Texas[100]);

int main()
{
    int t;
    cout<<"Enter the time(t) in years";
    cin>>t;

    cout<<"Calculating the population of cities in the file after 10 years"<<endl;
    city Texas[100];
    readFile(Texas);
    incPopulation(Texas,t);
    sortingPopulation(Texas);
    // displayPopulation(Texas);
    writingFile(Texas);
    
    
 
return 0;
}
void readFile(city Texas[100]){
    ifstream fin("input_city.txt");

    if (!fin){
        cout<<"Error";
    }

    int i = 0;
    while (!fin.eof() && i < 5){
        fin >> Texas[i].population; 
        fin.ignore();
        getline(fin,Texas[i].name);
        i++;
    }

}

void incPopulation(city Texas[100],int t){
    for (int i =0; i < 5;i++){
        if (Texas[i].population<50000){
            Texas[i].population = Texas[i].population * pow(2.72,0.011*t) ;
        }
        else{
            Texas[i].population = Texas[i].population * pow(2.72,0.011*t);
        }
    }
}

void displayPopulation(city Texas[100]){
    for (int j =0 ; j <5 ; j++){
        cout << Texas[j].population<<Texas[j].name<<endl;
    }
}

void sortingPopulation(city Texas[100]){
    int n = 5;
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if (Texas[i].population>Texas[j].population){
                int temp = Texas[j].population;
                Texas[j].population = Texas[i].population;
                Texas[i].population = temp;

                string tempo = Texas[j].name;
                Texas[j].name = Texas[i].name;
                Texas[i].name = tempo;
                
            }
        }
    }

}

void writingFile(city Texas[100]){
    ofstream fout("output_city.txt");
        if(!fout){
            cout<<"Error";}
        for (int i=0;i<5;i++){
            fout<<Texas[i].population<<" "<<Texas[i].name<<endl;
        }
    

    cout<<"Successfully calculated the population..."<<endl;
    cout<<"**Content written in the file**";
}
