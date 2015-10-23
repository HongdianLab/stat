all : main.o MetricStore.o
	g++ -o main main.o MetricStore.o

main.o : main.cpp MetricStore.h
	g++ -c main.cpp
MetricStore.o : MetricStore.cpp MetricStore.h
	g++ -c MetricStore.cpp
clean :
	rm main *.o
