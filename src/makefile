OUTDIR = ./bin
BUILD = project.out
OBJS = main.o fileIO.o login.o manageData.o menu.o

.PHONY: all clean

all : $(BUILD)

clean :
	@rm -f $(addprefix $(OUTDIR)/,$(BUILD)) $(addprefix $(OUTDIR)\,$(OBJS))

$(BUILD) : $(OBJS) 
	ld -o $(addprefix $(OUTDIR)/,$@) $(addprefix $(OUTDIR)/,$^)

main.o : $(subst .o,.c,$(notdir $@)) $(subst .o,.c,$(filter-out main.o,$(OBJS)))
%.o : $(subst .o,.c,$(notdir $@)) $(subst .o,.c,$(notdir $@))

.c.o :
	gcc -c -o $(addprefix $(OUTDIR)/,$@) $<
