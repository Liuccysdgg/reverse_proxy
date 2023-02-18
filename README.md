# reverse_proxy
C++  实现类nginx反向代理

# 配置文件示例
```json
{
    // 站点
	"website": [{
		"host": [{
            // 绑定域名及是否启用HTTPS协议
			"host": "121.4.122.35:7777",
			"ssl": false
		}],
		"proxy": [{
            // 代理源目录
			"src": "/",
            // 代理目标目录
			"dst": "/",
            // 代理地址
			"remote": "https://www.baidu.com",
            // 协议头
            "headers": [{
				"key": "Host",
				"value": "{host}"
			}]
		}],
        // 路由配置
        "router":{
            "threadpool":{
                "size":16,
                "queuemax":1000
            }
        }
	}],
    // SSL证书
	"ssl": {
		"xxx.com": {
			"enable": true,
			"pem_cert": "./res/ssl/xxx.pem",
			"pem_key": "./res/ssl/xxx.key",
			"pem_password": ""
		}
	}
}

```

# 安装部署

```shell

# 构建newobj基础框架
cd ~
mkdir lib
cd lib
wget http://file.newobj.org/build.sh
chmod 777 build.sh
./build.sh
cd ~

# 创建项目目录
mkdir project
git clone https://github.com/Liuccysdgg/reverse_proxy.git
cd reverse_proxy
./build.sh
./kernel

```
