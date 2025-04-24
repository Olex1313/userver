_userver_module_begin(
    NAME libmariadb
    VERSION 3.0.3
    DEBIAN_NAMES unixodbc-dev
    FORMULA_NAMES unixodbc
    PKG_CONFIG_NAMES unixodbc
)

_userver_module_find_include(
    NAMES sql.h
    PATH_SUFFIXES unixodbc
)

_userver_module_find_library(
    NAMES unixodbc 
)

_userver_module_end()
