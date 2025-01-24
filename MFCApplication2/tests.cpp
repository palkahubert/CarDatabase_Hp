#include <pch.h>
#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <iostream>
#include <CarDatabase_HP.h>

// Funkcja pomocnicza: sprawdza, czy plik zawiera okreœlony tekst
bool FileContains(const std::string& filePath, const std::string& content) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Nie mo¿na otworzyæ pliku." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.find(content) != std::string::npos) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// Funkcja pomocnicza: czyœci zawartoœæ pliku
void ClearDatabase(const std::string& filePath) {
    std::ofstream file(filePath, std::ofstream::trunc);
    if (!file.is_open()) {
        std::cerr << "Nie mo¿na wyczyœciæ pliku." << std::endl;
    }
    file.close();
}

// Test dodawania samochodu
TEST(CarDatabaseTests, AddCar) {
    const std::string filePath = "cars.txt";
    ClearDatabase(filePath);

    std::string carData = "Manufacturer: Ford, Model: Mustang, Year: 2022, Color: Red";
    {
        std::ofstream file(filePath, std::ios::app);
        ASSERT_TRUE(file.is_open()) << "Nie mo¿na otworzyæ pliku.";
        file << carData << "\n";
    }

    ASSERT_TRUE(FileContains(filePath, carData)) << "Samochód nie zosta³ dodany.";
}

// Test wyszukiwania samochodu
TEST(CarDatabaseTests, SearchCar) {
    const std::string filePath = "cars.txt";
    ClearDatabase(filePath);

    std::string carData = "Manufacturer: Ford, Model: Mustang, Year: 2022, Color: Red";
    {
        std::ofstream file(filePath, std::ios::app);
        ASSERT_TRUE(file.is_open()) << "Nie mo¿na otworzyæ pliku.";
        file << carData << "\n";
    }

    ASSERT_TRUE(FileContains(filePath, carData)) << "Nie mo¿na znaleŸæ samochodu.";
}

// Test usuwania samochodu
TEST(CarDatabaseTests, DeleteCar) {
    const std::string filePath = "cars.txt";
    const std::string tempFilePath = "cars_temp.txt";
    ClearDatabase(filePath);

    std::string carData = "Manufacturer: Ford, Model: Mustang, Year: 2022, Color: Red";
    {
        std::ofstream file(filePath, std::ios::app);
        ASSERT_TRUE(file.is_open()) << "Nie mo¿na otworzyæ pliku.";
        file << carData << "\n";
    }

    // Usuwanie samochodu
    std::ifstream file(filePath);
    std::ofstream tempFile(tempFilePath);
    ASSERT_TRUE(file.is_open() && tempFile.is_open()) << "Nie mo¿na otworzyæ plików.";

    std::string line;
    bool deleted = false;
    while (std::getline(file, line)) {
        if (line.find(carData) == std::string::npos) {
            tempFile << line << "\n";
        }
        else {
            deleted = true;
        }
    }
    file.close();
    tempFile.close();

    std::remove(filePath.c_str());
    std::rename(tempFilePath.c_str(), filePath.c_str());

    ASSERT_TRUE(deleted) << "Nie znaleziono samochodu do usuniêcia.";
    ASSERT_FALSE(FileContains(filePath, carData)) << "Samochód nie zosta³ usuniêty.";
}
