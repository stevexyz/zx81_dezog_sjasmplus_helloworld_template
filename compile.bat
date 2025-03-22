@echo off

clean.bat

sjasmplus\sjasmplus.exe --nologo --msg=war --fullpath --outprefix=.  --sld=zx81_hello_world.sld --lst=zx81_hello_world.lst --lstlab --sym=zx81_hello_world.sym --raw=zx81_hello_world.p zx81_hello_world.asm 

