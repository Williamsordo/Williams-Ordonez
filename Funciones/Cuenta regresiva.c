#include <stdio.h>

void cuentaRegresiva() {
    for(int i = 10; i > 0; i--) {
        printf("%d\n", i);
    }
    printf("¡Despegue!\n");
}

int main() {
    cuentaRegresiva();
    return 0;
}
