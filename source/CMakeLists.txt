

add_executable(raytracer 

raytracer.cpp

folders/loader/sdfLoader.cpp
folders/loader/objLoader.cpp

folders/shapes/shape.cpp
folders/shapes/sphere.cpp 
folders/shapes/material.cpp
folders/shapes/plane.cpp 
folders/shapes/box.cpp 
folders/shapes/triangle.cpp 
folders/shapes/composite.cpp
folders/shapes/cone.cpp
folders/shapes/cylinder.cpp

folders/camera/camera.cpp 
folders/camera/ray.cpp 

folders/renderer/render.cpp
folders/renderer/light.cpp
        folders/loader/sdfwriter.cpp
folders/renderer/scene.cpp

folders/skybox/skybox.cpp
folders/skybox/ppm.cpp
)


#set(CMAKE_EXE_LINKER_FLAGS "-static")#remove if it does not work
#set(CMAKE_CXX_STANDARD 14)#remove for non omp
#find_package(OpenMP REQUIRED)#remove for non omp



target_link_libraries(raytracer ${FRAMEWORK_NAME} ${LIBRARIES}
  glfw
  ${GLFW_LIBRARIES}
        #OpenMP::OpenMP_CXX #remove for non omp
  )
add_dependencies(raytracer glfw ${FRAMEWORK_NAME} ${COPY_BINARY})





install(TARGETS raytracer DESTINATION .)

# Build tests
add_executable(tests
        ../framework/prog5/tests.cpp ../framework/prog5/Shape.cpp ../framework/prog5/Sphere.cpp ../framework/prog5/Box.cpp ../framework/prog5/Shape.cpp ../framework/prog5/Ray.cpp ../framework/prog5/HitPoint.cpp)
target_link_libraries(tests
  ${GLFW_LIBRARIES}
  )



#if it does not work, remove below
#set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")#remove if it does not work
#set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")#remove if it does not work

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")#remove if it does not work
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")#remove if it does not work
#set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${OpenMP_SHARED_LINKER_FLAGS}")#remove if it does not work
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")#remove if it does not work


