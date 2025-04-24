project(userver-odbc CXX)

userver_module(odbc
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}"
    #LINK_LIBRARIES_PRIVATE libmariadb ZLIB::ZLIB OpenSSL::SSL OpenSSL::Crypto

    DBTEST_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/tests"
    DBTEST_DATABASES postgresql
    DBTEST_ENV POSTGRES_TEST_DSN=postgresql://testsuite@localhost:15433/postgres
    #UTEST_LINK_LIBRARIES libmariadb
    #DBTEST_DATABASES mysql
    #UBENCH_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/benchmarks"
    #UBENCH_LINK_LIBRARIES libmariadb
    #UBENCH_DATABASES mysql
)

_userver_directory_install(COMPONENT odbc FILES
    "${USERVER_ROOT_DIR}/cmake/modules/Findlibodbc.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/userver/modules"
)

# if (USERVER_BUILD_TESTS)
#   add_subdirectory(functional_tests)
# endif()
