#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <fstream>
#include <ctime>
#include <typeinfo>
//hi HIHIHSAIDHISADHKL
using namespace std;

int get_integer(string prompt);
int main(){
    time_t start;
    time(&start); // to keep track of time

    unsigned int max = get_integer("What number do you want to stop finding primes at?");
    max = UINT_MAX -3;
    // The Sieve of Eratosthenes
    vector<int> primeList;
    primeList.push_back(2);
    bool test;

    for (unsigned int i =3; i <= max; i++){
        test = true;
        for (unsigned int j = 0; j < primeList.size(); j++){
            if (i / primeList.at(j) == 0){ //TODO: Check for int vs Float
                test = false;
                break;
            }
        }
        if (test) {
	    primeList.push_back(i);
	    if (primeList.size() % 1000 == 0) cout << i << endl;
	}
    }
    
    ofstream primesTimes;
    primesTimes.open("primes.txt");
    if (!primesTimes.is_open()) {
        cout << "Could not open file primes.txt." << endl;
        return 1;
    }

    primesTimes << asctime(localtime(&start)) << endl;

    for (auto prime:primeList){
        primesTimes << prime << ' ';
    }
    time(&start);
    primesTimes << endl << asctime(localtime(&start));
    primesTimes.close();
    cout << endl;
}

int get_integer(string msg) { // barrowed from the hangman project
    while (true) {
        string input;    
        int result = 0;

        cout << msg << endl;
        getline(cin, input);

        result = atoi(input.c_str());
        if (result > 0) return result;

        cout << "I didn't understand that. Please enter a positive integer.";
        cout << endl;
    }
}
