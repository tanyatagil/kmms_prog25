#!/bin/bash

BUILD_TYPE=Ninja
BUILD_SUFFIX=ninja
BUILD_FOLDER="build_${BUILD_SUFFIX}"
SOURCE_FOLDER="."
IMG_FOLDER="img"

# Создаём папку сборки, если её нет
mkdir -p "$BUILD_FOLDER"

cd "$BUILD_FOLDER" || exit 1

# Конфигурация CMake
cmake -G "$BUILD_TYPE" "../$SOURCE_FOLDER" || exit 1

# Сборка проекта
cmake --build . || exit 1

# Создаём папку для изображений
mkdir -p "$IMG_FOLDER"

# Копируем изображение
cp "../$IMG_FOLDER/grustnii-smail.png" "$IMG_FOLDER/"

# Возвращаемся в корневую папку проекта
cd ..