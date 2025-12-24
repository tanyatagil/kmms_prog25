BUILD_TYPE="Ninja"
BUILD_SUFFIX="ninja"

BUILD_FOLDER="build_${BUILD_SUFFIX}"
SOURCE_FOLDER="projects"

if [ ! -d "${BUILD_SUFFIX}" ]; then
    mkdir "${BUILD_SUFFIX}"
fi

cd "${BUILD_SUFFIX}"

cmake -G "${BUILD_TYPE}" "../${SOURCE_FOLDER}"
cmake --build .

