import os, time, sys

cmds = ["nasm -f elf32 kernel.asm -o kasm.o", 
        "gcc -m32 -c kernel.c -o kc.o",
        "ld -m elf_i386 -T link.ld -o kernel.bin kasm.o kc.o",
        "cp kernel.bin kernel/boot/kernel.bin",
        "grub2-mkrescue -o kernel.iso kernel"]

print "Building..."
for i in cmds:
    os.system(i)

print "build complete"
if(len(sys.argv) > 1):
    os.system("qemu-system-x86_64 -boot d -cdrom kernel.iso -m 512")
