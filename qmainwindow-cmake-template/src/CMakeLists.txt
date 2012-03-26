include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}

    ${QT_INCLUDES}
)

set(qtapp_SRCS
    mainwindow.cpp
    main.cpp
)

qt4_automoc(${qtapp_SRCS})
add_executable(qtapp ${qtapp_SRCS})
target_link_libraries(qtapp
    ${QT_QTCORE_LIBRARY}
    ${QT_QTGUI_LIBRARY}
)

install(TARGETS qtapp ${INSTALL_TARGETS_DEFAULT_ARGS})
