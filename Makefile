jjy.exe: main.c jjy_encode.o jjy_decode.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

jjy_encode.o: jjy_encode.c jjy_encode.h
	$(CC) $(CFLAGS) -c $<

jjy_decode.o: jjy_decode.c jjy_decode.h
	$(CC) $(CFLAGS) -c $<