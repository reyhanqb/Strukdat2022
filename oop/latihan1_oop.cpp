// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>

using namespace std;

class Mhs {
  public:
  string Mhsnama;
  
  void printNama(){
      cout << Mhsnama;
  }
};

int main() {
    Mhs mhs1;
    mhs1.Mhsnama = "Rahmat";
    mhs1.printNama();

    return 0;
}