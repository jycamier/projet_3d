#! /bin/sh

latex -interaction=batchmode TD.tex
latex -interaction=batchmode TD.tex
rm *.aux
dvips TD.dvi
rm *.dvi
ps2pdf TD.ps
rm *.ps
rm *.tdo *.toc *.log

