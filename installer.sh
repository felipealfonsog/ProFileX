#!/bin/bash

# Installer for ProFileX on Linux systems

# Define variables
INSTALL_DIR="/usr/local/bin"
EXECUTABLE_NAME="proFileX"
SOURCE_URL="https://github.com/felipealfonsog/ProFileX/archive/refs/tags/v0.0.2.tar.gz"
TMP_DIR=$(mktemp -d)
SOURCE_DIR="$TMP_DIR/ProFileX-0.0.2"

# Function to display error and exit
error_exit() {
    echo "Error: $1"
    rm -rf "$TMP_DIR"
    exit 1
}

# Download source archive
echo "Downloading ProFileX source code..."
wget -q --show-progress -O "$TMP_DIR/proFileX.tar.gz" "$SOURCE_URL" || error_exit "Failed to download ProFileX source code."

# Extract source archive
echo "Extracting source code..."
tar -xf "$TMP_DIR/proFileX.tar.gz" -C "$TMP_DIR" || error_exit "Failed to extract source code."

# Build ProFileX
echo "Building ProFileX..."
cd "$SOURCE_DIR" || error_exit "Source directory not found."
qmake proFileX.pro || error_exit "Failed to run qmake."
make || error_exit "Failed to build ProFileX."

# Install ProFileX executable
echo "Installing ProFileX to $INSTALL_DIR..."
sudo install -m 755 "$SOURCE_DIR/build/proFileX" "$INSTALL_DIR" || error_exit "Failed to install ProFileX."

# Clean up
rm -rf "$TMP_DIR"

echo "ProFileX has been successfully installed to $INSTALL_DIR."
