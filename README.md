# ZX81 assembler projects template

This project to jumpstart ZX81 assemler developments with a modern integrated IDE/debugger.

Project is setup to use the internal DeZog emulator.

Required to be installed: Visual Studio Code with DeZog extension (https://github.com/maziac/DeZog). Recommended full sjasmplus (https://github.com/z00m128/sjasmplus): just "frozen" executable is provided within this repo.

How to start?
- Start vscode with "code ." inside the root repo directory
- Set a breakpoint inside the zx81_hello_world.asm on the infinite loop
- Run->Start Debugging (F5): the program will compile, will display hello world on the ZX81 emulated screen and stop on the infinite loop

Notes:
- To change the program name remember to change it also in the launch.json and tasks.json files in the .vscode directory
- When starting debug be sure to select DeZog
- To be able to set breakpoints in the source file verify that it has beeen recognized as assembler file in the language mode (and not e.g. as a Plain Text) in the bottom right of the window

External interesting links:
- Another very nice example that can be used to jumpstart is at: https://github.com/maziac/zx81-sample-program
- A very nice guide on how to create a game on ZX81 is at https://sinclairzxworld.com/viewtopic.php?f=6&t=4045

