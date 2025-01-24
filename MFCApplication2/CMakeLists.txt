cmake_minimum_required(VERSION 3.10)

# Nazwa projektu
project(CarDatabase_HP)

# Ustaw standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Określ, że projekt używa MFC
add_definitions(-D_AFXDLL)

# Pliki źródłowe aplikacji
set(SOURCE_FILES
    CarDatabase_HP.cpp
    CarDatabase_HPDlg.cpp
    pch.cpp
)

# Pliki nagłówkowe aplikacji
set(HEADER_FILES
    CarDatabase_HP.h
    CarDatabase_HPDlg.h
    pch.h
    resource.h
)

# Pliki zasobów aplikacji
set(RESOURCE_FILES
    CarDatabase_HP.rc
)

# Tworzenie pliku wykonywalnego aplikacji
add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES} ${HEADER_FILES} ${RESOURCE_FILES})

# Uwzględnij katalogi nagłówków aplikacji
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

# Konfiguracja GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# Zapobiegaj nadpisaniu ustawień kompilatora/linkera dla Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Konfiguracja testów
set(TEST_FILES tests.cpp)  # Pliki testowe

add_executable(CarDatabase_HP_Tests ${TEST_FILES})

# Uwzględnij katalog z nagłówkami aplikacji w testach
target_include_directories(CarDatabase_HP_Tests PRIVATE ${CMAKE_SOURCE_DIR})

# Linkowanie testów z GoogleTest
target_link_libraries(CarDatabase_HP_Tests PRIVATE gtest gtest_main)

# Rejestracja testów
enable_testing()
add_test(NAME CarDatabase_HP_Tests COMMAND CarDatabase_HP_Tests)
