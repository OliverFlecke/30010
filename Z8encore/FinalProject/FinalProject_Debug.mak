#
# ZDS II Make File - FinalProject, Debug
#

CC = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8cc
ASM = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8asm
LINK = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8link
LIB = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8lib

# compiler options
#   -alias -asm -bitfieldsize:32 -charsize:8 -const:RAM -debug
#   -define:_Z8F6403 -define:_Z8ENCORE_640_FAMILY
#   -define:_Z8ENCORE_F640X -define:_MODEL_LARGE -doublesize:32
#   -NOexpmac -floatsize:32 -NOfplib -genprintf -NOglobalcopy
#   -NOglobalcse -NOglobalfold -intrinsic -intsize:16 -intsrc -NOjmpopt
#   -NOkeepasm -NOkeeplst -NOlist -NOlistinc -localcopy -localcse
#   -localfold -longsize:32 -NOloopopt -maxerrs:50 -model:L -NOoptlink
#   -optsize -peephole -NOpromote -quiet -regvar -revaa -NOsdiopt
#   -shortsize:16
#   -stdinc:"C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -strict
#   -usrinc:"M:\Documents\GitHub\30010\Z8encore\FinalProject\include"
#   -NOwatch -cpu:Z8F6403
#   -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X -revaa"
CFLAGS = -sw:M:\Documents\GitHub\30010\Z8encore\FinalProject\FinalProject_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt
#   -warn -NOzmasm -revaa -cpu:Z8F6403
AFLAGS = -sw:M:\Documents\GitHub\30010\Z8encore\FinalProject\FinalProject_Debug.asmsw

OUTDIR = M:\Documents\GitHub\30010\Z8encore\FinalProject\

Debug: FinalProject

deltarget: 
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject\FinalProject.lod  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject\FinalProject.lod

clean: 
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject\FinalProject.lod  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject\FinalProject.lod
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject\zsldevinit.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject\zsldevinit.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject\main.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject\main.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject\charset.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject\charset.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject\displayDriver.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject\displayDriver.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject\game.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject\game.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject\keyDriver.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject\keyDriver.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject\level.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject\level.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject\numberformat.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject\numberformat.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject\serialDriver.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject\serialDriver.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject\timerDriver.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject\timerDriver.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject\trigonometry.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject\trigonometry.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject\vector.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject\vector.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\zsldevinit.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\main.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\charset.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\displayDriver.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\game.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\keyDriver.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\level.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\numberformat.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\serialDriver.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\timerDriver.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\trigonometry.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\vector.obj

FinalProject: $(OBJS)
	 $(LINK)  @M:\Documents\GitHub\30010\Z8encore\FinalProject\FinalProject_Debug.linkcmd

M:\Documents\GitHub\30010\Z8encore\FinalProject\zsldevinit.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\zsldevinit.asm  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject\zsldevinit.asm

M:\Documents\GitHub\30010\Z8encore\FinalProject\main.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\main.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject\main.c

M:\Documents\GitHub\30010\Z8encore\FinalProject\charset.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\charset.c
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\charset.c

M:\Documents\GitHub\30010\Z8encore\FinalProject\displayDriver.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\displayDriver.c
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\displayDriver.c

M:\Documents\GitHub\30010\Z8encore\FinalProject\game.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\game.c
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\game.c

M:\Documents\GitHub\30010\Z8encore\FinalProject\keyDriver.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\keyDriver.c
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\keyDriver.c

M:\Documents\GitHub\30010\Z8encore\FinalProject\level.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\level.c
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\level.c

M:\Documents\GitHub\30010\Z8encore\FinalProject\numberformat.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\numberformat.c
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\numberformat.c

M:\Documents\GitHub\30010\Z8encore\FinalProject\serialDriver.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\serialDriver.c
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\serialDriver.c

M:\Documents\GitHub\30010\Z8encore\FinalProject\timerDriver.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\timerDriver.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\timerDriver.c

M:\Documents\GitHub\30010\Z8encore\FinalProject\trigonometry.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\trigonometry.c
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\trigonometry.c

M:\Documents\GitHub\30010\Z8encore\FinalProject\vector.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\vector.c
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject\include\src\vector.c

