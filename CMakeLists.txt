# tp4 targets
add_executable(tp4 tp4.c)
target_link_libraries(tp4 eibase ei m ${Allegro_LIBRARIES})
 
add_executable(tp4_button tp4_button.c)
target_link_libraries(tp4_button eibase ei m ${Allegro_LIBRARIES})

# tp5 target
add_executable(tp5 tp5.c)
target_link_libraries(tp5 eibase ei m ${Allegro_LIBRARIES})

# tp6 target
add_executable(tp6 tp6.cpp viewer.cpp rectangle.cpp point.cpp)
target_link_libraries(tp6 eibase ei m ${Allegro_LIBRARIES})


# Automatic tests
add_executable(unit_tests unit_tests.cpp)
target_link_libraries(unit_tests eibase ei m ${Allegro_LIBRARIES})

enable_testing()
ms_add_catch_tests(unit_tests)