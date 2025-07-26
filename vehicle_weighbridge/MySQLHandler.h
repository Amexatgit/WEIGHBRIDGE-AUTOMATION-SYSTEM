

#ifndef MYSQLHANDLER_H
#define MYSQLHANDLER_H

#include <string>
#include <cppconn/driver.h>

class MySQLHandler {
public:
    MySQLHandler(const std::string& host,
                 const std::string& user,
                 const std::string& pass,
                 const std::string& db);

    void insertData(const std::string& weight,
                    const std::string& timestamp,
                    const std::string& imagePath);

private:
    sql::Driver* driver;
    std::unique_ptr<sql::Connection> con;
};

#endif
