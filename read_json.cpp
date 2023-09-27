#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


int main() {
    // 创建一个Boost PropertyTree对象来存储JSON数据
    boost::property_tree::ptree jsonData;

    // 从文件中加载JSON数据
    try {
        boost::property_tree::read_json("config.json", jsonData); // 替换为您的JSON文件路径
    } catch (const boost::property_tree::json_parser_error& e) {
        std::cerr << "解析JSON时发生错误: " << e.what() << std::endl;
        return 1;
    }
    
    // 提取参数
    try {
        std::string image_bg_path = jsonData.get<std::string>("image_bg_path");
        float gamma_value = jsonData.get<float>("gamma_value");
        //打印提取的参数
        std::cout << "参数 image_bg_path: " << image_bg_path << std::endl;
        std::cout << "参数 gamma_value: " << gamma_value << std::endl;

    } catch (const boost::property_tree::ptree_error& e) {
        std::cerr << "提取参数时发生错误: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
