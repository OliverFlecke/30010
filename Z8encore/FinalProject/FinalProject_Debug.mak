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
#   -usrinc:"C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\include;C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\include"
#   -NOwatch -cpu:Z8F6403
#   -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X -revaa"
CFLAGS = -sw:C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\FinalProject_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt
#   -warn -NOzmasm -revaa -cpu:Z8F6403
AFLAGS = -sw:C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\FinalProject_Debug.asmsw

OUTDIR = C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\

Debug: FinalProject

deltarget: 
	@if exist C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\FinalProject.lod  \
            del C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\FinalProject.lod

clean: 
	@if exist C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\FinalProject.lod  \
            del C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\FinalProject.lod
	@if exist C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\zsldevinit.obj  \
            del C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\zsldevinit.obj
	@if exist C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\main.obj  \
            del C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\main.obj
	@if exist C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\SerialDriver.obj  \
            del C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\SerialDriver.obj
	@if exist C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\Timer.obj  \
            del C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\Timer.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\zsldevinit.obj  \
            C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\main.obj  \
            C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\SerialDriver.obj  \
            C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\Timer.obj

FinalProject: $(OBJS)
	 $(LINK)  @C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\FinalProject_Debug.linkcmd

C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\zsldevinit.obj :  \
            C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\zsldevinit.asm  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\zsldevinit.asm

C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\main.obj :  \
            C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\main.c  \
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
            C:\Users\CHRIST~1\SkyDrive\DOCUME~1\DTU\PROGRA~1\30010\Z8encore\FINALP~1\include\SERIAL~1.H  \
            C:\Users\CHRIST~1\SkyDrive\DOCUME~1\DTU\PROGRA~1\30010\Z8encore\include\timer.h
	 $(CC)  $(CFLAGS) C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\main.c

C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\SerialDriver.obj :  \
            C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\include\src\SerialDriver.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\CHRIST~1\SkyDrive\DOCUME~1\DTU\PROGRA~1\30010\Z8encore\FINALP~1\include\SERIAL~1.H
	 $(CC)  $(CFLAGS) C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\include\src\SerialDriver.c

C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\Timer.obj :  \
            C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\include\src\Timer.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\CHRIST~1\SkyDrive\DOCUME~1\DTU\PROGRA~1\30010\Z8encore\include\timer.h
	 $(CC)  $(CFLAGS) C:\Users\Christian\SkyDrive\Documents\DTU\Programmeringsprojekt\30010\Z8encore\FinalProject\include\src\Timer.c

