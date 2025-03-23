# ZX81 assembler projects template

This project to jumpstart ZX81 assembler developments with a modern integrated IDE/debugger.

Project is setup to use the new internal ZX81 DeZog emulator.

Required to be installed: Visual Studio Code with [DeZog extension](https://github.com/maziac/DeZog). Recommended full [sjasmplus](https://github.com/z00m128/sjasmplus) installation, even if the executable provided within this repo should be enough to start.

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
- [Another nice and elaborated example](https://github.com/maziac/zx81-sample-program) that can be used to jumpstart ZX81 assembler programming
- [A nice guide on how to create a game](https://sinclairzxworld.com/viewtopic.php?t=4045) on ZX81

