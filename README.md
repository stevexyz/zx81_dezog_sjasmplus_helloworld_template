# ZX81 assembler projects template

This project to jumpstart ZX81 assembler developments with a modern integrated IDE/debugger.

Project is setup to use the internal DeZog emulator.

Required to be installed: Visual Studio Code with DeZog extension (https://github.com/maziac/DeZog). Recommended full sjasmplus installation (https://github.com/z00m128/sjasmplus), even if the executable provided within this repo should be enough to start.

How to start?
- Start vscode with "code ." inside the root repo directory
- Set a breakpoint on line 10 inside the zx81_hello_world.asm 
- Run->Start Debugging (F5): the program will compile and run until line 10
- Press again F5 to finish the program
  (note that the output to the simulated TV is built by the ROM code 50 times per simulated second during the infinite loop execution)

Notes:
- To change the program name remember to change it also in the launch.json and tasks.json files in the .vscode directory
- When starting debug be sure to select DeZog
- To be able to set breakpoints in the source file verify that it has beeen recognized as assembler file in the language mode (and not e.g. as a Plain Text) in the bottom right of the window
- GitHub codespaces can be used to develop inside the browser instead of a local installation

External interesting links:
- Another very nice example that can be used to jumpstart is at: https://github.com/maziac/zx81-sample-program
- A very nice guide on how to create a game on ZX81 is at https://sinclairzxworld.com/viewtopic.php?f=6&t=4045

