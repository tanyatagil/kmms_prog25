#!/bin/bash

export LANG=en_US.UTF-8

BUILD_TYPE="Ninja"
BUILD_SUFFIX="ninja"

BUILD_FOLDER="build_${BUILD_SUFFIX}"
SOURCE_FOLDER="project"

# Создаем папку сборки
mkdir -p ${BUILD_FOLDER}

# Переходим в папку сборки
cd ${BUILD_FOLDER} || exit 1

# Конфигурация CMake
cmake -G ${BUILD_TYPE} ../${SOURCE_FOLDER}

# Сборка
cmake --build .

# Запуск тестов (исправленный путь)
if [ -d "test" ]; then
    cd test || exit 1
    # Запускаем тесты напрямую, не через ctest
    ./ttv_test
    cd ..
fi

cd ..

echo "=== Сборка и тестирование завершены! ==="
