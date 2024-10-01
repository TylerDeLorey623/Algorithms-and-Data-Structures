Running the C++ files in the assignment
## In order to run the C++ code, you need a couple things set up
You need to be able to access the make command to run the code using the Makefile provided.
You also need access to the g++ command since the Makefile uses g++ to compile the C++ code in this repository.

LINUX:
  - To get g++, simply run "sudo apt install g++" in the terminal
  - To get make, simply run "sudo apt install make" in the terminal
  - If these don't work, try running "sudo apt update" in the terminal

WINDOWS:
  - You need to install tools to get these working
  - Something I recommend would be installing MSYS2 (MinGW64) to get access to these commands

MAC:
  - This repository has not been explicitly tested on MacOS, but you should probably be able to install g++ and make using Homebrew
  - Run "brew install gcc make" in the terminal if Homebrew is installed on your machine

## After setting up...
  
Go into the directory of the assignment you want to run, and simply run the command:
  - make
    
The output should appear in the terminal. 
If you want to remove the extra files added when running "make", simply run:
  - make clean

## Final Notes
The programs should work if you're running it on either Windows or Linux, but I'm not sure if it would be functional running on Mac.
If any problem arises, just let me know so I could try to fix it.
