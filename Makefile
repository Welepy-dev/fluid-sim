all :
	gcc main.c utils.c smoothing.c -lraylib -Llib -Iincludes -lGL -lm -lpthread -ldl -lrt -lX11 -o main
