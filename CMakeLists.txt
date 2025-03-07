# Get CMake PreDefined Variables https://cmake.org/cmake/help/latest/manual/cmake-variables.7.html
# This CMake File for OpenGL Projects is compiled by Kushagra
# I do not claim that this is the best CMake Configuration you will get but it does work.

cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(CEngine)

# Add all Source Files
file(GLOB_RECURSE SOURCE_FILES 
	${CMAKE_SOURCE_DIR}/src/*.c
)

# Add all Header Files
file(GLOB_RECURSE HEADER_FILES 
	${CMAKE_SOURCE_DIR}/src/*.h
	${CMAKE_SOURCE_DIR}/src/*.hpp
)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES}
		src/cengine/renderer/window.c
		src/cengine/util/prelude.c
		src/cengine/util/prelude.h
		src/cengine/renderer/window.h
		src/cengine/util/types.h
		src/cengine/util/uthash.h
		src/cengine/game/ecs.h
        src/game.c
		src/cengine/renderer/renderer.c
		src/cengine/renderer/renderer.h
		src/cengine/game/gamesetup.c
		src/cengine/game/gamesetup.h
		src/game.h
		src/cengine/game/gamestate.h
		src/cengine/cengine.h
		src/cengine/game/ecstypes.h
		src/cengine/game/input.c
		src/cengine/game/input.h
		src/game/player.c
		src/game/player.h
		src/cengine/game/prelude.h
		src/cengine/renderer/prelude.h
)


# Find the Required Packages (if Any -> OpenGL/Vulkan or Any)
find_package(OpenGL REQUIRED)

# Variable for the Libs to add to the Linkers
if (WIN32)
	set(LIBS glfw opengl32 glad)
elseif (UNIX)
	set(LIBS glfw GL glad)
endif ()

# Variables for Paths of External Libraries
set(GLFW_ROOT_DIR external/glfw)
set(GLAD_ROOT_DIR external/glad)


# Add the External Libraries / Files Directory
add_subdirectory(${GLFW_ROOT_DIR})
add_subdirectory(${GLAD_ROOT_DIR})

# Add the Include Directories for the Libraries / Files
#Used for adding #include into the cpp files

#		Include Files From Within the Workspace Folder

target_include_directories(${PROJECT_NAME} 
	PUBLIC ${GLFW_ROOT_DIR}/include
	PUBLIC ${GLAD_ROOT_DIR}/include/glad
)

#		Include Files from Outside the Workspace Folder -> Like Vulkan SDK

#target_include_directories(${PROJECT_NAME}
#	PRIVATE ${Vulkan_INCLUDE_DIRS}
#)

# Add the Link Directories for the Libraries / Files
#Used for creation of Static/Dynamic Libraries

#		Include Files From Within the Workspace Folder

target_link_directories(${PROJECT_NAME} 
	PRIVATE ${GLFW_ROOT_DIR}/src
	PRIVATE ${GLAD_ROOT_DIR}/src}
)

# Add the Libs to the Linker for the Project

target_link_libraries(${PROJECT_NAME} ${LIBS})

# EXPLANATION FOR SOME STUFF

# GLOB_RECURSE -> Recursively go through all subdirectories
#		of the given path and get all the files matching the extension provided
# file() -> Store the Files matching the RegEx into a variable
# set() -> Alternative to file() if you want to set variables for a custom behaviour