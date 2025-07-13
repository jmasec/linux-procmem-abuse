# linux-procmem-abuse

## LD_PRELOAD
```bash
gcc -fPIC -shared -o libinject.so lib_inject.c -ldl
gcc main.c -o test
LD_PRELOAD=$PWD/libinject.so ./test
```

