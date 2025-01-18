cmake_minimum_required(VERSION 3.10)

# Nazwa projektu
project(CarDatabase_HP)

# Ustaw standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Określ, że projekt używa MFC
add_definitions(-D_AFXDLL)

# Dodaj pliki źródłowe
set(SOURCE_FILES
    CarDatabase_HP.cpp
    CarDatabase_HPDlg.cpp
    pch.cpp
    )

# Dodaj pliki nagłówkowe
set(HEADER_FILES
    CarDatabase_HP.h
    CarDatabase_HPDlg.h
    pch.h
    resource.h
    )

# Dodaj pliki zasobów
set(RESOURCE_FILES
    CarDatabase_HP.rc
    )

# Tworzenie pliku wykonywalnego
add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES} ${HEADER_FILES} ${RESOURCE_FILES})

# Uwzględnij katalogi nagłówków
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR})

# Linkowanie z bibliotekami MFC
target_link_libraries(${PROJECT_NAME} PRIVATE
    user32
    gdi32
    comdlg32
    advapi32
    shell32
    ole32
    oleaut32
    uuid
    winmm
    )
