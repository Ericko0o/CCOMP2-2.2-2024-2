set(FILES
    board.cpp
    board.h
    chessGame.cpp
    chessGame.h
    main.cpp
    Piece_hijas.cpp
    Piece_hijas.h
    piece.cpp
    piece.h
    pieceTextures.cpp
    pieceTextures.h
    chessRules.cpp
    chessRules.h
    )

add_executable(${CMAKE_PROJECT_NAME} ${FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics sfml-window sfml-system)
