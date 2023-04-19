struct Z { };

struct X { 
    explicit operator Z (); // X can be converted to Z explicitly
    explicit X(int a) { // X can be constructed from int explicitly
        // constructor implementation
    }
};

struct Y{
    Y(int a); // int can be implicitly converted to Y
    operator Z (); // Y can be implicitly converted to Z
};

int main() {
    X a(1);
    // X b = 1; // error: no matching function for call to 'X::X(int)'
    // X c = Y(2); // error: no matching function for call to 'X::X(Y)'
    X b();
    return 0;
}