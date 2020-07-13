#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t swap_dword(uint32_t v) {
    /*return  (v & 0xff000000) >> 24 | (v & 0x00ff0000) >> 8 |
            (v & 0x0000ff00) << 8 | (v & 0x000000ff) << 24;
    */
    return ntohl(v);
}

uint32_t read_dword(const char* path) {
    FILE* fp = fopen(path, "rb");
    uint32_t read;
    fread(&read, 1, 4, fp);
    fclose(fp);
    return swap_dword(read);
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }
    uint32_t    a = read_dword(argv[1]), b = read_dword(argv[2]),
                c = a + b;
    printf("%lu(0x%x) + %lu(0x%x) = %lu(0x%x)\n", a, a, b, b, c, c);
    return 0;
}