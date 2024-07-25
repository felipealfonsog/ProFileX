#!/bin/bash

# Script de instalación para ProFileX
# Mantained by: Felipe Alfonso Gonzalez <f.alfonso@res-ear.ch>
# Version: 0.0.5
# Description: ProFileX is a Linux file management tool with a GTK3-based GUI.
# License: BSD-3-Clause
# URL: https://github.com/felipealfonsog/ProFileX

# Variables
pkgname="profilex"
pkgver="0.0.6"
srcdir="/tmp/${pkgname}-${pkgver}"
source="https://github.com/felipealfonsog/ProFileX/archive/refs/tags/v.${pkgver}.tar.gz"
bin_path="/usr/local/bin/profilex"
icon_path="/usr/share/pixmaps/profilex.png"
desktop_path="/usr/share/applications/profilex.desktop"

# Mostrar créditos
echo "************************************************************"
echo "* Welcome to the installation of ProFileX                 *"
echo "* Maintained by: Felipe Alfonso Gonzalez <f.alfonso@res-ear.ch> *"
echo "* Version: ${pkgver}                                     *"
echo "* Description: ProFileX is a Linux file management tool with a GTK3-based GUI. *"
echo "* License: BSD-3-Clause                                *"
echo "* More info: https://github.com/felipealfonsog/ProFileX  *"
echo "* Dependencies: gtk3, gcc                            *"
echo "************************************************************"
echo ""

# Función para preparar el entorno
prepare() {
  echo "Preparing build environment..."
  mkdir -p "$srcdir"
  wget -O "${srcdir}/v.${pkgver}.tar.gz" "$source"
  tar xf "${srcdir}/v.${pkgver}.tar.gz" -C "$srcdir" --strip-components=1
}

# Función para construir el paquete
build() {
  echo "Building package..."
  cd "$srcdir"
  gcc $(pkg-config --cflags gtk+-3.0) -o profilex src/main.c src/file_manager.c $(pkg-config --libs gtk+-3.0)
}

# Función para instalar el paquete
package() {
  echo "Installing package..."
  
  # Instalación del binario
  sudo install -Dm755 profilex "$bin_path"

  # Instalación del icono
  sudo install -Dm644 src/profilex-iconlogo.png "$icon_path"

  # Instalación del archivo .desktop
  sudo install -Dm644 src/profilex.desktop "$desktop_path"
}

# Ejecutar funciones
prepare
build
package

echo "Installation complete!"
