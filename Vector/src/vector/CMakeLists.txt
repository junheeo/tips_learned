add_library(Vector_Lib INTERFACE)
target_include_directories(Vector_Lib INTERFACE .)

set(EXPORT_DIR "${CMAKE_CURRENT_BINARY_DIR}/cmake")
export(TARGETS Vector_Lib
    APPEND
    FILE "${EXPORT_DIR}/Vector_LibTargets.cmake"
    NAMESPACE Vector::
)
