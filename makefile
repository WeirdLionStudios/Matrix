MATRIX_LIB=lib

include $(MATRIX_LIB)/make.config

GAUSS_EXEC=gauss_determinant
INVERSE_EXEC=inverse
MATRIX_LIB_INCLUDE=$(MATRIX_LIB)/include/

CPP_FLAGS=-I$(MATRIX_LIB_INCLUDE)

OBJS_COMMON=		\
$(MATRIX_LIB_OBJS)	\

OBJS_GAUSS=		\
gauss_determinant.o	\
$(OBJS_COMMON)		\

OBJS_INVERSE=		\
$(OBJS_COMMON)		\
inverse.o		\

.PHONY: all clean gauss inverse

all:gauss inverse
	echo Compiled all c++ projects

gauss: $(OBJS_GAUSS)
	g++ -o $(GAUSS_EXEC) $(OBJS_GAUSS)

inverse: $(OBJS_INVERSE)
	g++ -o $(INVERSE_EXEC) $(OBJS_INVERSE)

%.o: %.cpp
	g++ -c $< -o $@ $(CPP_FLAGS)

clean:
	rm *.o */*.o *~ */*~

