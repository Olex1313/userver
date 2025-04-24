#include "userver/storages/odbc/connection.hpp"
#include <sql.h>
#include <sqlext.h>
#include <stdexcept>

USERVER_NAMESPACE_BEGIN

namespace storages::odbc {

Connection::Connection(const settings::ODBCSettings& settings) : env_(), handle_() {
    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env_);
    SQLAllocConnect(env_, &handle_);

    SQLCHAR outString[1024];
    SQLSMALLINT outLength = 0;

    const char* dsn_const = settings.DSN.data();
    char* dsn_non_const = const_cast<char*>(dsn_const);            // NOLINT
    SQLCHAR* dsn_ptr = reinterpret_cast<SQLCHAR*>(dsn_non_const);  // NOLINT

    auto ret = SQLDriverConnect(
        handle_, nullptr, dsn_ptr, SQL_NTS, outString, sizeof(outString), &outLength, SQL_DRIVER_NOPROMPT
    );

    if (!SQL_SUCCEEDED(ret)) {
        throw std::runtime_error("failed to establish connection");
    }
}

Connection::~Connection() {
    SQLFreeEnv(env_);
    SQLFreeHandle(SQL_HANDLE_ENV, handle_);
}

}  // namespace storages::odbc

USERVER_NAMESPACE_END