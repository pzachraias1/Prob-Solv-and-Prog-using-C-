#include <iostream>
#include "FileStreamBuf.h"

int main(int argc, const char * argv[]) {
    //char filename [] = "test.txt";
    FILE* file = fopen("test.txt", "wb");
    FileStreamBuf buff(file, 1);
    std::ostream os (&buff);
    os.write("Hello bye", 9);
    
}
