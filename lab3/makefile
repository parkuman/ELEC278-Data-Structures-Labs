# Makefile for ELEC278 Lab 3
# Meant to be used with MSVC nmake command

bst.exe:	main.obj bst.obj
		cl /nologo /Febst /Fmbst bst.obj main.obj

main.obj:	main.c bst.h

bst.obj:	bst.c. bst.h

clean:
			del *.obj
			del *.map
			del *.exe
