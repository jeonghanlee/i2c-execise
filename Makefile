
i2c-01 : i2c-01.o 

i2c-01.o : i2c-01.c
	gcc -c i2c-01.c
clean :
	rm i2c-01 i2c-01.o *~
