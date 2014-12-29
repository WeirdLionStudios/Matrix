MATRIX_LIB_DIR=lib

include $(MATRIX_LIB_DIR)/make.config

GAUSS_EXEC=gauss_determinant
INVERSE_EXEC=inverse
MATRIX_LIB_INCLUDE=$(MATRIX_LIB_DIR)/include/
MATRIX_LIB_NAME=matrix
MATRIX_LIB=libmatrix.a

LINK_FLAGS=-static -L$(MATRIX_LIB_DIR) -l$(MATRIX_LIB_NAME)
CPP_FLAGS=-I$(MATRIX_LIB_INCLUDE)

OBJS_COMMON=

OBJS_GAUSS=		\
gauss_determinant.o	\
$(OBJS_COMMON)		\

OBJS_INVERSE=		\
$(OBJS_COMMON)		\
inverse.o		\

.PHONY: all clean clean-all gauss inverse libmatrix

all:gauss inverse
	$(info *****Compiled all c++ projects*****)

gauss: $(OBJS_GAUSS) libmatrix
	g++ -o $(GAUSS_EXEC) $(OBJS_GAUSS) $(LINK_FLAGS)

inverse: $(OBJS_INVERSE) libmatrix
	g++ -o $(INVERSE_EXEC) $(OBJS_INVERSE) $(LINK_FLAGS)

libmatrix: $(MATRIX_LIB_OBJS)
	$(info *****creating libmatrix*****)
	ar rcs $(MATRIX_LIB_DIR)/$(MATRIX_LIB) $(MATRIX_LIB_OBJS)

%.o: %.cpp
	g++ -c $< -o $@ $(CPP_FLAGS)

clean:
	rm -f *.o */*.o *~ */*~ */*/*~ *.a */*.a

clean-all: clean
	rm -f $(GAUSS_EXEC) $(INVERSE_EXEC)


