#
# ZDS II Make File - FinalProject2, Debug
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
#   -usrinc:"M:\Documents\GitHub\30010\Z8encore\FinalProject2\include"
#   -NOwatch -cpu:Z8F6403
#   -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X -revaa"
CFLAGS = -sw:M:\Documents\GitHub\30010\Z8encore\FinalProject2\FinalProject2_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt
#   -warn -NOzmasm -revaa -cpu:Z8F6403
AFLAGS = -sw:M:\Documents\GitHub\30010\Z8encore\FinalProject2\FinalProject2_Debug.asmsw

OUTDIR = M:\Documents\GitHub\30010\Z8encore\FinalProject2\

Debug: FinalProject2

deltarget: 
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject2\FinalProject2.lod  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject2\FinalProject2.lod

clean: 
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject2\FinalProject2.lod  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject2\FinalProject2.lod
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject2\zsldevinit.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject2\zsldevinit.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject2\main.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject2\main.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject2\displayDriver.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject2\displayDriver.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject2\game.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject2\game.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject2\keyDriver.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject2\keyDriver.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject2\numberformat.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject2\numberformat.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject2\trigonometry.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject2\trigonometry.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject2\vector.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject2\vector.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject2\level.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject2\level.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject2\timerDriver.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject2\timerDriver.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject2\serialDriver.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject2\serialDriver.obj
	@if exist M:\Documents\GitHub\30010\Z8encore\FinalProject2\charset.obj  \
            del M:\Documents\GitHub\30010\Z8encore\FinalProject2\charset.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\zsldevinit.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\main.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\displayDriver.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\game.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\keyDriver.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\numberformat.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\trigonometry.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\vector.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\level.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\timerDriver.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\serialDriver.obj  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\charset.obj

FinalProject2: $(OBJS)
	 $(LINK)  @M:\Documents\GitHub\30010\Z8encore\FinalProject2\FinalProject2_Debug.linkcmd

M:\Documents\GitHub\30010\Z8encore\FinalProject2\zsldevinit.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\zsldevinit.asm  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject2\zsldevinit.asm

M:\Documents\GitHub\30010\Z8encore\FinalProject2\main.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\main.c  \
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
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\charset.h  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\DISPLA~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\game.h  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\KEYDRI~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\level.h  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\NUMBER~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\SERIAL~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\TIMERD~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\TRIGON~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\vector.h
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject2\main.c

M:\Documents\GitHub\30010\Z8encore\FinalProject2\displayDriver.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\displayDriver.c  \
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
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\charset.h  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\DISPLA~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\SERIAL~1.H
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\displayDriver.c

M:\Documents\GitHub\30010\Z8encore\FinalProject2\game.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\game.c  \
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
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\charset.h  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\DISPLA~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\game.h  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\KEYDRI~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\level.h  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\NUMBER~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\SERIAL~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\TIMERD~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\TRIGON~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\vector.h
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\game.c

M:\Documents\GitHub\30010\Z8encore\FinalProject2\keyDriver.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\keyDriver.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\KEYDRI~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\TIMERD~1.H
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\keyDriver.c

M:\Documents\GitHub\30010\Z8encore\FinalProject2\numberformat.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\numberformat.c  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\NUMBER~1.H
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\numberformat.c

M:\Documents\GitHub\30010\Z8encore\FinalProject2\trigonometry.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\trigonometry.c  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\TRIGON~1.H
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\trigonometry.c

M:\Documents\GitHub\30010\Z8encore\FinalProject2\vector.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\vector.c  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\NUMBER~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\TRIGON~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\vector.h
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\vector.c

M:\Documents\GitHub\30010\Z8encore\FinalProject2\level.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\level.c  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\level.h
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\level.c

M:\Documents\GitHub\30010\Z8encore\FinalProject2\timerDriver.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\timerDriver.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\TIMERD~1.H
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\timerDriver.c

M:\Documents\GitHub\30010\Z8encore\FinalProject2\serialDriver.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\serialDriver.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\NUMBER~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\SERIAL~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\TRIGON~1.H  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\vector.h
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\serialDriver.c

M:\Documents\GitHub\30010\Z8encore\FinalProject2\charset.obj :  \
            M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\charset.c  \
            M:\DOCUME~1\GitHub\30010\Z8encore\FINALP~2\include\charset.h
	 $(CC)  $(CFLAGS) M:\Documents\GitHub\30010\Z8encore\FinalProject2\include\src\charset.c

