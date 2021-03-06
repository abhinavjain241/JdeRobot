#SET( DEPS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../Deps) # Directorio donde se encuentran las dependencias
#include(${DEPS_DIR}/openni2/CMakeLists.txt)
#include(${DEPS_DIR}/nite2/CMakeLists.txt)

IF(with_openni2)
	#check for the path openni libs
	


	SET( SOURCE_FILES openniServer.cpp myprogeo.cpp )
    add_definitions(-DGLADE_DIR="${gladedir}")

	set( CMAKE_CXX_FLAGS "-Wno-deprecated -Wl,-rpath ./" ) # Opciones para el compilador

    include_directories(
        ${INTERFACES_CPP_DIR}
        ${LIBS_DIR}/
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/cameras
		${NITE2_INC}
		
    )

    add_executable (openniServer ${SOURCE_FILES})
	#copy openni libs to local path
	if (NOT IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/OpenNI2)
		file (COPY ${OPENNI2_LIB} DESTINATION .)
		file (COPY ${OPENNI2_LIB_PATH}/OpenNI2 DESTINATION .)
		
	endif()


	if  ( NITE2_LIB )
		set_property ( SOURCE openniServer.cpp
			PROPERTY COMPILE_DEFINITIONS WITH_NITE2=1
		)
		#copy nite libs to local path
		if (NOT IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/NiTE2)
			message ("--CMake will install local NiTE2 lib and Driver")
			file (COPY ${NITE2_LIB}/libNiTE2.so DESTINATION .)
			file (COPY ${NITE2_LIB}/NiTE2 DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})
		endif()
	TARGET_LINK_LIBRARIES(openniServer
        ${CMAKE_THREAD_LIBS_INIT}
	${CMAKE_THREAD_LIBS_INIT}
        ${ZeroCIce_LIBRARIES}
        ${OpenCV_LIBRARIES}
        ${OpenCVGUI_LIBRARIES} 
        ${gsl_LIBRARIES}
	logger
	ns
        jderobotutil
        geometry
        colorspacesmm
        JderobotInterfaces
	${OPENNI2_LIB}
	${NITE2_LIB}/libNiTE2.so
	${Boost_LIBRARIES}
        ${LIBXML2_LIBRARIES}
	)
	else()
	TARGET_LINK_LIBRARIES(openniServer
        ${CMAKE_THREAD_LIBS_INIT}
	${ZeroCIce_LIBRARIES}
	${OpenCV_LIBRARIES}
        ${OpenCVGUI_LIBRARIES}
	${gsl_LIBRARIES}
        jderobotutil
        geometry
        colorspacesmm
        JderobotInterfaces
	logger
	ns
	${OPENNI2_LIB}
        ${Boost_LIBRARIES}
        ${LIBXML2_LIBRARIES}
	)
	endif()
ENDIF()
