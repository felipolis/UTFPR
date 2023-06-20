import optparse
from os import system

if __name__ == "__main__":

    p = optparse.OptionParser()
    p.add_option('--module', '-m')
    p.add_option('--clean', '-c')
    opt, args = p.parse_args()

    if opt.clean:
        mo = opt.clean
        system(f"rm *.o *.so {mo}.py {mo}_wrap.c __pycache__/ -Rf")
    if opt.module:
        mo = opt.module
        system(f"swig -python {mo}.i")
        system(f"gcc -fPIC -O0 -c {mo}.c {mo}_wrap.c -I/usr/include/python3.11")
        system(f"ld -shared {mo}.o {mo}_wrap.o -o _{mo}.so")