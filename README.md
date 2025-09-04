# CSTimer-3DS
A Speed Cubing Timer for the 3DS inspired by the aesthetics of csTimer at
https://github.com/cs0x7f/cstimer by @cs0x7f

The app includes Timer functionality, Past five solve recorder with interactive adjustments, Average-of-five scorer and an Automated Scrambler.

# BUILDING
To build source code simply run make in the root, ensuring devkitpro resources are installed.

To build 3dsx into a cia makerom will be needed, you can download it here https://github.com/3DSGuy/Project_CTR/releases/tag/makerom-v0.18.4
in the root folder write;
  ./path-to-makerom -f cia -o cstimer.cia -rsf homebrew.rsf -elf 3dsdevah.elf -banner icon/banner.bin -icon icon/icon.smdh
