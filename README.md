# CSTimer-3DS
A Speed Cubing Timer for the 3DS inspired by the aesthetics of csTimer at
https://github.com/cs0x7f/cstimer by @cs0x7f

The app includes Timer functionality, Past five solve recorder with interactive adjustments, Average-of-five scorer and an Automated Scrambler.

# TEXT
Install fontconfig and 3dsfont https://github.com/devkitPro/tex3ds/tree/feature/mkbcfnt

Find a font online such as monaco and run this to optomise the size:

```pyftsubset monaco.ttf --text=". 0123456789 aof: DUFBRL ' " --output-file=monaco_digits.ttf```

Run this to turn it into a font for 3ds, then move the output into romfs

```mkbcfnt -o arial.bcfntx -s 48 monaco_digits.ttf```

# BUILDING
To build source code simply run make in the root, ensuring devkitpro resources are installed.

To build 3dsx into a cia makerom will be needed, you can download it here https://github.com/3DSGuy/Project_CTR/releases/tag/makerom-v0.18.4
in the root folder write;

```./path-to-makerom -f cia -o cstimer.cia -rsf homebrew.rsf -elf 3dsdevah.elf -banner icon/banner.bin -icon icon/icon.smdh```
