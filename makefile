SRCDIR = ./src
OUTDIR = ./bin

object : main.o fileIO.o login.o manageData.o menu.o
	gcc -o $(OUTDIR)/object.out main.o fileIO.o login.o manageData.o menu.o
main.o : main.c


