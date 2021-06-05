#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
class algorithm {

private:
    bool m[18] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

public:
    algorithm() {
    }
    algorithm(bool mask[18]) {
        for (int i = 0; i < 18; ++i) m[i] = mask[i];
    }

    bool* prog(bool input[18]) {
        bool* output = new bool[18];
        // rewriting input to output without first element
        for (int i = 1; i < 18; ++i) output[i] = input[i - 1];
        // transforming input with mask
        for (int i = 0; i < 18; ++i) input[i] = input[i] xor m[i];
        for (int i = 2; i < 18; i = i * 2) {
            for (int j = 0; j < 18; j = j + i) {
                if (j + (i / 2) > 17) continue;
                input[j] = input[j] xor input[j + (i / 2)];
            }
        }
        //transforming last element from outside array
        output[0] = input[0] xor input[16];

        return output;
    }

};

bool* reading(bool* arr, const int size, ifstream &in) {   

    if (in.is_open())
    {   //waiting to end of line
        char ch = '\0';
           for (int i = 0; i < size; i++)
           {
               in.get(ch);
               
               if (ch == '1') {
                   arr[i] = true;
               }
               if (ch == '0') {
                   arr[i] = false;
               }    
               
           }
           return arr;
    }
    else {
        throw exception("impossible to open file");
    }

}


int main()
{
    string source;
    ifstream in;
    ofstream out;
    in.open("test");
    bool* number = new bool[20];
    algorithm nazvanie = algorithm();
    bool* answer = nazvanie.prog(number);
    while (in.peek() != -1)
    {       
        number = reading(number, 18, in);
        
        for (int i = 0; i < 18; i++)
        {
            cout << answer[i];
        }
        cout << endl;

    }
    in.close();
}

