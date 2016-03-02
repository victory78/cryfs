set(DIR_OF_GITVERSION_TOOL "${CMAKE_CURRENT_LIST_DIR}" CACHE INTERNAL "DIR_OF_GITVERSION_TOOL")

function (get_git_version OUTPUT_VARIABLE)
    EXECUTE_PROCESS(COMMAND ${DIR_OF_GITVERSION_TOOL}/getversion.py
        OUTPUT_VARIABLE VERSION
        ERROR_VARIABLE error
        RESULT_VARIABLE result)
    STRING(STRIP "${VERSION}" STRIPPED_VERSION)
    SET(${OUTPUT_VARIABLE} "${STRIPPED_VERSION}" CACHE INTERNAL "${OUTPUT_VARIABLE}")
    MESSAGE(STATUS "Building version ${${OUTPUT_VARIABLE}}")
    IF(NOT ${result} EQUAL 0)
        MESSAGE(FATAL_ERROR "Error running versioneer. Return code is: ${result}, error message is: ${error}")
    ENDIF()
endfunction(get_git_version)
