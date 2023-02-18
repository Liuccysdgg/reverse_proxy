#include "hpsocket/hpsocket.h"
#include "util/log4.h"
#include "public/environment.h"
#include <iostream>
#include "network/http/http_agent.h"
#include "network/http/http_center.h"
#include "network/http/http_website.h"
#include "network/http/http_router.h"
#include "network/http/http_request.h"
#include "network/http/http_response.h"
int main()
{
    // 创建控制中心
    auto center = new network::http::center;
    // 读取配置文件
    newobj::json config;
    config.parse_file("./res/config.json");
    if (center->create(config) == false)
    {
        newobj::log->fatal(center->last_error(),"main");
        return 0;
    }


    // 启动控制中心
    if(center->start() == false){
        newobj::log->fatal(center->last_error(),"main");
        return 0;
    }

    newobj::log->info("start success");




    while(true){
        std::string input;
        std::cin>>input;
        if(input == "exit" || input == "quit")
            break;
    }

    center->close();
    delete center;

    return 0;

}
