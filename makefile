PROGRAM=simulador
CC=gcc
EXT=c
OPC=-lm

SRC_D=src
OBJ_D=obj

# se pueden usar variables para buscar automaticamente los archivos
TDAS=$(wildcard $(SRC_D)/*.h)
SRCS=$(wildcard $(SRC_D)/*.$(EXT))
OBJS_=$(SRCS:.$(EXT)=.o)
OBJS=$(subst $(SRC_D),$(OBJ_D),$(OBJS_))


$(OBJ_D)/%.o: $(SRC_D)/%.$(EXT) $(TDAS)
	$(CC) -c -o $@ $< $(OPC)

all : $(OBJS)
	$(CC) -g -o $(PROGRAM) $^ $(OPC)

.PHONY : clean

clean :
	rm -f -r $(OBJ_D)/*.o & rm $(PROGRAM)
