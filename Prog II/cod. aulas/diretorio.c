#include <unistd.h>
#include <stdio.h>

int main() {
    char dir[1024];
    getcwd(dir, sizeof(dir));
    printf("Diretório atual: %s\n", dir);
    return 0;
}
