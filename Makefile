
default:
	g++ ./src/classes/WaterDrop.cpp ./src/main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -Llib -Iinc -o fluid_sim
