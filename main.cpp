#include "./include/Mlinson/JsonParser.hpp"
#include <iostream>

int main() {
    std::string json1 = R"({"name": "yo", "age": 21})";
    std::string json2 = R"({"numbers": [1, 2, 3, 4], "boolean": true, "nullValue": null})";

    JSONParser parser;

    try {
        JSONValue result1 = parser.parse(json1);
        JSONValue result2 = parser.parse(json2);

        JSONObject &obj1 = result1.getObject();
        JSONObject &obj2 = result2.getObject();

        std::cout << "Name: " << obj1["name"]->getString() << std::endl;
        std::cout << "Age: " << obj1["age"]->getInt() << std::endl;

        JSONArray &numbers = obj2["numbers"]->getArray();
        std::cout << "Numbers: ";
        for (const auto &num : numbers) {
            std::cout << num->getInt() << " ";
        }
        std::cout << std::endl;

        std::cout << "Boolean: " << (obj2["boolean"]->getBool() ? "true" : "false") << std::endl;
        std::cout << "Null value exists: " << (obj2.find("nullValue") != obj2.end()) << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
