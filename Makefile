PROG = hazi  # a program neve (ezt allitjuk elo)
PROG_O = main.o string5.o menu.o kocsi.o hely.o ido.o vonat.o jegy.o fajlKezeles.o test_esetek.o # program object fajljai 
PROG_H = string5.h menu.hpp memtrace.h kocsi.hpp hely.hpp dinTomb.hpp ido.hpp vonat.hpp test_esetek.hpp   # program header fajljai
PROG_L =              # program libjei

MTRACE_O = memtrace.o # memtrace object fajl
MTRACE_H = memtrace.h # memtrace header fajlja

CXX = g++   # a C fordito neve
#CXX = clang++ # clang-ot (llvm) is erdemes kiprobalni
CXXFLAGS = -pedantic -Wall # kapcsolok: legyen bobeszedu es pedans
CXXFLAGS += -g -DMEMTRACE # es debug info is
LDFLAGS = -g # debug a linkelesnel 

# osszes object, osszes header osszes lib
OBJS = $(PROG_O) $(MTRACE_O)
HEADS = $(PROG_H) $(MTRACE_H)
LIBS = $(PROG_L) 

# alapertelmezett cel: program
.PHONY: all
all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@ $(LIBS)

# feltetelezzuk, hogy az osszes obj fugg az osszes headertol
$(OBJS): $(HEADS)

# takaritas igeny szerint
.PHONY: clean
clean:
	rm -f $(OBJS) $(PROG)

