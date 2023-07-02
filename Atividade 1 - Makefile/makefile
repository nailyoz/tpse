all: calculadora

SRCDIR= ./src
OBJDIR= ./obj
SOURCEDIR = src/code
sources = $(wildcard $(SRCDIR)/*.c)
objects=  $(wildcard $(OBJDIR)/*.o)

calculadora: $(objects)
	gcc -o calculadora $(objects)

objetos: $(sources)
	gcc -c $(sources) -o $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$<)

clean:
	rm -rf $(objects)