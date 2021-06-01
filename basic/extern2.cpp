// If we want to use const variable in another file, we should use extern!
const int x2 = 2;
// Like this.0
extern const int x3 = 3;
// For non-const variable, it's default extern.
int x1 = 1;