#!/bin/bash

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

BITCOINRECOD=${BITCOINRECOD:-$BINDIR/bitcoinrecod}
BITCOINRECOCLI=${BITCOINRECOCLI:-$BINDIR/bitcoinreco-cli}
BITCOINRECOTX=${BITCOINRECOTX:-$BINDIR/bitcoinreco-tx}
BITCOINRECOQT=${BITCOINRECOQT:-$BINDIR/qt/bitcoinreco-qt}

[ ! -x $BITCOINRECOD ] && echo "$BITCOINRECOD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
BRECVER=($($BITCOINRECOCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for bitcoinrecod if --version-string is not set,
# but has different outcomes for bitcoinreco-qt and bitcoinreco-cli.
echo "[COPYRIGHT]" > footer.h2m
$BITCOINRECOD --version | sed -n '1!p' >> footer.h2m

for cmd in $BITCOINRECOD $BITCOINRECOCLI $BITCOINRECOTX $BITCOINRECOQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BRECVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BRECVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
