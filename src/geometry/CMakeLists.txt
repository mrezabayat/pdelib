#------------------------------------------------------------
# pdelib's geometry shared library
#------------------------------------------------------------

#------------------------------------------------------------
# Glob Source files
#------------------------------------------------------------
file(GLOB SOURCES_H   *.h)
file(GLOB SOURCES_CPP *.cpp)
set(SOURCE_FILES ${SOURCES_H} ${SOURCES_CPP})
set(LIBNAME geometry)

#------------------------------------------------------------
# Building the LIBRARY
#------------------------------------------------------------
add_library(${LIBNAME} ${SOURCE_FILES})

target_link_libraries(${LIBNAME} ${pdelib_libraries})

install(TARGETS ${LIBNAME} DESTINATION ${PDELIB_LIBS_INSTALL})
install(FILES ${SOURCES_H} DESTINATION ${PDELIB_INCLUDE_INSTALL})

# Storing the Library
set(pdelib_libraries ${pdelib_libraries} ${LIBNAME} CACHE INTERNAL "pdelib_libraries")