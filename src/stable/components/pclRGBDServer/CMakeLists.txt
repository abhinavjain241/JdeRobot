
if(pcl_openni)

    SET( SOURCE_FILES kinectServer.cpp)

    include_directories(
        ${INTERFACES_CPP_DIR}
        ${LIBS_DIR}/
        ${CMAKE_CURRENT_SOURCE_DIR}
        /usr/include/vtk-5.8
    )

    link_directories(${pcl_LIBRARIES})
    include_directories(${pcl_INCLUDE_DIR})

    add_executable (pclRGBDServer  ${SOURCE_FILES})

    TARGET_LINK_LIBRARIES(pclRGBDServer 
      ${CMAKE_THREAD_LIBS_INIT}
      ${ZeroCIce_LIBRARIES}
      ${PCL_LIBRARIES}
      ${OpenCV_LIBRARIES}
      JderobotInterfaces
      jderobotutil
      ${openni_LIBRARIES}
      ${Boost_LIBRARIES}
    )

endif()
