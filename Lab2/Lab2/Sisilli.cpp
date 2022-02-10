#include <iostream>
using namespace std;

unsigned int fact_iterative(unsigned int n){
    //Question 2
    unsigned int total = 1;
    for (unsigned int i = 1; i <= n; i++ ) {
        total *= i;
    }
    return total;
}
unsigned int fact_recursive(unsigned int n) {
    //Question 1
    if (n == 1 || n == 0) {
        return 1;
    }
    else {
        return n * fact_recursive(n - 1);
    }
}

int main() {
    cout << fact_recursive(6) << endl;
    cout << fact_iterative(4) << endl;

    return 0;
}


void iterative_char(char start, char last) {
    //Question 4
    for (char i = start; i < last; i++) {
        cout << i << ',';
    }
    cout << last << endl;
}
void recursive_char(char start, char last) {
    //Question 3
    if (start == last) {
        cout << start<<endl;
    }
    else {
        cout << start << ',';
        recursive_char(start+1,last);
    }

}

int main() {
    recursive_char('c', 'h');
    iterative_char('c','h');
    return 0;
}