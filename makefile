MATRIX_LIB_DIR=lib

include $(MATRIX_LIB_DIR)/make.config

EXEC=gauss inverse kramer multiplication
MATRIX_LIB_INCLUDE=$(MATRIX_LIB_DIR)/include/
MATRIX_LIB_NAME=matrix
MATRIX_LIB=$(MATRIX_LIB_DIR)/libmatrix.a

LINK_FLAGS=-static -L$(MATRIX_LIB_DIR) -l$(MATRIX_LIB_NAME)
CPP_FLAGS=-I$(MATRIX_LIB_INCLUDE)

OBJS_COMMON=

OBJS_GAUSS=		\
gauss_determinant.o	\
$(OBJS_COMMON)		\

OBJS_INVERSE=		\
$(OBJS_COMMON)		\
inverse.o		\

OBJS_KRAMER=		\
$(OBJS_COMMON)		\
kramer.o		\

OBJS_MULTIPLICATION=	\
$(OBJS_COMMON)		\
matrix_multiplication.o	\

.PHONY: all clean clean-exec clean-all gauss inverse kramer

all:$(EXEC)
	$(info *****Compiled all c++ projects*****)

gauss: $(OBJS_GAUSS) $(MATRIX_LIB)
	g++ -o $@ $(OBJS_GAUSS) $(LINK_FLAGS)

inverse: $(OBJS_INVERSE) $(MATRIX_LIB)
	g++ -o $@ $(OBJS_INVERSE) $(LINK_FLAGS)

kramer: $(OBJS_KRAMER) $(MATRIX_LIB)
	g++ -o $@ $(OBJS_KRAMER) $(LINK_FLAGS)

multiplication: $(OBJS_MULTIPLICATION) $(MATRIX_LIB)
	g++ -o $@ $(OBJS_MULTIPLICATION) $(LINK_FLAGS)
	
libmatrix: $(MATRIX_LIB)
	$(info *****libmatrix compilation complete*****)

%.a: $(MATRIX_LIB_OBJS)
	$(info *****creating libmatrix archive*****)
	ar rcs $(MATRIX_LIB) $(MATRIX_LIB_OBJS)

%.o: %.cpp
	g++ -c $< -o $@ $(CPP_FLAGS)

clean:
	rm -f *.o */*.o *~ */*~ */*/*~

clean-exec: clean
	rm -f $(EXEC)

clean-all: clean-exec
	rm -f $(MATRIX_LIB)


