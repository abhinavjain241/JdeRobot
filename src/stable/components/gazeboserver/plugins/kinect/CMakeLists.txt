if (pcl_LIBRARIES)

include_directories( 
	${GAZEBO_INCLUDE_DIRS}
    ${INTERFACES_CPP_DIR}
    ${LIBS_DIR}
	${GEARBOX_INCLUDE_DIRS}
	/usr/include/vtk-5.8
    ${CMAKE_CURRENT_SOURCE_DIR}
	) 

link_directories( 
	${GAZEBO_LIBRARY_DIRS} 
	)

set( CMAKE_CXX_FLAGS "-Wall -lpcl_filters" ) # Opciones para el compilador

add_library(kinectPlugin SHARED kinectPlugin.cc)

target_link_libraries(kinectPlugin 
    JderobotInterfaces
    jderobotutil
    ${GAZEBO_libraries} 
    ${pcl_LIBRARIES}  
    ${OpenCV_LIBRARIES}
    ${ZeroCIce_LIBRARIES}
)

endif()
