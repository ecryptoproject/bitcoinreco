
Debian
====================
This directory contains files used to package bitcoinrecod/bitcoinreco-qt
for Debian-based Linux systems. If you compile bitcoinrecod/bitcoinreco-qt yourself, there are some useful files here.

## bitcoinreco: URI support ##


bitcoinreco-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install bitcoinreco-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your bitcoinreco-qt binary to `/usr/bin`
and the `../../share/pixmaps/bitcoinreco128.png` to `/usr/share/pixmaps`

bitcoinreco-qt.protocol (KDE)

