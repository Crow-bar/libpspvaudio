PSPSDK = $(shell psp-config --pspsdk-path)
ifeq ($(PSPSDK),)
$(error PSPSDK wasn't set)
endif

TARGET_LIB = libpspvaudio.a
HEADER = pspvaudio.h

OBJS = sceVaudio_0000.o sceVaudio_0001.o sceVaudio_0002.o \
		sceVaudio_0003.o sceVaudio_0004.o sceVaudio_0005.o \
		sceVaudio_0006.o sceVaudio_0007.o sceVaudio_0008.o
CFLAGS = -O0 -G0

include $(PSPSDK)/lib/build.mak

install: $(TARGET_LIB)
	@cp -v $(TARGET_LIB) $(PSPSDK)/lib
	@cp -v $(HEADER) $(PSPSDK)/include
	@echo "Done."

uninstall:
	@rm -f $(PSPSDK)/lib/$(TARGET_LIB)
	@rm -f $(PSPSDK)/include/$(HEADER)
	@echo "Done."

$(OBJS): sceVaudio.S
	$(CC) $(CFLAGS) -DF_$* $< -c -o $@
