#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *handle;
    double (*add)(double, double);
    double (*subt)(double, double);
    double (*multip)(double, double);
    double (*divide)(double, double);
    char *error;
    
    handle = dlopen("./libcalc.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }
    
    add = dlsym(handle, "add");
    subt = dlsym(handle, "subtract");
    multip = dlsym(handle, "multiply");
    divide = dlsym(handle, "divide");
    
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        dlclose(handle);
        return 1;
    }
    
    double a = 10.0, b = 5.0;
    printf("=== 동적 라이브러리 사칙연산 테스트 ===\n");
    printf("a = %.1f, b = %.1f\n", a, b);
    printf("덧셈: %.1f\n", add(a, b));
    printf("뺄셈: %.1f\n", subt(a, b));
    printf("곱셈: %.1f\n", multip(a, b));
    printf("나눗셈: %.1f\n", divide(a, b));
    
    dlclose(handle);
    return 0;
}
