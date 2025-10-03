

#ifndef MYSQLHANDLER_H
#define MYSQLHANDLER_H

#include "DataStorage.h"
#include <string>
#include <memory>
#include <cppconn/driver.h>

class MySQLHandler : public DataStorage {
public:
    MySQLHandler(const std::string& host,
                 const std::string& user,
                 const std::string& pass,
                 const std::string& db);

    ~MySQLHandler();

    void insertData(const std::string& weight,
                    const std::string& timestamp,
                    const std::string& imagePath) override;

private:
    sql::Driver* driver;
    std::unique_ptr<sql::Connection> con;
};

#endif
