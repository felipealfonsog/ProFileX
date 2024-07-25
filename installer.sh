#!/bin/bash

# Maintainer: Felipe Alfonso Gonzalez <f.alfonso@res-ear.ch>
# Version: 0.0.5
# Description: ProFileX is a Linux file management tool with a GTK3-based GUI.
# License: BSD-3-Clause
# URL: https://github.com/felipealfonsog/ProFileX
# Dependencies: gtk3, gcc

pkgname=profilex
pkgver=0.0.5
pkgrel=1
pkgdesc="ProFileX is a Linux file management tool with a GTK3-based GUI."
arch=('x86_64')
url="https://github.com/felipealfonsog/ProFileX"
license=('BSD-3-Clause')
depends=('gtk3' 'gcc')
source=("https://github.com/felipealfonsog/ProFileX/archive/refs/tags/v.${pkgver}.tar.gz")
sha256sums=('7d6039c99c57dbf40f0c586f870f0951cb21a3d64d58ed2cb58576a65ca71864')

# Print credits and information
echo "************************************************************"
echo "* Welcome to the installation of ProFileX                 *"
echo "* Maintained by: Felipe Alfonso Gonzalez <f.alfonso@res-ear.ch> *"
echo "* Version: ${pkgver}                                     *"
echo "* Description: ${pkgdesc}                               *"
echo "* License: ${license[0]}                                *"
echo "* More info: ${url}                                    *"
echo "* Dependencies: ${depends[@]}                            *"
echo "************************************************************"
echo ""

# Prepare environment
prepare() {
  echo "Preparing build environment..."
  mkdir -p "$srcdir"
  wget -O "${srcdir}/v.${pkgver}.tar.gz" "${source[0]}"
  tar xf "${srcdir}/v.${pkgver}.tar.gz" -C "$srcdir" --strip-components=1
}

# Build the package
build() {
  echo "Building package..."
  cd "${srcdir}/ProFileX-v.${pkgver}"
  gcc $(pkg-config --cflags gtk+-3.0) -o profilex src/main.c src/file_manager.c $(pkg-config --libs gtk+-3.0)
}

# Install the package
package() {
  echo "Installing package..."
  cd "${srcdir}/ProFileX-v.${pkgver}"

  # Install the binary to /usr/local/bin
  install -Dm755 profilex "${pkgdir}/usr/local/bin/profilex"

  # Install the icon
  install -Dm644 "${srcdir}/ProFileX-v.${pkgver}/src/profilex-iconlogo.png" "${pkgdir}/usr/share/pixmaps/profilex.png"

  # Install the .desktop file
  install -Dm644 "${srcdir}/ProFileX-v.${pkgver}/src/profilex.desktop" "${pkgdir}/usr/share/applications/profilex.desktop"
}

# Execute the functions
prepare
build
package

echo "Installation complete!"
