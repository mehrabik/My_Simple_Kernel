all:
	mkdir -p out
	nasm -felf32 start.asm -o out/boot.o
	nasm -felf32 process.asm -o out/process.o	
	i686-elf-gcc -Iinclude/ -Ivfs/ -c kernel.c -o out/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -Iinclude/ -Ivfs/ -c gdt.c -o out/gdt.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -Iinclude/ -Ivfs/ -c idt.c -o out/idt.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -Iinclude/ -Ivfs/ -c isrs.c -o out/isrs.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -Iinclude/ -Ivfs/ -c irq.c -o out/irq.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -Iinclude/ -Ivfs/ -c tss.c -o out/tss.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -Iinclude/ -Ivf/ -c scrn.c -o out/scrn.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -Iinclude/ -Ivfs/ -c syscall.c -o out/syscall.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -Iinclude/ -Ivfs/ -c page.c -o out/page.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -Iinclude/ -Ivfs/ -c task.c -o out/task.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -Iinclude/ -Ivfs/ -c string.c -o out/string.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -Iinclude/ -Ivfs/ -c kmem.c -o out/kmem.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -Iinclude/ -Ivfs/ -c vmem.c -o out/vmem.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -Iinclude/ -Ivfs/ -c frame.c -o out/frame.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -Iinclude/ -Ivfs/ -c system.c -o out/system.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -Iinclude/ -Ivfs/ -c types/ordered_array.c -o out/ordered_array.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -Iinclude/ -Ivfs/ -c kb.c -o out/kb.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i686-elf-gcc -Iinclude/ -Ivfs/ -c check.c -o out/check.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
									
	
	i686-elf-gcc -T link.ld -o out/myos.bin -ffreestanding -O2 -nostdlib out/boot.o out/kernel.o out/process.o out/gdt.o out/idt.o out/isrs.o out/irq.o out/tss.o out/scrn.o out/syscall.o out/page.o out/task.o out/string.o out/kmem.o out/vmem.o out/frame.o out/system.o out/ordered_array.o out/kb.o out/check.o -lgcc
clean:
	rm -rf out
