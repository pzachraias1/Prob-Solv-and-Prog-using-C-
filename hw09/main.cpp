#include <iostream>
#include "FileStreamBuf.h"

int main(int argc, const char * argv[]) {
    //= *new char [size];
    FILE* file = fopen("test.txt", "wb");
    //FILE* file = fopen("test.txt", "rb");
    FileStreamBuf buff(file, 2);
    std::ostream os (&buff);
    os.write("Bird and the Bee story", 30);
    
    
    int size = 6;
    char example [] = "hellos";
    //FILE* read = fopen("test.txt", "rb");
    FileStreamBuf buffReader (file, 5);
    
    std::istream is (&buffReader);
    is.read(example, size);
    std::cout << example << std::endl;
}
