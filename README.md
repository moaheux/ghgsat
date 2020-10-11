# ghgsat

This project is the answer to the proposed ghgsat challenge.
The aim of the project is to extract matadata from a .sexp file. And then display the information.
This project must be cross plateform and run on X86 and ARM device.

To compile:
$ cd ghgsat

For x86:
$ make native

for ARM:
$ make cross

Make sure arm-linux-gnueabihf-g++ is install on your machine.

Executables will appear in root.

To run:

On linux environement:
X86:

$ ./ghgsat_native

ARM: ( I was using qemu-arm )

$ qemu-arm ghgsat_cross

Project description:
I decided to use c++ for this project because it is much easier with this language to deal with string.
A sub function will be in charge to read the provided file and then split line into string, with the care to remove space and parenthesis.
If the Label we are looking for is found, it is easy to deduce that the value we are looking for is the next one.

Unit Test:
You can run Unit test by uncomment the "#define TEST". The software will then ask for the file name to test, and the string to find.

Exemple:
$./ghgsat

Enter Name of file to test
test2
Enter string to find
floatVal
output 0.055

As you can see, you don't need to specify the extension. And files are store in files repository.

FURTHER WORK:

I would love to have the time to do it in C and have a better memory management.
Change variable's names and make it more industry friendly.
Implement a better error manager. There is way to much "return" in this code. A throw and catch could be nice.
