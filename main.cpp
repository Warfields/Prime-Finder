#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <fstream>
#include <ctime>

using namespace std;

int get_integer(string prompt);
int main(){
    time_t start;
    time(&start); // to keep track of time for time stamp at the end
    
    unsigned int max = get_integer("What number do you want to stop finding primes at?");
    max = UINT_MAX;
//   The Sieve of Eratosthenes (The Algorythm)
    vector<unsigned int> numList(max,1);
    cout << "NumList Reserved" << endl;  // This can use a shit ton of memory for larger numbers
    
    vector<unsigned int> primeList;
    primeList.reserve(max/2);
    cout << "Primelist Reservered" << endl; // This can use a shit ton of memory for larger numbers
    
    for (unsigned int i = 2; i < max; i++){
	    if (numList.at(i) == 0) continue;
            primeList.push_back(i);
        for (unsigned long j = 2; j * (unsigned long)i < max; j++){
            numList.at(j*i) = 0;
        }
	if (primeList.size() % 1000 == 0) cout << i << endl;
    }


    cout << "DONE WITH PRIME FINDING WRITING TO FILE" << endl; // Once found this may take a while
    ofstream primesTimes;
    primesTimes.open("primesVectorOrd.txt");
    if (!primesTimes.is_open()) {
        cout << "Could not open file primes.txt." << endl;
        return 1;
    }

    primesTimes << asctime(localtime(&start)) << endl;
    unsigned int loop;
    for (auto prime:primeList){
      primesTimes << prime << ' ';
    	    loop++;
    	    if (loop % 1000 == 0) primesTimes << endl;
    }
    
    time(&start);
    primesTimes << endl << asctime(localtime(&start)); // write end timestamp
    primesTimes.close();
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
