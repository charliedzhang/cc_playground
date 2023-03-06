add_library(cc_playground cc_playground.cpp)
target_include_directories(cc_playground PUBLIC ../include)
#target_link_libraries(cc_playground PRIVATE Boost::headers)
set_target_properties(cc_playground PROPERTIES VERSION ${CONAN_PACKAGE_VERSION})

