#!/bin/bash
# Build Script for MathIO

set -e  # Exit immediately if a command exits with a non-zero status

# Default installation prefix
PREFIX=${PREFIX:-/usr/local}

# Define installation directories
LIB_DIR="$PREFIX/lib"
INCLUDE_DIR="$PREFIX/include"
BIN_DIR="$PREFIX/bin"

echo "Installation prefix: $PREFIX"

# Create necessary directories
mkdir -p "$LIB_DIR"
mkdir -p "$INCLUDE_DIR"
mkdir -p "$BIN_DIR"

# Compile Library
echo "Compiling library..."
gcc -fPIC -c mathio.c -o libmathio.o                # Compile source to object file with position-independent code
gcc -shared -o libmathio.so libmathio.o            # Create the shared library

# Install Library
echo "Installing library to $LIB_DIR..."
cp libmathio.so "$LIB_DIR/"

# Install Headers
echo "Installing headers to $INCLUDE_DIR..."
cp mathio.h "$INCLUDE_DIR/"

# Compile Tool
echo "Compiling MathIO tool..."
gcc -o mathio tool_mathio.c -L"$LIB_DIR" -lmathio -I"$INCLUDE_DIR" -Wl,-rpath="$LIB_DIR"  # Compile tool linking against the shared library

# Install Tool
echo "Installing MathIO to $BIN_DIR..."
cp mathio "$BIN_DIR/"

# Give Permissions
chmod +x "$BIN_DIR/mathio"

echo "MathIO installation completed successfully!"
