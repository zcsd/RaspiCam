LIBS = -I/usr/local/include/ 
CFLAGS = -lraspicam -lraspicam_cv -lopencv_core -lopencv_highgui
objects= main.o camera.o

picam: $(objects) 
	g++ $(objects) -o picam $(LIBS)$(CFLAGS)

main.o: main.cpp camera.h
	g++ main.cpp -c

camera.o: camera.cpp camera.h
	g++ camera.cpp -c
	
.PHONY: clean
clean:
	rm picam $(objects)
