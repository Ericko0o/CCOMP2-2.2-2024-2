# Directorios de SFML
SFML_INCLUDE = C:\SFML\include
SFML_LIB = C:\SFML\lib

# Lista de archivos fuente
SOURCES = main.cpp chessGame.cpp board.cpp piece.cpp Piece_hijas.cpp pieceTextures.cpp

# Lista de archivos objeto
OBJECTS = $(SOURCES:.cpp=.o)

# Lista de archivos de encabezado
HEADERS = chessGame.h board.h piece.h Piece_hijas.h pieceTextures.h

# Nombre del ejecutable
EXECUTABLE = main

# Opciones del compilador
CXX = g++
CXXFLAGS = -I"$(SFML_INCLUDE)" -DSFML_STATIC
LDFLAGS = -L"$(SFML_LIB)" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

# Regla por defecto
all: $(EXECUTABLE)

# Regla para compilar los archivos fuente a objetos
%.o: %.cpp $(HEADERS)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# Regla para construir el ejecutable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $^ -o $@ $(LDFLAGS)

# Regla para limpiar archivos objeto y el ejecutable
clean:
	del /Q *.o $(EXECUTABLE).exe
