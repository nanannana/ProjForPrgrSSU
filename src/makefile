OUTDIR = ./bin
BUILD = project.out
OBJS = main.o fileIO.o login.o manageData.o menu.o

.PHONY: all clean

all : $(BUILD)

clean :
	@rm -f $(addprefix $(OUTDIR)/,$(BUILD)) $(addprefix $(OUTDIR)\,$(OBJS))

$(BUILD) : $(OBJS) 
	ld -o $(addprefix $(OUTDIR)/,$@) $(addprefix $(OUTDIR)/,$^)

main.o : $($(notdir $@):.o=.c) $($(filter-out main.o,$(OBJS)):.o=.h)
%.o : $($(notdir $@):.o=.c) $($(notdir $@):.o=.c)

.c.o :
	gcc -c -o $(addprefix $(OUTDIR)/,$@) $<
