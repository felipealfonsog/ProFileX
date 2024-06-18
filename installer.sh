#!/bin/bash

# Installer for ProFileX on Linux systems

# Define variables
INSTALL_DIR="/usr/local/bin"
EXECUTABLE_NAME="proFileX"
VERSION="0.0.3"  # Define the version
SOURCE_URL="https://github.com/felipealfonsog/ProFileX/archive/refs/tags/v.${VERSION}.tar.gz"
TMP_DIR=$(mktemp -d)
SOURCE_DIR="$TMP_DIR/ProFileX-${VERSION}"

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

# Create desktop entry
echo "Creating desktop entry..."
sudo mkdir -p /usr/share/applications
sudo tee /usr/share/applications/proFileX.desktop > /dev/null <<EOT
[Desktop Entry]
Version=1.0
Type=Application
Name=ProFileX
Comment=A Linux file management tool with a Qt-based GUI
Exec=$EXECUTABLE_NAME
Icon=applications-utilities
Terminal=false
Categories=Utility;
EOT

# Clean up
rm -rf "$TMP_DIR"

echo "ProFileX v.${VERSION} has been successfully installed to $INSTALL_DIR."
