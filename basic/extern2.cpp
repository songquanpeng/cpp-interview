// If we want to use const variable in another file, we should use the extern keyword!
const int x2 = 2;
// Like this: 
extern const int x3 = 3;
// For non-const variable, it's default extern.
int x1 = 1;