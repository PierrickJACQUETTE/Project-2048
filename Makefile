#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = `pwd`

CC = gcc
CXX = g++ -std=c++11
AR = ar
LD = g++
WINDRES = windres

INC = 
CFLAGS = -Wall -fexceptions
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

INC_DEBUG = $(INC) -Iinclude
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = bin/Debug/test

INC_RELEASE = $(INC) -Iinclude
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = bin/Release/test

OBJ_DEBUG = $(OBJDIR_DEBUG)/main.o $(OBJDIR_DEBUG)/src/Utilisateur.o $(OBJDIR_DEBUG)/src/Plateau.o $(OBJDIR_DEBUG)/src/Jeu_Taquin.o $(OBJDIR_DEBUG)/src/Jeu_Sokoban.o $(OBJDIR_DEBUG)/src/Jeu_2048_neg.o $(OBJDIR_DEBUG)/src/Jeu_2048_double.o $(OBJDIR_DEBUG)/src/Jeu_2048_destroy.o $(OBJDIR_DEBUG)/src/Jeu_2048.o $(OBJDIR_DEBUG)/src/Jeu.o $(OBJDIR_DEBUG)/src/Case.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/main.o $(OBJDIR_RELEASE)/src/Utilisateur.o $(OBJDIR_RELEASE)/src/Plateau.o $(OBJDIR_RELEASE)/src/Jeu_Taquin.o $(OBJDIR_RELEASE)/src/Jeu_Sokoban.o $(OBJDIR_RELEASE)/src/Jeu_2048_neg.o $(OBJDIR_RELEASE)/src/Jeu_2048_double.o $(OBJDIR_RELEASE)/src/Jeu_2048_destroy.o $(OBJDIR_RELEASE)/src/Jeu_2048.o $(OBJDIR_RELEASE)/src/Jeu.o $(OBJDIR_RELEASE)/src/Case.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)
	test -d $(OBJDIR_DEBUG)/src || mkdir -p $(OBJDIR_DEBUG)/src

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/main.o: main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c main.cpp -o $(OBJDIR_DEBUG)/main.o

$(OBJDIR_DEBUG)/src/Utilisateur.o: src/Utilisateur.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Utilisateur.cpp -o $(OBJDIR_DEBUG)/src/Utilisateur.o

$(OBJDIR_DEBUG)/src/Plateau.o: src/Plateau.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Plateau.cpp -o $(OBJDIR_DEBUG)/src/Plateau.o

$(OBJDIR_DEBUG)/src/Jeu_Taquin.o: src/Jeu_Taquin.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Jeu_Taquin.cpp -o $(OBJDIR_DEBUG)/src/Jeu_Taquin.o

$(OBJDIR_DEBUG)/src/Jeu_Sokoban.o: src/Jeu_Sokoban.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Jeu_Sokoban.cpp -o $(OBJDIR_DEBUG)/src/Jeu_Sokoban.o

$(OBJDIR_DEBUG)/src/Jeu_2048_neg.o: src/Jeu_2048_neg.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Jeu_2048_neg.cpp -o $(OBJDIR_DEBUG)/src/Jeu_2048_neg.o

$(OBJDIR_DEBUG)/src/Jeu_2048_double.o: src/Jeu_2048_double.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Jeu_2048_double.cpp -o $(OBJDIR_DEBUG)/src/Jeu_2048_double.o

$(OBJDIR_DEBUG)/src/Jeu_2048_destroy.o: src/Jeu_2048_destroy.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Jeu_2048_destroy.cpp -o $(OBJDIR_DEBUG)/src/Jeu_2048_destroy.o

$(OBJDIR_DEBUG)/src/Jeu_2048.o: src/Jeu_2048.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Jeu_2048.cpp -o $(OBJDIR_DEBUG)/src/Jeu_2048.o

$(OBJDIR_DEBUG)/src/Jeu.o: src/Jeu.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Jeu.cpp -o $(OBJDIR_DEBUG)/src/Jeu.o

$(OBJDIR_DEBUG)/src/Case.o: src/Case.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/Case.cpp -o $(OBJDIR_DEBUG)/src/Case.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)
	rm -rf $(OBJDIR_DEBUG)/src

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)
	test -d $(OBJDIR_RELEASE)/src || mkdir -p $(OBJDIR_RELEASE)/src

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/main.o: main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c main.cpp -o $(OBJDIR_RELEASE)/main.o

$(OBJDIR_RELEASE)/src/Utilisateur.o: src/Utilisateur.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Utilisateur.cpp -o $(OBJDIR_RELEASE)/src/Utilisateur.o

$(OBJDIR_RELEASE)/src/Plateau.o: src/Plateau.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Plateau.cpp -o $(OBJDIR_RELEASE)/src/Plateau.o

$(OBJDIR_RELEASE)/src/Jeu_Taquin.o: src/Jeu_Taquin.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Jeu_Taquin.cpp -o $(OBJDIR_RELEASE)/src/Jeu_Taquin.o

$(OBJDIR_RELEASE)/src/Jeu_Sokoban.o: src/Jeu_Sokoban.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Jeu_Sokoban.cpp -o $(OBJDIR_RELEASE)/src/Jeu_Sokoban.o

$(OBJDIR_RELEASE)/src/Jeu_2048_neg.o: src/Jeu_2048_neg.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Jeu_2048_neg.cpp -o $(OBJDIR_RELEASE)/src/Jeu_2048_neg.o

$(OBJDIR_RELEASE)/src/Jeu_2048_double.o: src/Jeu_2048_double.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Jeu_2048_double.cpp -o $(OBJDIR_RELEASE)/src/Jeu_2048_double.o

$(OBJDIR_RELEASE)/src/Jeu_2048_destroy.o: src/Jeu_2048_destroy.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Jeu_2048_destroy.cpp -o $(OBJDIR_RELEASE)/src/Jeu_2048_destroy.o

$(OBJDIR_RELEASE)/src/Jeu_2048.o: src/Jeu_2048.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Jeu_2048.cpp -o $(OBJDIR_RELEASE)/src/Jeu_2048.o

$(OBJDIR_RELEASE)/src/Jeu.o: src/Jeu.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Jeu.cpp -o $(OBJDIR_RELEASE)/src/Jeu.o

$(OBJDIR_RELEASE)/src/Case.o: src/Case.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/Case.cpp -o $(OBJDIR_RELEASE)/src/Case.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)
	rm -rf $(OBJDIR_RELEASE)/src

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

