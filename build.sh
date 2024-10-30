#!/bin/bash
# Build Script

# Compile Library
gcc -fPIC -c mathio.c -o libmathio.o                # Compile source to object file with position-independent code
gcc -shared -o libmathio.so libmathio.o            # Create the shared library

# Install Library
cp libmathio.so $PREFIX/lib/libmathio.so            # Copy shared library to specified location

# Install Headers
cp mathio.h $PREFIX/include/mathio.h                # Copy header file to specified include directory

# Compile Tool
gcc -o mathio tool_mathio.c -L$PREFIX/lib -lmathio  # Compile tool linking against the shared library

# Install Tool
cp mathio $PREFIX/bin/mathio # Copy the compiled tool to the specified binary directory
# Give Permissions
chmod +x $PREFIX/bin/mathio