target_sources(${LIBRARY_NAME}
	PRIVATE
		bubble_sort.cpp
	PUBLIC
		bubble_sort.hpp
)

target_include_directories(${LIBRARY_NAME} PUBLIC
	${PROJECT_SOURCE_DIR}/src
)
