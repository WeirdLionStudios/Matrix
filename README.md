Matrix
======

studio di matrici fatte nel corso

Study of matrix algorithms

The project contains a library shared by the programs.
Read the file lib.txt for more informations.

Build Instructions
------------------

If libmatrix is not already compiled, it is created when a program is built.

make all: compile all the programs

make gauss: compile the gauss determinant program

make inverse: compile the inverse matrix program

make kramer: compile kramer program

make multiplication: compile the matrix multiplication program

make libmatrix: compile libmatrix from source

Clean Instructions
------------------

make clean: remove all object and temp files. Use at the end of compilation

make clean-exec: remove object and temporary files and already compiled
				executables. Use when recompiling programs after modifications.

make clean-all: remove all object, temporary and executable files as above,
				but also removes the compiled library. Use when the libmatrix
				sources are modified and a recompilation is needed, and also
				when doing a commit, in order to not push useless junk.
