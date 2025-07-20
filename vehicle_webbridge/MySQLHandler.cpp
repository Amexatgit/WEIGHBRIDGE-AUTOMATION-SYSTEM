// SpongeBob work in here about sql file
// Made some changes to the original code by adding try and catch blocks for error handling
#include "MySQLHandler.h"
#include <cppconn/prepared_statement.h>
#include <iostream>

MySQLHandler::MySQLHandler(const std::string& host,
                           const std::string& user,
                           const std::string& pass,
                           const std::string& db) {
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = std::unique_ptr<sql::Connection>(
            driver->connect("tcp://" + host + ":3306", user, pass)
        );
        con->setSchema(db);
    } catch (sql::SQLException& e) {
        std::cerr << "MySQL connection failed: " << e.what() << std::endl;
        exit(1);
    }
}

MySQLHandler::~MySQLHandler() {
    if (con && !con->isClosed()) con->close();
}

void MySQLHandler::insertData(const std::string& weight,
                              const std::string& timestamp,
                              const std::string& imagePath) {
    try {
        std::unique_ptr<sql::PreparedStatement> stmt(
            con->prepareStatement("INSERT INTO vehicle_log(weight, timestamp, image_path) VALUES (?, ?, ?)")
        );
        stmt->setString(1, weight);
        stmt->setString(2, timestamp);
        stmt->setString(3, imagePath);
        stmt->execute();
    } catch (sql::SQLException& e) {
        std::cerr << "Data insert failed: " << e.what() << std::endl;
    }
}
